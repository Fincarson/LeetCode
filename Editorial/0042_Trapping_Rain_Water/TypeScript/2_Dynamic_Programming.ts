function trap(height: number[]): number {
    // Case of empty height array
    if (height.length == 0) return 0;
    let ans = 0;
    let size = height.length;
    // Create left and right max arrays
    let left_max: number[] = new Array(size).fill(0);
    let right_max: number[] = new Array(size).fill(0);
    // Initialize first height into left max
    left_max[0] = height[0];
    for (let i = 1; i < size; i++) {
        // update left max with current max
        left_max[i] = Math.max(height[i], left_max[i - 1]);
    }
    // Initialize last height into right max
    right_max[size - 1] = height[size - 1];
    for (let i = size - 2; i >= 0; i--) {
        // update right max with current max
        right_max[i] = Math.max(height[i], right_max[i + 1]);
    }
    // Calculate the trapped water
    for (let i = 1; i < size - 1; i++) {
        ans += Math.min(left_max[i], right_max[i]) - height[i];
    }
    // Return amount of trapped water
    return ans;
}
