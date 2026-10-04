class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size(), extra = 0;
        int curr = 0;

        for(int i=0;i<n;i++) {
            if(s[i] == '(') curr++;
            else if(s[i] =='*') extra++;
            else{
                curr--;
                if(curr < 0 ){
                    if(extra == 0) {
                        cout<<"Forward : "<<i<<endl;
                        return false;
                    }
                    else{
                        extra--;
                        curr = 0;
                    } 
                }
            }
        }
        if(curr == 0) return true;
        curr = 0, extra = 0;
        for(int i=n-1;i>=0;i--){
            if(s[i] == ')') curr++;
            else if(s[i] =='*') extra++;
            else{
                curr--;
                if(curr < 0 ){
                    if(extra == 0) {
                        cout<<"Reverse : "<<i<<endl;
                        return false;
                    }
                    else{
                        extra--;
                        curr = 0;
                    } 
                }
            }
        }
        return true;

    }
};