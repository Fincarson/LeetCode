public class Solution {
    private List<int> values = new List<int>();

    private void MapListToValues(ListNode head) {
        while (head != null) {
            this.values.Add(head.val);
            head = head.next;
        }
    }

    private TreeNode ConvertListToBST(int left, int right) {
        // Invalid case
        if (left > right) {
            return null;
        }

        // Middle element forms the root.
        int mid = (left + right) / 2;
        TreeNode node = new TreeNode(this.values[mid]);
        // Base case for when there is only one element left in the array
        if (left == right) {
            return node;
        }

        // Recursively form BST on the two halves
        node.left = this.ConvertListToBST(left, mid - 1);
        node.right = this.ConvertListToBST(mid + 1, right);
        return node;
    }

    public TreeNode SortedListToBST(ListNode head) {
        // Form an array out of the given linked list and then
        // use the array to form the BST.
        this.MapListToValues(head);
        // Convert the array to
        return this.ConvertListToBST(0, this.values.Count - 1);
    }
}
