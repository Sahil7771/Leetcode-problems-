
#include<bits/stdc++.h>
#define N 105
using namespace std;
typedef pair<int,pair<int,int>> ppi;
class compare{
    public:
    bool operator()(ppi below , ppi above){
        return below.first > above.first;
    }
    
};
    // element , col , arrayIndex
    
    vector<int> mergeKArrays(vector<vector<int>> arr, int K){
        priority_queue<ppi,vector<ppi>,compare>pq;
        for(int i=0;i < K;i++){
            pq.push({arr[i][0] ,{ i, 0}});
        }
        vector<int>ans;
        while(!pq.empty()){
            ppi temp = pq.top();
            pq.pop();
            ans.push_back(temp.first);
            int row = temp.second.first;
            int col = temp.second.second;
            if(col+1 < arr[row].size()){
                pq.push({arr[row][col+1] ,{row,col+1}});
            }

        }
        return ans;
    }
int main()
{
	    int k;
	    vector<vector<int>> arr = {{1,2,3},{4,5,6},{7,8,9}};
	    k=3;
    	vector<int>ans = mergeKArrays(arr, k);
    	for(auto &it :ans){
            cout<<it<<" ";
        }
        cout<<endl;
	return 0;
}






// } Driver Code Ends