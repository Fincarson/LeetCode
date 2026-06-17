class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        nodes_seen = set()
        current = head
        while current is not None:
            if current in nodes_seen:
                return True
            nodes_seen.add(current)
            current = current.next
        return False
