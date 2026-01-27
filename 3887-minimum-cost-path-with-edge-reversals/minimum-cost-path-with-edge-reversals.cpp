

class Solution {
public:
    long long minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> graph(n);
        
        for (const auto& edge : edges) {
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], 2 * edge[2]});
        }
        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<long long> dist(n, LLONG_MAX);
        
        dist[0] = 0;
        pq.push({0, 0});
        
        while (!pq.empty()) {
            long long d = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            
            if (d > dist[u]) continue;
            
            if (u == n - 1) return d;
            
            for (const auto& edge : graph[u]) {
                int v = edge.first;
                int weight = edge.second;
                
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        
        return -1;
    }
};