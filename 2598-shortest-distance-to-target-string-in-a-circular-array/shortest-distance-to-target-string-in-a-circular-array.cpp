class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int val = n;
        for(int i=0;i<n;i++){
            int idx1 = (i+startIndex)%n;
            int idx2 = ((startIndex-i)%n + n )%n;
            if(words[idx1] == target){
                val = min(i,val);
                break;
            }
            if(words[idx2] == target){
                val = min(i,val);
            }
        }
        if(val == n)return -1;
        return val;
    }
};