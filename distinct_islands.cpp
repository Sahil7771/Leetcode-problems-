#include<bits/stdc++.h>
using namespace std;
int dr[4] = {-1,0,+1,0};
int dc[4] = {0,+1,0,-1};
int n, m;
void dfs(int row,int col,vector<vector<int>>& arr , vector<pair<int,int>>& temp,vector<vector<int>>& vis,int row0,int col0){
    vis[row][col] = 1;
    temp.push_back({row-row0,col-col0});
    for(int i=0;i<4;i++){
        int nrow = row+dr[i];
        int ncol = col+dc[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && arr[nrow][ncol] == 1) {
            dfs(nrow,ncol,arr,temp,vis,row0,col0);
        }
    }
}
int distinctIslands(vector<vector<int>>& arr )
{
    set<vector<pair<int,int>>> distinct;
    vector<vector<int>>vis(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] == 1 && !vis[i][j]){
                vector<pair<int,int>>temp;
                dfs(i,j,arr,temp,vis,i,j);
                distinct.insert(temp);
            }
        }
    }
    return distinct.size();

}
int main(){
    vector<vector<int>>earth ={{1 ,0 ,1 ,1 ,0,1},{1 ,1, 0, 0, 1,1},{1, 0 ,1 ,1 ,0 , 1},{0,0, 0, 0, 0,0} , {1,1,0,0,1,1},{0,1,0,0,0,1}};
    n = 6,m = 6;
    int ans = distinctIslands(earth);
    cout<<ans<<endl;
    return 0;

}