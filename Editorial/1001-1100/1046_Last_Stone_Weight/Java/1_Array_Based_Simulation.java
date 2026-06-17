class Solution {
    
    private int removeLargest(List<Integer> stones) {
        int indexOfLargest = stones.indexOf(Collections.max(stones));
        int result = stones.get(indexOfLargest);
        stones.set(indexOfLargest, stones.get(stones.size() - 1));
        stones.remove(stones.size() - 1);
        return result;
    }

    public int lastStoneWeight(int[] stones) {
        List<Integer> stoneList = new ArrayList<>();
        for (int weight : stones) {
            stoneList.add(weight);
        }

        while (stoneList.size() > 1) {
            int stone1 = removeLargest(stoneList);
            int stone2 = removeLargest(stoneList);
            if (stone1 != stone2) {
                stoneList.add(stone1 - stone2);
            }
        }

        return !stoneList.isEmpty() ? stoneList.remove(0) : 0;
    }
}
