var checkStrings = function (s1, s2) {
    const counts = new Int32Array(256);

    for (let i = 0; i < s1.length; i++) {
        const offset = (i & 1) << 7;
        counts[offset + s1.charCodeAt(i)]++;
        counts[offset + s2.charCodeAt(i)]--;
    }

    for (let i = 0; i < 256; i++) {
        if (counts[i] !== 0) {
            return false;
        }
    }

    return true;
};
