class Solution {
    public List<String> generateParenthesis(int n) {
        if (n == 0) {
            return new ArrayList(Arrays.asList(""));
        }

        List<String> answer = new ArrayList();
        for (int leftCount = 0; leftCount < n; ++leftCount) {
            List<String> leftStrings = generateParenthesis(leftCount);
            List<String> rightStrings = generateParenthesis(n - 1 - leftCount);
            for (String leftString : leftStrings)
                for (String rightString : rightStrings)
                    answer.add("(" + leftString + ")" + rightString);
        }
        return answer;
    }
}
