class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Counter array to store the frequency of each task
        int counter[26] = {0};
        int maximum = 0;
        int maxCount = 0;
        // Traverse through tasks to calculate task frequencies
        for (char task : tasks) {
            counter[task - 'A']++;
            if (maximum == counter[task - 'A']) {
                maxCount++;
            }
            else if (maximum < counter[task - 'A']) {
                maximum = counter[task - 'A'];
                maxCount = 1;
            }
        }
        
        // Calculate empty slots, available tasks, and idles needed
        int partCount = maximum - 1;
        int partLength = n - (maxCount - 1);
        int emptySlots = partCount * partLength;
        int availableTasks = tasks.size() - maximum * maxCount;
        int idles = max(0, emptySlots - availableTasks);
        
        // Return the total time required
        return tasks.size() + idles;
    }
};
