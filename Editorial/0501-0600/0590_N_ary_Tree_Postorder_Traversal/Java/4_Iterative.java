class Solution {

    public List<Integer> postorder(Node root) {
        List<Integer> result = new ArrayList<>();
        // If the root is null, return the empty list
        if (root == null) return result;

        Stack<NodeVisitPair> nodeStack = new Stack<>();
        nodeStack.push(new NodeVisitPair(root, false));

        while (!nodeStack.isEmpty()) {
            NodeVisitPair currentPair = nodeStack.pop();

            if (currentPair.isVisited) {
                // If the node has been visited, add its value to the result
                result.add(currentPair.node.val);
            } else {
                // Mark the current node as visited and push it back to the stack
                currentPair.isVisited = true;
                nodeStack.push(currentPair);

                // Push all children to the stack in reverse order
                List<Node> children = currentPair.node.children;
                for (int i = children.size() - 1; i >= 0; i--) {
                    nodeStack.push(new NodeVisitPair(children.get(i), false));
                }
            }
        }

        return result;
    }

    // Helper class to pair a node with its visited status
    private class NodeVisitPair {

        Node node;
        boolean isVisited;

        NodeVisitPair(Node node, boolean isVisited) {
            this.node = node;
            this.isVisited = isVisited;
        }
    }
}
