class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        // Map to track of the frequencies of elements
        unordered_map<int, int> map;
        for (int i : arr) {
            map[i]++;
        }
        
        // Min heap to track all the frequencies
        priority_queue<int, vector<int>, greater<int> > frequencies;
        for (auto it : map) {
            frequencies.push(it.second);
        }

        // Tracking the number of elements removed
        int elementsRemoved = 0;
        
        // Traversing all frequencies
        while (!frequencies.empty()) {
            // Removing the least frequent element
            elementsRemoved += frequencies.top();

            // If the number of elements removed exceeds k, return
            // the remaining number of unique elements
            if (elementsRemoved > k) {
                return frequencies.size();
            }
            frequencies.pop();
        }
        
        // We have removed all elements, so no unique integers remain
        // Return 0 in this case
        return 0;
    }
};
