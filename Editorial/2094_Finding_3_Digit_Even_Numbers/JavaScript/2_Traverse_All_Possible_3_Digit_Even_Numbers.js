var findEvenNumbers = function (digits) {
    const res = [];
    const freq = new Map();
    // Count the number of occurrences of each number in the integer array
    for (const d of digits) {
        freq.set(d, (freq.get(d) || 0) + 1);
    }
    // Enumerate all three-digit even numbers
    for (let i = 100; i < 1000; i += 2) {
        const freq1 = new Map();
        let num = i;
        // Count the frequency of each digit of the current even number
        while (num > 0) {
            const d = num % 10;
            freq1.set(d, (freq1.get(d) || 0) + 1);
            num = Math.floor(num / 10);
        }
        // Check if the conditions are met
        let isValid = true;
        for (const [d, count] of freq1.entries()) {
            if ((freq.get(d) || 0) < count) {
                isValid = false;
                break;
            }
        }
        if (isValid) {
            res.push(i);
        }
    }
    return res;
};
