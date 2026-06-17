func specialTriplets(nums []int) int {
    const MOD = 1000000007
    pos := make(map[int][]int)
    
    for i, v := range nums {
        pos[v] = append(pos[v], i)
    }
    
    ans := 0
    for i := 1; i < len(nums)-1; i++ {
        target := nums[i] * 2
        if targetPos, exists := pos[target]; exists && len(targetPos) > 1 && targetPos[0] < i {
            l, r := upperBound(targetPos, i)
            if nums[i] == 0 {
                l--
            }
            ans = (ans + l * r) % MOD
        }
    }
    return ans
}

func upperBound(arr []int, i int) (int, int) {
    l, r := 0, len(arr)-1
    for l < r {
        mid := l + ((r - l + 1) >> 1)
        if i >= arr[mid] {
            l = mid
        } else {
            r = mid - 1
        }
    }
    return l + 1, len(arr) - 1 - l
}
