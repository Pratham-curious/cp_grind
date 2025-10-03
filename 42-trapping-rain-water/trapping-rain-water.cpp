class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0, n  = height.size();
        int maxi = 0;
        vector<int> water(n,INT_MAX);
        for(int i=0;i<n;i++){
            maxi = max(maxi,height[i]);
            water[i] = min(water[i],maxi-height[i]);
        }
        maxi = 0;
        for(int i=n-1;i>=0;i--){
            maxi = max(maxi,height[i]);
            water[i] = min(water[i],maxi-height[i]);
        }
        for(int i=0;i<n;i++) ans+=water[i];
        
        return ans;
    }
};