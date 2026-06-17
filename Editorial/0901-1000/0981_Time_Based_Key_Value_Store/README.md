# 981. Time Based Key-Value Store

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/time-based-key-value-store/)  
`Hash Table` `String` `Binary Search` `Design`

**Problem Link:** [LeetCode 981 - Time Based Key-Value Store](https://leetcode.com/problems/time-based-key-value-store/)

## Problem

Design a time-based key-value data structure that can store multiple values for the same key at different time stamps and retrieve the key's value at a certain timestamp.

Implement the TimeMap class:

- TimeMap() Initializes the object of the data structure.
- void set(String key, String value, int timestamp) Stores the key key with the value value at the given time timestamp.
- String get(String key, int timestamp) Returns a value such that set was called previously, with timestamp_prev <= timestamp. If there are multiple such values, it returns the value associated with the largest timestamp_prev. If there are no values, it returns "".

### Example 1

```text
Input
["TimeMap", "set", "get", "get", "set", "get", "get"]
[[], ["foo", "bar", 1], ["foo", 1], ["foo", 3], ["foo", "bar2", 4], ["foo", 4], ["foo", 5]]
Output
[null, null, "bar", "bar", null, "bar2", "bar2"]

Explanation
TimeMap timeMap = new TimeMap();
timeMap.set("foo", "bar", 1);  // store the key "foo" and value "bar" along with timestamp = 1.
timeMap.get("foo", 1);         // return "bar"
timeMap.get("foo", 3);         // return "bar", since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 is "bar".
timeMap.set("foo", "bar2", 4); // store the key "foo" and value "bar2" along with timestamp = 4.
timeMap.get("foo", 4);         // return "bar2"
timeMap.get("foo", 5);         // return "bar2"
```

## Constraints

- 1 <= key.length, value.length <= 100
- key and value consist of lowercase English letters and digits.
- 1 <= timestamp <= 107
- All the timestamps timestamp of set are strictly increasing.
- At most 2 * 105 calls will be made to set and get.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Stock Price Fluctuation ](https://leetcode.com/problems/stock-price-fluctuation/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 981. Time Based Key-Value Store

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Hashmap + Linear Search | C++, Java, JavaScript, Python3 |
| Sorted Map + Binary Search | C++, Java, Python3 |
| Array + Binary Search | C++, Java, JavaScript, Python3 |

## Approach 1: Hashmap + Linear Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class TimeMap {
public:
    unordered_map<string, unordered_map<int, string>> keyTimeMap;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        // Store '(timestamp, value)' pair in 'key' bucket.
        keyTimeMap[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        // If the 'key' does not exist in map we will return empty string.
        if (!keyTimeMap.count(key)) {
            return "";
        }
        
        // Iterate on time from 'timestamp' to '1'.
        for (int currTime = timestamp; currTime >= 1; --currTime) {
            // If a value for current time is stored in key's bucket we return the value.
            if (keyTimeMap[key].count(currTime)) {
                return keyTimeMap[key][currTime];
            }
        }
        
        // Otherwise no time <= timestamp was stored in key's bucket.
        return "";
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class TimeMap {
    HashMap<String, HashMap<Integer, String>> keyTimeMap;
    public TimeMap() {
        keyTimeMap = new HashMap<String, HashMap<Integer, String>>();
    }
    
    public void set(String key, String value, int timestamp) {
        // If the 'key' does not exist in map.
        if (!keyTimeMap.containsKey(key)) {
            keyTimeMap.put(key, new HashMap<Integer, String>());
        }
        
        // Store '(timestamp, value)' pair in 'key' bucket.
        keyTimeMap.get(key).put(timestamp, value);
    }
    
    public String get(String key, int timestamp) {
        // If the 'key' does not exist in map we will return empty string.
        if (!keyTimeMap.containsKey(key)) {
            return "";
        }
        
        // Iterate on time from 'timestamp' to '1'.
        for (int currTime = timestamp; currTime >= 1; --currTime) {
            // If a value for current time is stored in key's bucket we return the value.
            if (keyTimeMap.get(key).containsKey(currTime)) {
                return keyTimeMap.get(key).get(currTime);
            }
        }
        
        // Otherwise no time <= timestamp was stored in key's bucket.
        return ""; 
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
let keyTimeMap = {};
var TimeMap = function() {
};

TimeMap.prototype.set = function(key, value, timestamp) {
    // If the 'key' does not exist in dictionary.
    if (!(key in keyTimeMap)) {
        keyTimeMap[key] = {};
    }

    // Store '(timestamp, value)' pair in 'key' bucket.
    keyTimeMap[key][timestamp] = value;
};

TimeMap.prototype.get = function(key, timestamp) {
    // If the 'key' does not exist in dictionary we will return empty string.
    if (!(key in keyTimeMap)) {
        return "";
    }
    
    // Iterate on time from 'timestamp' to '1'.
    for (let currTime = timestamp; currTime >= 1; --currTime) {
        // If a value for current time is stored in key's bucket we return the value.
        if (currTime in keyTimeMap[key]) {
            return keyTimeMap[key][currTime];
        }
    }

    // Otherwise no time <= timestamp was stored in key's bucket.
    return "";
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class TimeMap:
    def __init__(self):
        self.key_time_map = {}

    def set(self, key: str, value: str, timestamp: int) -> None:
        # If the 'key' does not exist in dictionary.
        if not key in self.key_time_map:
            self.key_time_map[key] = {}
            
        # Store '(timestamp, value)' pair in 'key' bucket.
        self.key_time_map[key][timestamp] = value
        

    def get(self, key: str, timestamp: int) -> str:
        # If the 'key' does not exist in dictionary we will return empty string.
        if not key in self.key_time_map:
            return ""
        
        # Iterate on time from 'timestamp' to '1'.
        for curr_time in reversed(range(1, timestamp + 1)):
            # If a value for current time is stored in key's bucket we return the value.
            if curr_time in self.key_time_map[key]:
                return self.key_time_map[key][curr_time]
            
        # Otherwise no time <= timestamp was stored in key's bucket.
        return ""
```

</details>

<br>

## Approach 2: Sorted Map + Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class TimeMap {
public:
    unordered_map<string, map<int, string>> keyTimeMap;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        // Store '(timestamp, value)' pair in 'key' bucket.
        keyTimeMap[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        // If the 'key' does not exist in map we will return empty string.
        if (keyTimeMap.find(key) == keyTimeMap.end()) {
            return "";
        }
        
        auto it = keyTimeMap[key].upper_bound(timestamp);
        // If iterator points to first element it means, no time <= timestamp exists.
        if (it == keyTimeMap[key].begin()) {
            return "";
        }
        
        // Return value stored at previous position of current iterator.
        return prev(it)->second;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class TimeMap {
    HashMap<String, TreeMap<Integer, String>> keyTimeMap;
    
    public TimeMap() {
        keyTimeMap = new HashMap<String, TreeMap<Integer, String>>();
    }
    
    public void set(String key, String value, int timestamp) {
        if (!keyTimeMap.containsKey(key)) {
            keyTimeMap.put(key, new TreeMap<Integer, String>());
        }
        
        // Store '(timestamp, value)' pair in 'key' bucket.
        keyTimeMap.get(key).put(timestamp, value);
    }
    
    public String get(String key, int timestamp) {
        // If the 'key' does not exist in map we will return empty string.
        if (!keyTimeMap.containsKey(key)) {
            return "";
        }
        
        Integer floorKey = keyTimeMap.get(key).floorKey(timestamp);
        // Return searched time's value, if exists.
        if (floorKey != null) {
            return keyTimeMap.get(key).get(floorKey);
        }
        
        return "";
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
from sortedcontainers import SortedDict

class TimeMap:
    def __init__(self):
        self.key_time_map = {}

    def set(self, key: str, value: str, timestamp: int) -> None:
        # If the 'key' does not exist in dictionary.
        if not key in self.key_time_map:
            self.key_time_map[key] = SortedDict()
            
        # Store '(timestamp, value)' pair in 'key' bucket.
        self.key_time_map[key][timestamp] = value
        

    def get(self, key: str, timestamp: int) -> str:
        # If the 'key' does not exist in dictionary we will return empty string.
        if not key in self.key_time_map:
            return ""
        
        it = self.key_time_map[key].bisect_right(timestamp)
        # If iterator points to first element it means, no time <= timestamp exists.
        if it == 0:
            return ""
        
        # Return value stored at previous position of current iterator.
        return self.key_time_map[key].peekitem(it - 1)[1]
```

</details>

<br>

## Approach 3: Array + Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> keyTimeMap;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        // Push '(timestamp, value)' pair in 'key' bucket.
        keyTimeMap[key].push_back({ timestamp, value });
    }
    
    string get(string key, int timestamp) {
        // If the 'key' does not exist in map we will return empty string.
        if (keyTimeMap.find(key) == keyTimeMap.end()) {
            return "";
        }
        
        if (timestamp < keyTimeMap[key][0].first) {
            return "";
        }
        
        // Using binary search on the array of pairs.
        int left = 0;
        int right = keyTimeMap[key].size();
        
        while (left < right) {
            int mid = (left + right) / 2;
            if (keyTimeMap[key][mid].first <= timestamp) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        // If iterator points to first element it means, no time <= timestamp exists.
        if (right == 0) {
            return "";
        }
                
        return keyTimeMap[key][right - 1].second;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class TimeMap {
    HashMap<String, ArrayList<Pair<Integer, String>>> keyTimeMap;
    
    public TimeMap() {
        keyTimeMap = new HashMap();
    }
    
    public void set(String key, String value, int timestamp) {
        if (!keyTimeMap.containsKey(key)) {
            keyTimeMap.put(key, new ArrayList());
        }
        
        // Store '(timestamp, value)' pair in 'key' bucket.
        keyTimeMap.get(key).add(new Pair(timestamp, value));
    }
    
    public String get(String key, int timestamp) {
        // If the 'key' does not exist in map we will return empty string.
        if (!keyTimeMap.containsKey(key)) {
            return "";
        }
        
        if (timestamp < keyTimeMap.get(key).get(0).getKey()) {
            return "";
        }
        
        // Using binary search on the list of pairs.
        int left = 0;
        int right = keyTimeMap.get(key).size();
        
        while (left < right) {
            int mid = (left + right) / 2;
            if (keyTimeMap.get(key).get(mid).getKey() <= timestamp) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        // If iterator points to first element it means, no time <= timestamp exists.
        if (right == 0) {
            return "";
        }
                
        return keyTimeMap.get(key).get(right - 1).getValue();
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
let keyTimeMap = {};
var TimeMap = function() { 
    keyTimeMap = {};
};

TimeMap.prototype.set = function(key, value, timestamp) {
    // If the 'key' does not exist in dictionary.
    if (!(key in keyTimeMap)) {
        keyTimeMap[key] = Array();
    }

    // Store '(timestamp, value)' pair in 'key' bucket.
    keyTimeMap[key].push([ timestamp, value ]);
};


TimeMap.prototype.get = function(key, timestamp) {
    // If the 'key' does not exist in dictionary we will return empty string.
    if (!(key in keyTimeMap)) {
        return "";
    }
    
    if (timestamp < keyTimeMap[key][0][0]) {
        return "";
    }
    
    let left = 0;
    let right = keyTimeMap[key].length;

    while (left < right) {
        let mid = Math.floor((left + right) / 2);
        if (keyTimeMap[key][mid][0] <= timestamp) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    // If iterator points to first element it means, no time <= timestamp exists.
    if (right == 0) {
        return "";
    }

    return keyTimeMap[key][right - 1][1];
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class TimeMap:
    def __init__(self):
        self.key_time_map = {}

    def set(self, key: str, value: str, timestamp: int) -> None:
        # If the 'key' does not exist in dictionary.
        if not key in self.key_time_map:
            self.key_time_map[key] = []
            
        # Store '(timestamp, value)' pair in 'key' bucket.
        self.key_time_map[key].append([ timestamp, value ])
        

    def get(self, key: str, timestamp: int) -> str:
        # If the 'key' does not exist in dictionary we will return empty string.
        if not key in self.key_time_map:
            return ""
        
        if timestamp < self.key_time_map[key][0][0]:
            return ""
        
        left = 0
        right = len(self.key_time_map[key])
        
        while left < right:
            mid = (left + right) // 2
            if self.key_time_map[key][mid][0] <= timestamp:
                left = mid + 1
            else:
                right = mid

        # If iterator points to first element it means, no time <= timestamp exists.
        return "" if right == 0 else self.key_time_map[key][right - 1][1]
```

</details>
