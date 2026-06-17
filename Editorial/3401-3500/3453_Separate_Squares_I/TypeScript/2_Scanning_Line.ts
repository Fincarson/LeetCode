function separateSquares(squares: number[][]): number {
    let totalArea: bigint = 0n;
    const events: [number, number, number][] = [];

    for (const sq of squares) {
        const y = sq[1],
            l = sq[2];
        totalArea += BigInt(l) * BigInt(l);
        events.push([y, l, 1]);
        events.push([y + l, l, -1]);
    }

    // sort by y-coordinate
    events.sort((a, b) => a[0] - b[0]);

    let coveredWidth: number = 0; // sum of all bottom edges under the current scanning line
    let currArea: number = 0; // current cumulative area
    let prevHeight: number = 0; // height of the previous scanning line

    for (const [y, l, delta] of events) {
        const diff: number = y - prevHeight;
        // additional area between two scanning lines
        const area: number = coveredWidth * diff;
        // if this part of the area exceeds more than half of the total area
        if (2n * BigInt(Math.ceil(currArea + area)) >= totalArea) {
            return (
                prevHeight +
                (Number(totalArea) - 2.0 * currArea) / (2.0 * coveredWidth)
            );
        }
        // update width: add width at the start event, subtract width at the end event
        coveredWidth += delta * l;
        currArea += area;
        prevHeight = y;
    }

    return 0.0;
}
