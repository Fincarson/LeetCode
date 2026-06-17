public class Solution {
    public int EarliestFinishTime(int[] landStartTime, int[] landDuration,
                                  int[] waterStartTime, int[] waterDuration) {
        int n = landStartTime.Length;
        int m = waterStartTime.Length;
        int res = int.MaxValue;
        ;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int land = landStartTime[i] + landDuration[i];
                int land_water =
                    Math.Max(land, waterStartTime[j]) + waterDuration[j];
                res = Math.Min(res, land_water);

                int water = waterStartTime[j] + waterDuration[j];
                int water_land =
                    Math.Max(water, landStartTime[i]) + landDuration[i];
                res = Math.Min(res, water_land);
            }
        }
        return res;
    }
}
