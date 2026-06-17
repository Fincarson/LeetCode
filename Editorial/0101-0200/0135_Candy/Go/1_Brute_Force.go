func candy(ratings []int) int {
    candies := make([]int, len(ratings))
    for i := range candies {
        candies[i] = 1
    }
    hasChanged := true
    for hasChanged {
        hasChanged = false
        for i := 0; i < len(ratings); i++ {
            if i != len(ratings)-1 && ratings[i] > ratings[i+1] &&
                candies[i] <= candies[i+1] {
                candies[i] = candies[i+1] + 1
                hasChanged = true
            }
            if i > 0 && ratings[i] > ratings[i-1] &&
                candies[i] <= candies[i-1] {
                candies[i] = candies[i-1] + 1
                hasChanged = true
            }
        }
    }
    sum := 0
    for _, candy := range candies {
        sum += candy
    }
    return sum
}
