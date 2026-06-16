function differenceOfSums(n: number, m: number): number {
    const k = Math.floor(n / m);
    return (n * (n + 1)) / 2 - k * (k + 1) * m;
}
