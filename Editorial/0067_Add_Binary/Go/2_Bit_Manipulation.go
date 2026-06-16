// Bit Manipulation is used to perform operations using bit wise XOR, AND and shift left.
func addBinary(a string, b string) string {
    var x, y, zero, carry, answer big.Int
    _, _ = x.SetString(a, 2)
    _, _ = y.SetString(b, 2)
    zero.SetInt64(0)
    for y.Cmp(&zero) != 0 {
        answer.Xor(&x, &y)
        carry.And(&x, &y)
        carry.Lsh(&carry, 1)
        x.Set(&answer)
        y.Set(&carry)
    }
    return x.Text(2)
}
