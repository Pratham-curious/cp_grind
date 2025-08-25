class Solution {
public:
    static bool comp(pair<int,pair<int,int>>& a, pair<int,pair<int,int>>& b){
        if(a.first == b.first){
            if(a.first%2 == 0){
                return a.second.first > b.second.first;
            }
            else return a.second.first<b.second.first;
        }
        return a.first<b.first;
    }
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size(), m= mat[0].size();
        vector<pair<int,pair<int,int>>> temp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                temp.push_back({i+j,{i,j}});
            }
        }
        sort(temp.begin(),temp.end(),comp);
        vector<int> ans;
        for(int i=0;i<m*n;i++){
            int x = temp[i].second.first , y = temp[i].second.second;
            ans.push_back(mat[x][y]);
        }
        return ans;
    }
};