# find the middle of linked list [Problem 876]
# in 1->2->3->4->5->6 find 4
slow = fast = head
while fast and fast.next:
    slow = slow.next
    fast = fast.next.next
