class MRUQueue {

    private int totalElements;
    private int BUCKET_SIZE;
    List<List<Integer>> data = new ArrayList<>();
    List<Integer> index = new ArrayList<>();

    public MRUQueue(int n) {
        this.totalElements = n;
        this.BUCKET_SIZE = (int) Math.sqrt(n);
        for (int number = 1; number <= n; ++number) {
            int bucketIndex = (number - 1) / BUCKET_SIZE;
            if (bucketIndex == data.size()) {
                data.add(new ArrayList<>());
                index.add(number);
            }
            data.get(data.size() - 1).add(number);
        }
    }

    public int fetch(int k) {
        int bucketIndex = upperBound(index, k) - 1;
        int element = data.get(bucketIndex).get(k - index.get(bucketIndex));
        data.get(bucketIndex).remove(k - index.get(bucketIndex));

        for (int i = bucketIndex + 1; i < index.size(); ++i) {
            index.set(i, index.get(i) - 1);
        }

        if (data.get(data.size() - 1).size() >= BUCKET_SIZE) {
            data.add(new ArrayList<>());
            index.add(totalElements);
        }
        data.get(data.size() - 1).add(element);

        if (data.get(bucketIndex).isEmpty()) {
            data.remove(bucketIndex);
            index.remove(bucketIndex);
        }
        return element;
    }

    public int upperBound(List<Integer> nums, int target) {
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums.get(mid) > target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}
