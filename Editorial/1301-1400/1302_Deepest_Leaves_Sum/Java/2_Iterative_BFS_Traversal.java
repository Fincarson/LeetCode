class Solution {
  public int deepestLeavesSum(TreeNode root) {
    int deepestSum = 0, depth = 0, currDepth;
    Deque<Pair<TreeNode, Integer>> queue = new ArrayDeque();
    queue.offer(new Pair(root, 0));

    while (!queue.isEmpty()) {
      Pair<TreeNode, Integer> p = queue.poll();
      root = p.getKey();
      currDepth = p.getValue();

      if (root.left == null && root.right == null) {
        // if this leaf is the deepest one seen so far
        if (depth < currDepth) {
          deepestSum = root.val;      // start new sum
          depth = currDepth;          // note new depth    
        } else if (depth == currDepth) {
          // if there were already leaves at this depth
          deepestSum += root.val;     // update existing sum    
        }
      } else {
        if (root.left != null) {
          queue.offer(new Pair(root.left, currDepth + 1));
        }
        if (root.right != null) {
          queue.offer(new Pair(root.right, currDepth + 1));
        }
      }
    }
    return deepestSum;
  }
}
