type Node struct {
    name string
    timestamp int
    website string
}

func mostVisitedPattern(username []string, timestamp []int, website []string) []string {
    n := make([]Node, len(username))
    for i := 0; i < len(username); i++ {
        n[i] = Node{username[i], timestamp[i], website[i]}
    }
    sort.Slice(n, func(i, j int) bool {
        return n[i].timestamp < n[j].timestamp // Ensure the user's access records are orderly
    })
    m := make(map[string][]Node)
    for i := 0; i < len(n); i++ {
        m[n[i].name] = append(m[n[i].name], n[i]) // Retrieve all access records for each user
    }
    route := make(map[[3]string]int)
    for _, v := range m {
        tmp := make(map[[3]string]int)
        for i := 0; i < len(v); i++ {
            for j := i + 1; j < len(v); j++ {
                for k := j + 1; k < len(v); k++ {
                    tmp[[3]string{v[i].website, v[j].website, v[k].website}] = 1 // Retrieve each access path
                }
            }
        }
        for k1, v1 := range tmp {
            route[k1] += v1
        }
    }
    max := -1
    ret := [3]string{}
    for k, v := range route {
        if v > max {
            ret = k
            max = v
        } else if v == max {
            if k[0] < ret[0] || (k[0] == ret[0] && k[1] < ret[1] || (k[0] == ret[0] && k[1] == ret[1] && k[2] < ret[2])) {
                ret = k
            }
        }
    }
    return []string{ret[0], ret[1], ret[2]}
}
