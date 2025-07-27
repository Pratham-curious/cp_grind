class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        int hill = -1;

        for (int i = 1; i < n - 1; i++) {
            if (nums[i] == nums[i - 1] && nums[i] == nums[i + 1])
                continue;
            else if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
                cnt++;
                hill = -1;
            } else if (nums[i] < nums[i - 1] && nums[i] < nums[i + 1]) {
                hill = -1;
                cnt++;
            } else if (nums[i] == nums[i - 1] && nums[i] > nums[i + 1]) {
                if (hill == -1) {
                    hill = 0;
                } else {
                    if (hill == 1) {
                        cnt++;
                        hill = -1;
                    }
                }
            } else if (nums[i] == nums[i - 1] && nums[i] < nums[i + 1]) {
                if (hill == -1) {
                    hill = 1;
                } else {
                    if (hill == 0){
                        cnt++;
                        hill = -1;
                    }
                }
            } else if (nums[i] > nums[i - 1] && nums[i] == nums[i + 1]) {
                if (hill == -1) {
                    hill = 1;
                } 
            } else if (nums[i] < nums[i - 1] && nums[i] == nums[i + 1]) {
                if (hill == -1) {
                    hill = 0;
                } 
            }


        }
        return cnt;
    }
};