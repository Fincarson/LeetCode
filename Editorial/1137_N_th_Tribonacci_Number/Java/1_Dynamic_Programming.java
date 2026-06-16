public class Solution {
    private Map<Integer, Integer> dp = new HashMap<>(){{
            put(0, 0);
            put(1, 1);
            put(2, 1);
    }};
    
    private int dfs(int i) {
        if (dp.containsKey(i)) {
            return dp.get(i);
        }
        
        int answer = dfs(i - 1) + dfs(i - 2) + dfs(i - 3);
        dp.put(i, answer);
        return answer;
    }
    
    public int tribonacci(int n) {
        return dfs(n);
    }
}
