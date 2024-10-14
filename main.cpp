#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;

        int N = grid.size(), M = grid[0].size();
        int closedIslandCount = 0;

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (grid[i][j] == 1) {
                    if (isClosedIsland(grid, i, j, N, M)) {
                        closedIslandCount++;
                    }
                }
            }
        }

        return closedIslandCount;
    }

private:
    bool isClosedIsland(vector<vector<int>>& grid, int x, int y, int N, int M) {
        if (x < 0 || x >= N || y < 0 || y >= M) {
            return false;
        }
        if (grid[x][y] == 0) {
            return true;
        }

        grid[x][y] = 0;

        bool up = isClosedIsland(grid, x - 1, y, N, M);
        bool down = isClosedIsland(grid, x + 1, y, N, M);
        bool left = isClosedIsland(grid, x, y - 1, N, M);
        bool right = isClosedIsland(grid, x, y + 1, N, M);

        return up && down && left && right;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> mat1 = {
        {0, 0, 0, 0, 0, 0, 0, 1},
        {0, 1, 1, 1, 1, 0, 0, 1},
        {0, 1, 0, 1, 0, 0, 0, 1},
        {0, 1, 1, 1, 1, 0, 1, 0},
        {1, 0, 0, 0, 0, 1, 0, 1}
    };
    cout << sol.closedIsland(mat1) << endl;

    vector<vector<int>> mat2 = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };
    cout << sol.closedIsland(mat2) << endl;

    return 0;
}
