class Solution {
    int[] team;
    int t;
    StringBuilder ans;
    public String findContestMatch(int n) {
        team = new int[n];
        t = 0;
        ans = new StringBuilder();
        write(n, Integer.numberOfTrailingZeros(n));
        return ans.toString();
    }

    public void write(int n, int round) {
        if (round == 0) {
            int w = Integer.lowestOneBit(t);
            team[t] = w > 0 ? n / w + 1 - team[t - w] : 1;
            ans.append("" + team[t++]);
        } else {
            ans.append("(");
            write(n, round - 1);
            ans.append(",");
            write(n, round - 1);
            ans.append(")");
        }
    }
}
