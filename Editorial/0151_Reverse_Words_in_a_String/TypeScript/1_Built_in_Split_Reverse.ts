function reverseWords(s: string): string {
    // remove leading and trailing spaces
    s = s.trim();
    // split by spaces and reverse
    let words = s.split(/\s+/).reverse();
    // join the words with a space
    return words.join(" ");
}
