class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ']') {
                string decodedString;
                // get the encoded string (in reverse order from stack)
                while (st.top() != '[') {
                    decodedString.push_back(st.top());
                    st.pop();
                }
                // pop '[' from stack
                st.pop();

                // get the number k
                int base = 1;
                int k = 0;
                while (!st.empty() && isdigit(st.top())) {
                    k += (st.top() - '0') * base;
                    st.pop();
                    base *= 10;
                }

                // decodedString is reversed, so fix it
                reverse(decodedString.begin(), decodedString.end());

                // push decodedString k times into stack
                while (k-- > 0) {
                    for (char c : decodedString) {
                        st.push(c);
                    }
                }
            } else {
                st.push(s[i]);
            }
        }

        // build result from stack
        string result;
        result.reserve(st.size());
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
