class Solution {
public:
/*
observations :

1.An array wtih n numbers, we have to find the largest subarray ( a continguous part) with non zero xor 

2.Xor : 0 ^ 0 = 0
    1^1 = 0
    0^1 = 1
    1^0 = 1

3.So In a subarray we need to make sure that atleast at one bit the number of 1s at that bit is odd




*/
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int curr = 0,idx = -1;
        for(auto it : nums) {
            if(it != 0 ) idx = it;
            curr ^= it;
        }

        if(curr != 0) return n;
        if(idx == -1) return 0;
        return n-1;
    }
};