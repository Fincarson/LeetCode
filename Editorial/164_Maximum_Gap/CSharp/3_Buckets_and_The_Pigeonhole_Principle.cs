public class Solution {
    public class Bucket {
        public bool used = false;
        public int minval = int.MaxValue;
        public int maxval = int.MinValue;
    }

    public int MaximumGap(int[] nums) {
        if (nums == null || nums.Length < 2)
            return 0;

        int mini = nums.Min(),
            maxi = nums.Max();

        int bucketSize =
            Math.Max(1,
                (maxi - mini) / (nums.Length - 1)); // bucket size or capacity
        int bucketNum = (maxi - mini) / bucketSize + 1; // number of buckets
        Bucket[] buckets = new Bucket[bucketNum];

        foreach (int num in nums) {
            int bucketIdx =
                (num - mini) / bucketSize; // locating correct bucket
            if (buckets[bucketIdx] == null)
                buckets[bucketIdx] = new Bucket();

            buckets[bucketIdx].used = true;
            buckets[bucketIdx].minval =
                Math.Min(num, buckets[bucketIdx].minval);
            buckets[bucketIdx].maxval =
                Math.Max(num, buckets[bucketIdx].maxval);
        }

        int prevBucketMax = mini, maxGap = 0;
        foreach (Bucket bucket in buckets) {
            if (bucket == null || !bucket.used)
                continue;

            maxGap = Math.Max(maxGap, bucket.minval - prevBucketMax);
            prevBucketMax = bucket.maxval;
        }

        return maxGap;
    }
}
