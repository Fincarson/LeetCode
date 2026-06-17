var maxPoints = function (points) {
    let n = points.length;
    if (n == 1) {
        return 1;
    }
    let result = 2;
    for (let i = 0; i < n; i++) {
        let cnt = {};
        for (let j = 0; j < n; j++) {
            if (j != i) {
                let key = Math.atan2(
                    points[j][1] - points[i][1],
                    points[j][0] - points[i][0],
                );
                cnt[key] = cnt[key] ? cnt[key] + 1 : 1;
            }
        }
        result = Math.max(result, Math.max(...Object.values(cnt)) + 1);
    }
    return result;
};
