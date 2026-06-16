var maximalRectangle = function (matrix) {
    if (matrix.length === 0) return 0;
    let m = matrix.length;
    let n = matrix[0].length;
    let left = Array(n).fill(0);
    let right = Array(n).fill(n);
    let height = Array(n).fill(0);
    let maxarea = 0;
    for (let i = 0; i < m; i++) {
        let cur_left = 0,
            cur_right = n;
        for (let j = 0; j < n; j++) {
            if (matrix[i][j] === "1") height[j]++;
            else height[j] = 0;
        }
        for (let j = 0; j < n; j++) {
            if (matrix[i][j] === "1") left[j] = Math.max(left[j], cur_left);
            else {
                left[j] = 0;
                cur_left = j + 1;
            }
        }
        for (let j = n - 1; j >= 0; j--) {
            if (matrix[i][j] === "1") right[j] = Math.min(right[j], cur_right);
            else {
                right[j] = n;
                cur_right = j;
            }
        }
        for (let j = 0; j < n; j++) {
            maxarea = Math.max(maxarea, (right[j] - left[j]) * height[j]);
        }
    }
    return maxarea;
};
