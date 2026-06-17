class Node {
    name: string;
    timestamp: number;
    website: string;

    constructor(name: string, timestamp: number, website: string) {
        this.name = name;
        this.timestamp = timestamp;
        this.website = website;
    }
}

function mostVisitedPattern(
    username: string[],
    timestamp: number[],
    website: string[],
): string[] {
    let nodes = username.map(
        (name, i) => new Node(name, timestamp[i], website[i]),
    );
    nodes.sort((a, b) => a.timestamp - b.timestamp);

    let userVisits: { [key: string]: Node[] } = {};
    for (let node of nodes) {
        if (!userVisits[node.name]) {
            userVisits[node.name] = [];
        }
        userVisits[node.name].push(node);
    }

    let route: { [key: string]: number } = {};
    for (let visits of Object.values(userVisits)) {
        let tmp = new Set<string>();
        for (let i = 0; i < visits.length; i++) {
            for (let j = i + 1; j < visits.length; j++) {
                for (let k = j + 1; k < visits.length; k++) {
                    let path = [
                        visits[i].website,
                        visits[j].website,
                        visits[k].website,
                    ].join(",");
                    tmp.add(path);
                }
            }
        }
        for (let path of tmp) {
            route[path] = (route[path] || 0) + 1;
        }
    }

    let max = -1;
    let result = "";
    for (let path in route) {
        if (route[path] > max || (route[path] === max && path < result)) {
            max = route[path];
            result = path;
        }
    }
    return result.split(",");
}
