class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        // Find the frequency of each element
        vector<int> frequencies(100, 0);
        for (int num : nums) {
            frequencies[num - 1]++;
        }

        // Determine the maximum frequency, stored in the last index of the sorted array
        sort(frequencies.begin(), frequencies.end());
        int maxFreqIndex = frequencies.size() - 1;
        int totalFrequencies = frequencies[maxFreqIndex];

        // Calculate the total frequencies of elements with the maximum frequency
        // Start from the last index and iterate right to left
        while (maxFreqIndex > 0 && frequencies[maxFreqIndex] == frequencies[maxFreqIndex - 1]) {
            totalFrequencies += frequencies[maxFreqIndex];
            maxFreqIndex--;
        }
        return totalFrequencies;
    }
};
