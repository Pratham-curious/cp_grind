class Solution {
public:

/*
1. 



*/
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        priority_queue<int> pq;
        vector<vector<int>> v(n,vector<int>(2,0));
        for(int i=0;i<n;i++){
            v[i] = {nums[i],i};
        }
        sort(v.begin(),v.end());
        int j = 0;
        vector<int> ans(n,0);

        for(int i=0;i<n;i++){
            if(i == 0 || (v[i][0] - v[i-1][0] <= limit)){
               pq.push(v[i][1]);  
            }
            else{
                for(int k = i-1;k>=j;k--){
                    int idx = pq.top();
                    pq.pop();
                    ans[idx] = v[k][0];
                }
                pq.push(v[i][1]);
                j = i;
            } 
        }
        for(int i = n-1;i>=j;i--){
            int idx = pq.top();
            pq.pop();
            ans[idx] = v[i][0];
        }

        return ans;
    }
};