class Solution {
public:
    void cal(map<char,vector<char>>& mp,int i,string& digits,string temp,vector<string>& ans){
        int n = digits.size();
        if(i == n) {
            ans.push_back(temp);
            return;
        }
        for(auto it : mp[digits[i]]) {
            temp+=it;
            cal(mp,i+1,digits,temp,ans);
            temp.pop_back();
            
        }
    }
    vector<string> letterCombinations(string digits) {
        map<char,vector<char>> mp;
        int n = digits.size();
        mp['2']={'a','b','c'};
        mp['3']={'d','e','f'};
        mp['4']={'g','h','i'};
        mp['5']={'j','k','l'};
        mp['6']={'m','n','o'};
        mp['7']={'p','q','r','s'};
        mp['8']={'t','u','v'};
        mp['9']={'w','x','y','z'};
        int i=0;
        vector<string> ans;
        if(n==0) return ans;
        string temp;
        cal(mp,0,digits,temp,ans);
        return ans;
    }
};