class Solution {

    public PolyNode addPoly(PolyNode poly1, PolyNode poly2) {
        PolyNode p1 = poly1;
        PolyNode p2 = poly2;
        // initial dummy node
        PolyNode sum = new PolyNode();
        // maintain pointer to last node
        PolyNode current = sum;

        // Maintain two pointers
        while (p1 != null && p2 != null) {
            if (p1.power == p2.power) {
                if (p1.coefficient + p2.coefficient != 0) {
                    current.next = new PolyNode(
                        p1.coefficient + p2.coefficient,
                        p1.power
                    );
                    current = current.next;
                }
                p1 = p1.next;
                p2 = p2.next;
            } else if (p1.power > p2.power) {
                current.next = p1;
                p1 = p1.next;
                current = current.next;
            } else {
                current.next = p2;
                p2 = p2.next;
                current = current.next;
            }
        }
        if (p1 == null) {
            current.next = p2;
        } else {
            current.next = p1;
        }
        return sum.next;
    }
}
