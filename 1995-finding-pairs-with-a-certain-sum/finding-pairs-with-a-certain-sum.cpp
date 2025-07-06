class FindSumPairs {
private:
    unordered_map<int,int> mp1,mp2;
    vector<int> v1,v2;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        v2 = nums2;
        v1 = nums1;
        for(auto it : v1) mp1[it]++;
        for(auto it : v2) mp2[it]++;
    }
    
    void add(int index, int val) {
        mp2[v2[index]]--;
        mp2[val+v2[index]]++;
        v2[index]+=val;
    }
    
    int count(int tot) {
        int ans = 0;
        for(auto it : mp1){
            int val = it.first, freq = it.second;
            if(mp2.find(tot-val)!=mp2.end()) ans+= freq*mp2[tot-val];
        }
        return ans;
        
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */