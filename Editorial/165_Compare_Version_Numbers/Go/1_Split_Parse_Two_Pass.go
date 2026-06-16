func compareVersion(version1 string, version2 string) int {
    tokens1 := strings.Split(version1, ".")
    tokens2 := strings.Split(version2, ".")

    for i := 0; i < max(len(tokens1), len(tokens2)); i++ {
        i1 := 0
        i2 := 0
        if i < len(tokens1) {
            i1, _ = strconv.Atoi(tokens1[i])
        }
        if i < len(tokens2) {
            i2, _ = strconv.Atoi(tokens2[i])
        }

        if i1 != i2 {
            if i1 > i2 {
                return 1
            }
            return -1
        }
    }

    // The versions are equal
    return 0
}
