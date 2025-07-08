class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges,
                vector<int>& passingFees) {
        int n = passingFees.size();
        int source = 0, destination = n - 1;
        vector<vector<pair<int, int>>> adjacencyList(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1], time = edges[i][2];
            adjacencyList[u].push_back({v, time});
            adjacencyList[v].push_back({u, time});
        }
        // to save the cost i will make a distance array;
        vector<int> cost(n, INT_MAX);
        vector<int> Time(n,maxTime+1);
        cost[source] = passingFees[source];

        // queue -> {timeTaken till that node, node, cost Till now }
        using T = tuple<int,int,int>;
        priority_queue<T,vector<T>,greater<T>> qu;
        qu.push({0,source, cost[source]});
int m = INT_MAX;
        while(!qu.empty()){
            auto [a,b,c] = qu.top(); // a-> time taken till that node, that
                                         // particular node, cost till now
            qu.pop();

            if (a > maxTime)
                continue;
            
            for (auto [node, time] : adjacencyList[b]) {
                if (a + time <= maxTime && (c + passingFees[node] < cost[node] || a+time < Time[node])) {
                    
                        Time[node] = a+time;
                        cost[node] = c+passingFees[node];
                        if(node == destination){
                            m = min(cost[destination],m);
                        }
                    
                    qu.push({a+time,node,c+passingFees[node]});
                
                }
            }
        }
            if (m == INT_MAX)
                return -1;
            return m;
                
        
    }
};