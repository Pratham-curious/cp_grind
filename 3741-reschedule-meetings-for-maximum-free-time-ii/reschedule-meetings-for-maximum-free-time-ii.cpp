class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        multiset<int> st;
        int maxi = startTime[0], n  = startTime.size();
        for(int i=1;i<n;i++){
            int duration = startTime[i]-endTime[i-1];
            st.insert(duration);
            maxi = max(maxi,duration);
        }
        st.insert(eventTime - endTime[n-1])++;
        st.insert(startTime[0])++;
        maxi = max(maxi, eventTime - endTime[n-1]);
        for(int i=0;i<n;i++){
            int low = 0, high = eventTime;
            if(i >0) low = endTime[i-1];
            if(i<n-1) high = startTime[i+1];
            st.erase(st.find(high - endTime[i]));
            st.erase(st.find(startTime[i]-low));
            int duration = endTime[i]-startTime[i];
            auto it = st.lower_bound(duration);

            if(it != st.end()){
                maxi = max(maxi,high-low);
            }

            maxi = max(maxi,high-low-duration);
            st.insert(high-endTime[i])++;
            st.insert(startTime[i]-low)++;
        }
        return maxi;
    }
};