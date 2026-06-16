class TwoSum {
    private nums: number[];
    private is_sorted: boolean;

    constructor() {
        this.nums = [];
        this.is_sorted = false;
    }

    add(number: number) {
        this.nums.push(number);
        this.is_sorted = false;
    }

    find(value: number) {
        if (!this.is_sorted) {
            this.nums.sort((a, b) => a - b);
            this.is_sorted = true;
        }
        let low = 0,
            high = this.nums.length - 1;
        while (low < high) {
            let twosum = this.nums[low] + this.nums[high];
            if (twosum < value) low += 1;
            else if (twosum > value) high -= 1;
            else return true;
        }
        return false;
    }
}
