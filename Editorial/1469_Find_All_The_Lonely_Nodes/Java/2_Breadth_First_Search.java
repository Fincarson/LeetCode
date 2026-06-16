class Solution {
    public List<Integer> getLonelyNodes(TreeNode root) {
        List<Integer> ans = new ArrayList<>();
        
        Queue<Pair<TreeNode, Boolean>> q = new LinkedList<>();
        q.add(new Pair(root, false));

        while (!q.isEmpty()) {
            Pair<TreeNode, Boolean> qFront = q.remove();
            
            TreeNode currNode = qFront.getKey();
            Boolean isLonely = qFront.getValue();

            if (isLonely) {
                ans.add(currNode.val);
            }
            
            if (currNode.right != null) {
                q.add(new Pair(currNode.right, currNode.left == null));
            }

            if (currNode.left != null) {
                q.add(new Pair(currNode.left, currNode.right == null));
            }
        }
        
        return ans;
    }
}
