// Definition for singly-linked list.
// public class ListNode {
//     int val;
//     ListNode next;
//     ListNode(int x) {
//         val = x;
//         next = null;
//     }
// }
import java.util.ArrayList;
import java.util.Collections;

public class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        ArrayList<Integer> nodes = new ArrayList<>();
        ListNode head = new ListNode(0);
        ListNode point = head;
        for (ListNode l : lists) {
            while (l != null) {
                nodes.add(l.val);
                l = l.next;
            }
        }
        Collections.sort(nodes);
        for (int x : nodes) {
            point.next = new ListNode(x);
            point = point.next;
        }
        return head.next;
    }
}
