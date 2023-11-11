#include<bits/stdc++.h>
using namespace std;
struct compare{
    bool operator()( pair<int,int> a, pair<int,int> b ){
        return a.second > b.second;
    }
};
class Graph{
    public:
    int N;
    unordered_map<int,vector<pair<int,int>>>adj;
    priority_queue<pair<int,int>,vector<pair<int,int>>,compare>q;

    Graph(int n,vector<vector<int>>edges){
        N=n;
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v,wt});
        }
    }
    void addEdge(vector<int>edge){
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        adj[u].push_back({v,wt});
    }
    int shortestPath(int node1, int node2) {

        // {dist , node}
        q.push({node1 , 0});
        vector<int>dist(N,INT_MAX);
        dist[node1] = 0;

        while(!q.empty()){

            int node = q.top().first;
            int distToReach = q.top().second;
            q.pop();

            for(auto& it : adj[node]){
                int adjNode = it.first;
                int adjDist = it.second;
                if(distToReach + adjDist < dist[adjNode]){
                    dist[adjNode] = distToReach + adjDist;
                    q.push({ adjNode, distToReach + adjDist});
                }
            }
        }
        return dist[node2] == INT_MAX ?  -1 :   dist[node2];
    }

};
int main(){
    vector<vector<int>>edges = {{0, 2, 5}, {0, 1, 2}, {1, 2, 1}, {3, 0, 3}};
    Graph* graph1 = new Graph(4,edges);
    int ans = graph1->shortestPath(3,2);
    int ans2 = graph1->shortestPath(0,3);
    graph1->addEdge({1,3,4});
    int ans3= graph1->shortestPath(0,3);
    cout<<ans<<" "<<ans2<<" "<<ans3<<endl;
    cout<<"done"<<endl;
    return 0;
}