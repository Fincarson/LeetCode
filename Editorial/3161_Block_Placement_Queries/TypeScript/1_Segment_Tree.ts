import { AvlTree } from "@datastructures-js/binary-search-tree";

function getResults(queries: number[][]): boolean[] {
    const mx: number = 50000;
    const seg: number[] = new Array(mx << 2).fill(0);

    const update = (
        idx: number,
        val: number,
        p: number,
        l: number,
        r: number,
    ): void => {
        if (l === r) {
            seg[p] = val;
            return;
        }
        const mid = (l + r) >> 1;
        if (idx <= mid) {
            update(idx, val, p << 1, l, mid);
        } else {
            update(idx, val, (p << 1) | 1, mid + 1, r);
        }
        seg[p] = Math.max(seg[p << 1], seg[(p << 1) | 1]);
    };

    const query = (
        L: number,
        R: number,
        p: number,
        l: number,
        r: number,
    ): number => {
        if (L <= l && r <= R) {
            return seg[p];
        }
        const mid = (l + r) >> 1;
        let res: number = 0;
        if (L <= mid) {
            res = Math.max(res, query(L, R, p << 1, l, mid));
        }
        if (R > mid) {
            res = Math.max(res, query(L, R, (p << 1) | 1, mid + 1, r));
        }
        return res;
    };

    const tree = new AvlTree<number>((a: number, b: number) => a - b);
    tree.insert(0);
    tree.insert(mx);
    update(mx, mx, 1, 0, mx);

    const ans: boolean[] = [];

    for (const q of queries) {
        if (q[0] === 1) {
            const x: number = q[1];
            const rightNode = tree.ceil(x, false);
            const leftNode = tree.floor(x, false);
            const r: number = rightNode?.getValue() ?? mx;
            const l: number = leftNode?.getValue() ?? 0;

            update(x, x - l, 1, 0, mx);
            update(r, r - x, 1, 0, mx);
            tree.insert(x);
        } else {
            const x: number = q[1];
            const sz: number = q[2];
            const preNode = tree.floor(x, true);
            const pre: number = preNode?.getValue() ?? 0;

            let maxSpace: number = query(0, pre, 1, 0, mx);
            maxSpace = Math.max(maxSpace, x - pre);
            ans.push(maxSpace >= sz);
        }
    }

    return ans;
}
