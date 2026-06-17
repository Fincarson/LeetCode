class Solution {
    public Node cloneTree(Node root) {
        if (root == null) {
            return root;
        }

        Node newRoot = new Node(root.val);
        // Here we used the ArrayDeque instead of the Queue class,
        //   which is a more efficient implementation of queue data structure.
        Deque<Node[]> stack = new ArrayDeque<>();

        // Starting point to kick off the DFS visits.
        stack.addLast(new Node[]{root, newRoot});

        while (!stack.isEmpty()) {
            Node[] nodePair = stack.pop();
            Node oldNode = nodePair[0];
            Node newNode = nodePair[1];
            for (Node childNode : oldNode.children) {
                Node newChildNode = new Node(childNode.val);

                // Make a copy for each child node.
                newNode.children.add(newChildNode);

                // Schedule a visit to copy the child nodes of each child node.
                stack.push(new Node[]{childNode, newChildNode});
            }
        }

        return newRoot;
    }
}
