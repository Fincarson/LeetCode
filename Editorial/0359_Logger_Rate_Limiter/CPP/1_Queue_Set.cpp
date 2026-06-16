class Logger {
private:
    queue<pair<string, int>> msg_queue;
    unordered_set<string> msg_set;

public:
    /** Initialize your data structure here. */
    Logger() {
        // Leave as it is.
    }

    /** Returns true if the message should be printed in the given timestamp,
     * otherwise returns false. */
    bool shouldPrintMessage(int timestamp, string message) {
        while (!msg_queue.empty()) {
            pair<string, int> head = msg_queue.front();
            if (timestamp - head.second >= 10) {
                msg_set.erase(head.first);
                msg_queue.pop();
            } else
                break;
        }

        if (msg_set.count(message) == 0) {
            msg_queue.push(make_pair(message, timestamp));
            msg_set.insert(message);
            return true;
        } else
            return false;
    }
};
