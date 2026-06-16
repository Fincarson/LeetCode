import { Graph } from "@datastructures-js/graph";

interface Vertex {
    offline: boolean;
    powerGridId: number;
    vertexId: number;
}

function processQueries(
    c: number,
    connections: number[][],
    queries: number[][],
): number[] {
    const graph = new Graph<number, Vertex>();

    for (let i = 0; i < c; i++) {
        graph.addVertex(i + 1, {
            offline: false,
            powerGridId: -1,
            vertexId: i + 1,
        });
    }

    connections.forEach(([u, v]) => {
        graph.addEdge(u, v);
    });

    const getv = graph.getVertexValue.bind(graph);
    const powerGrids = new Array<MinPriorityQueue<number>>();

    for (let i = 1, powerGridId = 0; i <= c; i++) {
        const v = getv(i);

        if (v.powerGridId === -1) {
            const powerGrid = new MinPriorityQueue<number>();

            const traverse = (u: Vertex) => {
                u.powerGridId = powerGridId;

                powerGrid.enqueue(u.vertexId);

                for (const v of graph
                    .getConnectedVertices(u.vertexId)
                    .map(getv)) {
                    if (v.powerGridId === -1) {
                        traverse(v);
                    }
                }
            };

            traverse(v);
            powerGrids.push(powerGrid);
            powerGridId += 1;
        }
    }

    const ans: number[] = [];

    for (const [op, x] of queries) {
        if (op === 1) {
            if (getv(x).offline === false) {
                ans.push(x);
            } else {
                const powerGrid = powerGrids[getv(x).powerGridId];
                while (
                    powerGrid.front() !== null &&
                    getv(powerGrid.front()).offline === true
                ) {
                    powerGrid.dequeue();
                }

                ans.push(powerGrid.front() !== null ? powerGrid.front() : -1);
            }
        } else if (op === 2) {
            getv(x).offline = true;
        }
    }

    return ans;
}
