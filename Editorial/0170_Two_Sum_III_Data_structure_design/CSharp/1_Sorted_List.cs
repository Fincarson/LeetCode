public class TwoSum {
    private List<int> nums;
    private bool is_sorted;

    /** Initialize your data structure here. */
    public TwoSum() {
        this.nums = new List<int>();
        this.is_sorted = false;
    }

    /** Add the number to an internal data structure.. */
    public void Add(int number) {
        this.nums.Add(number);
        this.is_sorted = false;
    }

    /** Find if there exists any pair of numbers which sum is equal to the value. */
    public bool Find(int value) {
        if (!this.is_sorted) {
            this.nums.Sort();
            this.is_sorted = true;
        }

        int low = 0, high = this.nums.Count - 1;
        while (low < high) {
            int twosum = this.nums[low] + this.nums[high];
            if (twosum < value)
                low += 1;
            else if (twosum > value)
                high -= 1;
            else
                return true;
        }

        return false;
    }
}
