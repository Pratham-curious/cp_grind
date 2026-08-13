class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int curr = 0, n = s.size();
        int k = queryIndices.size();

        vector<int> ans(k,1);

        if(n == 1) return ans;

        set<pair<int,int>> s1,s2;
        for(int i=0;i<n-1;i++){
            curr++;
            if(s[i] != s[i+1]){
                s1.insert({i,curr});
                s2.insert({curr,i});
                curr = 0;
            }
        }
        s1.insert({n-1,curr+1});
        s2.insert({curr+1,n-1});

        for(int i=0;i<k;i++){
            int idx = queryIndices[i];
            char c = queryCharacters[i];

            if(c == s[idx]) {
                ans[i] = (*s2.rbegin()).first;
                continue;
            }

            if(idx == 0){ 
                if(s[0] == s[1]){
                    auto up = s1.upper_bound({0,0});
                    int prevCount = (*up).second , prevIdx = (*up).first;
                    s1.erase(up);
                    s2.erase({prevCount,prevIdx});
                    s1.insert({prevIdx,prevCount-1});
                    s2.insert({prevCount-1,prevIdx});

                    s1.insert({0,1});
                    s2.insert({1,0});

                }else if(c == s[1]){
                    auto up = s1.upper_bound({1,0});
                    int prevCount = (*up).second , prevIdx = (*up).first;
                    s1.erase(up);
                    s2.erase({prevCount,prevIdx});
                    s1.insert({prevIdx,prevCount+1});
                    s2.insert({prevCount+1,prevIdx});

                    s1.erase({0,1});
                    s2.erase({1,0});
                }
            }
            else if(idx == n-1){
                if(s[n-1] == s[n-2]){
                    auto up = s1.upper_bound({n-1,0});
                    int prevCount = (*up).second , prevIdx = (*up).first;
                    s1.erase(up);
                    s2.erase({prevCount,prevIdx});
                    s1.insert({prevIdx-1,prevCount-1});
                    s2.insert({prevCount-1,prevIdx-1});

                    s1.insert({n-1,1});
                    s2.insert({1,n-1});
                }
                else if(s[n-2] == c){
                    auto up = s1.upper_bound({n-2,0});
                    int prevCount = (*up).second , prevIdx = (*up).first;
                    s1.erase(up);
                    s2.erase({prevCount,prevIdx});
                    s1.insert({prevIdx+1,prevCount+1});
                    s2.insert({prevCount+1,prevIdx+1});

                    s1.erase({n-1,1});
                    s2.erase({1,n-1});
                }

            }
            else{
                if(s[idx-1] == s[idx+1]){
                    if(s[idx] == s[idx+1]){
                        auto up = s1.upper_bound({idx,0});
                        int prevCount = (*up).second , prevIdx = (*up).first;
                        s1.erase(up);
                        s2.erase({prevCount,prevIdx});
                        s1.insert({prevIdx,prevIdx-idx});
                        s1.insert({idx-1,prevCount-prevIdx+idx-1});
                        s2.insert({prevIdx-idx,prevIdx});
                        s2.insert({prevCount-prevIdx+idx-1,idx-1});

                        s1.insert({idx,1});
                        s2.insert({1,idx});
                    }
                    else if(c == s[idx+1]){
                        auto up1 = s1.upper_bound({idx+1,0});
                        auto up2 = s1.upper_bound({idx-1,0});
                        int prevCount1 = (*up1).second , prevIdx1 = (*up1).first;
                        int prevCount2 = (*up2).second , prevIdx2 = (*up2).first;

                        s1.erase(up1);
                        s1.erase(up2);
                        s2.erase({prevCount1,prevIdx1});
                        s2.erase({prevCount2,prevIdx2});

                        s1.insert({prevIdx1,prevCount1 + prevCount2 + 1});
                        s2.insert({prevCount1 + prevCount2 + 1,prevIdx1});

                        s1.erase({idx,1});
                        s2.erase({1,idx});
                    }
                }
                else if(s[idx] == s[idx+1]){
                    auto up = s1.upper_bound({idx,0});
                    int prevCount = (*up).second , prevIdx = (*up).first;
                  //  cout<<"idx : "<<prevIdx<<" , count : "<<prevCount<<endl;
                    s1.erase(up);
                    s2.erase({prevCount,prevIdx});
                    s1.insert({prevIdx,prevCount-1});
                    s2.insert({prevCount-1,prevIdx});

                    if(c != s[idx-1]){
                    
                        s1.insert({idx,1});
                        s2.insert({1,idx});
                    }
                    else{
                       // cout<<"entered : "<<i<<endl;
                        auto up1 = s1.upper_bound({idx-1,0});
                        int prevCount1 = (*up1).second , prevIdx1 = (*up1).first;
                    //    cout<<"idx1 : "<<prevIdx1<<" , count1 : "<<prevCount1<<endl;
                        s1.erase(up1);
                        s2.erase({prevCount1,prevIdx1});
                        s1.insert({prevIdx1+1,prevCount1+1});
                        s2.insert({prevCount1+1,prevIdx1+1});

                    }
                }
                else if(s[idx] == s[idx-1]){
                    auto up = s1.upper_bound({idx,0});
                    int prevCount = (*up).second , prevIdx = (*up).first;
                    s1.erase(up);
                    s2.erase({prevCount,prevIdx});
                    s1.insert({prevIdx-1,prevCount-1});
                    s2.insert({prevCount-1,prevIdx-1});

                    if(c != s[idx+1]){
                    
                        s1.insert({idx,1});
                        s2.insert({1,idx});
                    }
                    else{
                        auto up1 = s1.upper_bound({idx+1,0});
                        int prevCount1 = (*up1).second , prevIdx1 = (*up1).first;
                        s1.erase(up1);
                        s2.erase({prevCount1,prevIdx1});
                        s1.insert({prevIdx1,prevCount1+1});
                        s2.insert({prevCount1+1,prevIdx1});

                    }
                }
                else{
                    if(c == s[idx+1]){
                        auto up1 = s1.upper_bound({idx+1,0});
                        int prevCount1 = (*up1).second , prevIdx1 = (*up1).first;
                        s1.erase(up1);
                        s2.erase({prevCount1,prevIdx1});
                        s1.insert({prevIdx1,prevCount1+1});
                        s2.insert({prevCount1+1,prevIdx1});

                        s1.erase({idx,1});
                        s2.erase({1,idx});
                    }
                    else if(c == s[idx-1]){
                        auto up1 = s1.upper_bound({idx-1,0});
                        int prevCount1 = (*up1).second , prevIdx1 = (*up1).first;
                        s1.erase(up1);
                        s2.erase({prevCount1,prevIdx1});
                        s1.insert({prevIdx1+1,prevCount1+1});
                        s2.insert({prevCount1+1,prevIdx1+1});

                        s1.erase({idx,1});
                        s2.erase({1,idx});
                    }
                }
            }
            ans[i] = (*s2.rbegin()).first;
            s[idx] = c;
        }

        return ans;


    }
};