class Bucket {
    constructor() {
        this.used = false;
        this.minval = Number.MAX_SAFE_INTEGER;
        this.maxval = Number.MIN_SAFE_INTEGER;
    }
}

var maximumGap = function (nums) {
    if (!nums || nums.length < 2) return 0;

    let mini = Math.min(...nums),
        maxi = Math.max(...nums);

    let bucketSize = Math.max(1, Math.floor((maxi - mini) / (nums.length - 1))); // bucket size or capacity
    let bucketNum = Math.floor((maxi - mini) / bucketSize) + 1; // number of buckets
    let buckets = Array.from({ length: bucketNum }, () => new Bucket());

    for (let num of nums) {
        let bucketIdx = Math.floor((num - mini) / bucketSize); // locating correct bucket
        buckets[bucketIdx].used = true;
        buckets[bucketIdx].minval = Math.min(num, buckets[bucketIdx].minval);
        buckets[bucketIdx].maxval = Math.max(num, buckets[bucketIdx].maxval);
    }

    let prevBucketMax = mini,
        maxGap = 0;
    for (let bucket of buckets) {
        if (!bucket.used) continue;

        maxGap = Math.max(maxGap, bucket.minval - prevBucketMax);
        prevBucketMax = bucket.maxval;
    }

    return maxGap;
};
