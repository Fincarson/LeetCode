class FenwickTree {

    private int[] tree;

    public FenwickTree(int size) {
        this.tree = new int[size + 1];
    }

    public int sum(int index) {
        int result = 0;
        while (index > 0) {
            result += tree[index];
            index = index & (index - 1);
        }
        return result;
    }

    public void insert(int index, int value) {
        index += 1;
        while (index < tree.length) {
            tree[index] += value;
            index += index & -index;
        }
    }
}

class MRUQueue {

    private int size;
    private FenwickTree tree;
    private int[] values;

    public MRUQueue(int n) {
        this.size = n;
        this.tree = new FenwickTree(n + 2000);
        this.values = new int[n + 2000];
        for (int i = 0; i < n; ++i) {
            this.tree.insert(i, 1);
            this.values[i] = i + 1;
        }
    }

    public int fetch(int k) {
        int low = 0, high = size;
        while (low < high) {
            int mid = (low + high) >> 1;
            if (this.tree.sum(mid) < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        this.tree.insert(low - 1, -1);
        this.tree.insert(size, 1);
        this.values[size] = this.values[low - 1];
        this.size++;

        return this.values[low - 1];
    }
}
