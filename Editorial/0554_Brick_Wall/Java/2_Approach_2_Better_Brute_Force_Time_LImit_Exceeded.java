public class Solution {
    public int leastBricks(List < List < Integer >> wall) {
        int[] pos = new int[wall.size()];
        int sum = 0, res = Integer.MAX_VALUE;
        for (int el: wall.get(0))
            sum += el;
        while (sum != 0) {
            int count = 0, mini = Integer.MAX_VALUE;
            for (int i = 0; i < wall.size(); i++) {
                List < Integer > row = wall.get(i);
                if (row.get(pos[i]) != 0) {
                    count++;
                } else
                    pos[i]++;
                mini = Math.min(mini, row.get(pos[i]));
            }
            for (int i = 0; i < wall.size(); i++) {
                List < Integer > row = wall.get(i);
                row.set(pos[i], row.get(pos[i]) - mini);
            }
            sum -= mini;
            res = Math.min(res, count);
        }
        return res;
    }
}
