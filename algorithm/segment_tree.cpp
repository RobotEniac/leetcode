#include <iostream>
#include <string>
#include <vector>

using namespace std;

class SegmentTree {
public:
    SegmentTree(const vector<int> &nums)
        : nums_(nums) {
        tree_.resize(nums.size() * 4);
        build(0, nums.size(), 1);
    }

    void Init(const vector<int> &nums) {
        nums_ = nums;
        tree_.resize(nums.size() * 4);
        build(0, nums.size(), 1);
    }

    int Sum(int l, int r) {
        return sum(l, r, 0, nums_.size(), 1);
    }


private:
    void build(int start, int end, int node)
    {
        if (end - start < 2) {
            tree_[node] = nums_[start];
            return;
        }
        int mid = start + ((end - start) >> 1);
        build(start, mid, node * 2);
        build(mid, end, node * 2+1);
        tree_[node] = tree_[node * 2] + tree_[node * 2 + 1];
    }

    int sum(int l, int r, int s, int e, int node) {
        if (r < s || l >= e) {
            return 0;
        }
        if (l <= s && r >= e) {
            return tree_[node];
        }
        int m = s + ((e - s) >> 1);
        if (l >= m) {
            return sum(l, r, m, e, node * 2 + 1);
        }
        if (r <= m) {
            return sum(l, r, s, m, node * 2);
        }
        int ls = sum(l, r, s, m, node * 2);
        int rs = sum(l, r, m, e, node * 2 + 1);
        return ls + rs;
    }

private:
    vector<int> tree_;
    vector<int> nums_;
};

int main(int argc, char *argv[]) {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};
    SegmentTree st(nums);
    cout << st.Sum(0, 8) << endl;
    // 生成10个测试用例
    for (int i = 0; i < 10; i++) {
        int l = rand() % nums.size();
        int r = rand() % nums.size();
        if (l > r) {
            swap(l, r);
        }
        cout << l << " " << r << " " << st.Sum(l, r) << endl;
    }
    return 0;
}