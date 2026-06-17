# 271. Encode and Decode Strings

[![Medium](../../../_Misc/Badges/Med.svg)](https://leetcode.com/problems/encode-and-decode-strings/)  
`Array` `String` `Design`

**Problem Link:** [LeetCode 271 - Encode and Decode Strings](https://leetcode.com/problems/encode-and-decode-strings/)

## Problem

Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and is decoded back to the original list of strings.

Machine 1 (sender) has the function:

```text
string encode(vector<string> strs) {
  // ... your code
  return encoded_string;
}
```

```text
vector<string> decode(string s) {
  //... your code
  return strs;
}
```

So Machine 1 does:

```text
string encoded_string = encode(strs);
```

and Machine 2 does:

```text
vector<string> strs2 = decode(encoded_string);
```

strs2 in Machine 2 should be the same as strs in Machine 1.

Implement the encode and decode methods.

You are not allowed to solve the problem using any serialize methods (such as eval).

### Example 1

```text
Input: dummy_input = ["Hello","World"]
Output: ["Hello","World"]
Explanation:
Machine 1:
Codec encoder = new Codec();
String msg = encoder.encode(strs);
Machine 1 ---msg---> Machine 2

Machine 2:
Codec decoder = new Codec();
String[] strs = decoder.decode(msg);
```

### Example 2

```text
Input: dummy_input = [""]
Output: [""]
```

## Constraints

- 1 <= strs.length <= 200
- 0 <= strs[i].length <= 200
- strs[i] contains any possible characters out of 256 valid ASCII characters.

Follow up: Could you write a generalized algorithm to work on any possible set of characters?

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Count and Say](https://leetcode.com/problems/count-and-say/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Serialize and Deserialize Binary Tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/) | ![Hard](../../../_Misc/Badges/Hard.svg) |
| [String Compression](https://leetcode.com/problems/string-compression/) | ![Medium](../../../_Misc/Badges/Med.svg) |
| [Count Binary Substrings](https://leetcode.com/problems/count-binary-substrings/) | ![Easy](../../../_Misc/Badges/Easy.svg) |

<br>
<br>

---

<br>
<br>

# Editorial - 271. Encode and Decode Strings

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Non-ASCII delimiter | Java, Python3 |
| Escaping | C++, Java, Python3 |
| Chunked Transfer Encoding | C++, Java, Python3 |

## Approach 1: Non-ASCII delimiter

### Implementation

<details>
<summary><strong>Java</strong></summary>

```java
public class Codec {
    // Encodes a list of strings to a single string.
    public String encode(List<String> strs) {
        StringBuilder encodedString = new StringBuilder();
        // Iterate through the list of strings
        for (String s : strs) {
            // Append each string to the StringBuilder followed by the delimiter
            encodedString.append(s);
            encodedString.append("Ãâ‚¬");
        }
        // Return the entire encoded string
        return encodedString.toString();
    }

    // Decodes a single string to a list of strings.
    public List<String> decode(String s) {
        // Split the encoded string at each occurrence of the delimiter
        // Note: We use -1 as the limit parameter to ensure trailing empty strings are included
        String[] decodedStrings = s.split("Ãâ‚¬", -1);
        // Convert the array to a list and return it
        // Note: We remove the last element because it's an empty string resulting from the final delimiter
        return new ArrayList<>(Arrays.asList(decodedStrings).subList(0, decodedStrings.length - 1));
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Codec:
    def encode(self, strs):
        """Encodes a list of strings to a single string."""
        return 'Ãâ‚¬'.join(strs)
        
    def decode(self, s):
        """Decodes a single string to a list of strings."""
        return s.split('Ãâ‚¬')
```

</details>

<br>

## Approach 2: Escaping

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        // Initialize a string to hold the encoded strings
        string encodedString;

        // Iterate over each string in the input list
        for (const auto& s : strs) {
            // For each string, iterate over each character
            for (const char c : s) {
                // If the character is a slash, append an additional slash to 'encodedString'
                if (c == '/') {
                    encodedString += "//";
                }
                // Otherwise, simply append the character to 'encodedString'
                else {
                    encodedString += c;
                }
            }
            // After encoding each string, append the delimiter "/:"
            encodedString += "/:";
        }

        // Return the final encoded string
        return encodedString;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        // Initialize a vector to hold the decoded strings
        vector<string> decodedStrings;

        // Initialize a string to hold the current string being decoded
        string currentString;

        // Iterate over the characters in the input string
        for (size_t i = 0; i < s.size(); i++) {
            // If we encounter the delimiter "/:"
            if (i < s.size()-1 && s[i] == '/' && s[i+1] == ':') {
                // Add the current string to 'decodedStrings'
                decodedStrings.push_back(currentString);

                // Clear 'currentString' for the next string
                currentString.clear();

                // Move the index 1 step forward to skip the delimiter
                i += 1;
            }
            // If we encounter an escaped slash "//"
            else if (i < s.size()-1 && s[i] == '/' && s[i+1] == '/') {
                // Add a single slash to the 'currentString'
                currentString += '/';

                // Move the index 1 step forward to skip the escaped slash
                i += 1;
            }
            // Otherwise, just add the character to 'currentString'
            else {
                currentString += s[i];
            }
        }

        // Return the list of decoded strings
        return decodedStrings;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Codec {

    // Encodes a list of strings to a single string.
    public String encode(List<String> strs) {
        // Initialize a StringBuilder to hold the encoded strings
        StringBuilder encodedString = new StringBuilder();

        // Iterate over each string in the input list
        for (String s : strs) {
            // Replace each occurrence of '/' with '//'
            // This is our way of "escaping" the slash character
            // Then add our delimiter '/:' to the end
            encodedString.append(s.replace("/", "//")).append("/:");
        }

        // Return the final encoded string
        return encodedString.toString();
    }

    // Decodes a single string to a list of strings.
    public List<String> decode(String s) {
        // Initialize a List to hold the decoded strings
        List<String> decodedStrings = new ArrayList<>();

        // Initialize a StringBuilder to hold the current string being built
        StringBuilder currentString = new StringBuilder();

        // Initialize an index 'i' to start of the string
        int i = 0;

        // Iterate while 'i' is less than the length of the encoded string
        while (i < s.length()) {
            // If we encounter the delimiter '/:'
            if (i + 1 < s.length() && s.charAt(i) == '/' && s.charAt(i + 1) == ':') {
                // Add the currentString to the list of decodedStrings
                decodedStrings.add(currentString.toString());

                // Clear currentString for the next string
                currentString = new StringBuilder();

                // Move the index 2 steps forward to skip the delimiter
                i += 2;
            }
            // If we encounter an escaped slash '//'
            else if (i + 1 < s.length() && s.charAt(i) == '/' && s.charAt(i + 1) == '/') {
                // Add a single slash to the currentString
                currentString.append('/');

                // Move the index 2 steps forward to skip the escaped slash
                i += 2;
            }
            // Otherwise, just add the character to currentString and move the index 1 step forward.
            else {
                currentString.append(s.charAt(i));
                i++;
            }
        }

        // Return the list of decoded strings
        return decodedStrings;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Codec:
    def encode(self, strs):
        """
        Encodes a list of strings to a single string.

        :param strs: List of strings to encode.
        :return: Encoded string.
        """
        # Initialize an empty string to hold the encoded strings
        encoded_string = ''

        # Iterate over each string in the input list
        for s in strs:
            # Replace each occurrence of '/' with '//'
            # This is our way of "escaping" the slash character
            # Then add our delimiter '/:' to the end
            encoded_string += s.replace('/', '//') + '/:'

        # Return the final encoded string
        return encoded_string

    def decode(self, s):
        """
        Decodes a single string to a list of strings.

        :param s: String to decode.
        :return: List of decoded strings.
        """
        # Initialize an empty list to hold the decoded strings
        decoded_strings = []

        # Initialize a string to hold the current string being built
        current_string = ""

        # Initialize an index 'i' to start of the string
        i = 0

        # Iterate while 'i' is less than the length of the encoded string
        while i < len(s):
            # If we encounter the delimiter '/:'
            if s[i:i+2] == '/:':
                # Add the current_string to the list of decoded_strings
                decoded_strings.append(current_string)

                # Clear current_string for the next string
                current_string = ""

                # Move the index 2 steps forward to skip the delimiter
                i += 2

            # If we encounter an escaped slash '//'
            elif s[i:i+2] == '//':
                # Add a single slash to the current_string
                current_string += '/'

                # Move the index 2 steps forward to skip the escaped slash
                i += 2

            # Otherwise, just add the character to current_string
            else:
                current_string += s[i]
                i += 1

        # Return the list of decoded strings
        return decoded_strings
```

</details>

<br>

## Approach 3: Chunked Transfer Encoding

### Implementation

<details>
<summary><strong>C++</strong></summary>

```cpp
class Codec {
public:
    string encode(vector<string>& strs) {
        // Initialize an empty string to hold the encoded string.
        string encodedString;
        for (string &s : strs) {
            // Append the length, the delimiter, and the string itself.
            encodedString += to_string(s.size()) + "/:" + s;
        }
        return encodedString;
    }

    vector<string> decode(string s) {
        // Initialize a list to hold the decoded strings.
        vector<string> decodedStrings;
        size_t i = 0;
        while (i < s.size()) {
            // Find the delimiter.
            size_t delim = s.find("/:", i);
            // Get the length, which is before the delimiter.
            int length = stoi(s.substr(i, delim - i));
            // Get the string, which is of 'length' length after the delimiter.
            string str = s.substr(delim + 2, length);
            // Add the string to the list.
            decodedStrings.push_back(str);
            // Move the index to the start of the next length.
            i = delim + 2 + length;
        }
        return decodedStrings;
    }
};
```

</details>

<details>
<summary><strong>Java</strong></summary>

```java
public class Codec {
    public String encode(List<String> strs) {
        // Initialize a StringBuilder to hold the encoded string.
        StringBuilder encodedString = new StringBuilder();
        for (String s : strs) {
            // Append the length, the delimiter, and the string itself.
            encodedString.append(s.length()).append("/:").append(s);
        }
        return encodedString.toString();
    }

    public List<String> decode(String s) {
        // Initialize a list to hold the decoded strings.
        List<String> decodedStrings = new ArrayList<>();
        int i = 0;
        while (i < s.length()) {
            // Find the delimiter.
            int delim = s.indexOf("/:", i);
            // Get the length, which is before the delimiter.
            int length = Integer.parseInt(s.substring(i, delim));
            // Get the string, which is of 'length' length after the delimiter.
            String str = s.substring(delim + 2, delim + 2 + length);
            // Add the string to the list.
            decodedStrings.add(str);
            // Move the index to the start of the next length.
            i = delim + 2 + length;
        }
        return decodedStrings;
    }
}
```

</details>

<details>
<summary><strong>Python3</strong></summary>

```python
class Codec:
    def encode(self, strs):
        # Initialize an empty string to hold the encoded string.
        encoded_string = ''
        for s in strs:
            # Append the length, the delimiter, and the string itself.
            encoded_string += str(len(s)) + '/:' + s
        return encoded_string

    def decode(self, s):
        # Initialize a list to hold the decoded strings.
        decoded_strings = []
        i = 0
        while i < len(s):
            # Find the delimiter.
            delim = s.find('/:', i)
            # Get the length, which is before the delimiter.
            length = int(s[i:delim])
            # Get the string, which is of 'length' length after the delimiter.
            str_ = s[delim+2 : delim+2+length]
            # Add the string to the list.
            decoded_strings.append(str_)
            # Move the index to the start of the next length.
            i = delim + 2 + length
        return decoded_strings
```

</details>
