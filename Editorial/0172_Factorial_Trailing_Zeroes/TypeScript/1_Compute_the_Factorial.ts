function trailingZeroes(n: number): number {
    let nFactorial = BigInt(1);
    for (let i = 2; i <= n; i++) {
        nFactorial *= BigInt(i);
    }

    let zeroCount = 0;
    const ten = BigInt(10);

    while (nFactorial % ten === BigInt(0)) {
        nFactorial /= ten;
        zeroCount++;
    }

    return zeroCount;
}
