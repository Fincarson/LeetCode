class Solution {

    public int maxProfitAssignment(
        int[] difficulty,
        int[] profit,
        int[] worker
    ) {
        List<int[]> jobProfile = new ArrayList<>();
        jobProfile.add(new int[] { 0, 0 });
        for (int i = 0; i < difficulty.length; i++) {
            jobProfile.add(new int[] { profit[i], difficulty[i] });
        }

        // Sort in decreasing order of profit.
        jobProfile.sort((a, b) -> Integer.compare(b[0], a[0]));
        for (int i = 0; i < jobProfile.size() - 1; i++) {
            jobProfile.get(i + 1)[1] = Math.min(
                jobProfile.get(i)[1],
                jobProfile.get(i + 1)[1]
            );
        }

        int netProfit = 0;
        for (int i = 0; i < worker.length; i++) {
            int ability = worker[i];
            // Maximize profit using binary search.
            int l = 0, r = jobProfile.size() - 1, jobProfit = 0;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (jobProfile.get(mid)[1] <= ability) {
                    jobProfit = Math.max(jobProfit, jobProfile.get(mid)[0]);
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            // Add profit of each worker to total profit.
            netProfit += jobProfit;
        }
        return netProfit;
    }
}
