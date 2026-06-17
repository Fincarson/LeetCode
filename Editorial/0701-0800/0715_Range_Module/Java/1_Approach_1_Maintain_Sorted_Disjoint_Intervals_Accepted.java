class RangeModule {

    class Interval {

        int start;
        int end;

        public Interval(int start, int end) {
            this.start = start;
            this.end = end;
        }
    }

    private List<Interval> intervals;

    public RangeModule() {
        intervals = new ArrayList<>();
    }

    public void addRange(int left, int right) {
        List<Interval> result = new ArrayList<>();
        int n = intervals.size(), cur = 0;
        for (; cur < n; cur++) {
            Interval interval = intervals.get(cur);
            if (interval.end < left) {
                result.add(interval);
            } else if (interval.start > right) {
                result.add(new Interval(left, right));
                break;
            } else {
                left = Math.min(left, interval.start);
                right = Math.max(right, interval.end);
            }
        }
        if (cur == n) {
            result.add(new Interval(left, right));
        }
        while (cur < n) result.add(intervals.get(cur++));
        intervals = result;
    }

    public boolean queryRange(int left, int right) {
        int l = 0, r = intervals.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            Interval interval = intervals.get(mid);
            if (interval.start >= right) {
                r = mid - 1;
            } else if (interval.end <= left) {
                l = mid + 1;
            } else {
                return interval.start <= left && interval.end >= right;
            }
        }
        return false;
    }

    public void removeRange(int left, int right) {
        List<Interval> result = new ArrayList<>();
        int n = intervals.size(), cur = 0;
        for (; cur < n; cur++) {
            Interval interval = intervals.get(cur);
            if (interval.end <= left) {
                result.add(interval);
            } else if (interval.start >= right) {
                result.add(interval);
            } else {
                if (interval.start < left) result.add(
                    new Interval(interval.start, left)
                );
                if (interval.end > right) result.add(
                    new Interval(right, interval.end)
                );
            }
        }
        intervals = result;
    }
}
