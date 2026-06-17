function maxWalls(robots, distance, walls) {
    const n = robots.length;
    const robotDist = robots.map((r, i) => [r, distance[i]]);
    robotDist.sort((a, b) => a[0] - b[0]);
    walls.sort((a, b) => a - b);

    const m = walls.length;
    let rightPtr = 0,
        leftPtr = 0,
        curPtr = 0,
        robotPtr = 0;

    let prevLeft = 0,
        prevRight = 0,
        prevNum = 0;
    let subLeft = 0,
        subRight = 0;

    for (let i = 0; i < n; i++) {
        const [robotPos, robotDistVal] = robotDist[i];

        while (rightPtr < m && walls[rightPtr] <= robotPos) {
            rightPtr++;
        }
        const pos1 = rightPtr;

        while (curPtr < m && walls[curPtr] < robotPos) {
            curPtr++;
        }
        const pos2 = curPtr;

        let leftBound = robotPos - robotDistVal;
        if (i >= 1) {
            leftBound = Math.max(
                robotPos - robotDistVal,
                robotDist[i - 1][0] + 1,
            );
        }
        while (leftPtr < m && walls[leftPtr] < leftBound) {
            leftPtr++;
        }
        const leftPos = leftPtr;
        const currentLeft = pos1 - leftPos;

        let rightBound = robotPos + robotDistVal;
        if (i < n - 1) {
            rightBound = Math.min(
                robotPos + robotDistVal,
                robotDist[i + 1][0] - 1,
            );
        }
        while (rightPtr < m && walls[rightPtr] <= rightBound) {
            rightPtr++;
        }
        const rightPos = rightPtr;
        const currentRight = rightPos - pos2;

        let currentNum = 0;
        if (i > 0) {
            while (robotPtr < m && walls[robotPtr] < robotDist[i - 1][0]) {
                robotPtr++;
            }
            const pos3 = robotPtr;
            currentNum = pos1 - pos3;
        }

        if (i === 0) {
            subLeft = currentLeft;
            subRight = currentRight;
        } else {
            const newsubLeft = Math.max(
                subLeft + currentLeft,
                subRight -
                    prevRight +
                    Math.min(currentLeft + prevRight, currentNum),
            );
            const newsubRight = Math.max(
                subLeft + currentRight,
                subRight + currentRight,
            );
            subLeft = newsubLeft;
            subRight = newsubRight;
        }

        prevLeft = currentLeft;
        prevRight = currentRight;
        prevNum = currentNum;
    }

    return Math.max(subLeft, subRight);
}
