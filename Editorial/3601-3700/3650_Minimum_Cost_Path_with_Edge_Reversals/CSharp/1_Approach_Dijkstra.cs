using System;
using System.Collections.Generic;

public class Solution {
    public int MinCost(int n, int[][] edges) {
        var g = new List<(int node, int weight)>[n];
        for (int i = 0; i < n; i++) {
            g[i] = new List<(int, int)>();
        }

        foreach (var e in edges) {
            int x = e[0], y = e[1], w = e[2];
            g[x].Add((y, w));
            g[y].Add((x, 2 * w));
        }

        int[] dist = new int[n];
        bool[] visited = new bool[n];
        Array.Fill(dist, int.MaxValue);
        dist[0] = 0;

        var pq = new PriorityQueue<(int dist, int node), int>();
        pq.Enqueue((0, 0), 0);

        while (pq.Count > 0) {
            var current = pq.Dequeue();
            int currentDist = current.dist;
            int x = current.node;

            if (x == n - 1) {
                return currentDist;
            }

            if (visited[x]) {
                continue;
            }
            visited[x] = true;
            foreach (var neighbor in g[x]) {
                int y = neighbor.node;
                int w = neighbor.weight;

                if (currentDist + w < dist[y]) {
                    dist[y] = currentDist + w;
                    pq.Enqueue((dist[y], y), dist[y]);
                }
            }
        }

        return -1;
    }
}
