
using namespace std;

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        // Simulate Doubly Linked List using arrays
        // val: stores the current value of the node
        // prev, next: store the indices of neighbors
        vector<long long> val(n);
        vector<int> prev(n), next(n);
        vector<bool> active(n, true); // To track if a node is still part of the array

        for (int i = 0; i < n; ++i) {
            val[i] = nums[i];
            prev[i] = i - 1;
            next[i] = i + 1;
        }
        next[n - 1] = -1; // End of list marker

        // Min-Heap to store pairs: {sum, left_index, right_index}
        // effectively sorting by sum (asc), then left_index (asc)
        using PairInfo = tuple<long long, int, int>;
        priority_queue<PairInfo, vector<PairInfo>, greater<PairInfo>> pq;

        int inversion_count = 0;

        // Initialize heap and inversion count
        for (int i = 0; i < n - 1; ++i) {
            pq.push({val[i] + val[i + 1], i, i + 1});
            if (val[i] > val[i + 1]) {
                inversion_count++;
            }
        }

        int operations = 0;

        while (inversion_count > 0) {
            // This case shouldn't technically be reached if logic is correct 
            // and inversion_count > 0, but good for safety.
            if (pq.empty()) break; 

            auto [s, u, v] = pq.top();
            pq.pop();

            // Validation (Lazy Deletion Check):
            // 1. Are both nodes active?
            // 2. Are they still immediate neighbors?
            // 3. Is the sum current? (val[u] + val[v] == s)
            if (!active[u] || !active[v] || next[u] != v || val[u] + val[v] != s) {
                continue;
            }

            // Perform Merge Operation
            operations++;

            // Step 1: Remove old inversion contributions involving u and v
            if (prev[u] != -1 && val[prev[u]] > val[u]) inversion_count--; // Left neighbor > u
            if (val[u] > val[v]) inversion_count--;                        // u > v
            if (next[v] != -1 && val[v] > val[next[v]]) inversion_count--; // v > Right neighbor

            // Step 2: Merge v into u
            val[u] += val[v];      // u absorbs v
            active[v] = false;     // v is removed
            next[u] = next[v];     // u connects to v's right neighbor
            if (next[v] != -1) {
                prev[next[v]] = u; // Right neighbor connects back to u
            }

            // Step 3: Add new inversion contributions
            if (prev[u] != -1 && val[prev[u]] > val[u]) inversion_count++;
            if (next[u] != -1 && val[u] > val[next[u]]) inversion_count++;

            // Step 4: Push new adjacent pairs to heap
            // New pair with left neighbor
            if (prev[u] != -1) {
                pq.push({val[prev[u]] + val[u], prev[u], u});
            }
            // New pair with right neighbor
            if (next[u] != -1) {
                pq.push({val[u] + val[next[u]], u, next[u]});
            }
        }

        return operations;
    }
};

