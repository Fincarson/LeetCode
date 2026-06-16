# 649. Dota2 Senate

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/dota2-senate/)  
`String` `Greedy` `Queue`

**Problem Link:** [LeetCode 649 - Dota2 Senate](https://leetcode.com/problems/dota2-senate/)

## Problem

In the world of Dota2, there are two parties: the Radiant and the Dire.

The Dota2 senate consists of senators coming from two parties. Now the Senate wants to decide on a change in the Dota2 game. The voting for this change is a round-based procedure. In each round, each senator can exercise one of the two rights:

- Ban one senator's right: A senator can make another senator lose all his rights in this and all the following rounds.
- Announce the victory: If this senator found the senators who still have rights to vote are all from the same party, he can announce the victory and decide on the change in the game.

Given a string senate representing each senator's party belonging. The character 'R' and 'D' represent the Radiant party and the Dire party. Then if there are n senators, the size of the given string will be n.

The round-based procedure starts from the first senator to the last senator in the given order. This procedure will last until the end of voting. All the senators who have lost their rights will be skipped during the procedure.

Suppose every senator is smart enough and will play the best strategy for his own party. Predict which party will finally announce the victory and change the Dota2 game. The output should be "Radiant" or "Dire".

### Example 1

```text
Input: senate = "RD"
Output: "Radiant"
Explanation:
The first senator comes from Radiant and he can just ban the next senator's right in round 1.
And the second senator can't exercise any rights anymore since his right has been banned.
And in round 2, the first senator can just announce the victory since he is the only guy in the senate who can vote.
```

### Example 2

```text
Input: senate = "RDD"
Output: "Dire"
Explanation:
The first senator comes from Radiant and he can just ban the next senator's right in round 1.
And the second senator can't exercise any rights anymore since his right has been banned.
And the third senator comes from Dire and he can ban the first senator's right in round 1.
And in round 2, the third senator can just announce the victory since he is the only guy in the senate who can vote.
```

## Constraints

- n == senate.length
- 1 <= n <= 104
- senate[i] is either 'R' or 'D'.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Teemo Attacking](https://leetcode.com/problems/teemo-attacking/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 649. Dota2 Senate

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Greedy | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Boolean Array | C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Binary Search | C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Two Queues | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |
| Single Queue | C, C++, C#, Go, Java, JavaScript, Python3, TypeScript |

## Approach 1: Greedy

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
char *predictPartyVictory(char *senate) {
    
    // Count of Each Type of Senator to check for Winner
    int rCount = 0, dCount = 0;
    for (int i = 0; senate[i] != '\0'; i++) {
        if (senate[i] == 'R') {
            rCount++;
        } else {
            dCount++;
        }
    }

    // Ban the candidate "toBan", immediate next to "startAt"
    // If have to loop around, then it means next turn will be of
    // senator at same index. Returns loop around boolean
    bool ban(char toBan, int startAt) {
        bool loopAround = false;
        int pointer = startAt;

        while (true) {
            if (pointer == 0) {
                loopAround = true;
            }
            if (senate[pointer] == toBan) {
                for (int i = pointer; senate[i] != '\0'; i++) {
                    senate[i] = senate[i + 1];
                }
                break;
            }
            pointer = (pointer + 1) % strlen(senate);
        }

        return loopAround;
    }

    // Turn of Senator at this index
    int turn = 0;

    // While No Winner
    while (rCount > 0 && dCount > 0) {

        // Ban the next opponent, starting at one index ahead
        // Taking MOD to loop around.
        // If index of banned senator is before current index,
        // then we need to decrement turn by 1, as we have removed
        // a senator from list
        if (senate[turn] == 'R') {
            bool bannedSenatorBefore = ban('D', (turn + 1) % strlen(senate));
            dCount--;
            if (bannedSenatorBefore) {
                turn--;
            }
        } else {
            bool bannedSenatorBefore = ban('R', (turn + 1) % strlen(senate));
            rCount--;
            if (bannedSenatorBefore) {
                turn--;
            }
        }

        // Increment turn by 1
        turn = (turn + 1) % strlen(senate);
    }

    // Return Winner depending on count
    return dCount == 0 ? "Radiant" : "Dire";
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
  string predictPartyVictory(string senate) {

    // Count of Each Type of Senator to check for Winner
    int rCount = count(senate.begin(), senate.end(), 'R');
    int dCount = senate.size() - rCount;

    // Ban the candidate "toBan", immediate next to "startAt"
    // If have to loop around, then it means next turn will be of
    // senator at same index. Returns loop around boolean
    auto ban = [&](char toBan, int startAt) {
      bool loopAround = false;
      int pointer = startAt;

      while (true) {
        if (pointer == 0) {
          loopAround = true;
        }
        if (senate[pointer] == toBan) {
          senate.erase(senate.begin() + pointer);
          break;
        }
        pointer = (pointer + 1) % senate.size();
      }

      return loopAround;
    };

    // Turn of Senator at this index
    int turn = 0;

    // While No Winner
    while (rCount > 0 && dCount > 0) {

      // Ban the next opponent, starting at one index ahead
      // Taking MOD to loop around.
      // If index of banned senator is before current index,
      // then we need to decrement turn by 1, as we have removed
      // a senator from list
      if (senate[turn] == 'R') {
        bool bannedSenatorBefore = ban('D', (turn + 1) % senate.size());
        dCount--;
        if (bannedSenatorBefore) {
          turn--;
        }
      } else {
        bool bannedSenatorBefore = ban('R', (turn + 1) % senate.size());
        rCount--;
        if (bannedSenatorBefore) {
          turn--;
        }
      }

      // Increment turn by 1
      turn = (turn + 1) % senate.size();
    }

    // Return Winner depending on count
    return dCount == 0 ? "Radiant" : "Dire";
  }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public string PredictPartyVictory(string senate) {
        
        // Count of Each Type of Senator to check for Winner
        int rCount = senate.Count(c => c == 'R');
        int dCount = senate.Length - rCount;

        // Ban the candidate "toBan", immediate next to "startAt"
        // If have to loop around, then it means next turn will be of
        // senator at same index. Returns loop around boolean
        bool ban(char toBan, int startAt) {
            bool loopAround = false;
            int pointer = startAt;

            while (true) {
                if (pointer == 0) {
                    loopAround = true;
                }
                if (senate[pointer] == toBan) {
                    senate = senate.Remove(pointer, 1);
                    break;
                }
                pointer = (pointer + 1) % senate.Length;
            }

            return loopAround;
        }

        // Turn of Senator at this index
        int turn = 0;

        // While No Winner
        while (rCount > 0 && dCount > 0) {

            // Ban the next opponent, starting at one index ahead
            // Taking MOD to loop around.
            // If index of banned senator is before current index,
            // then we need to decrement turn by 1, as we have removed
            // a senator from list
            if (senate[turn] == 'R') {
                bool bannedSenatorBefore = ban('D', (turn + 1) % senate.Length);
                dCount--;
                if (bannedSenatorBefore) {
                    turn--;
                }
            } else {
                bool bannedSenatorBefore = ban('R', (turn + 1) % senate.Length);
                rCount--;
                if (bannedSenatorBefore) {
                    turn--;
                }
            }

            // Increment turn by 1
            turn = (turn + 1) % senate.Length;
        }

        // Return Winner depending on count
        return dCount == 0 ? "Radiant" : "Dire";
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func predictPartyVictory(senate string) string {
    
    // Count of Each Type of Senator to check for Winner
    rCount := 0
    dCount := 0
    for _, c := range senate {
        if c == 'R' {
            rCount++
        } else {
            dCount++
        }
    }

    // Ban the candidate "toBan", immediate next to "startAt"
    // If have to loop around, then it means next turn will be of
    // senator at same index. Returns loop around boolean
    ban := func(toBan byte, startAt int) bool {
        loopAround := false
        pointer := startAt

        for {
            if pointer == 0 {
                loopAround = true
            }
            if senate[pointer] == toBan {
                senate = senate[:pointer] + senate[pointer+1:]
                break
            }
            pointer = (pointer + 1) % len(senate)
        }

        return loopAround
    }

    // Turn of Senator at this index
    turn := 0

    // While No Winner
    for rCount > 0 && dCount > 0 {

        // Ban the next opponent, starting at one index ahead
        // Taking MOD to loop around.
        // If index of banned senator is before current index,
        // then we need to decrement turn by 1, as we have removed
        // a senator from list
        if senate[turn] == 'R' {
            bannedSenatorBefore := ban('D', (turn + 1) % len(senate))
            dCount--
            if bannedSenatorBefore {
                turn--
            }
        } else {
            bannedSenatorBefore := ban('R', (turn + 1) % len(senate))
            rCount--
            if bannedSenatorBefore {
                turn--
            }
        }

        // Increment turn by 1
        turn = (turn + 1) % len(senate)
    }

    // Return Winner depending on the count
    if dCount == 0 {
        return "Radiant"
    } else {
        return "Dire"
    }
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    // Ban the candidate "toBan", immediate next to "startAt"
    // If have to loop around, then it means next turn will be of
    // senator at same index. Returns loop around boolean
    public boolean ban(StringBuilder senateArray, char toBan, int startAt) {

        boolean loopAround = false;
        int pointer = startAt;

        while (true) {
            if (pointer == 0) {
                loopAround = true;
            }
            if (senateArray.charAt(pointer) == toBan) {
                senateArray.deleteCharAt(pointer);
                break;
            }
            pointer = (pointer + 1) % senateArray.length();
        }

        return loopAround;
    }

    public String predictPartyVictory(String senate) {

        // Convert to StringBuilder for easy deletion
        StringBuilder senateArray = new StringBuilder(senate);

        // Count of Each Type of Senator to check for Winner
        int rCount = 0;
        int dCount = 0;
        for (int i = 0; i < senateArray.length(); i++) {
            if (senateArray.charAt(i) == 'R') {
                rCount++;
            } else {
                dCount++;
            }
        }

        // Turn of Senator at this index
        int turn = 0;

        // While No Winner
        while (rCount > 0 && dCount > 0) {

            // Ban the next opponent, starting at one index ahead
            // Taking MOD to loop around.
            // If index of banned senator is before current index,
            // then we need to decrement turn by 1, as we have removed
            // a senator from list
            if (senateArray.charAt(turn) == 'R') {
                boolean bannedSenatorBefore = ban(senateArray, 'D', (turn + 1) % senateArray.length());
                if (bannedSenatorBefore) {
                    turn--;
                }
                dCount--;
            } else {
                boolean bannedSenatorBefore = ban(senateArray, 'R', (turn + 1) % senateArray.length());
                if (bannedSenatorBefore) {
                    turn--;
                }
                rCount--;
            }

            // Increment Turn
            turn = (turn + 1) % senateArray.length();
        }

        // Return Winner
        if (rCount > 0) {
            return "Radiant";
        } else {
            return "Dire";
        }
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {string} senate
 * @return {string}
 */

var predictPartyVictory = function(senate) {
    
    // Count of Each Type of Senator to check for Winner
    let rCount = 0, dCount = 0;
    for (let i = 0; i < senate.length; i++) {
        if (senate[i] == 'R') {
            rCount++;
        } else {
            dCount++;
        }
    }

    // Ban the candidate "toBan", immediate next to "startAt"
    // If have to loop around, then it means next turn will be of
    // senator at same index. Returns loop around boolean
    const ban = (toBan, startAt) => {
        let loopAround = false;
        let pointer = startAt;

        while (true) {
            if (pointer == 0) {
                loopAround = true;
            }
            if (senate[pointer] == toBan) {
                senate = senate.slice(0, pointer) + senate.slice(pointer + 1);
                break;
            }
            pointer = (pointer + 1) % senate.length;
        }

        return loopAround;
    }

    // Turn of Senator at this index
    let turn = 0;

    // While No Winner
    while (rCount > 0 && dCount > 0) {

        // Ban the next opponent, starting at one index ahead
        // Taking MOD to loop around.
        // If index of banned senator is before current index,
        // then we need to decrement turn by 1, as we have removed
        // a senator from list
        if (senate[turn] == 'R') {
            let bannedSenatorBefore = ban('D', (turn + 1) % senate.length);
            dCount--;
            if (bannedSenatorBefore) {
                turn--;
            }
        } else {
            let bannedSenatorBefore = ban('R', (turn + 1) % senate.length);
            rCount--;
            if (bannedSenatorBefore) {
                turn--;
            }
        }

        // Increment turn by 1
        turn = (turn + 1) % senate.length;
    }

    // Return Winner depending on count
    return dCount == 0 ? "Radiant" : "Dire";
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def predictPartyVictory(self, senate: str) -> str:

        # Converting to List as string is immutable, and we need to remove.
        # List will save only eligible senators
        senate = list(senate)

        # Count of Each Type of Senator to check for Winner
        r_count = senate.count('R')
        d_count = len(senate) - r_count

        # Ban the candidate "to_ban", immediate next to "start_at"
        # If have to loop around, then it means next turn will be of
        # senator at same index. Returns loop around boolean
        def ban(to_ban, start_at):

            loop_around = False
            pointer = start_at

            while True:
                if pointer == 0:
                    loop_around = True
                if senate[pointer] == to_ban:
                    senate.pop(pointer)
                    break
                pointer = (pointer + 1) % len(senate)

            return loop_around

        # Turn of Senator at this index
        turn = 0

        # While No Winner
        while r_count > 0 and d_count > 0:

            # Ban the next opponent, starting at one index ahead
            # Taking MOD to loop around
            if senate[turn] == 'R':
                banned_senator_before = ban('D', (turn + 1) % len(senate))
                d_count -= 1
            else:
                banned_senator_before = ban('R', (turn + 1) % len(senate))
                r_count -= 1

            # If the index of the banned senator is before current index,
            # then we need to decrement turn by 1, as we have removed
            # a senator from the list
            if banned_senator_before:
                turn -= 1

            # Increment turn by 1
            turn = (turn + 1) % len(senate)

        # Return Winner depending on the count
        return 'Radiant' if d_count == 0 else 'Dire'
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function predictPartyVictory(senate: string): string {
    
    // Count of Each Type of Senator to check for Winner
    let rCount = 0;
    let dCount = 0;
    for (let i = 0; i < senate.length; i++) {
        if (senate[i] == 'R') {
            rCount++;
        } else {
            dCount++;
        }
    }

    // Ban the candidate "toBan", immediate next to "startAt"
    // If have to loop around, then it means next turn will be of
    // senator at same index. Returns loop around boolean
    const ban = (toBan: string, startAt: number): boolean => {
        let loopAround = false;
        let pointer = startAt;

        while (true) {
            if (pointer == 0) {
                loopAround = true;
            }
            if (senate[pointer] == toBan) {
                senate = senate.slice(0, pointer) + senate.slice(pointer + 1);
                break;
            }
            pointer = (pointer + 1) % senate.length;
        }

        return loopAround;
    }

    // Turn of Senator at this index
    let turn = 0;

    // While No Winner
    while (rCount > 0 && dCount > 0) {

        // Ban the next opponent, starting at one index ahead
        // Taking MOD to loop around.
        // If index of banned senator is before current index,
        // then we need to decrement turn by 1, as we have removed
        // a senator from list
        if (senate[turn] == 'R') {
            const bannedSenatorBefore = ban('D', (turn + 1) % senate.length);
            dCount--;
            if (bannedSenatorBefore) {
                turn--;
            }
        } else {
            const bannedSenatorBefore = ban('R', (turn + 1) % senate.length);
            rCount--;
            if (bannedSenatorBefore) {
                turn--;
            }
        }

        // Increment turn by 1
        turn = (turn + 1) % senate.length;
    }

    // Return Winner depending on count
    if (dCount == 0) {
        return "Radiant";
    } else {
        return "Dire";
    }
};
```

</details>

<br>

## Approach 2: Boolean Array

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
  string predictPartyVictory(string senate) {

    // Count of Each Type of Senator to check for Winner
    int rCount = count(senate.begin(), senate.end(), 'R');
    int dCount = senate.size() - rCount;

    // To mark Banned Senators
    vector<bool> banned(senate.size(), false);

    // Ban the candidate "toBan", immediate next to "startAt"
    auto ban = [&](char toBan, int startAt) {
      // Find the next eligible senator of "toBan" type
      // On found, mark him as banned
      while (true) {
        if (senate[startAt] == toBan && !banned[startAt]) {
          banned[startAt] = true;
          break;
        }
        startAt = (startAt + 1) % senate.size();
      }
    };

    // Turn of Senator at this Index
    int turn = 0;

    // While both parties have at least one senator
    while (rCount > 0 && dCount > 0) {

      if (!banned[turn]) {
        if (senate[turn] == 'R') {
          ban('D', (turn + 1) % senate.size());
          dCount--;
        } else {
          ban('R', (turn + 1) % senate.size());
          rCount--;
        }
      }

      turn = (turn + 1) % senate.size();
    }

    return dCount == 0 ? "Radiant" : "Dire";
  }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public string PredictPartyVictory(string senate) {
        
        // Count of Each Type of Senator to check for Winner
        int rCount = senate.Count(x => x == 'R');
        int dCount = senate.Length - rCount;

        // To mark Banned Senators
        bool[] banned = new bool[senate.Length];

        // Ban the candidate "toBan", immediate next to "startAt"
        Action<char, int> ban = (toBan, startAt) => {
            // Find the next eligible senator of "toBan" type
            // On found, mark him as banned
            while (true) {
                if (senate[startAt] == toBan && !banned[startAt]) {
                    banned[startAt] = true;
                    break;
                }
                startAt = (startAt + 1) % senate.Length;
            }
        };

        // Turn of Senator at this Index
        int turn = 0;

        // While both parties have at least one senator
        while (rCount > 0 && dCount > 0) {

            if (!banned[turn]) {
                if (senate[turn] == 'R') {
                    ban('D', (turn + 1) % senate.Length);
                    dCount--;
                } else {
                    ban('R', (turn + 1) % senate.Length);
                    rCount--;
                }
            }

            turn = (turn + 1) % senate.Length;
        }

        // Return Winner
        return dCount == 0 ? "Radiant" : "Dire";
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func predictPartyVictory(senate string) string {
    
    // Count of Each Type of Senator to check for Winner
    rCount := strings.Count(senate, "R")
    dCount := len(senate) - rCount

    // To mark Banned Senators
    banned := make([]bool, len(senate))

    // Ban the candidate "toBan", immediate next to "startAt"
    ban := func(toBan byte, startAt int) {
        // Find the next eligible senator of "toBan" type
        // On found, mark him as banned
        for {
            if senate[startAt] == toBan && !banned[startAt] {
                banned[startAt] = true
                break
            }
            startAt = (startAt + 1) % len(senate)
        }
    }

    // Turn of Senator at this Index
    turn := 0

    // While both parties have at least one senator
    for rCount > 0 && dCount > 0 {

        if !banned[turn] {
            if senate[turn] == 'R' {
                ban('D', (turn + 1) % len(senate))
                dCount--
            } else {
                ban('R', (turn + 1) % len(senate))
                rCount--
            }
        }

        turn = (turn + 1) % len(senate)
    }

    // Return Winner depending on the count of each party
    if dCount == 0 {
        return "Radiant"
    }
    return "Dire"
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    // Ban the candidate "toBan", immediate next to "startAt"
    public void ban(String senate, boolean[] banned, char toBan, int startAt) {
        // Find the next eligible candidate to ban
        int pointer = startAt;
        while (true) {
            if (senate.charAt(pointer) == toBan && !banned[pointer]) {
                banned[pointer] = true;
                break;
            }
            pointer = (pointer + 1) % senate.length();
        }
    }

    public String predictPartyVictory(String senate) {

        // To mark Banned Senators
        boolean[] banned = new boolean[senate.length()];

        // Count of Each Type of Senator who are not-banned
        int rCount = 0, dCount = 0;
        for (int i = 0; i < senate.length(); i++) {
            if (senate.charAt(i) == 'R') {
                rCount++;
            } else {
                dCount++;
            }
        }

        // Turn of Senator at this Index
        int turn = 0;

        // While both parties have at least one senator
        while (rCount > 0 && dCount > 0) {

            if (!banned[turn]) {
                if (senate.charAt(turn) == 'R') {
                    ban(senate, banned, 'D', (turn + 1) % senate.length());
                    dCount--;
                } else {
                    ban(senate, banned, 'R', (turn + 1) % senate.length());
                    rCount--;
                }
            }

            turn = (turn + 1) % senate.length();
        }

        return dCount == 0 ? "Radiant" : "Dire";
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {string} senate
 * @return {string}
 */

var predictPartyVictory = function(senate) {
    
    // Count of Each Type of Senator to check for the Winner
    let rCount = senate.split('').filter(x => x == 'R').length;
    let dCount = senate.length - rCount;

    // To mark Banned Senators
    let banned = new Array(senate.length).fill(false);

    // Ban the candidate "toBan", immediate next to "startAt"
    let ban = (toBan, startAt) => {
        // Find the next eligible senator of "toBan" type
        // On found, mark him as banned
        while (true) {
            if (senate[startAt] == toBan && !banned[startAt]) {
                banned[startAt] = true;
                break;
            }
            startAt = (startAt + 1) % senate.length;
        }
    };

    // Turn of Senator at this Index
    let turn = 0;

    // While both parties have at least one senator
    while (rCount > 0 && dCount > 0) {

        if (!banned[turn]) {
            if (senate[turn] == 'R') {
                ban('D', (turn + 1) % senate.length);
                dCount--;
            } else {
                ban('R', (turn + 1) % senate.length);
                rCount--;
            }
        }

        turn = (turn + 1) % senate.length;
    }

    // Return Winner
    return dCount == 0 ? "Radiant" : "Dire";
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def predictPartyVictory(self, senate: str) -> str:

        # Number of Senators
        N = len(senate)

        # To mark Banned Senators
        banned = [False] * N

        # Count of Each Type of Senator who are not-banned
        r_count = senate.count('R')
        d_count = N - r_count

        # Ban the candidate "to_ban", immediate next to "start_at"
        def ban(to_ban, start_at):

            # Find the next eligible senator of "to_ban" type
            # On found, mark him as banned
            pointer = start_at
            while True:
                if senate[pointer] == to_ban and not banned[pointer]:
                    banned[pointer] = True
                    break
                pointer = (pointer + 1) % len(senate)

        # Turn of Senator at this Index
        turn = 0

        # While both parties have at least one senator
        while r_count > 0 and d_count > 0:

            if not banned[turn]:
                if senate[turn] == 'R':
                    ban('D', (turn + 1) % N)
                    d_count -= 1
                else:
                    ban('R', (turn + 1) % N)
                    r_count -= 1

            turn = (turn + 1) % N

        return 'Radiant' if d_count == 0 else 'Dire'
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function predictPartyVictory(senate: string): string {
    
    // Count of Each Type of Senator to check for Winner
    let rCount = senate.split('R').length - 1;
    let dCount = senate.length - rCount;

    // To mark Banned Senators
    let banned = new Array(senate.length).fill(false);

    // Ban the candidate "toBan", immediate next to "startAt"
    let ban = (toBan: string, startAt: number) => {
        // Find the next eligible senator of "toBan" type
        // On found, mark him as banned
        while (true) {
            if (senate[startAt] == toBan && !banned[startAt]) {
                banned[startAt] = true;
                break;
            }
            startAt = (startAt + 1) % senate.length;
        }
    };

    // Turn of Senator at this Index
    let turn = 0;

    // While both parties have at least one senator
    while (rCount > 0 && dCount > 0) {

        if (!banned[turn]) {
            if (senate[turn] == 'R') {
                ban('D', (turn + 1) % senate.length);
                dCount--;
            } else {
                ban('R', (turn + 1) % senate.length);
                rCount--;
            }
        }

        turn = (turn + 1) % senate.length;
    }

    // Return Winner depending on the count of each party
    return dCount == 0 ? "Radiant" : "Dire";
};
```

</details>

<br>

## Approach 3: Binary Search

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
  string predictPartyVictory(string senate) {

    // Number of Senators
    int n = senate.size();

    // To mark Banned Senators
    vector<bool> banned(n, false);

    // List of indices of Eligible Radiant and Dire Senators
    vector<int> rIndices, dIndices;
    for (int i = 0; i < n; i++) {
      if (senate[i] == 'R')
        rIndices.push_back(i);
      else
        dIndices.push_back(i);
    }

    // Ban the senator of "indices" array next to "startAt"
    auto ban = [&](vector<int> &indices, int start_at) {
      // Find the index of "index of senator to ban" using Binary Search
      auto temp = lower_bound(indices.begin(), indices.end(), start_at);

      // If start_at is more than the last index,
      // then start from the beginning. Ban the first senator
      if (temp == indices.end()) {
        banned[indices[0]] = true;
        indices.erase(indices.begin());
      }

      // Else, Ban the senator at the index
      else {
        banned[*temp] = true;
        indices.erase(temp);
      }
    };

    // Turn of Senator at this Index
    int turn = 0;

    // While both parties have at least one senator
    while (!rIndices.empty() && !dIndices.empty()) {

      if (!banned[turn]) {
        if (senate[turn] == 'R')
          ban(dIndices, turn);
        else
          ban(rIndices, turn);
      }

      turn = (turn + 1) % n;
    }

    // Return the party with at least one senator
    return dIndices.empty() ? "Radiant" : "Dire";
  }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public string PredictPartyVictory(string senate) {

        // Number of Senators
        int n = senate.Length;

        // To mark Banned Senators
        bool[] banned = new bool[n];

        // List of indices of Eligible Radiant and Dire Senators
        List<int> rIndices = new List<int>();
        List<int> dIndices = new List<int>();
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R')
                rIndices.Add(i);
            else
                dIndices.Add(i);
        }

        // Ban the senator of "indices" immediate next to "startAt"
        Action<List<int>, int> ban = (indices, startAt) => {
            // Find the index of "index of senator to ban" using Binary Search
            int temp = indices.BinarySearch(startAt);

            // If startAt is more than the last index,
            // then start from the beginning. Ban the first senator
            if (temp < 0) {
                temp = ~temp;
                if (temp == indices.Count) {
                    banned[indices[0]] = true;
                    indices.RemoveAt(0);
                }

                // Else, Ban the senator at the index
                else {
                    banned[indices[temp]] = true;
                    indices.RemoveAt(temp);
                }
            }

            // Else, Ban the senator at the index
            else {
                banned[indices[temp]] = true;
                indices.RemoveAt(temp);
            }
        };

        // Turn of Senator at this Index
        int turn = 0;

        // While both parties have at least one senator
        while (rIndices.Count > 0 && dIndices.Count > 0) {

            if (!banned[turn]) {
                if (senate[turn] == 'R')
                    ban(dIndices, turn);
                else
                    ban(rIndices, turn);
            }

            turn = (turn + 1) % n;
        }

        // Return the party with at least one senator
        return dIndices.Count == 0 ? "Radiant" : "Dire";
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func predictPartyVictory(senate string) string {

    // Number of Senators
    n := len(senate)

    // To mark Banned Senators
    banned := make([]bool, n)

    // List of indices of Eligible Radiant and Dire Senators
    rIndices := []int{}
    dIndices := []int{}
    for i := 0; i < n; i++ {
        if senate[i] == 'R' {
            rIndices = append(rIndices, i)
        } else {
            dIndices = append(dIndices, i)
        }
    }

    // Ban the senator of "indices" immediate next to "startAt"
    ban := func(indices *[]int, startAt int) {
        // Find the index of "index of senator to ban" using Binary Search
        temp := sort.SearchInts(*indices, startAt)

        // If startAt is more than the last index,
        // then start from the beginning. Ban the first senator
        if temp == len(*indices) {
            banned[(*indices)[0]] = true
            *indices = (*indices)[1:]
        } else {
            banned[(*indices)[temp]] = true
            *indices = append((*indices)[:temp], (*indices)[temp+1:]...)
        }
    }

    // Turn of Senator at this Index
    turn := 0

    // While both parties have at least one senator
    for len(rIndices) > 0 && len(dIndices) > 0 {
        if !banned[turn] {
            if senate[turn] == 'R' {
                ban(&dIndices, turn)
            } else {
                ban(&rIndices, turn)
            }
        }

        turn = (turn + 1) % n
    }

    // Return the party with at least one senator
    if len(dIndices) == 0 {
        return "Radiant"
    } else {
        return "Dire"
    }
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
  public String predictPartyVictory(String senate) {

    // Number of Senators
    int n = senate.length();

    // To mark Banned Senators
    boolean[] banned = new boolean[n];

    // List of indices of Eligible Radiant and Dire Senators
    List<Integer> rIndices = new ArrayList<>();
    List<Integer> dIndices = new ArrayList<>();
    for (int i = 0; i < n; i++) {
      if (senate.charAt(i) == 'R')
        rIndices.add(i);
      else
        dIndices.add(i);
    }

    // Ban the senator of "indices" array next to "startAt"
    BiConsumer<List<Integer>, Integer> ban = (indices, start_at) -> {
      // Find the index of "index of senator to ban" using Binary Search
      int temp = Collections.binarySearch(indices, start_at);

      // If start_at is more than the last index,
      // then start from the beginning. Ban the first senator
      if (temp < 0) {
        temp = -temp - 1;
        if (temp == indices.size()) {
          banned[indices.get(0)] = true;
          indices.remove(0);
        }

        // Else, Ban the senator at the index
        else {
          banned[indices.get(temp)] = true;
          indices.remove(temp);
        }
      }
    };

    // Turn of Senator at this Index
    int turn = 0;

    // While both parties have at least one senator
    while (!rIndices.isEmpty() && !dIndices.isEmpty()) {

      if (!banned[turn]) {
        if (senate.charAt(turn) == 'R')
          ban.accept(dIndices, turn);
        else
          ban.accept(rIndices, turn);
      }

      turn = (turn + 1) % n;
    }

    return dIndices.isEmpty() ? "Radiant" : "Dire";
  }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {string} senate
 * @return {string}
 */

var predictPartyVictory = function(senate) {

    // Number of Senators
    let n = senate.length;

    // To mark Banned Senators
    let banned = new Array(n).fill(false);

    // List of indices of Eligible Radiant and Dire Senators
    let rIndices = [];
    let dIndices = [];
    for (let i = 0; i < n; i++) {
        if (senate[i] == 'R')
            rIndices.push(i);
        else
            dIndices.push(i);
    }

    // Ban the senator of "indices" immediate next to "startAt"
    let ban = (indices, startAt) => {
        // Find the index of "index of senator to ban" using Binary Search
        let temp = indices.findIndex((x) => x >= startAt);

        // If startAt is more than the last index,
        // then start from the beginning. Ban the first senator
        if (temp == -1) {
            banned[indices[0]] = true;
            indices.shift();
        }

        // Else, Ban the senator at the index
        else {
            banned[indices[temp]] = true;
            indices.splice(temp, 1);
        }
    };

    // Turn of Senator at this Index
    let turn = 0;

    // While both parties have at least one senator
    while (rIndices.length > 0 && dIndices.length > 0) {

        if (!banned[turn]) {
            if (senate[turn] == 'R')
                ban(dIndices, turn);
            else
                ban(rIndices, turn);
        }

        turn = (turn + 1) % n;
    }

    // Return the party with at least one senator
    return dIndices.length == 0 ? "Radiant" : "Dire";
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def predictPartyVictory(self, senate: str) -> str:

        # Number of Senators
        N = len(senate)

        # To mark Banned Senators
        banned = [False] * N

        # List of indices of Eligible Radiant and Dire Senators
        r_indices = [i for i in range(N) if senate[i] == 'R']
        d_indices = [i for i in range(N) if senate[i] == 'D']

        # Ban the senator of "indices" array next to "start_at"
        def ban(indices_array, start_at):

            # Find the index of "index of senator to ban" using Binary Search
            temp = bisect.bisect_left(indices_array, start_at)

            # If start_at is more than the last index,
            # then start from the beginning. Ban the first senator
            if temp == len(indices_array):
                banned[indices_array.pop(0)] = True

            # Else, Ban the senator at the index
            else:
                banned[indices_array.pop(temp)] = True

        # Turn of Senator at this Index
        turn = 0

        # While both parties have at least one senator
        while r_indices and d_indices:

            if not banned[turn]:
                if senate[turn] == 'R':
                    ban(d_indices, turn)
                else:
                    ban(r_indices, turn)

            turn = (turn + 1) % N

        return 'Radiant' if d_indices == [] else 'Dire'
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function predictPartyVictory(senate: string): string {

    // Number of Senators
    const n = senate.length;

    // To mark Banned Senators
    const banned = new Array(n).fill(false);

    // List of indices of Eligible Radiant and Dire Senators
    const rIndices: number[] = [];
    const dIndices: number[] = [];
    for (let i = 0; i < n; i++) {
        if (senate[i] === 'R') {
            rIndices.push(i);
        } else {
            dIndices.push(i);
        }
    }

    // Ban the senator of "indices" immediate next to "startAt"
    function ban(indices: number[], startAt: number) {
        // Find the index of "index of senator to ban" using Binary Search
        const temp = indices.findIndex((x) => x >= startAt);

        // If startAt is more than the last index,
        // then start from the beginning. Ban the first senator
        if (temp === -1) {
            banned[indices[0]] = true;
            indices.shift();
        }

        // Else, Ban the senator at the index
        else {
            banned[indices[temp]] = true;
            indices.splice(temp, 1);
        }
    }

    // Turn of Senator at this Index
    let turn = 0;

    // While both parties have at least one senator
    while (rIndices.length > 0 && dIndices.length > 0) {
        if (!banned[turn]) {
            if (senate[turn] === 'R') {
                ban(dIndices, turn);
            } else {
                ban(rIndices, turn);
            }
        }

        turn = (turn + 1) % n;
    }

    // Return the party with at least one senator
    if (dIndices.length === 0) {
        return "Radiant";
    } else {
        return "Dire";
    }
}
```

</details>

<br>

## Approach 4: Two Queues

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
char * predictPartyVictory(char * senate){
    
    // Number of Senator
    int n = strlen(senate);

    // Queues with Senator's Index.
    // Index will be used to find the next turn of Senator
    // Using Circular Array to simulate Queue
    int rQueue[n];
    int dQueue[n];

    // Front and Rear of the Queues
    int rFront = 0, rRear = 0;
    int dFront = 0, dRear = 0;

    // Populate the Queues
    for (int i = 0; i < n; i++) {
        if (senate[i] == 'R') {
            rQueue[rRear++] = i;
        } else {
            dQueue[dRear++] = i;
        }
    }

    // While both parties have at least one Senator. 
    while (rFront != rRear && dFront != dRear) {
        
        // Pop the Next-Turn Senate from both Q.
        int rTurn = rQueue[rFront];
        rFront = (rFront + 1) % n;
        int dTurn = dQueue[dFront];
        dFront = (dFront + 1) % n;

        // ONE having a larger index will be banned by a lower index
        // Lower index will again get Turn, so EN-Queue again
        // But ensure its turn comes in the next round only
        if (dTurn < rTurn) {
            dQueue[dRear] = dTurn + n;
            dRear = (dRear + 1) % n;
        } else {
            rQueue[rRear] = rTurn + n;
            rRear = (rRear + 1) % n;
        }
    }

    // One's which Empty is not winner
    return rFront == rRear ? "Dire" : "Radiant";
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string predictPartyVictory(string senate) {
        
        // Number of Senator
        int n = senate.size();

        // Queues with Senator's Index.
        // Index will be used to find the next turn of Senator
        queue<int> rQueue;
        queue<int> dQueue;

        // Populate the Queues
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') {
                rQueue.push(i);
            } else {
                dQueue.push(i);
            }
        }

        // While both parties have at least one Senator
        while (!rQueue.empty() && !dQueue.empty()) {
            
            // Pop the Next-Turn Senate from both Q.
            int rTurn = rQueue.front();
            rQueue.pop();
            int dTurn = dQueue.front();
            dQueue.pop();

            // ONE having a larger index will be banned by a lower index
            // Lower index will again get Turn, so EN-Queue again
            // But ensure its turn comes in the next round only
            if (dTurn < rTurn) {
                dQueue.push(dTurn + n);
            } else {
                rQueue.push(rTurn + n);
            }
        }

        // One's which Empty is not winner
        return rQueue.empty() ? "Dire" : "Radiant";
    };
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public string PredictPartyVictory(string senate) {
        
        // Number of Senator
        int n = senate.Length;

        // Queues with Senator's Index.
        // Index will be used to find the next turn of Senator
        Queue<int> rQueue = new Queue<int>();
        Queue<int> dQueue = new Queue<int>();

        // Populate the Queues
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') {
                rQueue.Enqueue(i);
            } else {
                dQueue.Enqueue(i);
            }
        }

        // While both parties have at least one Senator
        while (rQueue.Count > 0 && dQueue.Count > 0) {
            
            // Pop the Next-Turn Senate from both Q.
            int rTurn = rQueue.Dequeue();
            int dTurn = dQueue.Dequeue();

            // ONE having a larger index will be banned by a lower index
            // Lower index will again get Turn, so EN-Queue again
            // But ensure its turn comes in the next round only
            if (dTurn < rTurn) {
                dQueue.Enqueue(dTurn + n);
            } else {
                rQueue.Enqueue(rTurn + n);
            }
        }

        // One's which Empty is not winner
        return rQueue.Count == 0 ? "Dire" : "Radiant";
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func predictPartyVictory(senate string) string {
    
    // Number of Senator
    n := len(senate)

    // Queues with Senator's Index.
    // Index will be used to find the next turn of Senator
    rQueue := []int{}
    dQueue := []int{}

    // Populate the Queues
    for i := 0; i < n; i++ {
        if senate[i] == 'R' {
            rQueue = append(rQueue, i)
        } else {
            dQueue = append(dQueue, i)
        }
    }

    // While both parties have at least one Senator
    for len(rQueue) > 0 && len(dQueue) > 0 {
        
        // Pop the Next-Turn Senate from both Q.
        rTurn := rQueue[0]
        rQueue = rQueue[1:]
        dTurn := dQueue[0]
        dQueue = dQueue[1:]

        // ONE having a larger index will be banned by a lower index
        // Lower index will again get Turn, so EN-Queue again
        // But ensure its turn comes in the next round only
        if dTurn < rTurn {
            dQueue = append(dQueue, dTurn + n)
        } else {
            rQueue = append(rQueue, rTurn + n)
        }
    }

    // One's which Empty is not winner
    if len(rQueue) == 0 {
        return "Dire"
    } else {
        return "Radiant"
    }
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String predictPartyVictory(String senate) {
        
        // Number of Senator
        int n = senate.length();

        // Queues with Senator's Index.
        // Index will be used to find the next turn of Senator
        Queue<Integer> rQueue = new LinkedList<>();
        Queue<Integer> dQueue = new LinkedList<>();

        // Populate the Queues
        for (int i = 0; i < n; i++) {
            if (senate.charAt(i) == 'R') {
                rQueue.add(i);
            } else {
                dQueue.add(i);
            }
        }

        // While both parties have at least one Senator
        while (!rQueue.isEmpty() && !dQueue.isEmpty()) {
            
            // Pop the Next-Turn Senate from both Q.
            int rTurn = rQueue.poll();
            int dTurn = dQueue.poll();

            // ONE having a larger index will be banned by a lower index
            // Lower index will again get Turn, so EN-Queue again
            // But ensure its turn comes in the next round only
            if (dTurn < rTurn) {
                dQueue.add(dTurn + n);
            } else {
                rQueue.add(rTurn + n);
            }
        }

        // One's which Empty is not winner
        return rQueue.isEmpty() ? "Dire" : "Radiant";
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {string} senate
 * @return {string}
 */

var predictPartyVictory = function(senate) {
    
    // Number of Senator
    let n = senate.length;

    // Queues with Senator's Index.
    // Index will be used to find the next turn of Senator
    let rQueue = [];
    let dQueue = [];

    // Populate the Queues
    for (let i = 0; i < n; i++) {
        if (senate[i] == 'R') {
            rQueue.push(i);
        } else {
            dQueue.push(i);
        }
    }

    // While both parties have at least one Senator
    while (rQueue.length > 0 && dQueue.length > 0) {
        
        // Pop the Next-Turn Senate from both Q.
        let rTurn = rQueue.shift();
        let dTurn = dQueue.shift();

        // ONE having a larger index will be banned by a lower index
        // Lower index will again get Turn, so EN-Queue again
        // But ensure its turn comes in the next round only
        if (dTurn < rTurn) {
            dQueue.push(dTurn + n);
        } else {
            rQueue.push(rTurn + n);
        }
    }

    // One's which Empty is not winner
    return rQueue.length == 0 ? "Dire" : "Radiant";
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def predictPartyVictory(self, senate: str) -> str:
        
        # Number of Senator
        n = len(senate)

        # Queues with Senator's Index.
        # Index will be used to find the next turn of Senator
        r_queue = deque()
        d_queue = deque()

        # Populate the Queues
        for i, s in enumerate(senate):
            if s == 'R':
                r_queue.append(i)
            else:
                d_queue.append(i)

        # While both parties have at least one Senator
        while r_queue and d_queue:
            
            # Pop the Next-Turn Senate from both Q.
            r_turn = r_queue.popleft()
            d_turn = d_queue.popleft()

            # ONE having a larger index will be banned by a lower index
            # Lower index will again get Turn, so EN-Queue again
            # But ensure its turn comes in the next round only
            if d_turn < r_turn:
                d_queue.append(d_turn + n)
            else:
                r_queue.append(r_turn + n)
        
        # One's which Empty is not the winner
        return "Radiant" if r_queue else "Dire"
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function predictPartyVictory(senate: string): string {
    
    // Number of Senator
    const n = senate.length;

    // Queues with Senator's Index.
    // Index will be used to find the next turn of Senator
    const rQueue: number[] = [];
    const dQueue: number[] = [];

    // Populate the Queues
    for (let i = 0; i < n; i++) {
        if (senate[i] === 'R') {
            rQueue.push(i);
        } else {
            dQueue.push(i);
        }
    }

    // While both parties have at least one Senator
    while (rQueue.length > 0 && dQueue.length > 0) {
        
        // Pop the Next-Turn Senate from both Q.
        const rTurn = rQueue.shift()!;
        const dTurn = dQueue.shift()!;

        // ONE having a larger index will be banned by a lower index
        // Lower index will again get Turn, so EN-Queue again
        // But ensure its turn comes in the next round only
        if (dTurn < rTurn) {
            dQueue.push(dTurn + n);
        } else {
            rQueue.push(rTurn + n);
        }
    }

    // One's which Empty is not winner
    if (rQueue.length === 0) {
        return "Dire";
    } else {
        return "Radiant";
    }
};
```

</details>

<br>

## Approach 5: Single Queue

### Implementation

<details>
<summary><strong>C</strong></summary>

```c
char * predictPartyVictory(char * senate){
    
    // Number of Senators of each party
    int rCount = 0, dCount = 0;

    // Floating Ban Count
    int dFloatingBan = 0, rFloatingBan = 0;

    // Queue of Senators.
    int n = strlen(senate);
    int q[n];
    int front = 0, rear = 0;
    for (int i = 0; senate[i]; i++) {
        if (senate[i] == 'R') rCount++;
        else dCount++;
        q[rear] = senate[i];
        rear = (rear + 1) % n;
    }

    // While any party has eligible Senators
    while (rCount && dCount) {

        // Pop the senator with turn
        char curr = q[front];
        front = (front + 1) % n;

        // If eligible, float the ban on the other party, enqueue again.
        // If not, decrement the floating ban and count of the party.
        if (curr == 'D') {
            if (dFloatingBan) {
                dFloatingBan--;
                dCount--;
            } else {
                rFloatingBan++;
                q[rear] = 'D';
                rear = (rear + 1) % n;
            }
        } else {
            if (rFloatingBan) {
                rFloatingBan--;
                rCount--;
            } else {
                dFloatingBan++;
                q[rear] = 'R';
                rear = (rear + 1) % n;
            }
        }
    }

    // Return the party with eligible Senators
    return rCount ? "Radiant" : "Dire";
}
```

</details>

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string predictPartyVictory(string senate) {
        
        // Number of Senators of each party
        int rCount = 0, dCount = 0;

        // Floating Ban Count
        int dFloatingBan = 0, rFloatingBan = 0;

        // Queue of Senators
        queue<char> q;
        for (char c : senate) {
            q.push(c);
            if (c == 'R') rCount++;
            else dCount++;
        }

        // While any party has eligible Senators
        while (rCount && dCount) {

            // Pop the senator with turn
            char curr = q.front();
            q.pop();

            // If eligible, float the ban on the other party, enqueue again.
            // If not, decrement the floating ban and count of the party.
            if (curr == 'D') {
                if (dFloatingBan) {
                    dFloatingBan--;
                    dCount--;
                } else {
                    rFloatingBan++;
                    q.push('D');
                }
            } else {
                if (rFloatingBan) {
                    rFloatingBan--;
                    rCount--;
                } else {
                    dFloatingBan++;
                    q.push('R');
                }
            }
        }

        // Return the party with eligible Senators
        return rCount ? "Radiant" : "Dire";
    }
};
```

</details>

<details>
<summary><strong>C#</strong></summary>

```csharp
public class Solution {
    public string PredictPartyVictory(string senate) {
        
        // Number of Senators of each party
        int rCount = 0, dCount = 0;

        // Floating Ban Count
        int dFloatingBan = 0, rFloatingBan = 0;

        // Queue of Senators
        Queue<char> q = new Queue<char>();
        foreach (char c in senate) {
            q.Enqueue(c);
            if (c == 'R') rCount++;
            else dCount++;
        }

        // While any party has eligible Senators
        while (rCount > 0 && dCount > 0) {

            // Pop the senator with turn
            char curr = q.Dequeue();

            // If eligible, float the ban on the other party, enqueue again.
            // If not, decrement the floating ban and count of the party.
            if (curr == 'D') {
                if (dFloatingBan > 0) {
                    dFloatingBan--;
                    dCount--;
                } else {
                    rFloatingBan++;
                    q.Enqueue('D');
                }
            } else {
                if (rFloatingBan > 0) {
                    rFloatingBan--;
                    rCount--;
                } else {
                    dFloatingBan++;
                    q.Enqueue('R');
                }
            }
        }

        // Return the party with eligible Senators
        return rCount > 0 ? "Radiant" : "Dire";
    }
}
```

</details>

<details>
<summary><strong>Go</strong></summary>

```go
func predictPartyVictory(senate string) string {
    
    // Number of Senators of each party
    rCount, dCount := 0, 0

    // Floating Ban Count
    dFloatingBan, rFloatingBan := 0, 0

    // Queue of Senators
    q := []byte{}
    for i := 0; i < len(senate); i++ {
        q = append(q, senate[i])
        if senate[i] == 'R' {
            rCount++
        } else {
            dCount++
        }
    }

    // While any party has eligible Senators
    for rCount > 0 && dCount > 0 {

        // Pop the senator with turn
        curr := q[0]
        q = q[1:]

        // If eligible, float the ban on the other party, enqueue again.
        // If not, decrement the floating ban and count of the party.
        if curr == 'D' {
            if dFloatingBan > 0 {
                dFloatingBan--
                dCount--
            } else {
                rFloatingBan++
                q = append(q, 'D')
            }
        } else {
            if rFloatingBan > 0 {
                rFloatingBan--
                rCount--
            } else {
                dFloatingBan++
                q = append(q, 'R')
            }
        }
    }

    // Return the party with eligible Senators
    if rCount > 0 {
        return "Radiant"
    } else {
        return "Dire"
    }
}
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public String predictPartyVictory(String senate) {
        
        // Number of Senators of each party
        int rCount = 0, dCount = 0;
       
        // Floating Ban Count
        int dFloatingBan = 0, rFloatingBan = 0;

        // Queue of Senators
        Queue<Character> q = new LinkedList<>();
        for (char c : senate.toCharArray()) {
            q.add(c);
            if (c == 'R') rCount++;
            else dCount++;
        }

        // While any party has eligible Senators
        while (rCount > 0 && dCount > 0) {

            // Pop the senator with turn
            char curr = q.poll();

            // If eligible, float the ban on the other party, enqueue again.
            // If not, decrement the floating ban and count of the party.
            if (curr == 'D') {
                if (dFloatingBan > 0) {
                    dFloatingBan--;
                    dCount--;
                } else {
                    rFloatingBan++;
                    q.add('D');
                }
            } else {
                if (rFloatingBan > 0) {
                    rFloatingBan--;
                    rCount--;
                } else {
                    dFloatingBan++;
                    q.add('R');
                }
            }
        }

        // Return the party with eligible Senators
        return rCount > 0 ? "Radiant" : "Dire";
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
/**
 * @param {string} senate
 * @return {string}
 */

var predictPartyVictory = function(senate) {
    
    // Number of Senators of each party
    let rCount = 0, dCount = 0;

    // Floating Ban Count
    let dFloatingBan = 0, rFloatingBan = 0;

    // Queue of Senators
    let q = [];
    for (let i = 0; i < senate.length; i++) {
        q.push(senate[i]);
        if (senate[i] == 'R') rCount++;
        else dCount++;
    }

    // While any party has eligible Senators
    while (rCount > 0 && dCount > 0) {

        // Pop the senator with turn
        let curr = q.shift();

        // If eligible, float the ban on the other party, enqueue again.
        // If not, decrement the floating ban and count of the party.
        if (curr == 'D') {
            if (dFloatingBan > 0) {
                dFloatingBan--;
                dCount--;
            } else {
                rFloatingBan++;
                q.push('D');
            }
        } else {
            if (rFloatingBan > 0) {
                rFloatingBan--;
                rCount--;
            } else {
                dFloatingBan++;
                q.push('R');
            }
        }
    }

    // Return the party with eligible Senators
    return rCount > 0 ? "Radiant" : "Dire";
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def predictPartyVictory(self, senate: str) -> str:

        # Eligible Senators of each party
        r_count = senate.count('R')
        d_count = len(senate) - r_count

        # Floating Ban Count
        d_floating_ban = 0
        r_floating_ban = 0

        # Queue of Senators
        q = deque(senate)

        # While any party has eligible Senators
        while r_count and d_count:

            # Pop the senator with turn
            curr = q.popleft()

            # If eligible, float the ban on the other party, enqueue again.
            # If not, decrement the floating ban and count of the party.
            if curr == 'D':
                if d_floating_ban:
                    d_floating_ban -= 1
                    d_count -= 1
                else:
                    r_floating_ban += 1
                    q.append('D')
            else:
                if r_floating_ban:
                    r_floating_ban -= 1
                    r_count -= 1
                else:
                    d_floating_ban += 1
                    q.append('R')

        # Return the party with eligible Senators
        return 'Radiant' if r_count else 'Dire'
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function predictPartyVictory(senate: string): string {
    
    // Number of Senators of each party
    let rCount = 0;
    let dCount = 0;

    // Floating Ban Count
    let dFloatingBan = 0;
    let rFloatingBan = 0;

    // Queue of Senators.
    let q = [];
    for (let i = 0; i < senate.length; i++) {
        q.push(senate[i]);
        if (senate[i] == 'R') {
            rCount += 1;
        } else {
            dCount += 1;
        }
    }

    // While any party has eligible Senators
    while (rCount > 0 && dCount > 0) {

        // Pop the senator with turn
        let curr = q.shift();

        // If eligible, float the ban on the other party, enqueue again.
        // If not, decrement the floating ban and count of the party.
        if (curr == 'D') {
            if (dFloatingBan > 0) {
                dFloatingBan -= 1;
                dCount -= 1;
            } else {
                rFloatingBan += 1;
                q.push('D');
            }
        } else {
            if (rFloatingBan > 0) {
                rFloatingBan -= 1;
                rCount -= 1;
            } else {
                dFloatingBan += 1;
                q.push('R');
            }
        }
    }

    // Return the party with eligible Senators
    if (rCount > 0) {
        return "Radiant";
    } else {
        return "Dire";
    }
};
```

</details>
