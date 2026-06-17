class Solution:

    def furthestBuilding(self, heights: List[int], bricks: int, ladders: int) -> int:
        
        # Helper function to check whether or not the specified building is reachable
        # from the first building with the bricks and ladders we have.
        def is_reachable(building_index):
            # Make a sorted list of all the climbs needed to get to the given building.
            climbs = []
            for h1, h2 in zip(heights[:building_index], heights[1:building_index + 1]):
                if h2 - h1 > 0:
                    climbs.append(h2 - h1)
            climbs.sort()
            # Check whether or not we have enough bricks and ladders to cover all
            # of these climbs. Bricks will be used before ladders.
            bricks_remaining = bricks
            ladders_remaining = ladders
            for climb in climbs:
                # If there are enough bricks left, use those.
                if climb <= bricks_remaining:
                    bricks_remaining -= climb
                # Otherwise, you'll have to use a ladder.
                elif ladders_remaining >= 1:
                    ladders_remaining -= 1
                # And if there are no ladders either, we can't reach buildingIndex.
                else:
                    return False
            return True
         
        # Do the binary search to find the final reachable building.
        lo = 0
        hi = len(heights) - 1
        while lo < hi:
            mid = lo + (hi - lo + 1) // 2
            if is_reachable(mid):
                lo = mid
            else:
                hi = mid - 1
        return hi # Note that return lo would be equivalent.
