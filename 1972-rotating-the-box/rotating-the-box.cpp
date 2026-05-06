class Solution {
public:
    vector<vector<char>> rotate(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<char>> rot(m, vector<char>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                rot[j][n - 1 - i] = matrix[i][j];
            }
        }

        return rot;
    }
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();

        for (int row = 0; row < m; row++) {
            vector<char> arr = boxGrid[row];
            int j = 0;
            int hashC = 0;
            while (j <= n) {
                // either j is not equal to n-1
                if ((j != n && arr[j] != '*')) {
                    if (arr[j] == '#') {
                        hashC++;
                        arr[j] = '.';
                    }
                    j++;
                    continue;
                }
                int k = j - 1;
                while (hashC > 0) {
                    arr[k] = '#';
                    k--;
                    hashC--;
                }
                j++;
            }
            boxGrid[row] = arr;
        }

        // transpose matrix next
        // return transpose(boxGrid);
        return rotate(boxGrid);
        return boxGrid;
    }
};