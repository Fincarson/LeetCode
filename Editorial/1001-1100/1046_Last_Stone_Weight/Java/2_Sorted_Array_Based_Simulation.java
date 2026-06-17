class Solution {
    public int lastStoneWeight(int[] stones) {
        List<Integer> stoneList = new ArrayList<>();
        for (int stone : stones) {
            stoneList.add(stone);
        }
        Collections.sort(stoneList);

        while (stoneList.size() > 1) {
            int stone1 = stoneList.remove(stoneList.size() - 1);
            int stone2 = stoneList.remove(stoneList.size() - 1);

            if (stone1 != stone2) {
                int newStone = stone1 - stone2;
                int index = Collections.binarySearch(stoneList, newStone);
                if (index < 0) {
                    stoneList.add(-index - 1, newStone);
                } else {
                    stoneList.add(index, newStone);
                }
            }
        }

        return !stoneList.isEmpty() ? stoneList.remove(0) : 0;
    }
}
