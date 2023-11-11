#include<bits/stdc++.h>
using namespace std;

vector<string>ans;
void insertingLetters(unordered_map<char, string>& mp){
    mp['2'] = "abc";
    mp['3'] = "def";
    mp['4'] = "ghi";
    mp['5'] = "jkl";
    mp['6'] = "mno";
    mp['7'] = "pqrs";
    mp['8'] = "tuv";
    mp['9'] = "wxyz"; 
}

void helper(int idx ,string digits ,unordered_map<char,string> mp , string temp ){
    // base case
    if(idx == digits.length()){
        ans.push_back(temp);
        return;
    }
    string S = mp[digits[idx]];
    for(int i = 0;i<S.length();i++){
        temp.push_back(S[i]);
        helper(idx+1 , digits,mp,temp);
        temp.pop_back();
    }
}

vector<string> letterCombinations(string digits){
    string temp;
    unordered_map<char, string> mp;
    insertingLetters(mp);
    helper(0,digits,mp,temp);
    return ans;

}
void printVector(vector<string>ans){
    for(int i=0;i<ans.size();i++){
        for(char ch : ans[i]){
            cout<<ch<<"";
        }
        cout<<endl;
    }
}
int main(){
    string digits = "23";
    vector<string> ans = letterCombinations(digits);
    printVector(ans);
    return 0;
}