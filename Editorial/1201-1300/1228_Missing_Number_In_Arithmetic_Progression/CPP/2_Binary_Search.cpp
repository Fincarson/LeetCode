class Solution {
public:
    int missingNumber(vector<int> &arr) {
        int n = arr.size();

        // Get the difference `difference`.
        int difference = (arr.back() - arr.front()) / n;
        int lo = 0;
        int hi = n - 1;

        // Basic binary search template.
        while (lo < hi) {
            int mid = (lo + hi) / 2;

            // All numbers upto `mid` have no missing number, so search on the right side.
            if (arr[mid] == arr.front() + mid * difference) {
                lo = mid + 1;
            }

            // A number is missing before `mid` inclusive of `mid` itself.
            else {
                hi = mid;
            }
        }

        // Index `lo` will be the position with the first incorrect number.
        // Return the value that was supposed to be at this index.
        return arr.front() + difference * lo;
    }
};
