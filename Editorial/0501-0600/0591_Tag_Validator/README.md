# 591. Tag Validator

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/tag-validator/)  
`String` `Stack`

**Problem Link:** [LeetCode 591 - Tag Validator](https://leetcode.com/problems/tag-validator/)

## Problem

Given a string representing a code snippet, implement a tag validator to parse the code and return whether it is valid.

A code snippet is valid if all the following rules hold:

### Example 1

```text
Input: code = "<DIV>This is the first line <![CDATA[<div>]]></DIV>"
Output: true
Explanation:
The code is wrapped in a closed tag : <DIV> and </DIV>.
The TAG_NAME is valid, the TAG_CONTENT consists of some characters and cdata.
Although CDATA_CONTENT has an unmatched start tag with invalid TAG_NAME, it should be considered as plain text, not parsed as a tag.
So TAG_CONTENT is valid, and then the code is valid. Thus return true.
```

### Example 2

```text
Input: code = "<DIV>>>  ![cdata[]] <![CDATA[<div>]>]]>]]>>]</DIV>"
Output: true
Explanation:
We first separate the code into : start_tag|tag_content|end_tag.
start_tag -> "<DIV>"
end_tag -> "</DIV>"
tag_content could also be separated into : text1|cdata|text2.
text1 -> ">>  ![cdata[]] "
cdata -> "<![CDATA[<div>]>]]>", where the CDATA_CONTENT is "<div>]>"
text2 -> "]]>>]"
The reason why start_tag is NOT "<DIV>>>" is because of the rule 6.
The reason why cdata is NOT "<![CDATA[<div>]>]]>]]>" is because of the rule 7.
```

### Example 3

```text
Input: code = "<A>  <B> </A>   </B>"
Output: false
Explanation: Unbalanced. If "<A>" is closed, then "<B>" must be unmatched, and vice versa.
```

## Constraints

- 1 <= code.length <= 500
- code consists of English letters, digits, '<', '>', '/', '!', '[', ']', '.', and ' '.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Add Bold Tag in String](https://leetcode.com/problems/add-bold-tag-in-string/) | ![Medium](../../../_Misc/Badges/Med.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 591. Tag Validator

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Stack | Java |
| Regex | Java |

## Approach 1: Stack

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Solution {
    Stack < String > stack = new Stack < > ();
    boolean contains_tag = false;
    public boolean isValidTagName(String s, boolean ending) {
        if (s.length() < 1 || s.length() > 9)
            return false;
        for (int i = 0; i < s.length(); i++) {
            if (!Character.isUpperCase(s.charAt(i)))
                return false;
        }
        if (ending) {
            if (!stack.isEmpty() && stack.peek().equals(s))
                stack.pop();
            else
                return false;
        } else {
            contains_tag = true;
            stack.push(s);
        }
        return true;
    }
    public boolean isValidCdata(String s) {
        return s.indexOf("[CDATA[") == 0;
    }
    public boolean isValid(String code) {
        if (code.charAt(0) != '<' || code.charAt(code.length() - 1) != '>')
            return false;
        for (int i = 0; i < code.length(); i++) {
            boolean ending = false;
            int closeindex;
            if(stack.isEmpty() && contains_tag)
                return false;
            if (code.charAt(i) == '<') {
                if (!stack.isEmpty() && code.charAt(i + 1) == '!') {
                    closeindex = code.indexOf("]]>", i + 1);
                    if (closeindex < 0 || !isValidCdata(code.substring(i + 2, closeindex)))
                        return false;
                } else {
                    if (code.charAt(i + 1) == '/') {
                        i++;
                        ending = true;
                    }
                    closeindex = code.indexOf('>', i + 1);
                    if (closeindex < 0 || !isValidTagName(code.substring(i + 1, closeindex), ending))
                        return false;
                }
                i = closeindex;
            }
        }
        return stack.isEmpty() && contains_tag;
    }
}
```

</details>

<br>

## Approach 2: Regex

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
import java.util.regex.*;
public class Solution {
    Stack < String > stack = new Stack < > ();
    boolean contains_tag = false;
    public boolean isValidTagName(String s, boolean ending) {
        if (ending) {
            if (!stack.isEmpty() && stack.peek().equals(s))
                stack.pop();
            else
                return false;
        } else {
            contains_tag = true;
            stack.push(s);
        }
        return true;
    }
    public boolean isValid(String code) {
        String regex = "<[A-Z]{0,9}>([^<]*(<((\\/?[A-Z]{1,9}>)|(!\\[CDATA\\[(.*?)]]>)))?)*";
        if (!Pattern.matches(regex, code))
            return false;
        for (int i = 0; i < code.length(); i++) {
            boolean ending = false;
            if (stack.isEmpty() && contains_tag)
                return false;
            if (code.charAt(i) == '<') {
                if (code.charAt(i + 1) == '!') {
                    i = code.indexOf("]]>", i + 1);
                    continue;
                }
                if (code.charAt(i + 1) == '/') {
                    i++;
                    ending = true;
                }
                int closeindex = code.indexOf('>', i + 1);
                if (closeindex < 0 || !isValidTagName(code.substring(i + 1, closeindex), ending))
                    return false;
                i = closeindex;
            }
        }
        return stack.isEmpty();
    }
}
```

</details>
