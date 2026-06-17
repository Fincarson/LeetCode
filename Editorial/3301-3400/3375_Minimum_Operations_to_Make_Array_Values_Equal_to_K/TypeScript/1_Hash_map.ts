function minOperations(nums: number[], k: number): number {
    const st = new Set<number>();
    for (const x of nums) {
        if (x < k) {
            return -1;
        } else if (x > k) {
            st.add(x);
        }
    }
    return st.size;
}
