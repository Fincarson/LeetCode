class Solution {
    unordered_map<char, vector<char>> reverseAdjList;
    unordered_map<char, bool> seen;
    string output;

public:
    string alienOrder(vector<string>& words) {
        // Step 0: Put all unique letters into reverseAdjList as keys.
        for (string word : words) {
            for (char c : word) {
                if (reverseAdjList.find(c) == reverseAdjList.end())
                    reverseAdjList[c] = vector<char>();
            }
        }

        // Step 1: Find all edges and add reverse edges to reverseAdjList.
        for (int i = 0; i < words.size() - 1; i++) {
            string word1 = words[i];
            string word2 = words[i + 1];
            // Check that word2 is not a prefix of word1.
            if (word1.length() > word2.length() &&
                word1.substr(0, word2.size()) == word2)
                return "";

            // Find the first non match and insert the corresponding relation.
            for (int j = 0; j < min(word1.length(), word2.length()); j++) {
                if (word1[j] != word2[j]) {
                    reverseAdjList[word2[j]].push_back(word1[j]);
                    break;
                }
            }
        }

        // Step 2: DFS to build up the output list.
        for (auto const& iter : reverseAdjList) {
            bool result = dfs(iter.first);
            if (!result) return "";
        }

        return output;
    }

    // Return true iff no cycles detected.
    bool dfs(char c) {
        if (seen.find(c) != seen.end()) {
            // If this node was grey (false), a cycle was detected.
            return seen[c];
        }
        seen[c] = false;
        for (char next : reverseAdjList[c]) {
            bool result = dfs(next);
            if (!result) return false;
        }
        seen[c] = true;
        output += c;
        return true;
    }
};
