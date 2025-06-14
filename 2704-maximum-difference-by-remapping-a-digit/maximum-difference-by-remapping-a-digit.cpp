class Solution {
public:
    int minMaxDifference(int num) {
        int maxi = 9;
        int temp = num;
        int last = 0;
        while(temp>0){
            maxi = temp%10 == 9 ? maxi : temp%10;
            last = temp%10;
            temp/=10;
        }
        int mul = 1;
        int ans1 = num,ans2 = num;
        while(num>0){
            if(num%10 == maxi){
                ans1 += mul*(9-maxi);
            }
            if(num%10 == last){
                ans2 -= mul*(last);
            }
            mul*=10;
            num/=10;
        }
        return ans1-ans2;

    }
};