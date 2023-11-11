#include<bits/stdc++.h>
using namespace std;
int n;
unordered_set<int>st;
vector<vector<int>>ans;
void helper(vector<int>& temp,vector<int>& nums){
    if(temp.size() == n){
        ans.push_back(temp);
        return;
    }
    for(int i=0;i<n;i++){
        if(st.find(nums[i]) == st.end()){
            st.insert(nums[i]);
            temp.push_back(nums[i]);
            helper(temp,nums);
            st.erase(nums[i]);
            temp.pop_back();
        }
    }
}
vector<vector<int>> permute(vector<int>& nums) {
    n = nums.size();
    vector<int>temp;
    helper(temp,nums);
    return ans;

}
void printarray(){
    for(int i = 0; i < ans.size();i++){
        for(int j = 0; j < ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
}
int main(){
    vector<int> nums ={1,2,3,5};
    vector<vector<int>> ans = permute(nums);
    printarray();
    return 0;
}