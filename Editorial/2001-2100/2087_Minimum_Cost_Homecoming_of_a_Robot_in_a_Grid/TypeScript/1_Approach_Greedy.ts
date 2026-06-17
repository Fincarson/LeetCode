function minCost(
    startPos: number[],
    homePos: number[],
    rowCosts: number[],
    colCosts: number[],
): number {
    const r1 = startPos[0],
        c1 = startPos[1];
    const r2 = homePos[0],
        c2 = homePos[1];
    let res = 0; // total cost

    // move to the row where the home is located, determine the direction of movement between rows, and calculate the corresponding cost
    if (r2 >= r1) {
        for (let i = r1 + 1; i <= r2; i++) {
            res += rowCosts[i];
        }
    } else {
        for (let i = r2; i < r1; i++) {
            res += rowCosts[i];
        }
    }

    // move to the location of the house, determine the direction of movement between columns, and calculate the corresponding cost
    if (c2 >= c1) {
        for (let i = c1 + 1; i <= c2; i++) {
            res += colCosts[i];
        }
    } else {
        for (let i = c2; i < c1; i++) {
            res += colCosts[i];
        }
    }

    return res;
}
