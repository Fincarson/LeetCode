class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2,
                                   vector<int>& arr3) {
        vector<int> ans;

        // Initialize three pointers for the three arrays
        int p1 = 0, p2 = 0, p3 = 0;

        while (p1 < arr1.size() && p2 < arr2.size() && p3 < arr3.size()) {
            // Check if all three pointers point to the same element
            if (arr1[p1] == arr2[p2] && arr2[p2] == arr3[p3]) {
                ans.push_back(arr1[p1]);
                p1++;
                p2++;
                p3++;
            } else {
                // Move the pointer with the smallest value to find the
                // intersection
                if (arr1[p1] < arr2[p2]) {
                    p1++;
                } else if (arr2[p2] < arr3[p3]) {
                    p2++;
                } else {
                    p3++;
                }
            }
        }

        return ans;
    }
};
