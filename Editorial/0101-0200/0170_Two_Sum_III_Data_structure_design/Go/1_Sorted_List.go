type TwoSum struct {
    nums      []int
    is_sorted bool
}

func Constructor() TwoSum {
    return TwoSum{nums: []int{}, is_sorted: false}
}

func (this *TwoSum) Add(number int) {
    this.nums = append(this.nums, number)
    this.is_sorted = false
}

func (this *TwoSum) Find(value int) bool {
    if !this.is_sorted {
        sort.Ints(this.nums)
        this.is_sorted = true
    }
    low, high := 0, len(this.nums)-1
    for low < high {
        var twosum int = this.nums[low] + this.nums[high]
        if twosum < value {
            low += 1
        } else if twosum > value {
            high -= 1
        } else {
            return true
        }
    }
    return false
}
