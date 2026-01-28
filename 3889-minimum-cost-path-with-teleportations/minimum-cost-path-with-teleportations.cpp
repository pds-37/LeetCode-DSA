
class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        // 1. Coordinate Compression
        // Map grid values to 0..unique_count-1 for efficient array indexing
        vector<int> unique_vals;
        for(const auto& row : grid) {
            for(int val : row) {
                unique_vals.push_back(val);
            }
        }
        sort(unique_vals.begin(), unique_vals.end());
        unique_vals.erase(unique(unique_vals.begin(), unique_vals.end()), unique_vals.end());
        
        auto getValIdx = [&](int val) {
            return lower_bound(unique_vals.begin(), unique_vals.end(), val) - unique_vals.begin();
        };
        
        int num_unique = unique_vals.size();

        // Precompute indices for every cell to avoid log n lookups inside loops
        vector<vector<int>> cell_val_indices(m, vector<int>(n));
        for(int r = 0; r < m; ++r) {
            for(int c = 0; c < n; ++c) {
                cell_val_indices[r][c] = getValIdx(grid[r][c]);
            }
        }

        // 2. Dijkstra with Layered Batches
        // dist[r][c] stores the minimum cost to reach (r,c) found SO FAR.
        const int INF = 1e9 + 7;
        vector<vector<int>> dist(m, vector<int>(n, INF));
        
        // Priority Queue: {cost, r, c}
        // We do not need to store 'k' in state because we process layers sequentially.
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

        // Initialize Start
        dist[0][0] = 0;
        pq.push({0, 0, 0});

        // Loop K+1 times (0 teleports to K teleports)
        for (int layer = 0; layer <= k; ++layer) {
            
            // --- Phase A: Grid Moves (Standard Dijkstra) ---
            // Expand strictly using Right/Down moves with current teleport count
            while (!pq.empty()) {
                auto [d, r, c] = pq.top();
                pq.pop();

                if (d > dist[r][c]) continue;

                // Move Right
                if (c + 1 < n) {
                    int new_cost = d + grid[r][c+1];
                    if (new_cost < dist[r][c+1]) {
                        dist[r][c+1] = new_cost;
                        pq.push({new_cost, r, c+1});
                    }
                }
                // Move Down
                if (r + 1 < m) {
                    int new_cost = d + grid[r+1][c];
                    if (new_cost < dist[r+1][c]) {
                        dist[r+1][c] = new_cost;
                        pq.push({new_cost, r+1, c});
                    }
                }
            }
            
            // If this was the last layer, we can stop
            if (layer == k) break;

            // --- Phase B: Teleportation (Batch Update) ---
            
            // 1. Identify minimum cost to be at any "Source Value"
            // min_cost_by_val[v] = min cost to reach any cell with value index v
            vector<int> min_cost_by_val(num_unique, INF);
            for(int r = 0; r < m; ++r) {
                for(int c = 0; c < n; ++c) {
                    if (dist[r][c] != INF) {
                        int v_idx = cell_val_indices[r][c];
                        min_cost_by_val[v_idx] = min(min_cost_by_val[v_idx], dist[r][c]);
                    }
                }
            }

            // 2. Suffix Minimum (Propagate Reachability)
            // If we can jump FROM a value V, we can jump TO any value <= V.
            // This is equivalent to: To jump TO value X, we need a source with value >= X.
            // We want the cheapest source with value >= X.
            for (int i = num_unique - 2; i >= 0; --i) {
                min_cost_by_val[i] = min(min_cost_by_val[i], min_cost_by_val[i+1]);
            }

            // 3. Update Distances for Next Layer
            // Teleport cost is 0. So if min_cost_by_val[v] is C, we can reach any cell
            // with value index v with cost C.
            for(int r = 0; r < m; ++r) {
                for(int c = 0; c < n; ++c) {
                    int v_idx = cell_val_indices[r][c];
                    int teleport_cost = min_cost_by_val[v_idx];
                    
                    if (teleport_cost < dist[r][c]) {
                        dist[r][c] = teleport_cost;
                        pq.push({teleport_cost, r, c});
                    }
                }
            }
            // The PQ now contains the starting states for the next layer (k+1)
        }

        return dist[m-1][n-1];
    }
};