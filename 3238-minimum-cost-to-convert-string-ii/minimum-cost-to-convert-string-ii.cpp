
class Solution {
    // 1. Define the TrieNode struct so the compiler recognizes the type
    struct TrieNode {
        TrieNode* children[26];
        int id = -1;
        TrieNode() {
            for (int i = 0; i < 26; ++i) children[i] = nullptr;
        }
    };

    void insert(TrieNode* root, const string& s, int id) {
        TrieNode* curr = root;
        for (char c : s) {
            if (!curr->children[c - 'a']) curr->children[c - 'a'] = new TrieNode();
            curr = curr->children[c - 'a'];
        }
        curr->id = id;
    }

public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        // Use constexpr for constants to avoid "undefined symbol" linker errors
        static constexpr long long INF = 1e16;
        int n = source.length();
        
        // 2. Map unique strings to IDs for the graph matrix
        unordered_set<string> distinctStrs;
        for (const string& s : original) distinctStrs.insert(s);
        for (const string& s : changed) distinctStrs.insert(s);

        unordered_map<string, int> strToId;
        int m = 0;
        for (const string& s : distinctStrs) strToId[s] = m++;

        // 3. Floyd-Warshall for shortest conversion paths
        vector<vector<long long>> dist(m, vector<long long>(m, INF));
        for (int i = 0; i < m; ++i) dist[i][i] = 0;

        for (int i = 0; i < original.size(); ++i) {
            int u = strToId[original[i]];
            int v = strToId[changed[i]];
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        for (int k = 0; k < m; ++k) {
            for (int i = 0; i < m; ++i) {
                if (dist[i][k] == INF) continue;
                for (int j = 0; j < m; ++j) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        // 4. Build the Trie
        TrieNode* root = new TrieNode();
        for (auto& [str, id] : strToId) insert(root, str, id);

        // 5. Dynamic Programming
        vector<long long> dp(n + 1, INF);
        dp[0] = 0;

        for (int i = 0; i < n; ++i) {
            if (dp[i] == INF) continue;

            // Option: Characters match exactly
            if (source[i] == target[i]) {
                dp[i + 1] = min(dp[i + 1], dp[i]);
            }

            // Option: Replace substrings using Trie matching
            TrieNode *pS = root, *pT = root;
            for (int j = i; j < n; ++j) {
                pS = pS->children[source[j] - 'a'];
                pT = pT->children[target[j] - 'a'];
                
                if (!pS || !pT) break;

                if (pS->id != -1 && pT->id != -1) {
                    long long moveCost = dist[pS->id][pT->id];
                    if (moveCost < INF) {
                        dp[j + 1] = min(dp[j + 1], dp[i] + moveCost);
                    }
                }
            }
        }

        return dp[n] >= INF ? -1 : dp[n];
    }
};