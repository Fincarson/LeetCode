// Golang translation
func mySqrt(x int) int {
    if x < 2 {
        return x
    }
    left := mySqrt(x>>2) << 1
    right := left + 1
    if right*right > x {
        return left
    }
    return right
}
