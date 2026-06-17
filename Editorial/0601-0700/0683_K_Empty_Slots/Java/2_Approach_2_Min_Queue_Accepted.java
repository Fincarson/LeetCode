class Solution {
    public int kEmptySlots(int[] flowers, int k) {
        int[] days = new int[flowers.length];
        for (int i = 0; i < flowers.length; i++) {
            days[flowers[i] - 1] = i + 1;
        }

        MinQueue<Integer> window = new MinQueue();
        int ans = days.length;

        for (int i = 0; i < days.length; i++) {
            int day = days[i];
            window.addLast(day);
            if (k <= i && i < days.length - 1) {
                window.pollFirst();
                if (k == 0 || days[i-k] < window.min() && days[i+1] < window.min()) {
                    ans = Math.min(ans, Math.max(days[i-k], days[i+1]));
                }
            }
        }

        return ans < days.length ? ans : -1;
    }
}

class MinQueue<E extends Comparable<E>> extends ArrayDeque<E> {
    Deque<E> mins;

    public MinQueue() {
        mins = new ArrayDeque<E>();
    }

    @Override
    public void addLast(E x) {
        super.addLast(x);
        while (mins.peekLast() != null &&
                x.compareTo(mins.peekLast()) < 0) {
            mins.pollLast();
        }
        mins.addLast(x);
    }

    @Override
    public E pollFirst() {
        E x = super.pollFirst();
        if (x == mins.peekFirst()) {
            mins.pollFirst();
        }
        return x;
    }

    public E min() {
        return mins.peekFirst();
    }
}
