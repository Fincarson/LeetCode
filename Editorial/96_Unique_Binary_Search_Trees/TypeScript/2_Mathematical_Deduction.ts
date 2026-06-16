function numTrees(n: number): number {
    // Note: we should use BigInt here instead of number, otherwise overflow
    let C = BigInt(1);
    for (let i = 0; i < n; ++i) {
        C = (C * BigInt(2) * BigInt(2 * i + 1)) / BigInt(i + 2);
    }
    return Number(C);
}
