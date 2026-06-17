public class Solution {
    public String gameResult(ListNode head) {
        ListNode even = head;
        int evenPoints = 0;
        int oddPoints = 0;

        // Traverse through the linked list assigning points
        while (even != null) {
            ListNode odd = even.next;
            if (even.val > odd.val) {
                evenPoints += 1;
            } else {
                oddPoints += 1;
            }
            even = odd.next;
        }

        // Return the winning team
        if (oddPoints > evenPoints) {
            return "Odd";
        } else if (oddPoints < evenPoints) {
            return "Even";
        } else {
            return "Tie";
        }
    }
}
