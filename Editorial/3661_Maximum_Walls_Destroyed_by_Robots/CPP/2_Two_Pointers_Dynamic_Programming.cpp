class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance,
                 vector<int>& walls) {
        int n = robots.size();
        vector<int> left(n, 0), right(n, 0), num(n, 0);
        unordered_map<int, int> robotsToDistance;

        for (int i = 0; i < n; i++) {
            robotsToDistance[robots[i]] = distance[i];
        }

        sort(robots.begin(), robots.end());
        sort(walls.begin(), walls.end());

        int m = walls.size();
        int rightPtr = 0, leftPtr = 0, curPtr = 0, robotPtr = 0;

        for (int i = 0; i < n; i++) {
            // rightPtr finds the position of the first element greater than
            // robots[i] (corresponding to upper_bound)
            while (rightPtr < m && walls[rightPtr] <= robots[i]) {
                rightPtr++;
            }
            int pos1 = rightPtr;

            // curPtr finds the position of the first element >= robots[i]
            // (corresponding to lower_bound, used for calculating right[i])
            while (curPtr < m && walls[curPtr] < robots[i]) {
                curPtr++;
            }
            int pos2 = curPtr;

            // leftPtr finds the first wall >= the left boundary
            int leftBound = (i >= 1)
                                ? max(robots[i] - robotsToDistance[robots[i]],
                                      robots[i - 1] + 1)
                                : robots[i] - robotsToDistance[robots[i]];
            while (leftPtr < m && walls[leftPtr] < leftBound) {
                leftPtr++;
            }
            int leftPos = leftPtr;
            left[i] = pos1 - leftPos;

            // Count the number of walls that can be reached on the right side
            // The right boundary needs to consider the overlapping area with
            // the next robot
            int rightBound = (i < n - 1)
                                 ? min(robots[i] + robotsToDistance[robots[i]],
                                       robots[i + 1] - 1)
                                 : robots[i] + robotsToDistance[robots[i]];
            // Find the first wall greater than the right boundary
            while (rightPtr < m && walls[rightPtr] <= rightBound) {
                rightPtr++;
            }
            int rightPos = rightPtr;
            right[i] = rightPos - pos2;

            if (i == 0) {
                continue;
            }
            // robotPtr finds the position of the previous robot
            while (robotPtr < m && walls[robotPtr] < robots[i - 1]) {
                robotPtr++;
            }
            int pos3 = robotPtr;
            num[i] = pos1 - pos3;
        }

        int subLeft = left[0], subRight = right[0];
        for (int i = 1; i < n; i++) {
            int currentLeft =
                max(subLeft + left[i], subRight - right[i - 1] +
                                           min(left[i] + right[i - 1], num[i]));
            int currentRight = max(subLeft + right[i], subRight + right[i]);
            subLeft = currentLeft;
            subRight = currentRight;
        }
        return max(subLeft, subRight);
    }
};
