#include <iostream>
#include <vector>

using namespace std;

int jump_aux(vector<int> &nums, int s) {
    if (s == 0) {
        return nums.size();
    }
    if (s >= nums.size() - 1) {
        return 0;
    }
    if (nums.size() - s < 2) {
        return 1;
    }
    if (s + nums[s] >= nums.size()) {
        return 1;
    }
    int min = 1;
    for (int i = 1; i <= nums[s]; ++i) {

    }
}

int jump(vector<int> &nums) {
    if (nums.size() < 2) {
        return 1;
    }
}
