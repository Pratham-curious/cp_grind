class Solution {
public:
    int totalNumbers(vector<int>& digits) {
       vector<int> f(10,0);
       for(auto it : digits) f[it]++;
       int ans = 0;

       for(int i=100;i<=999;i+=2){
        int temp = i;
        vector<int> f1 = f;
        bool make = true;
        while(temp > 0){
            int d = temp%10;
            temp/=10;
            if(f1[d] == 0){
                make = false;
            }
            f1[d]--;
        }
        ans += make;

       }
       return ans;
    }
};