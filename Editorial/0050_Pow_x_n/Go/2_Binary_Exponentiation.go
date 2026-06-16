func binaryExp(x float64, n int) float64 {
    if n == 0 {
        return 1
    }
    // Handle case where, n < 0.
    if n < 0 {
        n = -1 * n
        x = 1.0 / x
    }
    // Perform Binary Exponentiation.
    var result float64 = 1
    for n != 0 {
        // If 'n' is odd we multiply result with 'x' and reduce 'n' by '1'.
        if n%2 == 1 {
            result = result * x
            n -= 1
        }
        // We square 'x' and reduce 'n' by half, x^n => (x^2)^(n/2).
        x = x * x
        n = n / 2
    }
    return result
}

func myPow(x float64, n int) float64 {
    return binaryExp(x, n)
}
