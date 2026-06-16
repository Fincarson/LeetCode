function reverseWords(s: string): string {
    let left = 0,
        right = s.length - 1;
    while (left <= right && s.charAt(left) == " ") ++left;
    while (left <= right && s.charAt(right) == " ") --right;

    let d: string[] = [];
    let word: string = "";

    while (left <= right) {
        if (word.length != 0 && s.charAt(left) == " ") {
            d.push(word);
            word = "";
        } else if (s.charAt(left) != " ") {
            word += s.charAt(left);
        }
        ++left;
    }
    d.push(word);
    return d.reverse().join(" ");
}
