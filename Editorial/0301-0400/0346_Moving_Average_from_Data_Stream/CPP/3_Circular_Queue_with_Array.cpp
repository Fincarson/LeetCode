class MovingAverage {
private:
    int size;
    int head = 0;
    int windowSum = 0;
    int count = 0;
    vector<int> queue;

public:
    MovingAverage(int size) {
        this->size = size;
        queue = vector<int>(size);
    }

    double next(int val) {
        ++count;
        // calculate the new sum by shifting the window
        int tail = (head + 1) % size;
        windowSum = windowSum - queue[tail] + val;
        // move on to the next head
        head = (head + 1) % size;
        queue[head] = val;
        return windowSum * 1.0 / min(size, count);
    }
};
