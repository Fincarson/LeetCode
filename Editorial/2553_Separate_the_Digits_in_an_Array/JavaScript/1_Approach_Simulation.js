var separateDigits = function (nums) {
    const res = [];
    for (let num of nums) {
        let x = num;
        const tmp = [];
        while (x > 0) {
            tmp.push(x % 10);
            x = Math.floor(x / 10);
        }
        for (let i = tmp.length - 1; i >= 0; i--) {
            res.push(tmp[i]);
        }
    }
    return res;
};
