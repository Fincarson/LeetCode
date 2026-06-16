class Solution {
    
    public int furthestBuilding(int[] heights, int bricks, int ladders) {
        // Do a binary search on the heights array to find the final reachable building.
        int lo = 0;
        int hi = heights.length - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            if (isReachable(mid, heights, bricks, ladders)) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        return hi; // Note that return lo would be equivalent.
    }
    
    private boolean isReachable(int buildingIndex, int[] heights, int bricks, int ladders) {
        // Make a list of all the climbs we need to do to reach buildingIndex.
        List<Integer> climbs = new ArrayList<>();
        for (int i = 0; i < buildingIndex; i++) {
            int h1 = heights[i];
            int h2 = heights[i + 1];
            if (h2 <= h1) {
                continue;
            }
            climbs.add(h2 - h1);
        }
        Collections.sort(climbs);
        
        // And now determine whether or not all of these climbs can be covered with the
        // given bricks and ladders.
        for (int climb : climbs) {
            // If there are bricks left, use those.
            if (climb <= bricks) {
                bricks -= climb;
            // Otherwise, you'll have to use a ladder.
            } else if (ladders >= 1) {
                ladders -= 1;
            // And if there are no ladders either, we can't reach buildingIndex.
            } else {
                return false;
            }
        }
        return true;
    }
}
