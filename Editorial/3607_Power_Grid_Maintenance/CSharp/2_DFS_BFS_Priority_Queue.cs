public class Vertex {
    public int vertexId;
    public bool offline = false;
    public int powerGridId = -1;

    public Vertex() {}

    public Vertex(int id) {
        this.vertexId = id;
    }
}

public class Graph {
    private Dictionary<int, List<int>> adj;
    private Dictionary<int, Vertex> vertices;

    public Graph() {
        this.adj = new Dictionary<int, List<int>>();
        this.vertices = new Dictionary<int, Vertex>();
    }

    public void AddVertex(int id, Vertex value) {
        this.vertices[id] = value;
        this.adj[id] = new List<int>();
    }

    public void AddEdge(int u, int v) {
        this.adj[u].Add(v);
        this.adj[v].Add(u);
    }

    public Vertex GetVertexValue(int id) {
        return this.vertices[id];
    }

    public List<int> GetConnectedVertices(int id) {
        return this.adj[id];
    }
}

public class Solution {
    private void Traverse(Vertex u, int powerGridId,
                          PriorityQueue<int, int> powerGrid, Graph graph) {
        u.powerGridId = powerGridId;
        powerGrid.Enqueue(u.vertexId, u.vertexId);
        foreach (int vid in graph.GetConnectedVertices(u.vertexId)) {
            Vertex v = graph.GetVertexValue(vid);
            if (v.powerGridId == -1) {
                Traverse(v, powerGridId, powerGrid, graph);
            }
        }
    }

    public int[] ProcessQueries(int c, int[][] connections, int[][] queries) {
        Graph graph = new Graph();
        for (int i = 0; i < c; i++) {
            Vertex v = new Vertex(i + 1);
            graph.AddVertex(i + 1, v);
        }

        foreach (int[] conn in connections) {
            graph.AddEdge(conn[0], conn[1]);
        }

        List<PriorityQueue<int, int>> powerGrids =
            new List<PriorityQueue<int, int>>();
        for (int i = 1, powerGridId = 0; i <= c; i++) {
            Vertex v = graph.GetVertexValue(i);
            if (v.powerGridId == -1) {
                PriorityQueue<int, int> powerGrid =
                    new PriorityQueue<int, int>();
                Traverse(v, powerGridId, powerGrid, graph);
                powerGrids.Add(powerGrid);
                powerGridId++;
            }
        }

        List<int> ans = new List<int>();
        foreach (int[] q in queries) {
            int op = q[0], x = q[1];
            if (op == 1) {
                Vertex vertex = graph.GetVertexValue(x);
                if (!vertex.offline) {
                    ans.Add(x);
                } else {
                    PriorityQueue<int, int> powerGrid =
                        powerGrids[vertex.powerGridId];
                    while (powerGrid.Count > 0 &&
                           graph.GetVertexValue(powerGrid.Peek()).offline) {
                        powerGrid.Dequeue();
                    }
                    ans.Add(powerGrid.Count > 0 ? powerGrid.Peek() : -1);
                }
            } else if (op == 2) {
                graph.GetVertexValue(x).offline = true;
            }
        }

        return ans.ToArray();
    }
}
