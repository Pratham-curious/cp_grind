class TaskManager {
private:
    unordered_map<int,pair<int,int>> mp;
    set<pair<int,int>> st;
public:
    TaskManager(vector<vector<int>>& tasks) {
        int n = tasks.size();
        for(int i=0;i<n;i++){
            int a = tasks[i][0], b = tasks[i][1], c = tasks[i][2];
            st.insert({c,b});
            mp[b] = {c,a};
        }
    }
    
    void add(int userId, int taskId, int priority) {
        st.insert({priority,taskId});
        mp[taskId] = {priority,userId};
        
    }
    
    void edit(int taskId, int newPriority) {
        int old = mp[taskId].first;
        mp[taskId].first = newPriority;
        st.erase({old,taskId});
        st.insert({newPriority,taskId});
    }
    
    void rmv(int taskId) {
        int priority = mp[taskId].first;
        st.erase({priority,taskId});
        mp.erase(taskId);
    }
    
    int execTop() {
        if(st.empty()) return -1;
        auto [priority,task] = *st.rbegin();
        st.erase(*st.rbegin());
        int user = mp[task].second;
        rmv(task);
        return user;
        
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */