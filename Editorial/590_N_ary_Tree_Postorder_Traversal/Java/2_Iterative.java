class Solution {

    public List<Integer> postorder(Node root) {
        List<Integer> result = new ArrayList<>();

        // If the root is null, return the empty list
        if (root == null) return result;

        Stack<Node> stack = new Stack<>();
        stack.add(root);

        // Traverse the tree using the stack
        while (!stack.isEmpty()) {
            Node currentNode = stack.pop();

            result.add(currentNode.val);
            // Push all the children of the current node to the stack
            for (Node child : currentNode.children) stack.add(child);
        }

        // Reverse the result list to get the correct postorder traversal
        Collections.reverse(result);
        return result;
    }
}
