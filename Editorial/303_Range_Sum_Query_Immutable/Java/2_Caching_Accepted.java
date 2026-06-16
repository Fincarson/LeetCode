private Map<Pair<Integer, Integer>, Integer> map = new HashMap<>();

public NumArray(int[] nums) {
    for (int i = 0; i < nums.length; i++) {
        int sum = 0;
        for (int j = i; j < nums.length; j++) {
            sum += nums[j];
            map.put(Pair.create(i, j), sum);
        }
    }
}

public int sumRange(int i, int j) {
    return map.get(Pair.create(i, j));
}
