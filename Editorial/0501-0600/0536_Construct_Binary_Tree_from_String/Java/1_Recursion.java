class Solution {
    public TreeNode str2tree(String s) {
        return this.str2treeInternal(s, 0).getKey();
    }
    
    public Pair<Integer, Integer> getNumber(String s, int index) {
        
        boolean isNegative = false;
        
        // A negative number
        if (s.charAt(index) == '-') {
            isNegative = true;
            index++;
        }
            
        int number = 0;
        while (index < s.length() && Character.isDigit(s.charAt(index))) {
            number = number * 10 + (s.charAt(index) - '0');
            index++;
        }
        
        return new Pair<Integer, Integer>(isNegative ? -number : number, index);
    } 
    
    public Pair<TreeNode, Integer> str2treeInternal(String s, int index) {
        
        if (index == s.length()) {
            return new Pair<TreeNode, Integer>(null, index);
        }
        
        // Start of the tree will always contain a number representing
        // the root of the tree. So we calculate that first.
        Pair<Integer, Integer> numberData = this.getNumber(s, index);
        int value = numberData.getKey();
        index = numberData.getValue();
        
        TreeNode node = new TreeNode(value);
        Pair<TreeNode, Integer> data;
        
        // Next, if there is any data left, we check for the first subtree
        // which according to the problem statement will always be the left child.
        if (index < s.length() && s.charAt(index) == '(') {
            data = this.str2treeInternal(s, index + 1);
            node.left = data.getKey();
            index = data.getValue();
        }
            
        
        // Indicates a right child
        if (node.left != null && index < s.length() && s.charAt(index) == '(') {
            data = this.str2treeInternal(s, index + 1);
            node.right = data.getKey();
            index = data.getValue();
        }
            
        
        return new Pair<TreeNode, Integer>(node, index < s.length() && s.charAt(index) == ')' ? index + 1 : index);
    }
}
