class MovingAverage {
private:
    int size;
    vector<int> queue;

public:
    /** Initialize your data structure here. */
    MovingAverage(int size) { this->size = size; }

    double next(int val) {
        queue.push_back(val);
        // calculate the sum of the moving window
        int windowSum = 0;
        for (int i = max(0, (int)queue.size() - size); i < queue.size(); ++i)
            windowSum += queue[i];

        return windowSum * 1.0 / min((int)queue.size(), size);
    }
};
