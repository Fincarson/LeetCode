func reverseByte(b uint32, cache map[uint32]uint64) uint64 {
    value, ok := cache[b]
    if ok {
        return value
    }
    value = (uint64(b) * 0x0202020202 & 0x010884422010) % 1023
    cache[b] = value
    return value
}

func reverseBits(num uint32) uint32 {
    ret := uint64(0)
    power := uint64(24)
    var cache = map[uint32]uint64{}

    for num != 0 {
        ret += reverseByte(num & 0xff, cache) << power
        num = num >> 8
        power -= 8
    }
    return uint32(ret)
}
