# 929. Unique Email Addresses

[![Easy](../../Miscellaneous/Badges/Easy.svg)](https://leetcode.com/problems/unique-email-addresses/)  
`Array` `Hash Table` `String`

**Problem Link:** [LeetCode 929 - Unique Email Addresses](https://leetcode.com/problems/unique-email-addresses/)

## Problem

Every valid email consists of a local name and a domain name, separated by the '@' sign. Besides lowercase letters, the email may contain one or more '.' or '+'.

- For example, in "alice@leetcode.com", "alice" is the local name, and "leetcode.com" is the domain name.

If you add periods '.' between some characters in the local name part of an email address, mail sent there will be forwarded to the same address without dots in the local name. Note that this rule does not apply to domain names.

- For example, "alice.z@leetcode.com" and "alicez@leetcode.com" forward to the same email address.

If you add a plus '+' in the local name, everything after the first plus sign will be ignored. This allows certain emails to be filtered. Note that this rule does not apply to domain names.

- For example, "m.y+name@email.com" will be forwarded to "my@email.com".

It is possible to use both of these rules at the same time.

Given an array of strings emails where we send one email to each emails[i], return the number of different addresses that actually receive mails.

### Example 1

```text
Input: emails = ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
Output: 2
Explanation: "testemail@leetcode.com" and "testemail@lee.tcode.com" actually receive mails.
```

### Example 2

```text
Input: emails = ["a@leetcode.com","b@leetcode.com","c@leetcode.com"]
Output: 3
```

## Constraints

- 1 <= emails.length <= 100
- 1 <= emails[i].length <= 100
- emails[i] consist of lowercase English letters, '+', '.' and '@'.
- Each emails[i] contains exactly one '@' character.
- All local and domain names are non-empty.
- Local names do not start with a '+' character.
- Domain names end with the ".com" suffix.
- Domain names must contain at least one character before ".com" suffix.

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 929. Unique Email Addresses

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Linear Iteration | C++, Java, JavaScript, Python3 |
| Using String Split Method | Java, JavaScript, Python3 |

## Approach 1: Linear Iteration

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        // hash set to store all the unique emails
        unordered_set<string> uniqueEmails;

        for (string email : emails) {
            string cleanEmail = "";

            // iterate over each character in email
            for (char ch : email) {
                // stop adding characters to localName
                if (ch == '+' || ch == '@') break;

                // skip this character
                if (ch == '.') continue;

                cleanEmail += ch;
            }

            string domainName;
            for (int i = email.size()-1; i >= 0; --i) {
                char currChar = email[i];
                domainName += currChar;
                if (currChar == '@') break;
            }

            reverse(domainName.begin(), domainName.end());
            cleanEmail += domainName;

            // insert the email formed in hashset
            uniqueEmails.insert(cleanEmail);
        }

        // return count of unique emails
        return uniqueEmails.size();
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int numUniqueEmails(String[] emails) {
        // hash set to store all the unique emails
        Set<String> uniqueEmails = new HashSet<>();

        for (String email : emails) {
            StringBuilder cleanMail = new StringBuilder();

            // iterate over each character in email
            for (int i = 0; i < email.length(); ++i) {
                char currChar = email.charAt(i);

                // stop adding characters to localName
                if (currChar == '+' || currChar == '@') break;

                // add this character if not '.'
                if (currChar != '.') cleanMail.append(currChar);
            }

            // compute domain name (substring from end to '@')
            StringBuilder domainName = new StringBuilder();

            for (int i = email.length() - 1; i >= 0; --i) {
                char currChar = email.charAt(i);
                domainName.append(currChar);
                if (currChar == '@') break;
            }

            domainName = domainName.reverse();
            cleanMail.append(domainName);
            uniqueEmails.add(cleanMail.toString());
        }

        return uniqueEmails.size();
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
let numUniqueEmails = function (emails) {
    // hash set to store all the unique emails
    let uniqueEmails = new Set();

    emails.forEach((email) => {
        let cleanMail = [];

        // iterate over each character in email
        for (let i = 0; i < email.length; ++i) {
            let currChar = email.charAt(i);

            // stop adding characters to localName
            if (currChar === "+" || currChar === "@") break;

            // add this character if not '.'
            if (currChar !== ".") cleanMail.push(currChar);
        }

        // compute domain name (substring from end to '@')
        let domainName = [];

        for (i = email.length - 1; i >= 0; --i) {
            let currChar = email.charAt(i);
            domainName.push(currChar);
            if (currChar == "@") break;
        }

        domainName = domainName.reverse().join("");
        cleanMail = cleanMail.join("");

        uniqueEmails.add(cleanMail + domainName);
    });

    return uniqueEmails.size;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        # Hash set to store all the unique emails.
        uniqueEmails = set()

        # Iterate over each character in email.
        for email in emails:
            cleanMail = []

            # Iterate over each character in email.
            for currChar in email:
                # Stop adding characters to localName.
                if currChar == '+' or currChar == '@':
                    break

                # Add this character if not '.'.
                if currChar != '.':
                    cleanMail.append(currChar)

            # Compute domain name (substring from end to '@').
            domainName = []
            for currChar in reversed(email):
                domainName.append(currChar)
                if currChar == '@':
                    break

            # Reverse domain name and append to local name.
            domainName = ''.join(domainName[::-1])
            cleanMail = ''.join(cleanMail)
            uniqueEmails.add(cleanMail + domainName)

        return len(uniqueEmails)
```

</details>

<br>

## Approach 2: Using String Split Method

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
class Solution {
    public int numUniqueEmails(String[] emails) {
        // hash set to store all the unique emails
        Set<String> uniqueEmails = new HashSet<>();

        for (String email : emails) {
            // split into two parts local and domain
            String[] parts = email.split("@");

            // split local by '+'
            String[] local = parts[0].split("\\+");

            // remove all '.', and concatenate '@' and append domain
            uniqueEmails.add(local[0].replace(".", "") + "@" + parts[1]);
        }

        return uniqueEmails.size();
    }
}
```

</details>

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
let numUniqueEmails = function (emails) {
    // hash set to store all the unique emails
    let uniqueEmails = new Set();

    emails.forEach((email) => {
        // split into two parts local and domain
        let parts = email.split("@");

        // split local by '+'
        let local = parts[0].split("+");

        // remove all '.', and concatenate '@' and append domain
        uniqueEmails.add(local[0].replaceAll(".", "") + "@" + parts[1]);
    });

    return uniqueEmails.size;
};
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        # Hash set to store all the unique emails.
        uniqueEmails = set()

        for email in emails:
            # Split into two parts: local and domain.
            name, domain = email.split('@')

             # Split local by '+' and replace all '.' with ''.
            local = name.split('+')[0].replace('.', '')

            # Concatenate local, '@', and domain.
            uniqueEmails.add(local + '@' + domain)

        return len(uniqueEmails)
```

</details>
