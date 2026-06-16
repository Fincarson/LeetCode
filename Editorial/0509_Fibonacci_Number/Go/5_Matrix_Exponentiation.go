func fib(N int) int {
    if N <= 1 {
        return N
    }
    var A = [2][2]int{
        {1, 1},
        {1, 0},
    }
    A = matrixPower(A, N - 1)
    return A[0][0]
}

func matrixPower(A [2][2]int, N int) [2][2]int {
    if N <= 1 {
        return A
    }
    A = matrixPower(A, N / 2)
    A = multiply(A, A)

    var B = [2][2]int{
        {1, 1},
        {1, 0},
    }
    if N % 2 != 0 {
        A = multiply(A, B)
    }

    return A
}

func multiply(A [2][2]int, B [2][2]int) [2][2]int {
    x := A[0][0] * B[0][0] + A[0][1] * B[1][0];
    y := A[0][0] * B[0][1] + A[0][1] * B[1][1];
    z := A[1][0] * B[0][0] + A[1][1] * B[1][0];
    w := A[1][0] * B[0][1] + A[1][1] * B[1][1];

    A[0][0] = x;
    A[0][1] = y;
    A[1][0] = z;
    A[1][1] = w;

    return A
}
