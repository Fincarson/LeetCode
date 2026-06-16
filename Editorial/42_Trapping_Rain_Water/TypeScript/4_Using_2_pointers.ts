function trap(height: number[]): number {
    let left = 0,
        right = height.length - 1;
    let ans = 0;
    let left_max = 0,
        right_max = 0;
    while (left < right) {
        if (height[left] < height[right]) {
            left_max = Math.max(left_max, height[left]);
            ans += left_max - height[left];
            ++left;
        } else {
            right_max = Math.max(right_max, height[right]);
            ans += right_max - height[right];
            --right;
        }
    }
    return ans;
}
