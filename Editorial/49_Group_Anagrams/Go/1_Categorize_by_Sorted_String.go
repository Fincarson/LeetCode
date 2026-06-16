func groupAnagrams(strs []string) [][]string {
    // Create a map to store the anagrams, where the keys are the sorted strings and the values are the lists of anagrams
    ans := make(map[string][]string)
    for _, s := range strs {
        key := sortString(s)
        // If the string is an anagram of another string, they will have the same key and thus be grouped together
        ans[key] = append(ans[key], s)
    }

    // Build the result slice from the map entries
    var result [][]string
    for _, group := range ans {
        result = append(result, group)
    }
    return result
}

// sortString sorts the characters of a string and returns the sorted string
func sortString(s string) string {
    sorted := strings.Split(s, "")
    sort.Strings(sorted)
    return strings.Join(sorted, "")
}
