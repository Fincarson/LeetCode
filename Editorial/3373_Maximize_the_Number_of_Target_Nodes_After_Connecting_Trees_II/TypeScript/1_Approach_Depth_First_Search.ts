function maxTargetNodes(edges1: number[][], edges2: number[][]): number[] {
    function dfs(
        node: number,
        parent: number,
        depth: number,
        children: number[][],
        color: number[],
    ): number {
        let res = 1 - (depth % 2);
        color[node] = depth % 2;
        for (let child of children[node]) {
            if (child === parent) {
                continue;
            }
            res += dfs(child, node, depth + 1, children, color);
        }
        return res;
    }

    function build(edges: number[][], color: number[]): number[] {
        const n = edges.length + 1;
        const children: number[][] = Array.from({ length: n }, () => []);
        for (const [u, v] of edges) {
            children[u].push(v);
            children[v].push(u);
        }
        const res = dfs(0, -1, 0, children, color);
        return [res, n - res];
    }

    const n = edges1.length + 1;
    const m = edges2.length + 1;
    const color1: number[] = new Array(n).fill(0);
    const color2: number[] = new Array(m).fill(0);
    const count1 = build(edges1, color1);
    const count2 = build(edges2, color2);
    const res: number[] = new Array(n).fill(0);
    for (let i = 0; i < n; i++) {
        res[i] = count1[color1[i]] + Math.max(count2[0], count2[1]);
    }
    return res;
}
