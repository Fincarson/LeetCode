using vv = vector<vector<int>>;

class Solution {
public:
    vv getSkyline(vv& buildings) {
        // Pass `buildings` on to the recursive divide-and-conquer function.
        return divideAndConquer(buildings, 0, buildings.size() - 1);
    }
    // Recursively divide buildings and merge the skylines.
    vv divideAndConquer(vv& buildings, int left, int right) {
        // If the given array of buildings contains only 1 building,
        // we can directly return the corresponding skyline.
        if (left == right) {
            return {{buildings[left][0], buildings[left][2]}, {buildings[left][1], 0}};
        }

        // Otherwise, recursively divide the buildings and merge the skylines.
        int mid = left + (right - left) / 2;
        vv leftSkyline = divideAndConquer(buildings, left, mid);
        vv rightSkyline = divideAndConquer(buildings, mid + 1, right);
        return mergeSkylines(leftSkyline, rightSkyline);
    }
    
    // Merge two skylines into one.
    vv mergeSkylines(vv& left, vv& right) {
        int leftPos = 0, rightPos = 0;
        int leftPrevHeight = 0, rightPrevHeight = 0;
        int curY = 0, curX = 0;
        vv answer;

        // Process both skylines in order of increasing X value.
        while (leftPos < left.size() && rightPos < right.size()) {
            // For each of the three possible cases,
            // update the current position and previous heights.
            int nextLeftX = left[leftPos][0], nextRightX = right[rightPos][0];
            if (nextLeftX < nextRightX) {
                curX = nextLeftX;
                curY = max(left[leftPos][1], rightPrevHeight);
                leftPrevHeight = left[leftPos++][1];
            } else if (nextLeftX > nextRightX) {
                curX = nextRightX;
                curY = max(right[rightPos][1], leftPrevHeight);
                rightPrevHeight = right[rightPos++][1];
            } else {
                curX = nextLeftX;
                curY = max(left[leftPos][1], right[rightPos][1]);
                leftPrevHeight = left[leftPos++][1];
                rightPrevHeight = right[rightPos++][1];
            }

            // If the height has changed, add the skyline point to our answer.
            if (answer.empty() || curY != answer.back()[1]) {
                answer.push_back({curX, curY});
            }
        }

        // If we have reached the end of one of the skylines,
        // append the other skyline's remaining points to our answer. 
        while (leftPos < left.size()) {
            answer.push_back(left[leftPos++]);
        }
        while (rightPos < right.size()) {
            answer.push_back(right[rightPos++]);
        }
        return answer;
    }
};
