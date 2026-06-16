/**
 * @param {number[][]} img
 * @return {number[][]}
 */
var imageSmoother = function(img) {
    // Save the dimensions of the image.
    const m = img.length;
    const n = img[0].length;

    // Create a new image of the same dimension as the input image.
    const smoothImg = new Array(m).fill(0).map(() => new Array(n).fill(0));

    // Iterate over the cells of the image.
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            // Initialize the sum and count
            let sum = 0;
            let count = 0;

            // Iterate over all plausible nine indices.
            for (let x = i - 1; x <= i + 1; x++) {
                for (let y = j - 1; y <= j + 1; y++) {
                    // If the indices form valid neighbor
                    if (0 <= x && x < m && 0 <= y && y < n) {
                        sum += img[x][y];
                        count += 1;
                    }
                }
            }

            // Store the rounded down value in smoothImg[i][j].
            smoothImg[i][j] = Math.floor(sum / count);
        }
    }

    // Return the smooth image.
    return smoothImg;
};
