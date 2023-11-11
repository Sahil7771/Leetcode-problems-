#include<bits/stdc++.h>
using namespace std;
int binarySearch(int* arr,int n , int k){
    int s= 0;
    int e = n-1;
    int ans;
    while(s<=e){
        int mid = s+(e-s)/2;
        if(arr[mid] <= k){
            ans = mid;
            s = mid+1;
        }
        else{
            e = mid-1;
        }
    }
    return ans;

}
int main(){
    int currency[9] = {1,2,5,10,20,50,100,200,500};
    vector<int>ans;
    int k = 4830;
    int idx = binarySearch(currency,9,k);
    while(idx>=0){
        int curr = currency[idx];
        if(k >= curr){
            ans.push_back(curr);
            k -= curr;
        }
        else if(k < curr){
            idx--;
        }
        if(k == 0)break;
    }
    for(auto it : ans){
        cout<<it<<" ";
    }
    cout<<endl;
    // cout<<binarySearch(currency,9,k);
    return 0;
}