public class Container {
    private int k;
    private PriorityQueue<int, int> st1;
    private PriorityQueue<int, int> st2;
    private Dictionary<int, int> cnt1;
    private Dictionary<int, int> cnt2;
    private Dictionary<int, int> del1;
    private Dictionary<int, int> del2;
    private int st1Size;
    private int st2Size;
    private long sm;

    public Container(int k) {
        this.k = k;
        this.st1 = new PriorityQueue<int, int>();
        this.st2 = new PriorityQueue<int, int>();
        this.cnt1 = new Dictionary<int, int>();
        this.cnt2 = new Dictionary<int, int>();
        this.del1 = new Dictionary<int, int>();
        this.del2 = new Dictionary<int, int>();
        this.st1Size = 0;
        this.st2Size = 0;
        this.sm = 0;
    }

    private static void Inc(Dictionary<int, int> dict, int key) {
        if (dict.TryGetValue(key, out int v))
            dict[key] = v + 1;
        else
            dict[key] = 1;
    }

    private static void Dec(Dictionary<int, int> dict, int key) {
        int v = dict[key] - 1;
        if (v == 0)
            dict.Remove(key);
        else
            dict[key] = v;
    }

    private void Prune1() {
        while (st1.Count > 0) {
            int x = st1.Peek();
            if (del1.TryGetValue(x, out int d) && d > 0) {
                st1.Dequeue();
                if (d == 1)
                    del1.Remove(x);
                else
                    del1[x] = d - 1;
            } else {
                break;
            }
        }
    }

    private void Prune2() {
        while (st2.Count > 0) {
            int x = st2.Peek();
            if (del2.TryGetValue(x, out int d) && d > 0) {
                st2.Dequeue();
                if (d == 1)
                    del2.Remove(x);
                else
                    del2[x] = d - 1;
            } else {
                break;
            }
        }
    }

    private int ExtractMax1() {
        Prune1();
        int x = st1.Dequeue();
        Dec(cnt1, x);
        st1Size--;
        sm -= x;
        return x;
    }

    private int ExtractMin2() {
        Prune2();
        int x = st2.Dequeue();
        Dec(cnt2, x);
        st2Size--;
        return x;
    }

    private int Min2() {
        Prune2();
        return st2.Peek();
    }

    private void Insert1(int x) {
        st1.Enqueue(x, -x);
        Inc(cnt1, x);
        st1Size++;
        sm += x;
    }

    private void Insert2(int x) {
        st2.Enqueue(x, x);
        Inc(cnt2, x);
        st2Size++;
    }

    private void Adjust() {
        while (st1Size < k && st2Size > 0) {
            int x = ExtractMin2();
            Insert1(x);
        }
        while (st1Size > k) {
            int x = ExtractMax1();
            Insert2(x);
        }
    }

    // insert element x
    public void Add(int x) {
        if (st2Size > 0) {
            int mn = Min2();
            if (x >= mn)
                Insert2(x);
            else
                Insert1(x);
        } else {
            Insert1(x);
        }
        Adjust();
    }

    // delete element x
    public void Erase(int x) {
        if (cnt1.TryGetValue(x, out int c1) && c1 > 0) {
            Dec(cnt1, x);
            st1Size--;
            sm -= x;
            Inc(del1, x);
        } else {
            Dec(cnt2, x);
            st2Size--;
            Inc(del2, x);
        }
        Adjust();
    }

    // sum of the first k smallest elements
    public long Sum() {
        return sm;
    }
}

public class Solution {
    public long MinimumCost(int[] nums, int k, int dist) {
        int n = nums.Length;
        Container cnt = new Container(k - 2);
        for (int i = 1; i < k - 1; i++) {
            cnt.Add(nums[i]);
        }

        long ans = cnt.Sum() + nums[k - 1];
        // sliding window
        for (int i = k; i < n; i++) {
            int j = i - dist - 1;
            if (j > 0) {
                cnt.Erase(nums[j]);
            }
            cnt.Add(nums[i - 1]);
            ans = Math.Min(ans, cnt.Sum() + nums[i]);
        }

        return ans + nums[0];
    }
}
