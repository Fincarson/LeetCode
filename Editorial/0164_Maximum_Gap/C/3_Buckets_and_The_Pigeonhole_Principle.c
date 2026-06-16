#define MIN(i, j) ((i) < (j) ? (i) : (j))
#define MAX(i, j) ((i) > (j) ? (i) : (j))

typedef struct {
    int used;
    int minval;
    int maxval;
} Bucket;

int maximumGap(int* nums, int numsSize) {
    if (!nums || numsSize < 2) return 0;

    int mini = nums[0], maxi = nums[0];
    for (int i = 0; i < numsSize; i++) {
        mini = MIN(mini, nums[i]);
        maxi = MAX(maxi, nums[i]);
    }

    int bucketSize =
        MAX(1, (maxi - mini) / (numsSize - 1));      // bucket size or capacity
    int bucketNum = (maxi - mini) / bucketSize + 1;  // number of buckets
    Bucket* buckets = (Bucket*)malloc(sizeof(Bucket) * bucketNum);
    for (int i = 0; i < bucketNum; i++) {
        buckets[i].used = 0;
        buckets[i].minval = INT_MAX;
        buckets[i].maxval = INT_MIN;
    }

    for (int i = 0; i < numsSize; i++) {
        int bucketIdx =
            (nums[i] - mini) / bucketSize;  // locating correct bucket
        buckets[bucketIdx].used = 1;
        buckets[bucketIdx].minval = MIN(nums[i], buckets[bucketIdx].minval);
        buckets[bucketIdx].maxval = MAX(nums[i], buckets[bucketIdx].maxval);
    }

    int prevBucketMax = mini, maxGap = 0;
    for (int i = 0; i < bucketNum; i++) {
        if (!buckets[i].used) continue;

        maxGap = MAX(maxGap, buckets[i].minval - prevBucketMax);
        prevBucketMax = buckets[i].maxval;
    }

    free(buckets);
    return maxGap;
}
