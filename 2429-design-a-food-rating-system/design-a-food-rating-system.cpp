class FoodRatings {
private:

    unordered_map<string,pair<string,int>> fd;
    unordered_map<string,multiset<pair<int,string>>> cu;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i=0;i<n;i++){
            fd[foods[i]] = {cuisines[i],ratings[i]};
            cu[cuisines[i]].insert({ratings[i],foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        int old = fd[food].second;
        string cuisine = fd[food].first;
        fd[food].second = newRating;
        cu[cuisine].erase(cu[cuisine].find({old,food}));
        cu[cuisine].insert({newRating,food});
    }
    
    string highestRated(string cuisine) {
        int high = (*cu[cuisine].rbegin()).first;
        auto it = cu[cuisine].lower_bound({high,"a"});
        return (*it).second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */