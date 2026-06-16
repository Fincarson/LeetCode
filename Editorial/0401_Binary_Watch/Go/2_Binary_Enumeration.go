func readBinaryWatch(turnedOn int) (ans []string) {
    for i := 0; i < 1024; i++ {
        h, m := i>>6, i&63 // Extract the high 4 bits and low 6 bits using bitwise operations
        if h < 12 && m < 60 && bits.OnesCount(uint(i)) == turnedOn {
            ans = append(ans, fmt.Sprintf("%d:%02d", h, m))
        }
    }
    return
}
