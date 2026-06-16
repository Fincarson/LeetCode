func earliestFinishTime(landStartTime []int, landDuration []int, waterStartTime []int, waterDuration []int) int {
    n := len(landStartTime)
    m := len(waterStartTime)
    res := 1000000
    for i := 0; i < n; i++ {
        for j := 0; j < m; j++ {
            land := landStartTime[i] + landDuration[i]
            land_water := land
            if waterStartTime[j] > land_water {
                land_water = waterStartTime[j]
            }
            land_water += waterDuration[j]
            if land_water < res {
                res = land_water
            }

            water := waterStartTime[j] + waterDuration[j]
            water_land := water
            if landStartTime[i] > water_land {
                water_land = landStartTime[i]
            }
            water_land += landDuration[i]
            if water_land < res {
                res = water_land
            }
        }
    }
    return res
}
