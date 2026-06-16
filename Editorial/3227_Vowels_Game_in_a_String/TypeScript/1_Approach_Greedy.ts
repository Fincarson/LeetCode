function doesAliceWin(s: string): boolean {
    return [...s].some((c) => "aeiou".includes(c));
}
