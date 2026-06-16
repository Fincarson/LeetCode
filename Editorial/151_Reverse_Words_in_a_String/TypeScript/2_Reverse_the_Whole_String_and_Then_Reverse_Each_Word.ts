// Translated TypeScript solution
function reverseWords(s: string): string {
    // convert string to char array
    // and trim spaces at the same time
    let arr: string[] = trimSpaces(s);

    // reverse the whole string
    reverse(arr, 0, arr.length - 1);

    // reverse each word
    reverseEachWord(arr);

    return arr.join("");
}

function trimSpaces(s: string): string[] {
    let left = 0,
        right = s.length - 1;
    // remove leading spaces
    while (left <= right && s[left] === " ") ++left;
    // remove trailing spaces
    while (left <= right && s[right] === " ") --right;
    // reduce multiple spaces to single one
    let output: string[] = [];
    while (left <= right) {
        if (s[left] !== " ") output.push(s[left]);
        else if (output[output.length - 1] !== " ") output.push(s[left]);
        ++left;
    }
    return output;
}

function reverseEachWord(arr: string[]): void {
    let n = arr.length;
    let start = 0,
        end = 0;
    while (start < n) {
        // go to the end of the word
        while (end < n && arr[end] !== " ") ++end;
        // reverse the word
        reverse(arr, start, end - 1);
        // move to the next word
        start = end + 1;
        ++end;
    }
}

function reverse(arr: string[], start: number, end: number) {
    while (start < end) {
        const tmp = arr[start];
        arr[start++] = arr[end];
        arr[end--] = tmp;
    }
}
