let kthGrammar = function(n, k) {
    if (n === 1) {
        return 0;
    }

    // We assume the symbol at the target position is '1'.
    let symbol = 1;

    for (let currRow = n; currRow > 1; --currRow) {
        const totalElements = Math.pow(2, currRow - 1);
        const halfElements = totalElements / 2;

        // If 'k' lies in the right half symbol, then we flip over to the respective left half symbol.
        if (k > halfElements) {
            // Flip the symbol.
            symbol = 1 - symbol;
            // Change the position after flipping.
            k -= halfElements;
        }
    }

    // We reached the 1st row; if the symbol is not '0', we started with the wrong symbol.
    if (symbol !== 0) {
        // Thus, the start symbol was '0', not '1'.
        return 0;
    }

    // The start symbol was indeed what we started with, a '1'.
    return 1;
};
