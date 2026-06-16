class Solution {
public:
    int equalDigitFrequency(const std::string& s) {
        TrieNode* root = new TrieNode();  // Initialize the Trie root
        int totalValidSubstrings = 0;

        // Iterate through all starting indices of substrings
        for (int start = 0; start < s.size(); start++) {
            TrieNode* currentNode = root;
            // Frequency table for digits 0-9
            vector<int> digitFrequency(10, 0);
            int uniqueDigitsCount = 0;
            int maxDigitFrequency = 0;

            // Extend the substring from 'start' to different end positions
            for (int end = start; end < s.size(); end++) {
                int currentDigit = s[end] - '0';  // Current digit

                // Update digit frequency and unique digits count
                if (digitFrequency[currentDigit]++ == 0) {
                    uniqueDigitsCount++;
                }

                maxDigitFrequency =
                    max(maxDigitFrequency, digitFrequency[currentDigit]);

                // Traverse or create a new node in the Trie
                if (currentNode->children[currentDigit] == nullptr) {
                    currentNode->children[currentDigit] =
                        new TrieNode();  // Add new node for the digit
                }

                // Move to the child node
                currentNode = currentNode->children[currentDigit];

                // Check if the substring is valid
                if (uniqueDigitsCount * maxDigitFrequency == end - start + 1 &&
                    !currentNode->isVisited) {
                    // Increment valid substrings count
                    totalValidSubstrings++;
                    // Mark this substring as seen
                    currentNode->isVisited = true;
                }
            }
        }

        delete root;  // Cleanup allocated memory
        return totalValidSubstrings;
    }

private:
    class TrieNode {
    public:
        TrieNode* children[10];  // Pointers to children nodes (0-9)
        bool isVisited;

        TrieNode() : isVisited(false) {
            fill(begin(children), end(children), nullptr);
        }
    };
};
