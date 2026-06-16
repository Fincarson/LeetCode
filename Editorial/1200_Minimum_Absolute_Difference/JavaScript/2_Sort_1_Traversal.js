var minimumAbsDifference = function(arr) {
    // Sort the original array
    arr.sort((x, y) => x - y);

    // Initialize minimum difference `minPairDiff` as a huge integer in order not 
    // to miss the absolute difference of the first pair. 
    let minPairDiff = Infinity;
    let answer = [];

    // Traverse the sorted array
    for (let i = 0; i < arr.length - 1; ++i) {
        // For the absolute value `currPairDiff` of the current pair:
        let currPairDiff = arr[i + 1] - arr[i];

        // If `currPairDiff` equals `minPairDiff`, add this pair to the answer list.
        // If `currPairDiff` is smaller than `minPairDiff`, discard all pairs in the answer list, 
        //add this pair to the answer list and update `minPairDiff`.
        // If `currPairDiff` is larger than `minPairDiff`, we just go ahead.
        if (currPairDiff == minPairDiff) {
            answer.push([arr[i], arr[i + 1]]);
        } else if (currPairDiff < minPairDiff) {
            answer = [];
            answer.push([arr[i], arr[i + 1]]);
            minPairDiff = currPairDiff;
        }
    } 

    return answer;   
};
