function largestRectangleArea(heights: number[]): number {
    let max_area = 0;
    for (let i = 0; i < heights.length; i++) {
        for (let j = i; j < heights.length; j++) {
            let min_height = Infinity;
            for (let k = i; k <= j; k++)
                min_height = Math.min(min_height, heights[k]);
            max_area = Math.max(max_area, min_height * (j - i + 1));
        }
    }
    return max_area;
}
