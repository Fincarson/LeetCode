# 726. Number of Atoms

[![Hard](../../Miscellaneous/Badges/Hard.svg)](https://leetcode.com/problems/number-of-atoms/)  
`Hash Table` `String` `Stack` `Sorting`

**Problem Link:** [LeetCode 726 - Number of Atoms](https://leetcode.com/problems/number-of-atoms/)

## Problem

Given a string formula representing a chemical formula, return the count of each atom.

The atomic element always starts with an uppercase character, then zero or more lowercase letters, representing the name.

One or more digits representing that element's count may follow if the count is greater than 1. If the count is 1, no digits will follow.

- For example, "H2O" and "H2O2" are possible, but "H1O2" is impossible.

Two formulas are concatenated together to produce another formula.

- For example, "H2O2He3Mg4" is also a formula.

A formula placed in parentheses, and a count (optionally added) is also a formula.

- For example, "(H2O2)" and "(H2O2)3" are formulas.

Return the count of all elements as a string in the following form: the first name (in sorted order), followed by its count (if that count is more than 1), followed by the second name (in sorted order), followed by its count (if that count is more than 1), and so on.

The test cases are generated so that all the values in the output fit in a 32-bit integer.

### Example 1

```text
Input: formula = "H2O"
Output: "H2O"
Explanation: The count of elements are {'H': 2, 'O': 1}.
```

### Example 2

```text
Input: formula = "Mg(OH)2"
Output: "H2MgO2"
Explanation: The count of elements are {'H': 2, 'Mg': 1, 'O': 2}.
```

### Example 3

```text
Input: formula = "K4(ON(SO3)2)2"
Output: "K4N2O14S4"
Explanation: The count of elements are {'K': 4, 'N': 2, 'O': 14, 'S': 4}.
```

## Constraints

- 1 <= formula.length <= 1000
- formula consists of English letters, digits, '(', and ')'.
- formula is always valid.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Decode String](https://leetcode.com/problems/decode-string/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Encode String with Shortest Length](https://leetcode.com/problems/encode-string-with-shortest-length/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |
| [Parse Lisp Expression](https://leetcode.com/problems/parse-lisp-expression/) | ![Hard](../../Miscellaneous/Badges/Hard.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 726. Number of Atoms

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursion | C++, Java, Python3 |
| Stack | C++, Java, Python3 |
| Regular Expression | C++, Java, Python3 |
| Reverse Scanning | C++, Java, Python3 |
| Preprocessing | C++, Java, Python3 |
| Reverse Scanning with Regex | C++, Java, Python3 |

## Approach 1: Recursion

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string countOfAtoms(string formula) {
        // Recursively parse the formula
        unordered_map<string, int> finalMap = parseFormula(formula);

        // Sort the final map
        map<string, int> sortedMap(finalMap.begin(), finalMap.end());

        // Generate the answer string
        string ans;
        for (auto& [atom, count] : sortedMap) {
            ans += atom;
            if (count > 1) {
                ans += to_string(count);
            }
        }

        return ans;
    }

    // Recursively parse the formula
    unordered_map<string, int> parseFormula(string& formula) {
        // Local variable
        unordered_map<string, int> currMap;
        string currAtom;
        string currCount;

        // Iterate until the end of the formula
        while (index < formula.length()) {
            // UPPERCASE LETTER
            if (isupper(formula[index])) {
                if (!currAtom.empty()) {
                    if (currCount.empty()) {
                        currMap[currAtom] += 1;
                    } else {
                        currMap[currAtom] += stoi(currCount);
                    }
                }

                currAtom = formula[index];
                currCount = "";
                index++;
            }

            // lowercase letter
            else if (islower(formula[index])) {
                currAtom += formula[index];
                index++;
            }

            // Digit. Concatenate the count
            else if (isdigit(formula[index])) {
                currCount += formula[index];
                index++;
            }

            // Left Parenthesis
            else if (formula[index] == '(') {
                index++;
                unordered_map<string, int> nestedMap = parseFormula(formula);
                for (auto& [atom, count] : nestedMap) {
                    currMap[atom] += count;
                }
            }

            // Right Parenthesis
            else if (formula[index] == ')') {
                // Save the last atom and count of nested formula
                if (!currAtom.empty()) {
                    if (currCount.empty()) {
                        currMap[currAtom] += 1;
                    } else {
                        currMap[currAtom] += stoi(currCount);
                    }
                }

                index++;
                string multiplier;
                while (index < formula.length() && isdigit(formula[index])) {
                    multiplier += formula[index];
                    index++;
                }
                if (!multiplier.empty()) {
                    int mult = stoi(multiplier);
                    for (auto& [atom, count] : currMap) {
                        currMap[atom] = count * mult;
                    }
                }

                return currMap;
            }
        }

        // Save the last atom and count
        if (!currAtom.empty()) {
            if (currCount.empty()) {
                currMap[currAtom] += 1;
            } else {
                currMap[currAtom] += stoi(currCount);
            }
        }

        return currMap;
    }

private:
    // Global variable
    int index = 0;
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    // Global variable
    int index = 0;

    public String countOfAtoms(String formula) {
        // Recursively parse the formula
        Map<String, Integer> finalMap = parseFormula(formula);

        // Sort the final map
        TreeMap<String, Integer> sortedMap = new TreeMap<>(finalMap);

        // Generate the answer string
        StringBuilder ans = new StringBuilder();
        for (String atom : sortedMap.keySet()) {
            ans.append(atom);
            if (sortedMap.get(atom) > 1) {
                ans.append(sortedMap.get(atom));
            }
        }

        return ans.toString();
    }

    // Recursively parse the formula
    private Map<String, Integer> parseFormula(String formula) {
        // Local variable
        Map<String, Integer> currMap = new HashMap<>();
        String currAtom = new String();
        String currCount = new String();

        // Iterate until the end of the formula
        while (index < formula.length()) {
            // UPPERCASE LETTER
            if (Character.isUpperCase(formula.charAt(index))) {
                if (!currAtom.isEmpty()) {
                    if (currCount.isEmpty()) {
                        currMap.put(
                            currAtom,
                            currMap.getOrDefault(currAtom, 0) + 1
                        );
                    } else {
                        currMap.put(
                            currAtom,
                            currMap.getOrDefault(currAtom, 0) +
                            Integer.parseInt(currCount)
                        );
                    }
                }

                currAtom = String.valueOf(formula.charAt(index));
                currCount = "";
                index++;
            }
            // lowercase letter
            else if (Character.isLowerCase(formula.charAt(index))) {
                currAtom += formula.charAt(index);
                index++;
            }
            // Digit. Concatenate the count
            else if (Character.isDigit(formula.charAt(index))) {
                currCount += formula.charAt(index);
                index++;
            }
            // Left Parenthesis
            else if (formula.charAt(index) == '(') {
                index++;
                Map<String, Integer> nestedMap = parseFormula(formula);
                for (String atom : nestedMap.keySet()) {
                    currMap.put(
                        atom,
                        currMap.getOrDefault(atom, 0) + nestedMap.get(atom)
                    );
                }
            }
            // Right Parenthesis
            else if (formula.charAt(index) == ')') {
                // Save the last atom and count of nested formula
                if (!currAtom.isEmpty()) {
                    if (currCount.isEmpty()) {
                        currMap.put(
                            currAtom,
                            currMap.getOrDefault(currAtom, 0) + 1
                        );
                    } else {
                        currMap.put(
                            currAtom,
                            currMap.getOrDefault(currAtom, 0) +
                            Integer.parseInt(currCount)
                        );
                    }
                }

                index++;
                StringBuilder multiplier = new StringBuilder();
                while (
                    index < formula.length() &&
                    Character.isDigit(formula.charAt(index))
                ) {
                    multiplier.append(formula.charAt(index));
                    index++;
                }
                if (multiplier.length() > 0) {
                    int mult = Integer.parseInt(multiplier.toString());
                    for (String atom : currMap.keySet()) {
                        currMap.put(atom, currMap.get(atom) * mult);
                    }
                }

                return currMap;
            }
        }

        // Save the last atom and count
        if (!currAtom.isEmpty()) {
            if (currCount.isEmpty()) {
                currMap.put(currAtom, currMap.getOrDefault(currAtom, 0) + 1);
            } else {
                currMap.put(
                    currAtom,
                    currMap.getOrDefault(currAtom, 0) +
                    Integer.parseInt(currCount)
                );
            }
        }

        return currMap;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countOfAtoms(self, formula: str) -> str:
        # Length of the formula
        n = len(formula)

        # Current index. It should be global as needs
        # to be updated in the recursive function
        self.index = 0

        # Recursively parse the formula
        def parse_formula():
            # Local variable
            curr_map = defaultdict(int)
            curr_atom = ""
            curr_count = ""

            # Iterate until the end of the formula
            while self.index < n:
                # UPPERCASE LETTER
                if formula[self.index].isupper():
                    # Save the previous atom and count
                    if curr_atom:
                        if curr_count == "":
                            curr_map[curr_atom] += 1
                        else:
                            curr_map[curr_atom] += int(curr_count)

                    curr_atom = formula[self.index]
                    curr_count = ""
                    self.index += 1

                # lowercase letter
                elif formula[self.index].islower():
                    curr_atom += formula[self.index]
                    self.index += 1

                # Digit. Concatenate the count
                elif formula[self.index].isdigit():
                    curr_count += formula[self.index]
                    self.index += 1

                # Left Parenthesis
                elif formula[self.index] == "(":
                    self.index += 1
                    nested_map = parse_formula()
                    for atom in nested_map:
                        curr_map[atom] += nested_map[atom]

                # Right Parenthesis
                elif formula[self.index] == ")":
                    # Save the last atom and count of nested formula
                    if curr_atom:
                        if curr_count == "":
                            curr_map[curr_atom] += 1
                        else:
                            curr_map[curr_atom] += int(curr_count)

                    self.index += 1
                    multiplier = ""
                    while self.index < n and formula[self.index].isdigit():
                        multiplier += formula[self.index]
                        self.index += 1
                    if multiplier:
                        multiplier = int(multiplier)
                        for atom in curr_map:
                            curr_map[atom] *= multiplier

                    return curr_map

            # Save the last atom and count
            if curr_atom:
                if curr_count == "":
                    curr_map[curr_atom] += 1
                else:
                    curr_map[curr_atom] += int(curr_count)

            return curr_map

        # Parse the formula
        final_map = parse_formula()

        # Sort the final map
        final_map = dict(sorted(final_map.items()))

        # Generate the answer string
        ans = ""
        for atom in final_map:
            ans += atom
            if final_map[atom] > 1:
                ans += str(final_map[atom])

        return ans
```

</details>

<br>

## Approach 2: Stack

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string countOfAtoms(string formula) {
        // Stack to keep track of the atoms and their counts
        stack<unordered_map<string, int>> stack;
        stack.push(unordered_map<string, int>());

        // Index to keep track of the current character
        int index = 0;

        // Parse the formula
        while (index < formula.length()) {
            // If left parenthesis, insert a new hashmap to the stack. It will
            // keep track of the atoms and their counts in the nested formula
            if (formula[index] == '(') {
                stack.push(unordered_map<string, int>());
                index++;
            }

            // If right parenthesis, pop the top element from the stack
            // Multiply the count with the multiplicity of the nested formula
            else if (formula[index] == ')') {
                unordered_map<string, int> currMap = stack.top();
                stack.pop();
                index++;
                string multiplier;
                while (index < formula.length() && isdigit(formula[index])) {
                    multiplier += formula[index];
                    index++;
                }
                if (!multiplier.empty()) {
                    int mult = stoi(multiplier);
                    for (auto& [atom, count] : currMap) {
                        currMap[atom] = count * mult;
                    }
                }

                for (auto& [atom, count] : currMap) {
                    stack.top()[atom] += count;
                }
            }

            // Otherwise, it must be a UPPERCASE LETTER. Extract the complete
            // atom with frequency, and update the most recent hashmap
            else {
                string currAtom;
                currAtom += formula[index];
                index++;
                while (index < formula.length() && islower(formula[index])) {
                    currAtom += formula[index];
                    index++;
                }

                string currCount;
                while (index < formula.length() && isdigit(formula[index])) {
                    currCount += formula[index];
                    index++;
                }

                int count = currCount.empty() ? 1 : stoi(currCount);
                stack.top()[currAtom] += count;
            }
        }

        // Sort the final map
        map<string, int> finalMap(stack.top().begin(), stack.top().end());

        // Generate the answer string
        string ans;
        for (auto& [atom, count] : finalMap) {
            ans += atom;
            if (count > 1) {
                ans += to_string(count);
            }
        }

        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String countOfAtoms(String formula) {
        // Stack to keep track of the atoms and their counts
        Stack<Map<String, Integer>> stack = new Stack<>();
        stack.push(new HashMap<>());

        // Index to keep track of the current character
        int index = 0;

        // Parse the formula
        while (index < formula.length()) {
            // If left parenthesis, insert a new hashmap to the stack. It will
            // keep track of the atoms and their counts in the nested formula
            if (formula.charAt(index) == '(') {
                stack.push(new HashMap<>());
                index++;
            }
            // If right parenthesis, pop the top element from the stack
            // Multiply the count with the multiplicity of the nested formula
            else if (formula.charAt(index) == ')') {
                Map<String, Integer> currMap = stack.pop();
                index++;
                StringBuilder multiplier = new StringBuilder();
                while (
                    index < formula.length() &&
                    Character.isDigit(formula.charAt(index))
                ) {
                    multiplier.append(formula.charAt(index));
                    index++;
                }
                if (multiplier.length() > 0) {
                    int mult = Integer.parseInt(multiplier.toString());
                    for (String atom : currMap.keySet()) {
                        currMap.put(atom, currMap.get(atom) * mult);
                    }
                }

                for (String atom : currMap.keySet()) {
                    stack
                        .peek()
                        .put(
                            atom,
                            stack.peek().getOrDefault(atom, 0) +
                            currMap.get(atom)
                        );
                }
            }
            // Otherwise, it must be a UPPERCASE LETTER. Extract the complete
            // atom with frequency, and update the most recent hashmap
            else {
                StringBuilder currAtom = new StringBuilder();
                currAtom.append(formula.charAt(index));
                index++;
                while (
                    index < formula.length() &&
                    Character.isLowerCase(formula.charAt(index))
                ) {
                    currAtom.append(formula.charAt(index));
                    index++;
                }

                StringBuilder currCount = new StringBuilder();
                while (
                    index < formula.length() &&
                    Character.isDigit(formula.charAt(index))
                ) {
                    currCount.append(formula.charAt(index));
                    index++;
                }

                int count = currCount.length() > 0
                    ? Integer.parseInt(currCount.toString())
                    : 1;
                stack
                    .peek()
                    .put(
                        currAtom.toString(),
                        stack.peek().getOrDefault(currAtom.toString(), 0) +
                        count
                    );
            }
        }

        // Sort the final map
        TreeMap<String, Integer> finalMap = new TreeMap<>(stack.peek());

        // Generate the answer string
        StringBuilder ans = new StringBuilder();
        for (String atom : finalMap.keySet()) {
            ans.append(atom);
            if (finalMap.get(atom) > 1) {
                ans.append(finalMap.get(atom));
            }
        }

        return ans.toString();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countOfAtoms(self, formula: str) -> str:
        # Stack to keep track of the atoms and their counts
        stack = [defaultdict(int)]

        # Index to keep track of the current character
        index = 0

        # Parse the formula
        while index < len(formula):
            # If left parenthesis, insert a new hashmap to the stack. It will
            # keep track of the atoms and their counts in the nested formula
            if formula[index] == "(":
                stack.append(defaultdict(int))
                index += 1

            # If right parenthesis, pop the top element from the stack
            # Multiply the count with the multiplicity of the nested formula
            elif formula[index] == ")":
                curr_map = stack.pop()
                index += 1
                multiplier = ""
                while index < len(formula) and formula[index].isdigit():
                    multiplier += formula[index]
                    index += 1
                if multiplier:
                    multiplier = int(multiplier)
                    for atom in curr_map:
                        curr_map[atom] *= multiplier

                for atom in curr_map:
                    stack[-1][atom] += curr_map[atom]

            # Otherwise, it must be a UPPERCASE LETTER. Extract the complete
            # atom with frequency, and update the most recent hashmap
            else:
                curr_atom = formula[index]
                index += 1
                while index < len(formula) and formula[index].islower():
                    curr_atom += formula[index]
                    index += 1

                curr_count = ""
                while index < len(formula) and formula[index].isdigit():
                    curr_count += formula[index]
                    index += 1

                if curr_count == "":
                    stack[-1][curr_atom] += 1
                else:
                    stack[-1][curr_atom] += int(curr_count)

        # Sort the final map
        final_map = dict(sorted(stack[0].items()))

        # Generate the answer string
        ans = ""
        for atom in final_map:
            ans += atom
            if final_map[atom] > 1:
                ans += str(final_map[atom])

        return ans
```

</details>

<br>

## Approach 3: Regular Expression

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string countOfAtoms(string formula) {
        // Regular expression to extract atom, count, (, ), multiplier
        // Every element of matcher will be a quintuple
        regex reg("([A-Z][a-z]*)(\\d*)|(\\()|(\\))(\\d*)");
        sregex_iterator it(formula.begin(), formula.end(), reg);
        sregex_iterator end;

        // Stack to keep track of the atoms and their counts
        stack<unordered_map<string, int>> stack;
        stack.push(unordered_map<string, int>());

        // Parse the formula
        while (it != end) {
            smatch match = *it;
            string atom = match[1].str();
            string count = match[2].str();
            string left = match[3].str();
            string right = match[4].str();
            string multiplier = match[5].str();

            // If atom, add it to the top hashmap
            if (!atom.empty()) {
                stack.top()[atom] += count.empty() ? 1 : stoi(count);
            }

            // If left parenthesis, insert a new hashmap to the stack
            else if (!left.empty()) {
                stack.push(unordered_map<string, int>());
            }

            // If right parenthesis, pop the top element from the stack
            // Multiply the count with the attached multiplicity.
            // Add the count to the current formula
            else if (!right.empty()) {
                unordered_map<string, int> currMap = stack.top();
                stack.pop();
                if (!multiplier.empty()) {
                    int mult = stoi(multiplier);
                    for (auto& [atom, count] : currMap) {
                        currMap[atom] = count * mult;
                    }
                }

                for (auto& [atom, count] : currMap) {
                    stack.top()[atom] += count;
                }
            }

            it++;
        }

        // Sort the final map
        map<string, int> finalMap(stack.top().begin(), stack.top().end());

        // Generate the answer string
        string ans;
        for (auto& [atom, count] : finalMap) {
            ans += atom;
            if (count > 1) {
                ans += to_string(count);
            }
        }

        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
import java.util.regex.*;

class Solution {

    public String countOfAtoms(String formula) {
        // Regular expression to extract atom, count, (, ), multiplier
        // Every element of parsed will be a quintuple
        String regex = "([A-Z][a-z]*)(\\d*)|(\\()|(\\))(\\d*)";
        Pattern pattern = Pattern.compile(regex);
        Matcher matcher = pattern.matcher(formula);

        // Stack to keep track of the atoms and their counts
        Stack<Map<String, Integer>> stack = new Stack<>();
        stack.push(new HashMap<>());

        // Parse the formula
        while (matcher.find()) {
            String atom = matcher.group(1);
            String count = matcher.group(2);
            String left = matcher.group(3);
            String right = matcher.group(4);
            String multiplier = matcher.group(5);

            // If atom, add it to the top hashmap
            if (atom != null) {
                stack
                    .peek()
                    .put(
                        atom,
                        stack.peek().getOrDefault(atom, 0) +
                        (count.isEmpty() ? 1 : Integer.parseInt(count))
                    );
            }
            // If left parenthesis, insert a new hashmap to the stack
            else if (left != null) {
                stack.push(new HashMap<>());
            }
            // If right parenthesis, pop the top element from the stack
            // Multiply the count with the attached multiplicity.
            // Add the count to the current formula
            else if (right != null) {
                Map<String, Integer> currMap = stack.pop();
                if (!multiplier.isEmpty()) {
                    int mult = Integer.parseInt(multiplier);
                    for (String atomName : currMap.keySet()) {
                        currMap.put(atomName, currMap.get(atomName) * mult);
                    }
                }

                for (String atomName : currMap.keySet()) {
                    stack
                        .peek()
                        .put(
                            atomName,
                            stack.peek().getOrDefault(atomName, 0) +
                            currMap.get(atomName)
                        );
                }
            }
        }

        // Sort the final map
        TreeMap<String, Integer> finalMap = new TreeMap<>(stack.peek());

        // Generate the answer string
        StringBuilder ans = new StringBuilder();
        for (String atom : finalMap.keySet()) {
            ans.append(atom);
            if (finalMap.get(atom) > 1) {
                ans.append(finalMap.get(atom));
            }
        }

        return ans.toString();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countOfAtoms(self, formula: str) -> str:
        # Regular expression to extract atom, count, (, ), multiplier
        # Every element of matcher will be a quintuple
        regex = r"([A-Z][a-z]*)(\d*)|(\()|(\))(\d*)"
        matcher = re.findall(regex, formula)

        # Stack to keep track of the atoms and their counts
        stack = [defaultdict(int)]

        # Parse the formula
        for atom, count, left, right, multiplier in matcher:
            # If atom, add it to the top hashmap
            if atom:
                stack[-1][atom] += int(count) if count else 1

            # If left parenthesis, insert a new hashmap to the stack
            elif left:
                stack.append(defaultdict(int))

            # If right parenthesis, pop the top element from the stack
            # Multiply the count with the attached multiplicity.
            # Add the count to the current formula
            elif right:
                curr_map = stack.pop()
                if multiplier:
                    multiplier = int(multiplier)
                    for atom in curr_map:
                        curr_map[atom] *= multiplier
                for atom in curr_map:
                    stack[-1][atom] += curr_map[atom]

        # Sort the final map
        final_map = dict(sorted(stack[0].items()))

        # Generate the answer string
        ans = ""
        for atom in final_map:
            ans += atom
            if final_map[atom] > 1:
                ans += str(final_map[atom])

        return ans
```

</details>

<br>

## Approach 4: Reverse Scanning

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string countOfAtoms(string formula) {
        // For multipliers
        int runningMul = 1;
        stack<int> stack;
        stack.push(1);

        // Map to store the count of atoms
        unordered_map<string, int> finalMap;

        // Strings to take care of current atom and count
        string currAtom = "";
        string currCount = "";

        // Index to traverse the formula in reverse
        int index = formula.length() - 1;

        // Parse the formula
        while (index >= 0) {
            // If digit, update the count
            if (isdigit(formula[index])) {
                currCount = formula[index] + currCount;
            }

            // If a lowercase letter, prepend to the currAtom
            else if (islower(formula[index])) {
                currAtom = formula[index] + currAtom;
            }

            // If UPPERCASE LETTER, update the finalMap
            else if (isupper(formula[index])) {
                currAtom = formula[index] + currAtom;
                int count = currCount.empty() ? 1 : stoi(currCount);
                finalMap[currAtom] += count * runningMul;

                currAtom = "";
                currCount = "";
            }

            // If the right parenthesis, the currCount if any
            // will be considered as multiplier
            else if (formula[index] == ')') {
                int currMultiplier = currCount.empty() ? 1 : stoi(currCount);
                stack.push(currMultiplier);
                runningMul *= currMultiplier;
                currCount = "";
            }

            // If left parenthesis, update the runningMul
            else if (formula[index] == '(') {
                runningMul /= stack.top();
                stack.pop();
            }

            index--;
        }

        // Sort the final map
        map<string, int> sortedMap(finalMap.begin(), finalMap.end());

        // Generate the answer string
        string ans;
        for (auto& [atom, count] : sortedMap) {
            ans += atom;
            if (count > 1) {
                ans += to_string(count);
            }
        }

        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String countOfAtoms(String formula) {
        // For multipliers
        int runningMul = 1;
        Stack<Integer> stack = new Stack<>();
        stack.push(1);

        // Map to store the count of atoms
        Map<String, Integer> finalMap = new HashMap<>();

        // Strings to take care of current atom and count
        StringBuilder currAtom = new StringBuilder();
        StringBuilder currCount = new StringBuilder();

        // Index to traverse the formula in reverse
        int index = formula.length() - 1;

        // Parse the formula
        while (index >= 0) {
            // If digit, update the count
            if (Character.isDigit(formula.charAt(index))) {
                currCount.insert(0, formula.charAt(index));
            }
            // If a lowercase letter, prepend to the currAtom
            else if (Character.isLowerCase(formula.charAt(index))) {
                currAtom.insert(0, formula.charAt(index));
            }
            // If UPPERCASE LETTER, update the finalMap
            else if (Character.isUpperCase(formula.charAt(index))) {
                currAtom.insert(0, formula.charAt(index));
                int count = currCount.length() > 0
                    ? Integer.parseInt(currCount.toString())
                    : 1;
                finalMap.put(
                    currAtom.toString(),
                    finalMap.getOrDefault(currAtom.toString(), 0) +
                    count * runningMul
                );

                currAtom = new StringBuilder();
                currCount = new StringBuilder();
            }
            // If the right parenthesis, the currCount if any
            // will be considered as multiplier
            else if (formula.charAt(index) == ')') {
                int currMultiplier = currCount.length() > 0
                    ? Integer.parseInt(currCount.toString())
                    : 1;
                stack.push(currMultiplier);
                runningMul *= currMultiplier;
                currCount = new StringBuilder();
            }
            // If left parenthesis, update the runningMul
            else if (formula.charAt(index) == '(') {
                runningMul /= stack.pop();
            }

            index--;
        }

        // Sort the final map
        TreeMap<String, Integer> sortedMap = new TreeMap<>(finalMap);

        // Generate the answer string
        StringBuilder ans = new StringBuilder();
        for (String atom : sortedMap.keySet()) {
            ans.append(atom);
            if (sortedMap.get(atom) > 1) {
                ans.append(sortedMap.get(atom));
            }
        }

        return ans.toString();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countOfAtoms(self, formula: str) -> str:
        # For multipliers
        running_mul = 1
        stack = [1]

        # Map to store the count of atoms
        final_map = defaultdict(int)

        # Strings to take care of current atom and count
        curr_atom = ""
        curr_count = ""

        # Index to traverse the formula in reverse
        index = len(formula) - 1

        # Parse the formula
        while index >= 0:
            # If digit, update the count
            if formula[index].isdigit():
                curr_count = formula[index] + curr_count

            # If lowercase letter, prepend to the curr_atom
            elif formula[index].islower():
                curr_atom = formula[index] + curr_atom

            # If UPPERCASE LETTER, prepend and update the finalMap
            elif formula[index].isupper():
                curr_atom = formula[index] + curr_atom
                if curr_count:
                    final_map[curr_atom] += int(curr_count) * running_mul
                else:
                    final_map[curr_atom] += 1 * running_mul

                curr_atom = ""
                curr_count = ""

            # If the right parenthesis, the curr_count if any
            # will be considered a multiplier
            elif formula[index] == ")":
                curr_multiplier = int(curr_count) if curr_count else 1
                stack.append(curr_multiplier)
                running_mul *= curr_multiplier
                curr_count = ""

            # If left parenthesis, update the running_mul
            elif formula[index] == "(":
                running_mul //= stack.pop()

            index -= 1

        # Sort the final map
        final_map = dict(sorted(final_map.items()))

        # Generate the answer string
        ans = ""
        for atom in final_map:
            ans += atom
            if final_map[atom] > 1:
                ans += str(final_map[atom])

        return ans
```

</details>

<br>

## Approach 5: Preprocessing

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string countOfAtoms(string formula) {
        // For every index, store the valid multiplier
        vector<int> muls(formula.length());
        int runningMul = 1;

        // Stack to take care of nested formula
        stack<int> stack;
        stack.push(1);

        // Preprocess the formula and extract all multipliers
        int index = formula.length() - 1;
        string currNumber = "";
        while (index >= 0) {
            if (isdigit(formula[index])) {
                currNumber = formula[index] + currNumber;
            }

            // If we encountered a letter, then the scanned
            // number was count and not a multiplier. Discard it.
            else if (isalpha(formula[index])) {
                currNumber = "";
            }

            // If we encounter a right parenthesis, then the
            // scanned number was multiplier. Store it.
            else if (formula[index] == ')') {
                int currMultiplier = currNumber.empty() ? 1 : stoi(currNumber);
                runningMul *= currMultiplier;
                stack.push(currMultiplier);
                currNumber = "";
            }

            // If we encounter a left parenthesis, then the
            // most recent multiplier will cease to exist.
            else if (formula[index] == '(') {
                runningMul /= stack.top();
                stack.pop();
                currNumber = "";
            }

            // For every index, store the valid multiplier
            muls[index] = runningMul;
            index--;
        }

        // Map to store the count of atoms
        unordered_map<string, int> finalMap;

        // Traverse left to right in the formula
        index = 0;
        while (index < formula.length()) {
            // If UPPER CASE LETTER, extract the entire atom
            if (isupper(formula[index])) {
                string currAtom = "";
                currAtom += formula[index];
                string currCount = "";
                index++;
                while (index < formula.length() && islower(formula[index])) {
                    currAtom += formula[index];
                    index++;
                }

                // Extract the count
                while (index < formula.length() && isdigit(formula[index])) {
                    currCount += formula[index];
                    index++;
                }

                // Update the final map
                int count = currCount.empty() ? 1 : stoi(currCount);
                finalMap[currAtom] += count * muls[index - 1];
            } else {
                index++;
            }
        }

        // Sort the final map
        map<string, int> sortedMap(finalMap.begin(), finalMap.end());

        // Generate the answer string
        string ans;
        for (auto& [atom, count] : sortedMap) {
            ans += atom;
            if (count > 1) {
                ans += to_string(count);
            }
        }

        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {

    public String countOfAtoms(String formula) {
        // For every index, store the valid multiplier
        int[] muls = new int[formula.length()];
        int runningMul = 1;

        // Stack to take care of nested formula
        Stack<Integer> stack = new Stack<>();
        stack.push(1);

        // Preprocess the formula and extract all multipliers
        int index = formula.length() - 1;
        StringBuilder currNumber = new StringBuilder();
        while (index >= 0) {
            if (Character.isDigit(formula.charAt(index))) {
                currNumber.insert(0, formula.charAt(index));
            }
            // If we encountered a letter, then the scanned
            // number was count and not a multiplier. Discard it.
            else if (Character.isAlphabetic(formula.charAt(index))) {
                currNumber = new StringBuilder();
            }
            // If we encounter a right parenthesis, then the
            // scanned number was multiplier. Store it.
            else if (formula.charAt(index) == ')') {
                int currMultiplier = currNumber.length() > 0
                    ? Integer.parseInt(currNumber.toString())
                    : 1;
                runningMul *= currMultiplier;
                stack.push(currMultiplier);
                currNumber = new StringBuilder();
            }
            // If we encounter a left parenthesis, then the
            // most recent multiplier will cease to exist.
            else if (formula.charAt(index) == '(') {
                runningMul /= stack.pop();
                currNumber = new StringBuilder();
            }

            // For every index, store the valid multiplier
            muls[index] = runningMul;
            index--;
        }

        // Map to store the count of atoms
        Map<String, Integer> finalMap = new HashMap<>();

        // Traverse left to right in the formula
        index = 0;
        while (index < formula.length()) {
            // If UPPER CASE LETTER, extract the entire atom
            if (Character.isUpperCase(formula.charAt(index))) {
                StringBuilder currAtom = new StringBuilder();
                currAtom.append(formula.charAt(index));
                StringBuilder currCount = new StringBuilder();
                index++;
                while (
                    index < formula.length() &&
                    Character.isLowerCase(formula.charAt(index))
                ) {
                    currAtom.append(formula.charAt(index));
                    index++;
                }

                // Extract the count
                while (
                    index < formula.length() &&
                    Character.isDigit(formula.charAt(index))
                ) {
                    currCount.append(formula.charAt(index));
                    index++;
                }

                // Update the final map
                int count = currCount.length() > 0
                    ? Integer.parseInt(currCount.toString())
                    : 1;
                finalMap.put(
                    currAtom.toString(),
                    finalMap.getOrDefault(currAtom.toString(), 0) +
                    count * muls[index - 1]
                );
            } else {
                index++;
            }
        }

        // Sort the final map
        TreeMap<String, Integer> sortedMap = new TreeMap<>(finalMap);

        // Generate the answer string
        StringBuilder ans = new StringBuilder();
        for (String atom : sortedMap.keySet()) {
            ans.append(atom);
            if (sortedMap.get(atom) > 1) {
                ans.append(sortedMap.get(atom));
            }
        }

        return ans.toString();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countOfAtoms(self, formula: str) -> str:
        # For every index, store the valid multiplier
        muls = []
        running_mul = 1

        # Stack to take care of nested formula
        stack = [1]

        # Preprocess the formula and extract all multipliers
        index = len(formula) - 1
        curr_number = ""
        while index >= 0:
            if formula[index].isdigit():
                curr_number += formula[index]

            # If we encountered a letter, then the scanned
            # number was count and not multiplier. Discard it.
            elif formula[index].isalpha():
                curr_number = ""

            # If we encounter a right parenthesis, then the
            # scanned number was a multiplier. Store it.
            elif formula[index] == ")":
                curr_multiplier = int(curr_number[::-1]) if curr_number else 1
                running_mul *= curr_multiplier
                stack.append(curr_multiplier)
                curr_number = ""

            # If we encounter a left parenthesis, then the
            # most recent multiplier will cease to exist.
            elif formula[index] == "(":
                running_mul //= stack.pop()
                curr_number = ""

            # For every index, store the valid multiplier
            muls.append(running_mul)
            index -= 1

        # Reverse the muls
        muls = muls[::-1]

        # Map to store the count of atoms
        final_map = defaultdict(int)

        # Traverse left to right in the formula
        index = 0
        while index < len(formula):
            # If UPPER CASE LETTER, extract the entire atom
            if formula[index].isupper():
                curr_atom = formula[index]
                curr_count = ""
                index += 1
                while index < len(formula) and formula[index].islower():
                    curr_atom += formula[index]
                    index += 1

                # Extract the count
                while index < len(formula) and formula[index].isdigit():
                    curr_count += formula[index]
                    index += 1

                # Update the final map
                if curr_count:
                    final_map[curr_atom] += int(curr_count) * muls[index - 1]
                else:
                    final_map[curr_atom] += 1 * muls[index - 1]

            else:
                index += 1

        # Sort the final map
        final_map = dict(sorted(final_map.items()))

        # Generate the answer string
        ans = ""
        for atom in final_map:
            ans += atom
            if final_map[atom] > 1:
                ans += str(final_map[atom])

        return ans
```

</details>

<br>

## Approach 6: Reverse Scanning with Regex

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    string countOfAtoms(string formula) {
        // Every element of matcher will be a quintuple
        regex reg("([A-Z][a-z]*)(\\d*)|(\\()|(\\))(\\d*)");
        sregex_iterator it(formula.begin(), formula.end(), reg);
        sregex_iterator end;
        vector<tuple<string, string, string, string, string>> matcher;
        while (it != end) {
            matcher.push_back(
                {(*it)[1], (*it)[2], (*it)[3], (*it)[4], (*it)[5]});
            it++;
        }
        reverse(matcher.begin(), matcher.end());

        // Map to store the count of atoms
        unordered_map<string, int> finalMap;

        // Stack to keep track of the nested multiplicities
        stack<int> stack;
        stack.push(1);

        // Current Multiplicity
        int runningMul = 1;

        // Parse the formula
        for (auto& quintuple : matcher) {
            string atom = get<0>(quintuple);
            string count = get<1>(quintuple);
            string left = get<2>(quintuple);
            string right = get<3>(quintuple);
            string multiplier = get<4>(quintuple);

            // If atom, add it to the final map
            if (!atom.empty()) {
                int cnt = count.empty() ? 1 : stoi(count);
                finalMap[atom] += cnt * runningMul;
            }

            // If the right parenthesis, multiply the runningMul
            else if (!right.empty()) {
                int currMultiplier = multiplier.empty() ? 1 : stoi(multiplier);
                runningMul *= currMultiplier;
                stack.push(currMultiplier);
            }

            // If left parenthesis, divide the runningMul
            else if (!left.empty()) {
                runningMul /= stack.top();
                stack.pop();
            }
        }

        // Sort the final map
        map<string, int> sortedMap(finalMap.begin(), finalMap.end());

        // Generate the answer string
        string ans;
        for (auto& [atom, count] : sortedMap) {
            ans += atom;
            if (count > 1) {
                ans += to_string(count);
            }
        }

        return ans;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
import java.util.regex.*;

class Solution {

    public String countOfAtoms(String formula) {
        // Every element of matcher will be a quintuple
        Matcher matcher = Pattern.compile(
            "([A-Z][a-z]*)(\\d*)|(\\()|(\\))(\\d*)"
        ).matcher(formula);
        List<String[]> list = new ArrayList<>();
        while (matcher.find()) {
            list.add(
                new String[] {
                    matcher.group(1),
                    matcher.group(2),
                    matcher.group(3),
                    matcher.group(4),
                    matcher.group(5),
                }
            );
        }
        Collections.reverse(list);

        // Map to store the count of atoms
        Map<String, Integer> finalMap = new HashMap<>();

        // Stack to keep track of the nested multiplicities
        Stack<Integer> stack = new Stack<>();
        stack.push(1);

        // Current Multiplicity
        int runningMul = 1;

        // Parse the formula
        for (String[] quintuple : list) {
            String atom = quintuple[0];
            String count = quintuple[1];
            String left = quintuple[2];
            String right = quintuple[3];
            String multiplier = quintuple[4];

            // If atom, add it to the final map
            if (atom != null) {
                int cnt = count.length() > 0 ? Integer.parseInt(count) : 1;
                finalMap.put(
                    atom,
                    finalMap.getOrDefault(atom, 0) + cnt * runningMul
                );
            }
            // If the right parenthesis, multiply the runningMul
            else if (right != null) {
                int currMultiplier = multiplier.length() > 0
                    ? Integer.parseInt(multiplier)
                    : 1;
                runningMul *= currMultiplier;
                stack.push(currMultiplier);
            }
            // If left parenthesis, divide the runningMul
            else if (left != null) {
                runningMul /= stack.pop();
            }
        }

        // Sort the final map
        TreeMap<String, Integer> sortedMap = new TreeMap<>(finalMap);

        // Generate the answer string
        StringBuilder ans = new StringBuilder();
        for (String atom : sortedMap.keySet()) {
            ans.append(atom);
            if (sortedMap.get(atom) > 1) {
                ans.append(sortedMap.get(atom));
            }
        }

        return ans.toString();
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def countOfAtoms(self, formula: str) -> str:
        # Every element of matcher will be a quintuple
        matcher = re.findall(r"([A-Z][a-z]*)(\d*)|(\()|(\))(\d*)", formula)
        matcher.reverse()

        # Map to store the count of atoms
        final_map = defaultdict(int)

        # Stack to keep track of the nested multiplicities
        stack = [1]

        # Current Multiplicity
        running_mul = 1

        # Parse the formula
        for atom, count, left, right, multiplier in matcher:
            # If atom, add it to the final map
            if atom:
                if count:
                    final_map[atom] += int(count) * running_mul
                else:
                    final_map[atom] += 1 * running_mul

            # If the right parenthesis, multiply the running_mul
            elif right:
                if not multiplier:
                    multiplier = 1
                else:
                    multiplier = int(multiplier)
                running_mul *= multiplier
                stack.append(multiplier)

            # If left parenthesis, divide the running_mul
            elif left:
                running_mul //= stack.pop()

        # Sort the final map
        final_map = dict(sorted(final_map.items()))

        # Generate the answer string
        ans = ""
        for atom in final_map:
            ans += atom
            if final_map[atom] > 1:
                ans += str(final_map[atom])

        return ans
```

</details>
