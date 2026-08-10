class Solution {
public:

    pair<int,int> check(int& mid,string& s,map<char,int>& f,int tot){
        int n = s.size();
     //   cout<<"for m : "<<mid<<endl;

        map<char,int> temp;
        for(auto it : f) temp[it.first] = it.second;

        for(int i=0;i<mid;i++){
            if(f[s[i]] > 0){
                if(temp[s[i]] > 0) tot--;
                temp[s[i]]--;
            }
        }
    //    cout<<" current (l,r) : "<<0<<", "<<mid-1<<" , with tot : "<<tot<<endl;
        if(tot == 0) return {0,mid-1};

        for(int i=mid,left = 0; i<n && left < n; i++,left++){
            if(f[s[i]]> 0) {
                if(temp[s[i]] > 0) tot--;
                temp[s[i]]--;
            }
            if(f[s[left]] > 0){
               // cout<<temp[s[left]]<<endl;

                if(temp[s[left]] >=  0) tot++;
                temp[s[left]]++;
            }
          //  cout<<"current (l,r) : "<<left+1<<", "<<i<<" , with tot : "<<tot<<endl;
            if(tot == 0) return {left+1,i};
        }
        return {-1,-1};

    }
    string minWindow(string s, string t) {
        map<char,int> f;

        int n = s.size(), m = t.size();
        for(auto it : t) f[it]++;

        int tot = 0;
        for(auto it : f ) tot += it.second;
       

        int l = -1,r =-1;

        int low = 1,high = n;
        while(low <= high){
            int mid = low + (high-low)/2;
            auto it = check(mid,s,f,tot);
            if(it.first != -1) {
                l = it.first ;
                r = it.second;
                high = mid-1;
            }
            else low = mid+1;
        }

        if(low > n) return "";
        return s.substr(l,r-l+1);
        
    }
};