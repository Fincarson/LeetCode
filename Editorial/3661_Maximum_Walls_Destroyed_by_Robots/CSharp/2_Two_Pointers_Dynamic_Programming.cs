public class Solution {
    public int MaxWalls(int[] robots, int[] distance, int[] walls) {
        int n = robots.Length;
        int[] left = new int[n];
        int[] right = new int[n];
        int[] num = new int[n];
        Dictionary<int, int> robotsToDistance = new Dictionary<int, int>();

        for (int i = 0; i < n; i++) {
            robotsToDistance[robots[i]] = distance[i];
        }

        Array.Sort(robots);
        Array.Sort(walls);

        int m = walls.Length;
        int rightPtr = 0, leftPtr = 0, curPtr = 0, robotPtr = 0;

        for (int i = 0; i < n; i++) {
            while (rightPtr < m && walls[rightPtr] <= robots[i]) {
                rightPtr++;
            }
            int pos1 = rightPtr;

            while (curPtr < m && walls[curPtr] < robots[i]) {
                curPtr++;
            }
            int pos2 = curPtr;

            int leftBound = robots[i] - robotsToDistance[robots[i]];
            if (i >= 1) {
                leftBound = Math.Max(robots[i] - robotsToDistance[robots[i]],
                                     robots[i - 1] + 1);
            }
            while (leftPtr < m && walls[leftPtr] < leftBound) {
                leftPtr++;
            }
            int leftPos = leftPtr;
            left[i] = pos1 - leftPos;

            int rightBound = robots[i] + robotsToDistance[robots[i]];
            if (i < n - 1) {
                rightBound = Math.Min(robots[i] + robotsToDistance[robots[i]],
                                      robots[i + 1] - 1);
            }
            while (rightPtr < m && walls[rightPtr] <= rightBound) {
                rightPtr++;
            }
            int rightPos = rightPtr;
            right[i] = rightPos - pos2;

            if (i == 0) {
                continue;
            }
            while (robotPtr < m && walls[robotPtr] < robots[i - 1]) {
                robotPtr++;
            }
            int pos3 = robotPtr;
            num[i] = pos1 - pos3;
        }

        int subLeft = left[0], subRight = right[0];
        for (int i = 1; i < n; i++) {
            int currentLeft =
                Math.Max(subLeft + left[i],
                         subRight - right[i - 1] +
                             Math.Min(left[i] + right[i - 1], num[i]));
            int currentRight =
                Math.Max(subLeft + right[i], subRight + right[i]);
            subLeft = currentLeft;
            subRight = currentRight;
        }

        return Math.Max(subLeft, subRight);
    }
}
