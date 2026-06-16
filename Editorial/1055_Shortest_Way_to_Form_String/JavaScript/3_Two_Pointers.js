/**
 * @param {string} source
 * @param {string} target
 * @return {number}
 */
var shortestWay = function(source, target) {
    
    // Boolean array to mark all characters of source
    let sourceChars = new Array(26).fill(false);
    for (let c of source) {
        sourceChars[c.charCodeAt(0) - 'a'.charCodeAt(0)] = true;
    }

    // Check if all characters of target are present in source
    // If any character is not present, return -1
    for (let c of target) {
        if (!sourceChars[c.charCodeAt(0) - 'a'.charCodeAt(0)]) {
            return -1;
        }
    }

    // Length of source to loop back to start of source using mod
    let m = source.length;

    // Pointer for source
    let sourceIterator = 0;

    // Number of times source is traversed. It will be incremented when
    // while finding occurrence of a character in target, sourceIterator
    // reaches the start of source again.
    let count = 0;

    // Find all characters of target in source
    for (let c of target) {

        // If while finding, iterator reaches start of source again,
        // increment count
        if (sourceIterator == 0) {
            count++;
        }

        // Find the first occurrence of c in source
        while (source[sourceIterator] != c) {

            // Formula for incrementing while looping back to start.
            sourceIterator = (sourceIterator + 1) % m;

            // If while finding, iterator reaches start of source again,
            // increment count
            if (sourceIterator == 0) {
                count++;
            }
        }

        // Loop will break when c is found in source. Thus, increment.
        // Don't increment count until it is not clear that target has
        // remaining characters.
        sourceIterator = (sourceIterator + 1) % m;
    }

    // Return count
    return count;
};
