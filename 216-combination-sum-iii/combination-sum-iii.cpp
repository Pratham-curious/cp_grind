class Solution {
public:
    void cal(int n, int& k,vector<int>& temp,vector<vector<int>>& ans,int curr){
        if(curr > 9 || curr > n){
            if(n==0 && temp.size()==k) ans.push_back(temp);
            return;
        }
        if(n>=curr){
            temp.push_back(curr);
            cal(n-curr,k,temp,ans,curr+1);
            temp.pop_back();
        }
        cal(n,k,temp,ans,curr+1);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        cal(n,k,temp,ans,1);
        return ans;
    }
};