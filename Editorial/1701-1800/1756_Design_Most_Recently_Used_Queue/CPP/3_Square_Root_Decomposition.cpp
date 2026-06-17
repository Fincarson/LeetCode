class MRUQueue {
private:
    int totalElements;
    const int BUCKET_SIZE;
    // Stores elements in different buckets
    vector<vector<int>> data;
    // Tracks the starting index of each bucket
    vector<int> index;

public:
    MRUQueue(int n) : totalElements(n), BUCKET_SIZE(sqrt(n)) {
        // Initialize data with the given number of elements
        for (int number = 1; number <= n; ++number) {
            int bucketIndex = (number - 1) / BUCKET_SIZE;
            // Create a new bucket if it's not already present
            if (bucketIndex == data.size()) {
                data.push_back({});
                index.push_back(number);
            }
            // Add the number to the corresponding bucket
            data.back().push_back(number);
        }
    }

    int fetch(int k) {
        // Find the bucket that contains the kth element using binary search
        int bucketIndex =
            upper_bound(index.begin(), index.end(), k) - index.begin() - 1;

        // Get the element from the selected bucket
        int element = data[bucketIndex][k - index[bucketIndex]];
        // Remove the element from its current bucket
        data[bucketIndex].erase(data[bucketIndex].begin() +
                                (k - index[bucketIndex]));

        // Shift the starting indices of the subsequent buckets
        for (int i = bucketIndex + 1; i < index.size(); ++i) {
            index[i]--;
        }

        // Append the element to the last bucket
        if (data.back().size() >= BUCKET_SIZE) {
            data.push_back({});
            // Update the last bucket's index
            index.push_back(totalElements);
        }
        // Add the element to the last bucket
        data.back().push_back(element);

        // Remove any empty buckets after the operation
        if (data[bucketIndex].empty()) {
            data.erase(data.begin() + bucketIndex);
            index.erase(index.begin() + bucketIndex);
        }

        return element;
    }
};
