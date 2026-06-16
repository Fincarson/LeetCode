/**
 * @param {number[][]} img
 * @return {number[][]}
 */
var imageSmoother = function(img) {
    // Save the dimensions of the image.
    const m = img.length;
    const n = img[0].length;

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
                        // Extract the original value of img[x][y].
                        sum += img[x][y] & 255;
                        count += 1;
                    }
                }
            }

            // Encode the smoothed value in img[i][j].
            img[i][j] |= Math.floor(sum / count) << 8;
        }
    }

    // Extract the smoothed value from encoded img[i][j].
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            img[i][j] >>= 8;
        }
    }

    // Return the smooth image.
    return img;
};
