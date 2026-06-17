function totalWaviness(num1: number, num2: number): number {
    const getWaviness = (x: number): number => {
        const s: string = x.toString();
        let waviness: number = 0;

        for (let i = 1; i < s.length - 1; i++) {
            const isPeak: boolean = s[i] > s[i - 1] && s[i] > s[i + 1];
            const isValley: boolean = s[i] < s[i - 1] && s[i] < s[i + 1];
            if (isPeak || isValley) {
                waviness++;
            }
        }

        return waviness;
    };

    let total: number = 0;
    for (let i = num1; i <= num2; i++) {
        total += getWaviness(i);
    }

    return total;
}
