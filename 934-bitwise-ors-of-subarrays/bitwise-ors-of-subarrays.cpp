class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        set<int> ans;
        vector<int> pos(31,-1);
        int n = arr.size();
        for(int i=0;i<n;i++){
            int temp = 0;
            for(int j= 30;j>=0;j--){
                if(arr[i] &(1 << j)) pos[j] = i;
                if(pos[j] != -1) temp += (1<<j);
            }
            ans.insert({arr[i],temp});
            bool ent = false;
            for(int j=30;j>=0;j--){
                if(pos[j] != i && pos[j] != -1){
                    int curr = pos[j];
                    ent = true;
                    int val = 0;
                    for(int k=30;k>=0;k--){
                        if(pos[k] > curr){
                            val += (1<<k);
                        }
                    }
                    ans.insert(val);
                }
            }
            //if(i > 0 && !ent) ans.insert(0);
        }
        int m = ans.size();
        return m;
    }
};