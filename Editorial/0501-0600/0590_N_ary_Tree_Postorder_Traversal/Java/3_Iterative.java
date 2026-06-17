class Solution {

    public List<Integer> postorder(Node root) {
        List<Integer> result = new ArrayList<>();

        // If the root is null, return the empty list
        if (root == null) return result;

        Stack<Node> nodeStack = new Stack<>(); // Stack for traversal
        Stack<Node> reverseStack = new Stack<>(); // Stack to reverse the order

        nodeStack.push(root);

        // Traverse the tree using the nodeStack
        while (!nodeStack.isEmpty()) {
            Node currentNode = nodeStack.pop();
            reverseStack.push(currentNode);

            // Push all the children of the current node to nodeStack
            for (Node child : currentNode.children) {
                nodeStack.push(child);
            }
        }

        // Pop nodes from reverseStack and add their values to the result list
        while (!reverseStack.isEmpty()) {
            Node currentNode = reverseStack.pop();
            result.add(currentNode.val);
        }

        return result;
    }
}
