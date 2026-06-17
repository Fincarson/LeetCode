class FenwickTree {
private:
    vector<int> tree;

public:
    FenwickTree(int size) : tree(size + 1, 0) {}

    // Calculates the sum up to the given index
    int sum(int index) {
        int result = 0;
        while (index > 0) {
            result += tree[index];
            index &= index - 1;
        }
        return result;
    }

    // Updates the tree by adding value at the given index
    void insert(int index, int value) {
        // Adjust for 1-based indexing
        index += 1;
        while (index < tree.size()) {
            tree[index] += value;
            index += index & -index;
        }
    }
};

class MRUQueue {
private:
    int size;
    FenwickTree tree;
    vector<int> values;

public:
    MRUQueue(int n) : size(n), tree(n + 2000), values(n + 2000, 0) {
        for (int i = 0; i < n; ++i) {
            // Mark positions in the Fenwick Tree
            tree.insert(i, 1);
            // Set the initial values
            values[i] = i + 1;
        }
    }

    // Fetches the kth value from the queue
    int fetch(int k) {
        int low = 0, high = size;

        // Binary search to find the kth value
        while (low < high) {
            int mid = (low + high) >> 1;
            if (tree.sum(mid) < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        // Move the found value to the end
        tree.insert(low - 1, -1);
        tree.insert(size, 1);
        values[size] = values[low - 1];
        size += 1;

        // Return the fetched value
        return values[low - 1];
    }
};
