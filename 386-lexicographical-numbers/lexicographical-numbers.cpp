class Solution {
public:
    void cal(vector<int>& ans,int curr, int& n){
        if(curr>n) return;
        if(curr != 0) ans.push_back(curr);
        for(int i=0;i<=9;i++){
            if(curr == 0 && i == 0) continue;
            cal(ans,curr*10+i,n);
        }

    }
    vector<int> lexicalOrder(int n) {
       vector<int> ans;
       cal(ans,0,n); 
       return ans;
    }
};