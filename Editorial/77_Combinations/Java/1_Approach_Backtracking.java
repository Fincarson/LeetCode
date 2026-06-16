public void backtrack(
    List<Integer> curr,
    int firstNum,
    List<List<Integer>> ans
) {
    if (curr.size() == k) {
        ans.add(new ArrayList<>(curr));
        return;
    }

    for (int num = firstNum; num <= n; num++) {
        curr.add(num);
        backtrack(curr, num + 1, ans);
        curr.remove(curr.size() - 1);
    }

    return;
}
