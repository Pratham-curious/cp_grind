class Solution {
public:
    int maximum69Number (int num) {
       string temp = to_string(num);
       int n = temp.size();
       for(int i=0;i<n;i++){
        if(temp[i] == '6'){
            temp[i] = '9';
            break;
        }
       }
       int ans = stoi(temp);
       return ans;
    }
};