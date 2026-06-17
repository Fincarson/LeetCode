class Solution:
    def garbageCollection(self, garbage, travel):
        # Store the prefix sum in travel itself.
        for i in range(1, len(travel)):
            travel[i] = travel[i - 1] + travel[i]

        # Dictionary to store garbage type to the last house index.
        garbageLastPos = {}
        ans = 0
        for i in range(len(garbage)):
            for c in garbage[i]:
                garbageLastPos[c] = i
            ans += len(garbage[i])

        garbageTypes = "MPG"
        for c in garbageTypes:
            # No travel time is required if the last house is at index 0.
            ans += (
                0
                if garbageLastPos.get(c, 0) == 0
                else travel[garbageLastPos.get(c) - 1]
            )

        return ans
