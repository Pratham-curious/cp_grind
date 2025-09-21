class MovieRentingSystem {
    private :
    map<pair<int,int>,int> mp;
     set<pair<int,pair<int,int>>> all;
     map<int,set<pair<int,int>>> mov;
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        int m = entries.size();
        for(int i=0;i<m;i++){
            int movie = entries[i][1], shop = entries[i][0], price = entries[i][2];
            mp[{shop,movie}] = price;
            mov[movie].insert({price,shop});
        }
    }
    
    vector<int> search(int movie) {
        vector<int> ans;
        vector<int> regprice;
        int m = mov[movie].size();
        for(int  i=0;i<min(5,m); i++){
            int price = (*mov[movie].begin()).first , shop = (*mov[movie].begin()).second;
            mov[movie].erase(*mov[movie].begin());
            ans.push_back(shop);
            regprice.push_back(price);
        }
        m = ans.size();
        for(int i =0;i<m;i++){
            mov[movie].insert({regprice[i],ans[i]});
        }
        return ans;
    }
    
    void rent(int shop, int movie) {
        int price = mp[{shop,movie}];
        mov[movie].erase({price,shop});
        all.insert({price,{shop,movie}});
    }
    
    void drop(int shop, int movie) {
        int price = mp[{shop,movie}];
        all.erase({price,{shop,movie}});
        mov[movie].insert({price,shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> ans;
        for(int i=0;i<5 && !all.empty() ;i++){
            auto [price,it] = *all.begin();
            all.erase(all.begin());
            auto [shop,movie] = it;
            ans.push_back(vector<int> {shop,movie});
        }
        int m = ans.size();
        for(int i=0;i<m;i++){
            int price = mp[{ans[i][0],ans[i][1]}];
            all.insert({price,{ans[i][0],ans[i][1]}});
        }
        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */