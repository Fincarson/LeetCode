class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k = k % size;

        int start = 0, count = 0;
        while (count < size) {
            int current = start, prev = nums[start];
            do {
                int next = (current + k) % size;
                int temp = nums[next];
                nums[next] = prev;
                prev = temp;
                current = next;
                count++;
            } while (start != current);
            start++;
        }
    }
};
