func canCompleteCircuit(gas []int, cost []int) int {
    var currGain int = 0
    var totalGain int = 0
    var answer int = 0
    for i := 0; i < len(gas); i++ {
        // gain[i] = gas[i] - cost[i]
        totalGain += gas[i] - cost[i]
        currGain += gas[i] - cost[i]
        // If we meet a "valley", start over from the next station
        // with 0 initial gas.
        if currGain < 0 {
            answer = i + 1
            currGain = 0
        }
    }
    if totalGain >= 0 {
        return answer
    } else {
        return -1
    }
}
