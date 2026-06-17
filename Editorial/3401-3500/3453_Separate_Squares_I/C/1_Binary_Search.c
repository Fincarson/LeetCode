bool check(double limit_y, int** squares, int squaresSize, double total_area) {
    double area = 0.0;

    for (int i = 0; i < squaresSize; i++) {
        int y = squares[i][1];
        int l = squares[i][2];
        if (y < limit_y) {
            area += (double)l * fmin(l, limit_y - y);
        }
    }

    return area >= total_area / 2.0;
}

double separateSquares(int** squares, int squaresSize, int* squaresColSize) {
    double max_y = 0.0, total_area = 0.0;
    for (int i = 0; i < squaresSize; i++) {
        int y = squares[i][1];
        int l = squares[i][2];
        total_area += (double)l * l;
        if (y + l > max_y) {
            max_y = y + l;
        }
    }

    double lo = 0.0, hi = max_y;
    double eps = 1e-5;
    while (fabs(hi - lo) > eps) {
        double mid = (hi + lo) / 2.0;
        if (check(mid, squares, squaresSize, total_area)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    return hi;
}
