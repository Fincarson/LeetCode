class TwoSum {
private:
    std::vector<int> nums;
    bool is_sorted;

public:
    TwoSum() : is_sorted(false) {}

    void add(int number) {
        nums.push_back(number);
        is_sorted = false;
    }

    bool find(int value) {
        if (!is_sorted) {
            std::sort(nums.begin(), nums.end());
            is_sorted = true;
        }

        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {
            int sum = nums[low] + nums[high];

            if (sum < value) {
                low += 1;
            } else if (sum > value) {
                high -= 1;
            } else {
                return true;
            }
        }

        return false;
    }
};
