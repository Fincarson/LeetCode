// Bit Manipulation is used to perform operations using bit wise XOR, AND and shift left.
function addBinary(a: string, b: string): string {
    let x = BigInt(`0b${a}`);
    let y = BigInt(`0b${b}`);
    while (y) {
        let answer = x ^ y;
        let carry = (x & y) << BigInt(1);
        x = answer;
        y = carry;
    }
    return x.toString(2);
}
