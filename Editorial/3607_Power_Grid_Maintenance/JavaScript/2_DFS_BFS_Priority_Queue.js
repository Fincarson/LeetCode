var processQueries = function (c, connections, queries) {
    const graph = Array.from({ length: c + 1 }, () => []);
    const vertices = Array.from({ length: c + 1 });

    for (let i = 0; i < c; i++) {
        vertices[i + 1] = {
            offline: false,
            powerGridId: -1,
            vertexId: i + 1,
        };
    }

    connections.forEach(([u, v]) => {
        graph[u].push(v);
        graph[v].push(u);
    });

    const powerGrids = new Array();

    for (let i = 1, powerGridId = 0; i <= c; i++) {
        if (vertices[i].powerGridId === -1) {
            const powerGrid = new MinPriorityQueue();

            const traverse = (u) => {
                u.powerGridId = powerGridId;

                powerGrid.enqueue(u.vertexId);

                for (const v of graph[u.vertexId].map((i) => vertices[i])) {
                    if (v.powerGridId === -1) {
                        traverse(v);
                    }
                }
            };

            traverse(vertices[i]);
            powerGrids.push(powerGrid);
            powerGridId += 1;
        }
    }

    const ans = [];

    for (const [op, x] of queries) {
        if (op === 1) {
            if (vertices[x].offline === false) {
                ans.push(x);
            } else {
                const powerGrid = powerGrids[vertices[x].powerGridId];
                while (
                    powerGrid.front() !== null &&
                    vertices[powerGrid.front()].offline === true
                ) {
                    powerGrid.dequeue();
                }

                ans.push(powerGrid.front() !== null ? powerGrid.front() : -1);
            }
        } else if (op === 2) {
            vertices[x].offline = true;
        }
    }

    return ans;
};
