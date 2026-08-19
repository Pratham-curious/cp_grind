class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        map<int,vector<int>> mp;
        for(auto it : reservedSeats) {
            mp[it[0]].push_back(it[1]);
        }

        int start = 0;
        long ans = 0;
        vector<int> temp(11,0);
        for(auto it : mp){
            ans += (it.first - start-1) * 2;
            start = it.first;

            for(auto val : it.second){
                temp[val] = 1;
            }
            bool f = true,s = true, t = true;
            for(int i=1;i<=10;i++){
                if(temp[i] == 1){
                    if(2 <= i && i <= 5) f = false;
                    if(4 <= i && i <=7) s = false;
                    if(6 <= i && i <= 9) t = false;
                    temp[i] = 0;
                }
            }

            if(f && t) ans += 2;
            else if(f || t || s) ans+=1;
        }
        ans += (n - start)*2;
        return ans;



    }
};