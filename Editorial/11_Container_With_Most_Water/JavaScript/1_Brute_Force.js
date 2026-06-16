var maxArea = function (height) {
    var maxarea = 0;

    for (var left = 0; left < height.length; left++) {
        for (var right = left + 1; right < height.length; right++) {
            var width = right - left;
            maxarea = Math.max(
                maxarea,
                Math.min(height[left], height[right]) * width,
            );
        }
    }

    return maxarea;
};
