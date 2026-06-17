function calculateArea(heights: number[], start: number, end: number) {
    if (start > end) return 0;
    let min_index = start;
    for (let i = start; i <= end; i++)
        if (heights[min_index] > heights[i]) min_index = i;
    return Math.max(
        heights[min_index] * (end - start + 1),
        Math.max(
            calculateArea(heights, start, min_index - 1),
            calculateArea(heights, min_index + 1, end),
        ),
    );
}
function largestRectangleArea(heights: number[]): number {
    return calculateArea(heights, 0, heights.length - 1);
}
