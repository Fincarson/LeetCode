#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int earliestFinishTime(int* landStartTime, int landStartTimeSize,
                       int* landDuration, int landDurationSize,
                       int* waterStartTime, int waterStartTimeSize,
                       int* waterDuration, int waterDurationSize) {
    int n = landStartTimeSize;
    int m = waterStartTimeSize;
    int res = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int land = landStartTime[i] + landDuration[i];
            int land_water = MAX(land, waterStartTime[j]) + waterDuration[j];
            res = MIN(res, land_water);

            int water = waterStartTime[j] + waterDuration[j];
            int water_land = MAX(water, landStartTime[i]) + landDuration[i];
            res = MIN(res, water_land);
        }
    }
    return res;
}
