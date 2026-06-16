var largestRectangleArea = function (heights) {
    function calculateArea(heights, start, end) {
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
    return calculateArea(heights, 0, heights.length - 1);
};
