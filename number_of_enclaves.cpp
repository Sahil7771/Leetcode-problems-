#include<bits/stdc++.h>
using namespace std;
int dr[4] = {-1,0,+1,0};
int dc[4] = {0,+1,0,-1};
int n,m;
void dfs(int row,int col,vector<vector<int>>& grid ,vector<vector<int>>& vis){
    vis[row][col] = 1;
    for(int i=0;i<4;i++){
        int nrow = row + dr[i];
        int ncol = col + dc[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
            dfs(nrow,ncol,grid,vis);
        }
    }
}
    int numEnclaves(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i = 0;i < n;i++){
            if(grid[i][0] == 1 && !vis[i][0]){
                dfs(i,0,grid,vis);
            }
            if(grid[i][m-1] == 1 && !vis[i][m-1]){
                dfs(i,m-1,grid,vis);
            }
        }
        for(int j=0;j<m;j++){
            if(grid[0][j] == 1 && !vis[0][j]){
                dfs(0,j,grid,vis);
            }
            if(grid[n-1][j] == 1 && ! vis[n-1][j]){
                dfs(n-1,j,grid,vis);
            }
        }
        int ans =0;
        for(int i=0;i<n;i++){
            for(int j=0 ; j<m;j++){
                if(grid[i][j] == 1 & vis[i][j] == 0) ans++;
            }
        }
        return ans;
    }
int main(){
    vector<vector<int>> grid = {{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}};
    int ans = numEnclaves(grid);
    cout<<ans<<endl;
    return 0;
}