// find the middle of linked list [Problem 876]
// in 1->2->3->4->5->6 find 4 
ListNode slow = head, fast = head;
while (fast != null && fast.next != null) {
  slow = slow.next;
  fast = fast.next.next;
}
