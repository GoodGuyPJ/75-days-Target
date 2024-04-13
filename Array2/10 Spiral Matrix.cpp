class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int row = matrix.size();
        int col = matrix[0].size();

        /*
        dir 0 left to right
        dir 1 top to down
        dir  2 right to left
        dir 3 down to top
        */
        int dir = 0;
        int left = 0, right = col-1, top =0, down = row-1;
        while (top<=down && left<=right) {
            if (dir == 0) {
                for (int i = left; i <= right; i++) {
                    res.push_back(matrix[top][i]);
                }
                top++;
            }
            if (dir == 1) {
                for (int i = top; i <= down; i++) {
                    res.push_back(matrix[i][right]);
                }
                right--;
            }
            if (dir == 2) {
                for (int i = right; i >= left; i--) {
                    res.push_back(matrix[down][i]);
                }
                down--;
            }
            if (dir == 3) {
                for (int i = down; i >= top; i--) {
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
            dir++;
            if (dir == 4) {
                dir = 0;
            }
        }
        return res;
    }
};