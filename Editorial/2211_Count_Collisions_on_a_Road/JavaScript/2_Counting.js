var countCollisions = function (directions) {
    const n = directions.length;
    let l = 0,
        r = n - 1;

    while (l < n && directions[l] === "L") {
        l++;
    }

    while (r >= l && directions[r] === "R") {
        r--;
    }

    let res = 0;
    for (let i = l; i <= r; i++) {
        if (directions[i] !== "S") {
            res++;
        }
    }
    return res;
};
