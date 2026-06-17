function count(n: number): number {
    // Function to calculate sum of first n natural numbers
    return (n * (n + 1)) / 2;
}
function candy(ratings: number[]): number {
    if (ratings.length <= 1) {
        return ratings.length;
    }
    let candies = 0;
    let up = 0;
    let down = 0;
    let oldSlope = 0;
    for (let i = 1; i < ratings.length; i++) {
        let newSlope =
            ratings[i] > ratings[i - 1]
                ? 1
                : ratings[i] < ratings[i - 1]
                  ? -1
                  : 0;
        // slope is changing from uphill to flat or downhill
        // or from downhill to flat or uphill
        if (
            (oldSlope > 0 && newSlope == 0) ||
            (oldSlope < 0 && newSlope >= 0)
        ) {
            candies += count(up) + count(down) + Math.max(up, down);
            up = 0;
            down = 0;
        }
        // slope is uphill
        if (newSlope > 0) {
            up++;
        }
        // slope is downhill
        else if (newSlope < 0) {
            down++;
        }
        // slope is flat
        else {
            candies++;
        }
        oldSlope = newSlope;
    }
    candies += count(up) + count(down) + Math.max(up, down) + 1;
    return candies;
}
