function grayCode(n: number): number[] {
    const res: number[] = [0];
    const seen = new Set(res);
    const helper = (n: number, res: number[], seen: Set<Number>) => {
        if (res.length === Math.pow(2, n)) {
            return true;
        }
        const curr = res[res.length - 1];
        for (let i = 0; i < n; i++) {
            const next = curr ^ (1 << i);
            if (!seen.has(next)) {
                seen.add(next);
                res.push(next);
                if (helper(n, res, seen)) return true;
                seen.delete(next);
                res.pop();
            }
        }
        return false;
    };
    helper(n, res, seen);
    return res;
}
