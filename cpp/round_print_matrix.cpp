#include <vector>
#include <iostream>

using namespace std;

vector<int> round_print_matrix(vector<vector<int>> &matrix) {
    vector<int> ret;
    int m = matrix.size();
    int n = matrix[0].size();
    int sz = m * n;
    int left = 0, right = n - 1, top = 0, bottom = m - 1;
    int i =0, j = 0;
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int d = 0;
    while (ret.size() < sz) {
        if (i >= top && i <= bottom && j >= left && j <= right) {
            ret.push_back(matrix[i][j]);
        } else {
            break;
        }
        int ni = i + dirs[d][0];
        int nj = j + dirs[d][1];
        if (nj > right) {
            d = (d + 1) % 4;
            ++i;
            ++top;
        } else if (nj < left) {
            d = (d + 1) % 4;
            --i;
            --bottom;
        } else if (ni > bottom) {
            d = (d + 1) % 4;
            --j;
            --right;
        } else if (ni < top) {
            d = (d + 1) % 4;
            ++j;
            ++left;
        } else {
            i = ni;
            j = nj;
        }
    }
    return ret;
}

int main() {
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> ret = round_print_matrix(matrix);
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << " ";
    }
    cout << endl;
    return 0;
}