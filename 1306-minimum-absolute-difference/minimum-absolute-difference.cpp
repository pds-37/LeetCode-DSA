class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        std::vector<std::vector<int>> result;
        int min_diff = INT_MAX;
        
        // Step 2: Single pass to find min_diff and collect pairs
        for (size_t i = 0; i < arr.size() - 1; ++i) {
            int current_diff = arr[i + 1] - arr[i];
            
            // Case A: Found a smaller difference than before
            if (current_diff < min_diff) {
                min_diff = current_diff;
                result.clear(); // Discard previous pairs, they weren't optimal
                result.push_back({arr[i], arr[i + 1]});
            }
            // Case B: Found a difference equal to the current minimum
            else if (current_diff == min_diff) {
                result.push_back({arr[i], arr[i + 1]});
            }
        }
        return result;
    }
};