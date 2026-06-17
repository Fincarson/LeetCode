function convertToTitle(columnNumber: number): string {
    let ans: string[] = [];

    while (columnNumber > 0) {
        columnNumber--;
        // Get the last character and append it at the end of string.
        ans.push(String.fromCharCode((columnNumber % 26) + "A".charCodeAt(0)));
        columnNumber = Math.floor(columnNumber / 26);
    }

    // Reverse it, as we appended characters in reverse order.
    return ans.reverse().join("");
}
