#include<bits/stdc++.h>
using namespace std;
class DisjointSet
{
    public:
    vector<int> parent;
    vector<int> size;
    vector<int> rank;
    
    DisjointSet(int n)
    {
        parent.resize(n+1);
        rank.resize(n+1, 0);
        size.resize(n+1);
        
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
            size[i]=1;
        }
    }
    
    int findUParent(int node)
    {
        if(node==parent[node])
        {
            return node;
        }
        
        return parent[node]=findUParent(parent[node]);
    }
    void unionBySize(int u, int v)
    {
        int ulp_u=findUParent(u);
        int ulp_v=findUParent(v);
        
        if(ulp_u==ulp_v)
        {
            return;
        }
        
        if(size[ulp_u]<size[ulp_v])
        {
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else
        {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};
int main(){
    vector<vector<int>> edges = {{1,2},{2,3},{3,4},{1,4},{1,5}};
    DisjointSet ds(5);
    for(auto it : edges){
        int u = it[0];
        int v = it[1];
        if(ds.findUParent(u) == ds.findUParent(v)){
            cout<<u<<" "<<v<<endl;
        } 
        ds.unionBySize(u,v);

    }
    return 0;
}