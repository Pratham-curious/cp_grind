class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n = trainers.size(),m = players.size();
        int i=0,j = 0;
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        while(i<m && j<n){
            if(players[i] <= trainers[j]){ i++;}
            j++;
        }
        return i;
    }
};