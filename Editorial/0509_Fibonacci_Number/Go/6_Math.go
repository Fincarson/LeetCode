func fib(N int) int {
    var goldenRatio float64 = float64((1 + math.Sqrt(5)) / 2);
    return int(math.Round(math.Pow(goldenRatio, float64(N)) / math.Sqrt(5)));
}
