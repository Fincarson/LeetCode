func letterCombinations(digits string) []string {
    if len(digits) == 0 {
        return []string{}
    }
    combinations := []string{}
    letters := map[rune]string{
        '2': "abc", '3': "def", '4': "ghi", '5': "jkl",
        '6': "mno", '7': "pqrs", '8': "tuv", '9': "wxyz",
    }
    var backtrack func(index int, path []rune)
    backtrack = func(index int, path []rune) {
        if len(path) == len(digits) {
            combinations = append(combinations, string(path))
            return
        }
        possibleLetters := letters[rune(digits[index])]
        for _, letter := range possibleLetters {
            path = append(path, letter)
            backtrack(index+1, path)
            path = path[:len(path)-1]
        }
    }
    backtrack(0, []rune{})
    return combinations
}
