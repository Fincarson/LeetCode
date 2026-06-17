class Bucket {
    used: boolean = false;
    minval: number = Number.MAX_SAFE_INTEGER;
    maxval: number = Number.MIN_SAFE_INTEGER;
}

function maximumGap(nums: number[]): number {
    if (!nums || nums.length < 2) return 0;

    let mini: number = Math.min(...nums),
        maxi: number = Math.max(...nums);

    let bucketSize: number = Math.max(
        1,
        Math.floor((maxi - mini) / (nums.length - 1)),
    ); // bucket size or capacity
    let bucketNum: number = Math.floor((maxi - mini) / bucketSize) + 1; // number of buckets
    let buckets: Bucket[] = Array.from(
        { length: bucketNum },
        () => new Bucket(),
    );

    for (let num of nums) {
        let bucketIdx: number = Math.floor((num - mini) / bucketSize); // locating correct bucket
        buckets[bucketIdx].used = true;
        buckets[bucketIdx].minval = Math.min(num, buckets[bucketIdx].minval);
        buckets[bucketIdx].maxval = Math.max(num, buckets[bucketIdx].maxval);
    }

    let prevBucketMax: number = mini,
        maxGap: number = 0;
    for (let bucket of buckets) {
        if (!bucket.used) continue;

        maxGap = Math.max(maxGap, bucket.minval - prevBucketMax);
        prevBucketMax = bucket.maxval;
    }

    return maxGap;
}
