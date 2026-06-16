let recursion = (n, k) => {
    // First row will only have one symbol '0'.
    if (n === 1) {
        return 0;
    }

    const totalElements = Math.pow(2, n - 1);
    const halfElements = totalElements / 2;

    // If the target is present in the right half, we switch to the respective left half symbol.
    if (k > halfElements) {
        return 1 - recursion(n, k - halfElements);
    }

    // Otherwise, we switch to the previous row.
    return recursion(n - 1, k);
}

let kthGrammar = function(n, k) {
    return recursion(n, k);
};
