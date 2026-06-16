class Pair<K, V> {
    K key;
    V value;

    Pair(K a, V b) {
        this.key = a;
        this.value = b;
    }

    public K getKey() {
        return this.key;
    }

    public V getValue() {
        return this.value;
    }
}

class Solution {
    public void flatten(TreeNode root) {
        // Handle the null scenario
        if (root == null) {
            return;
        }

        int START = 1, END = 2;

        TreeNode tailNode = null;
        Stack<Pair<TreeNode, Integer>> stack = new Stack<
            Pair<TreeNode, Integer>
        >();
        stack.push(new Pair<TreeNode, Integer>(root, START));

        while (!stack.isEmpty()) {
            Pair<TreeNode, Integer> nodeData = stack.pop();
            TreeNode currentNode = nodeData.getKey();
            int recursionState = nodeData.getValue();

            // We reached a leaf node. Record this as a tail
            // node and move on.
            if (currentNode.left == null && currentNode.right == null) {
                tailNode = currentNode;
                continue;
            }

            // If the node is in the START state, it means we still
            // haven't processed it's left child yet.
            if (recursionState == START) {
                // If the current node has a left child, we add it
                // to the stack AFTER adding the current node again
                // to the stack with the END recursion state.
                if (currentNode.left != null) {
                    stack.push(new Pair<TreeNode, Integer>(currentNode, END));
                    stack.push(
                        new Pair<TreeNode, Integer>(currentNode.left, START)
                    );
                } else if (currentNode.right != null) {
                    // In case the current node didn't have a left child
                    // we will add it's right child
                    stack.push(
                        new Pair<TreeNode, Integer>(currentNode.right, START)
                    );
                }
            } else {
                // If the current node is in the END recursion state,
                // that means we did process one of it's children. Left
                // if it existed, else right.
                TreeNode rightNode = currentNode.right;

                // If there was a left child, there must have been a leaf
                // node and so, we would have set the tailNode
                if (tailNode != null) {
                    // Establish the proper connections.
                    tailNode.right = currentNode.right;
                    currentNode.right = currentNode.left;
                    currentNode.left = null;
                    rightNode = tailNode.right;
                }

                if (rightNode != null) {
                    stack.push(new Pair<TreeNode, Integer>(rightNode, START));
                }
            }
        }
    }
}
