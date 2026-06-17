class Solution:
    def addPoly(self, poly1: "PolyNode", poly2: "PolyNode") -> "PolyNode":
        sum_ = PolyNode()
        current = sum_
        table = {}

        # Calculate terms for sum
        self._process_nodes(table, poly1)
        self._process_nodes(table, poly2)

        # Iterate over sorted keys and build sum
        for key in sorted(table.keys(), reverse=True):
            current.next = PolyNode(table[key], key)
            current = current.next

        return sum_.next

    def _process_nodes(self, table, node):
        while node:
            if node.power in table:
                new_coefficient = node.coefficient + table[node.power]
                if new_coefficient == 0:
                    table.pop(node.power)
                else:
                    table[node.power] = new_coefficient
            else:
                table[node.power] = node.coefficient
            node = node.next
