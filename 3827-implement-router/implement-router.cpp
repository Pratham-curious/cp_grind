class Router {
private : 
 int limit = 0;
 unordered_map<int,vector<int>> add, rm;
set<pair<pair<int,int>,int>> st;
 deque<pair<pair<int,int>,int>> dq;

public:
    Router(int memoryLimit) {
        limit = memoryLimit;
        
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        int s = source, d = destination, t = timestamp;
        if(st.find({{s,d},t}) != st.end()) return false;
        if(dq.size() == limit){
            forwardPacket();
        }
        st.insert({{s,d},t});
        dq.push_back({{s,d},t});
        add[d].push_back(t);
        return true;
    }
    
    vector<int> forwardPacket() {
        vector<int> ans;
        if(st.empty()) return ans;
        auto [travel,time] = dq.front();
        auto [s,d] = travel;
        dq.pop_front();
        st.erase({{s,d},time});
        rm[d].push_back(time);
        return vector<int>{s,d,time};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        int d = destination, start = startTime , end = endTime;
        int f = (upper_bound(add[d].begin(),add[d].end(),end) - add[d].begin()) - (lower_bound(add[d].begin(),add[d].end(),start) - add[d].begin());
        int s = (upper_bound(rm[d].begin(),rm[d].end(),end) - rm[d].begin()) - (lower_bound(rm[d].begin(),rm[d].end(),start) - rm[d].begin());
        return f-s;

    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */