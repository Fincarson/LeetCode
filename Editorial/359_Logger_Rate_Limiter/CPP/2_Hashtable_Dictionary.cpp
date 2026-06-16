class Logger {
private:
    unordered_map<string, int> msgDict;

public:
    /** Initialize your data structure here. */
    Logger() {}

    /**
     * Returns true if the message should be printed in the given timestamp,
     * otherwise returns false.
     */
    bool shouldPrintMessage(int timestamp, string message) {
        if (this->msgDict.find(message) == this->msgDict.end()) {
            this->msgDict[message] = timestamp;
            return true;
        }

        int oldTimestamp = this->msgDict[message];
        if (timestamp - oldTimestamp >= 10) {
            this->msgDict[message] = timestamp;
            return true;
        } else
            return false;
    }
};
