var readBinaryWatch = function (turnedOn) {
    const ans = [];
    for (let i = 0; i < 1024; ++i) {
        let h = i >> 6,
            m = i & 63; // Extract the high 4 bits and low 6 bits using bitwise operations
        if (
            h < 12 &&
            m < 60 &&
            i.toString(2).split("0").join("").length === turnedOn
        ) {
            ans.push(h + ":" + (m < 10 ? "0" : "") + m);
        }
    }
    return ans;
};
