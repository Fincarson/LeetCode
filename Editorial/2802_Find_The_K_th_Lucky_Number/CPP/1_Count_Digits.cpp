class Solution {
public:
    string kthLuckyNumber(int k) {
        int c = 0;         // The number of digits in the kth lucky number
        int numCount = 0;  // The number of lucky numbers with c or fewer digits
        while (numCount < k) {
            c++;
            numCount += pow(2, c);
        }

        // Calculate the number of lucky numbers with c digits before the kth
        // lucky number
        int x = k - 1 - (numCount - pow(2, c));

        // Build result using x by prepending 4 for 0 and 1 for 7
        string kthLuckyNum;
        for (int i = 0; i < c; i++) {
            string digit;
            if (x % 2 == 1) {
                digit = '7';
            } else {
                digit = '4';
            }
            kthLuckyNum.insert(0, digit);
            x /= 2;
        }

        return kthLuckyNum;
    }
};
