class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> a(101,0);
        int max = 1;
        int sum  = 0;
        for(int i = 0;i<nums.size();i++){
            a[nums[i]]++;
        }
        for(int  i = 0;i<nums.size();i++){
            // if(a[i]>=max){
            //     if(max == a[i]){
            //         sum += a[i];
            //     }
            //     else{
            //         max = a[i];
            //         sum = max;
            //     }
            // }
            if(a[nums[i]]>=max){
                if(a[nums[i]] == max){
                    sum+=a[nums[i]];
                }
                else{
                    max = a[nums[i]];
                    sum = max;
                }
               
            }
            a[nums[i]]=0;

        }
        return sum;
    }
};