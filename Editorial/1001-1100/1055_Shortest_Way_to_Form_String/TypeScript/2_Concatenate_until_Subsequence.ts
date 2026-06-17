function shortestWay(source: string, target: string): number {

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

    // Concatenate source until target is a subsequence of concatenated string
    let concatenatedSource = source;
    let count = 1;
    while (!isSubsequence(target, concatenatedSource)) {
        concatenatedSource += source;
        count++;
    }

    // Number of concatenations done
    return count;
};

// To check if toCheck is a subsequence of inString
function isSubsequence(toCheck: string, inString: string): boolean {
    let i = 0, j = 0;
    while (i < toCheck.length && j < inString.length) {
        if (toCheck[i] == inString[j]) {
            i++;
        }
        j++;
    }

    return i == toCheck.length;
}
