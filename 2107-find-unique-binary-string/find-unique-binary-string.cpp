class Solution {
public:
    bool make(vector<string>& nums,string temp,int& n,string& ans){
        if(temp.size()==n){
            bool found = false;
            for(int i=0;i<n;i++){
                if(temp==nums[i]){
                    found = true;
                    break;
                }
            }
            if(!found) {
                ans = temp;
                return true;
            }
            return false;
        }
        return make(nums,temp+'0',n,ans) ||  make(nums,temp+'1',n,ans);
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string temp = "";
        string ans = "";
        if(make(nums,temp,n,ans)) return ans;
        return ans;
    }
};