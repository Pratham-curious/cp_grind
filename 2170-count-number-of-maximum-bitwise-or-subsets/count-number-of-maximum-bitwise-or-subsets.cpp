class Solution {
public:
    void cal(int i,vector<int>& nums,int& ans, int& cnt, int curr){
        int n = nums.size();
        if(i == n){
            if(curr == ans) cnt++;
            else if( curr > ans){
                ans = curr;
                cnt = 1;
            }
            return;
        }
        cal(i+1,nums,ans,cnt,(curr | nums[i]));
        cal(i+1,nums,ans,cnt,curr);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int ans = 0, cnt = 0,curr = 0;
        cal(0,nums,ans,cnt,curr);
        return cnt;
    }
};