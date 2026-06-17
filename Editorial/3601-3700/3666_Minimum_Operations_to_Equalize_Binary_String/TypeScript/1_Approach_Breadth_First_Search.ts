import { AvlTree, AvlTreeNode } from "@datastructures-js/binary-search-tree";

function minOperations(s: string, k: number): number {
    const n: number = s.length;
    let m: number = 0;
    const dist: number[] = new Array(n + 1).fill(Number.MAX_SAFE_INTEGER);

    const nodeTrees: AvlTree<number>[] = [
        new AvlTree<number>(),
        new AvlTree<number>(),
    ];
    for (let i = 0; i <= n; i++) {
        nodeTrees[i % 2].insert(i);
        if (i < n && s.charAt(i) === "0") {
            m++;
        }
    }

    const queue: number[] = new Array(n + 1);
    let head: number = 0,
        tail: number = 0;
    queue[tail++] = m;
    dist[m] = 0;
    nodeTrees[m % 2].remove(m);

    while (head < tail) {
        const currentM: number = queue[head++];
        const c1: number = Math.max(k - n + currentM, 0);
        const c2: number = Math.min(currentM, k);
        const lnode: number = currentM + k - 2 * c2;
        const rnode: number = currentM + k - 2 * c1;
        const currentTree: AvlTree<number> = nodeTrees[lnode % 2];

        let node: AvlTreeNode<number> | null = currentTree.upperBound(
            lnode,
            true,
        );
        while (node !== null) {
            const nodeValue: number = node.getValue();
            if (nodeValue > rnode) {
                break;
            }
            dist[nodeValue] = dist[currentM] + 1;
            queue[tail++] = nodeValue;

            const nextNode: AvlTreeNode<number> | null = currentTree.upperBound(
                nodeValue,
                false,
            );
            currentTree.remove(nodeValue);
            node = nextNode;
        }
    }

    return dist[0] === Number.MAX_SAFE_INTEGER ? -1 : dist[0];
}
