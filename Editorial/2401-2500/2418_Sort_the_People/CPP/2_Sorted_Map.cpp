class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int numberOfPeople = names.size();

        // Create a map to store height-name pairs (automatically sorted by
        // height)
        map<int, string> heightToNameMap;

        // Populate the map with height as key and name as value
        for (int i = 0; i < numberOfPeople; i++) {
            heightToNameMap[heights[i]] = names[i];
        }

        vector<string> sortedNames(numberOfPeople);

        // Index for filling sortedNames vector from end to start
        int currentIndex = numberOfPeople - 1;

        // Iterate through the map (sorted by height in ascending order)
        // and fill the sortedNames vector from end to start
        for (const auto& pair : heightToNameMap) {
            sortedNames[currentIndex] = pair.second;
            currentIndex--;
        }

        return sortedNames;
    }
};
