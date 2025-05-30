class Solution {
public:
    vector<int> cal(vector<int>& edges,int node){
        int n = edges.size();
        vector<int> dist(n,INT_MAX);
        dist[node] = 0;
        int curr = node;
        while(curr != -1 ){

            int nex = edges[curr];
            if(nex == -1 || dist[nex] != INT_MAX) break;
            dist[nex] = 1+dist[curr];
            curr = nex;

        }
        return dist;
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<int> dist1 = cal(edges,node1);
        vector<int> dist2 = cal(edges,node2);
        int n = edges.size();
        int ans = INT_MAX;
        int idx = -1;
        for(int i=0;i<n;i++) {
            if (ans > max(dist1[i],dist2[i])){
                ans = max(dist1[i],dist2[i]);
                idx = i;
            }
        }
        return idx;

    }
};