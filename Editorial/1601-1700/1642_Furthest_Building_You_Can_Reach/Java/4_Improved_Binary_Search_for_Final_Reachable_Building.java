class Solution {
    
    public int furthestBuilding(int[] heights, int bricks, int ladders) {
        // Make a sorted list of all the climbs.
        List<int[]> sortedClimbs = new ArrayList<>();
        for (int i = 0; i < heights.length - 1; i++) {
            int climb = heights[i + 1] - heights[i];
            if (climb <= 0) {
                continue;
            }
            sortedClimbs.add(new int[]{climb, i + 1});
        }
        Collections.sort(sortedClimbs, (a,b) -> a[0] - b[0]);
        
        // Now do the binary search, same as before.
        int lo = 0;
        int hi = heights.length - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            if (isReachable(mid, sortedClimbs, bricks, ladders)) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        return hi; // Note that return lo would be equivalent.
    }
    
    private boolean isReachable(int buildingIndex, List<int[]> climbs, int bricks, int ladders) {
        for (int[] climbEntry : climbs) {
            // Extract the information for this climb
            int climb = climbEntry[0];
            int index = climbEntry[1];
            // Check if this climb is within the range.
            if (index > buildingIndex) {
                continue;
            }
            // Allocate bricks if enough remain; otherwise, allocate a ladder if
            // at least one remains.
            if (climb <= bricks) {
                bricks -= climb;
            } else if (ladders >= 1) {
                ladders -= 1;
            } else {
                return false;
            }
        }
        return true;
    }
}
