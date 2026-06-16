class Node {
    constructor(name, timestamp, website) {
        this.name = name;
        this.timestamp = timestamp;
        this.website = website;
    }
}

var mostVisitedPattern = function (username, timestamp, website) {
    let nodes = username.map(
        (name, i) => new Node(name, timestamp[i], website[i]),
    );
    nodes.sort((a, b) => a.timestamp - b.timestamp);

    let userVisits = {};
    for (let node of nodes) {
        if (!userVisits[node.name]) {
            userVisits[node.name] = [];
        }
        userVisits[node.name].push(node);
    }

    let route = {};
    for (let visits of Object.values(userVisits)) {
        let tmp = new Set();
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
};
