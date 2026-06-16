function intToRoman(num: number): string {
    let thousands: string[] = ["", "M", "MM", "MMM"];
    let hundreds: string[] = [
        "",
        "C",
        "CC",
        "CCC",
        "CD",
        "D",
        "DC",
        "DCC",
        "DCCC",
        "CM",
    ];
    let tens: string[] = [
        "",
        "X",
        "XX",
        "XXX",
        "XL",
        "L",
        "LX",
        "LXX",
        "LXXX",
        "XC",
    ];
    let ones: string[] = [
        "",
        "I",
        "II",
        "III",
        "IV",
        "V",
        "VI",
        "VII",
        "VIII",
        "IX",
    ];

    return (
        thousands[Math.floor(num / 1000)] +
        hundreds[Math.floor((num % 1000) / 100)] +
        tens[Math.floor((num % 100) / 10)] +
        ones[num % 10]
    );
}
