function titleToNumber(s: string): number {
    let result: number = 0;

    const alpha_map: { [key: string]: number } = {};
    for (let i: number = 0; i < 26; i++) {
        // Decimal 65 in ASCII corresponds to char 'A'
        alpha_map[String.fromCharCode(i + 65)] = i + 1;
    }

    const n: number = s.length;
    for (let i: number = 0; i < n; i++) {
        const cur_char: string = s[n - 1 - i];
        result += alpha_map[cur_char] * Math.pow(26, i);
    }
    return result;
}
