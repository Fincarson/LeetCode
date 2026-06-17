function countAndSay(n: number): string {
    let currentString: string = "1";
    for (let i = 2; i <= n; i++) {
        let nextString: string = "";
        for (let j = 0, k = 0; j < currentString.length; j = k) {
            while (
                k < currentString.length &&
                currentString.charAt(k) == currentString.charAt(j)
            )
                k++;
            nextString += (k - j).toString() + currentString.charAt(j);
        }
        currentString = nextString;
    }
    return currentString;
}
