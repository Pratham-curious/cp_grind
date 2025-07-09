class Solution {
public:
    bool canTransform(string start, string result) {
        int i = 0 ,j = 0;
        int n = start.size();
        while(i<n && j<n){
            if(start[i] == 'X') i++;
            else if(result[j] == 'X') j++;
            else{
                if(start[i] != result[j]) return false;
                else if(start[i] == 'R' && j < i) return false;
                else if(start[i] == 'L' && j > i) return false;
                i++,j++;
            }
        }
        while(j < n){
            if(result[j] != 'X') return false;
            j++;
        }
        while(i < n){
            if(start[i] != 'X') return false;
            i++;
        }
        return true;
    }
};