public class Solution {
    public int MaxWalls(int[] robots, int[] distance, int[] walls) {
        int n = robots.Length;
        int[][] robotDist = new int [n][];
        for (int i = 0; i < n; i++) {
            robotDist[i] = new int[] { robots[i], distance[i] };
        }
        Array.Sort(robotDist, (a, b) => a[0].CompareTo(b[0]));
        Array.Sort(walls);

        int m = walls.Length;
        int rightPtr = 0, leftPtr = 0, curPtr = 0, robotPtr = 0;

        int prevLeft = 0, prevRight = 0, prevNum = 0;
        int subLeft = 0, subRight = 0;

        for (int i = 0; i < n; i++) {
            int robotPos = robotDist[i][0];
            int robotDistVal = robotDist[i][1];

            while (rightPtr < m && walls[rightPtr] <= robotPos) {
                rightPtr++;
            }
            int pos1 = rightPtr;

            while (curPtr < m && walls[curPtr] < robotPos) {
                curPtr++;
            }
            int pos2 = curPtr;

            int leftBound = robotPos - robotDistVal;
            if (i >= 1) {
                leftBound =
                    Math.Max(robotPos - robotDistVal, robotDist[i - 1][0] + 1);
            }
            while (leftPtr < m && walls[leftPtr] < leftBound) {
                leftPtr++;
            }
            int leftPos = leftPtr;
            int currentLeft = pos1 - leftPos;

            int rightBound = robotPos + robotDistVal;
            if (i < n - 1) {
                rightBound =
                    Math.Min(robotPos + robotDistVal, robotDist[i + 1][0] - 1);
            }
            while (rightPtr < m && walls[rightPtr] <= rightBound) {
                rightPtr++;
            }
            int rightPos = rightPtr;
            int currentRight = rightPos - pos2;

            int currentNum = 0;
            if (i > 0) {
                while (robotPtr < m && walls[robotPtr] < robotDist[i - 1][0]) {
                    robotPtr++;
                }
                int pos3 = robotPtr;
                currentNum = pos1 - pos3;
            }

            if (i == 0) {
                subLeft = currentLeft;
                subRight = currentRight;
            } else {
                int newsubLeft =
                    Math.Max(subLeft + currentLeft,
                             subRight - prevRight +
                                 Math.Min(currentLeft + prevRight, currentNum));
                int newsubRight =
                    Math.Max(subLeft + currentRight, subRight + currentRight);
                subLeft = newsubLeft;
                subRight = newsubRight;
            }

            prevLeft = currentLeft;
            prevRight = currentRight;
            prevNum = currentNum;
        }

        return Math.Max(subLeft, subRight);
    }
}
