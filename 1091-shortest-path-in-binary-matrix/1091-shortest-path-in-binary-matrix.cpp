#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        if (n == 0) return -1;

        // 시작/끝이 막혀있으면 불가능
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        // n==1 이면 시작==끝
        if (n == 1) return 1;

        // 8방향
        int dr[8] = {1, 1, 1, 0, 0, -1, -1, -1};
        int dc[8] = {1, 0, -1, 1, -1, 1, 0, -1};

        queue<pair<int,int>> q;
        q.push({0, 0});

        // 방문 처리: 지나간 칸을 1로 바꿔서 다시 못 오게
        grid[0][0] = 1;

        int dist = 1;

        while (!q.empty()) {
            int sz = (int)q.size();
            while (sz--) {
                auto [r, c] = q.front();
                q.pop();

                // 인접 8칸 탐색
                for (int k = 0; k < 8; k++) {
                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
                    if (grid[nr][nc] == 1) continue; // 벽이거나 이미 방문

                    // 도착
                    if (nr == n - 1 && nc == n - 1) return dist + 1;

                    grid[nr][nc] = 1; // 방문 처리
                    q.push({nr, nc});
                }
            }
            dist++;
        }

        return -1;
    }
};
