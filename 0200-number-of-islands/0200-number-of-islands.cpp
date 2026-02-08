class Solution {
private:
    void dfs(vector<vector<char>>&grid, int r, int c, int n, int m){
        if(r<0||r>=n||c<0||c>=m||grid[r][c]!='1')return;

        grid[r][c]='0';

        dfs(grid, r+1, c, n, m);
        dfs(grid, r-1, c, n, m);
        dfs(grid, r, c+1, n, m);
        dfs(grid, r, c-1, n, m);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        if(n==0) return 0;

        int m=grid[0].size();
        int islands=0;

        for(int r=0; r<n; r++){
            for(int c=0; c<m; c++){
                if(grid[r][c]=='1'){
                    islands++;
                    dfs(grid, r, c, n ,m);
                }
            }
        }

        return islands;
        
    }

};