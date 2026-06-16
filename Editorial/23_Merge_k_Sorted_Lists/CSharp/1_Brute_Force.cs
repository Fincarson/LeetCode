public class Solution {
    public ListNode MergeKLists(ListNode[] lists) {
        List<int> nodes = new List<int>();
        ListNode head = new ListNode(0);
        ListNode point = head;
        foreach (ListNode listNode in lists) {
            ListNode list = listNode;
            while (list != null) {
                nodes.Add(list.val);
                list = list.next;
            }
        }

        nodes.Sort();
        foreach (int val in nodes) {
            point.next = new ListNode(val);
            point = point.next;
        }

        return head.next;
    }
}
