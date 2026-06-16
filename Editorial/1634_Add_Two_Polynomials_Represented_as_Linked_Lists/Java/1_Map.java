class Solution {

    public PolyNode addPoly(PolyNode poly1, PolyNode poly2) {
        // Initialize dummy node and pointer to track the last node
        PolyNode sum = new PolyNode();
        PolyNode current = sum;

        // Use TreeMap with reverse order comparator
        Map<Integer, Integer> map = new TreeMap<>(Collections.reverseOrder());

        // Calculate terms for sum
        processNodes(map, poly1);
        processNodes(map, poly2);

        // Iterate over sorted keys and build sum
        for (int key : map.keySet()) {
            current.next = new PolyNode(map.get(key), key);
            current = current.next;
        }

        return sum.next;
    }

    private void processNodes(Map<Integer, Integer> map, PolyNode node) {
        while (node != null) {
            if (map.containsKey(node.power)) {
                int newCoefficient = node.coefficient + map.get(node.power);
                if (newCoefficient == 0) {
                    map.remove(node.power);
                } else {
                    map.put(node.power, newCoefficient);
                }
            } else {
                map.put(node.power, node.coefficient);
            }
            node = node.next;
        }
    }
}
