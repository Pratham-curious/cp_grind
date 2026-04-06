class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int,int>> s1;
        for(auto it : obstacles){
            int x = it[0], y = it[1];
            s1.insert({x,y});
        }
        int idx = 0;
        int ans = 0;
        vector<int> pt = {0,0};
        for(auto it : commands){
            if(it == -1){
                idx = (idx+1)%4;
            }
            else if(it == -2){
                idx = ((idx-1)%4 + 4)%4;
            }
            else{
                int x = pt[0],y = pt[1];
                if(idx == 0 || idx == 2){
                    int mul = 1;
                    if(idx == 2) mul = -1;
                    for(int k = 1;k<=it;k++){
                        if(s1.find({x,y+mul*k}) != s1.end()){
                            break;
                        }
                        pt[1] = pt[1]+mul;
                    }
                }
                else{
                    int mul = 1;
                    if(idx == 3) mul = -1;
                    for(int k = 1;k<=it;k++){
                        if(s1.find({x+mul*k,y}) != s1.end()){
                            break;
                        }
                        pt[0] = pt[0]+mul;
                    }
                }
              //  cout<<pt[0]<<" "<<pt[1]<<endl;
                ans = max(ans,pt[0]*pt[0] + pt[1]*pt[1]);
            }
        }
        return ans;
    }
};