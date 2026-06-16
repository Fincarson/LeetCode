class Solution {
public:
    static map<string, int>
        values;  // static ensures map initialization only happens once instead
                 // of every object of the class

    Solution() {
        if (values.empty()) {
            values.insert(pair<string, int>("I", 1));
            values.insert(pair<string, int>("V", 5));
            values.insert(pair<string, int>("X", 10));
            values.insert(pair<string, int>("L", 50));
            values.insert(pair<string, int>("C", 100));
            values.insert(pair<string, int>("D", 500));
            values.insert(pair<string, int>("M", 1000));
            values.insert(pair<string, int>("IV", 4));
            values.insert(pair<string, int>("IX", 9));
            values.insert(pair<string, int>("XL", 40));
            values.insert(pair<string, int>("XC", 90));
            values.insert(pair<string, int>("CD", 400));
            values.insert(pair<string, int>("CM", 900));
        }
    }

    int romanToInt(string s) {
        int sum = 0;
        int i = 0;
        while (i < s.size()) {
            if (i < s.size() - 1) {
                string doubleSymbol = s.substr(i, 2);
                // check if this is the length-2 symbol case
                if (values.count(doubleSymbol)) {
                    sum += values[doubleSymbol];
                    i += 2;
                    continue;
                }
            }
            // otherwise, it must be the length-1 symbol case
            string singleSymbol = s.substr(i, 1);
            sum += values[singleSymbol];
            i += 1;
        }
        return sum;
    }
};

map<string, int> Solution::values;  // initalizing the map outside the class
