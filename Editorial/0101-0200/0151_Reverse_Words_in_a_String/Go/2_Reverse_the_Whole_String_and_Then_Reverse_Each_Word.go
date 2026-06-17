// Translated Go solution
func reverseWords(s string) string {
    // convert string to char slice
    // and trim spaces at the same time
    arr := trimSpaces(s)

    // reverse the whole string
    reverse(arr, 0, len(arr)-1)

    // reverse each word
    reverseEachWord(arr)

    return strings.Join(arr, "")
}

func trimSpaces(s string) []string {
    left, right := 0, len(s)-1
    // remove leading spaces
    for left <= right && s[left] == ' ' {
        left++
    }

    // remove trailing spaces
    for left <= right && s[right] == ' ' {
        right--
    }

    // reduce multiple spaces to single one
    output := make([]string, 0)
    for left <= right {
        if s[left] != ' ' {
            output = append(output, string(s[left]))
        } else if output[len(output)-1] != " " {
            output = append(output, string(s[left]))
        }
        left++
    }
    return output
}

func reverseEachWord(c []string) {
    n := len(c)
    start, end := 0, 0

    for start < n {
        // go to the end of the word
        for end < n && c[end] != " " {
            end++
        }
        // reverse the word
        reverse(c, start, end-1)
        // move to the next word
        start = end + 1
        end++
    }
}

func reverse(c []string, start int, end int) {
    for start < end {
        c[start], c[end] = c[end], c[start]
        start++
        end--
    }
}
