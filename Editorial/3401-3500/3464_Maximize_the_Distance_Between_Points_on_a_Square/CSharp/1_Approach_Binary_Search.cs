public class Solution {
    public int MaxDistance(int side, int[][] points, int k) {
        List<long> arr = new List<long>();

        foreach (var p in points) {
            int x = p[0], y = p[1];
            if (x == 0) {
                arr.Add(y);
            } else if (y == side) {
                arr.Add(side + (long)x);
            } else if (x == side) {
                arr.Add(side * 3L - y);
            } else {
                arr.Add(side * 4L - x);
            }
        }
        arr.Sort();

        long lo = 1, hi = side;
        int ans = 0;

        while (lo <= hi) {
            long mid = (lo + hi) / 2;
            if (Check(arr, side, k, mid)) {
                lo = mid + 1;
                ans = (int)mid;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }

    private bool Check(List<long> arr, int side, int k, long limit) {
        long perimeter = side * 4L;

        foreach (long start in arr) {
            long end = start + perimeter - limit;
            long cur = start;

            for (int i = 0; i < k - 1; i++) {
                int idx = LowerBound(arr, cur + limit);
                if (idx == arr.Count || arr[idx] > end) {
                    cur = -1;
                    break;
                }
                cur = arr[idx];
            }

            if (cur >= 0) {
                return true;
            }
        }
        return false;
    }

    private int LowerBound(List<long> arr, long target) {
        int left = 0, right = arr.Count;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
}
