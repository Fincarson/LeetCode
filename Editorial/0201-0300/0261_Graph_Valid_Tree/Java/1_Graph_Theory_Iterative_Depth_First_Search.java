// Create a new list of lists.
List<List<Integer>> adjacencyList = new ArrayList<>();
// Initialise an empty list for each node.
for (int i = 0; i < n; i++) {
    adjacencyList.add(new ArrayList<>());
}
// Go through the edge list, populating the adjacency list.
for (int[] edge : edges) {
    adjacencyList.get(edge[0]).add(edge[1]);
    adjacencyList.get(edge[1]).add(edge[0]);
}
