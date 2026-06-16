func mySqrt(x int) int {
    if x < 2 {
        return x
    }
    left := int(math.Pow(math.E, 0.5*math.Log(float64(x))))
    right := left + 1
    if right*right > x {
        return left
    }
    return right
}
