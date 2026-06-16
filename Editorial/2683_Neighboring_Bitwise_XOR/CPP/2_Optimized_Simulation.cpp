class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        // Initialize the original array with 0 as the first element.
        vector<int> original = {0};

        // Generate the original array based on derived and original[0] = 0.
        for (int i = 0; i < derived.size(); i++) {
            original.push_back((derived[i] ^ original[i]));
        }

        // Check if the array is valid by comparing the first and last elements.
        return original[0] == original[original.size() - 1];
    }
};
