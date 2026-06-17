# 1629. Slowest Key

[![Easy](../../../_Misc/Badges/Easy.svg)](https://leetcode.com/problems/slowest-key/)  
`Array` `String`

**Problem Link:** [LeetCode 1629 - Slowest Key](https://leetcode.com/problems/slowest-key/)

## Problem

A newly designed keypad was tested, where a tester pressed a sequence of n keys, one at a time.

You are given a string keysPressed of length n, where keysPressed[i] was the ith key pressed in the testing sequence, and a sorted list releaseTimes, where releaseTimes[i] was the time the ith key was released. Both arrays are 0-indexed. The 0th key was pressed at the time 0, and every subsequent key was pressed at the exact time the previous key was released.

The tester wants to know the key of the keypress that had the longest duration. The ith keypress had a duration of releaseTimes[i] - releaseTimes[i - 1], and the 0th keypress had a duration of releaseTimes[0].

Note that the same key could have been pressed multiple times during the test, and these multiple presses of the same key may not have had the same duration.

Return the key of the keypress that had the longest duration. If there are multiple such keypresses, return the lexicographically largest key of the keypresses.

### Example 1

```text
Input: releaseTimes = [9,29,49,50], keysPressed = "cbcd"
Output: "c"
Explanation: The keypresses were as follows:
Keypress for 'c' had a duration of 9 (pressed at time 0 and released at time 9).
Keypress for 'b' had a duration of 29 - 9 = 20 (pressed at time 9 right after the release of the previous character and released at time 29).
Keypress for 'c' had a duration of 49 - 29 = 20 (pressed at time 29 right after the release of the previous character and released at time 49).
Keypress for 'd' had a duration of 50 - 49 = 1 (pressed at time 49 right after the release of the previous character and released at time 50).
The longest of these was the keypress for 'b' and the second keypress for 'c', both with duration 20.
'c' is lexicographically larger than 'b', so the answer is 'c'.
```

### Example 2

```text
Input: releaseTimes = [12,23,36,46,62], keysPressed = "spuda"
Output: "a"
Explanation: The keypresses were as follows:
Keypress for 's' had a duration of 12.
Keypress for 'p' had a duration of 23 - 12 = 11.
Keypress for 'u' had a duration of 36 - 23 = 13.
Keypress for 'd' had a duration of 46 - 36 = 10.
Keypress for 'a' had a duration of 62 - 46 = 16.
The longest of these was the keypress for 'a' with duration 16.
```

## Constraints

- releaseTimes.length == n
- keysPressed.length == n
- 2 <= n <= 1000
- 1 <= releaseTimes[i] <= 109
- releaseTimes[i] < releaseTimes[i+1]
- keysPressed contains only lowercase English letters.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 1629. Slowest Key

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Using Map | C++, Java |
| Fixed Size Array | C++, Java |
| Constant Extra Space | C++, Java |

## Approach 1: Using Map

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        unordered_map<char, int> durationMap;
        durationMap[keysPressed[0]] = releaseTimes[0];
        // find and store the keypress duration for each key in the durationMap
        for (int i = 1; i < releaseTimes.size(); i++) {
            int currentDuration = releaseTimes[i] - releaseTimes[i - 1];
            char currentKey = keysPressed[i];
            durationMap[currentKey] =
                max(durationMap[currentKey], currentDuration);
        }
        char slowestKey = ' ';
        int longestPressDuration = 0;
        // iterate over the map to find the slowest key
        for (auto mapElement : durationMap) {
            char key = static_cast<char>(mapElement.first);
            int duration = static_cast<int>(mapElement.second);
            if (duration > longestPressDuration) {
                longestPressDuration = duration;
                slowestKey = key;
            } else if (duration == longestPressDuration && key > slowestKey) {
                slowestKey = key;
            }
        }
        return slowestKey;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public char slowestKey(int[] releaseTimes, String keysPressed) {
        HashMap<Character, Integer> durationMap = new HashMap<>();
        durationMap.put(keysPressed.charAt(0), releaseTimes[0]);
        // find and store the keypress duration for each key in the durationMap
        for (int i = 1; i < releaseTimes.length; i++) {
            int currentDuration = releaseTimes[i] - releaseTimes[i - 1];
            char currentKey = keysPressed.charAt(i);
            durationMap.put(currentKey,
                Math.max(durationMap.getOrDefault(currentKey, 0), currentDuration));
        }
        char slowestKey = ' ';
        int longestPressDuration = 0;
        // iterate over the map to find the slowest key
        for (Map.Entry mapElement : durationMap.entrySet()) {
            int duration = (int) mapElement.getValue();
            char key = (char) mapElement.getKey();
            if (duration > longestPressDuration) {
                longestPressDuration = duration;
                slowestKey = key;
            } else if (duration == longestPressDuration && key > slowestKey) {
                slowestKey = key;
            }
        }
        return slowestKey;
    }
}
```

</details>

<br>

## Approach 2: Fixed Size Array

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int durationArray[26] = {0};
        durationArray[keysPressed[0] - 'a'] = releaseTimes[0];
        // find and store the key pressed duration for each key
        for (int i = 1; i < releaseTimes.size(); i++) {
            int currentDuration = releaseTimes[i] - releaseTimes[i - 1];
            char currentKey = keysPressed[i];
            durationArray[currentKey - 'a'] =
                max(durationArray[currentKey - 'a'], currentDuration);
        }
        // initialize slowest key as 'z'
        int slowestKeyIndex = 25;
        // iterate from 'y' to 'a' to find slowest key
        for (int currentKey = 24; currentKey >= 0; currentKey--) {
            if (durationArray[currentKey] > durationArray[slowestKeyIndex]) {
                slowestKeyIndex = currentKey;
            }
        }
        return slowestKeyIndex + 'a';
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public char slowestKey(int[] releaseTimes, String keysPressed) {
        int[] durationArray = new int[26];
        durationArray[keysPressed.charAt(0) - 'a'] = releaseTimes[0];

        // find and store the key pressed duration for each key
        for (int i = 1; i < releaseTimes.length; i++) {
            int currentDuration = releaseTimes[i] - releaseTimes[i - 1];
            char currentKey = keysPressed.charAt(i);
            durationArray[currentKey - 'a'] = Math.max(durationArray[currentKey - 'a'], currentDuration);
        }
        // initialize slowest key as 'z'
        int slowestKeyIndex = 25;
        // iterate from 'y' to 'a' to find slowest key
        for (int currentKey = 24; currentKey >= 0; currentKey--) {
            if (durationArray[currentKey] > durationArray[slowestKeyIndex]) {
                slowestKeyIndex = currentKey;
            }
        }
        return (char) (slowestKeyIndex + 'a');
    }
}
```

</details>

<br>

## Approach 3: Constant Extra Space

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int n = releaseTimes.size();
        int longestPress = releaseTimes[0];
        char slowestKey = keysPressed[0];
        for (int i = 1; i < n; i++) {
            int currentDuration = releaseTimes[i] - releaseTimes[i - 1];
            // check if we found the key that is slower than slowestKey
            if (currentDuration > longestPress ||
                (currentDuration == longestPress &&
                 keysPressed[i] > slowestKey)) {
                // update the slowest key and longest press duration
                longestPress = currentDuration;
                slowestKey = keysPressed[i];
            }
        }
        return slowestKey;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public char slowestKey(int[] releaseTimes, String keysPressed) {
        int n = releaseTimes.length;
        int longestPress = releaseTimes[0];
        char slowestKey = keysPressed.charAt(0);
        for (int i = 1; i < n; i++) {
            int currentDuration = releaseTimes[i] - releaseTimes[i - 1];
            // check if we found the key that is slower than slowestKey
            if (currentDuration > longestPress ||
                (currentDuration == longestPress && keysPressed.charAt(i) > slowestKey)) {
                // update the slowest key and longest press duration
                longestPress = currentDuration;
                slowestKey = keysPressed.charAt(i);
            }
        }
        return slowestKey;
    }
}
```

</details>
