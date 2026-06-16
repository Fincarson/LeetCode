function combinationSum(candidates: number[], target: number): number[][] {
    function backtrack(remain: number, start: number, path: number[]): void {
        if (remain < 0) {
            return;
        }
        if (remain === 0) {
            combinations.push([...path]);
            return;
        }
        for (let i = start; i < candidates.length; i++) {
            path.push(candidates[i]);
            backtrack(remain - candidates[i], i, path);
            path.pop();
        }
    }
    const combinations: number[][] = [];
    backtrack(target, 0, []);
    return combinations;
}
