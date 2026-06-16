class Solution {

    public int pathSum(int[] nums) {
        // Store the node values in a hashmap, using coordinates as the key.
        Map<Integer, Integer> map = new HashMap<>();
        for (int element : nums) {
            int coordinates = element / 10;
            int value = element % 10;
            map.put(coordinates, value);
        }

        // Initialize the BFS queue and start with the root node.
        Queue<Pair<Integer, Integer>> q = new LinkedList<>();
        int totalSum = 0;

        int rootCoordinates = nums[0] / 10;
        q.add(
            new Pair<Integer, Integer>(
                rootCoordinates,
                map.get(rootCoordinates)
            )
        );

        while (!q.isEmpty()) {
            Pair<Integer, Integer> current = q.poll();
            int coordinates = current.getKey();
            int currentSum = current.getValue();
            int level = coordinates / 10;
            int position = coordinates % 10;

            // Find the left and right child coordinates.
            int left = (level + 1) * 10 + position * 2 - 1;
            int right = (level + 1) * 10 + position * 2;

            // If it's a leaf node (no left and right children), add currentSum to totalSum.
            if (!map.containsKey(left) && !map.containsKey(right)) {
                totalSum += currentSum;
            }

            // Add the left child to the queue if it exists.
            if (map.containsKey(left)) {
                q.add(
                    new Pair<Integer, Integer>(left, currentSum + map.get(left))
                );
            }

            // Add the right child to the queue if it exists.
            if (map.containsKey(right)) {
                q.add(
                    new Pair<Integer, Integer>(
                        right,
                        currentSum + map.get(right)
                    )
                );
            }
        }

        return totalSum;
    }
}
