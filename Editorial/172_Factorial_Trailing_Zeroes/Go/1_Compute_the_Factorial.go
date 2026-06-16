import (
    "math/big"
)

func trailingZeroes(n int) int {
    // Calculate n!
    nFactorial := big.NewInt(1)
    for i := 2; i <= n; i++ {
        nFactorial.Mul(nFactorial, big.NewInt(int64(i)))
    }

    // Count how many 0's are on the end.
    zeroCount := 0
    ten := big.NewInt(10)
    zero := big.NewInt(0)

    // Temp variable to hold the result of the mod operation
    modResult := new(big.Int)

    for {
        modResult.Mod(nFactorial, ten)
        if modResult.Cmp(zero) == 0 {
            nFactorial.Div(nFactorial, ten)
            zeroCount++
        } else {
            break
        }
    }

    return zeroCount
}
