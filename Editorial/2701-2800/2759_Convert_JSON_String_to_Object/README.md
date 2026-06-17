# 2759. Convert JSON String to Object

[![Hard](../../../_Misc/Badges/Hard.svg)](https://leetcode.com/problems/convert-json-string-to-object/)  

**Problem Link:** [LeetCode 2759 - Convert JSON String to Object](https://leetcode.com/problems/convert-json-string-to-object/)

## Problem

Given a string str, return parsed JSON parsedStr. You may assume the str is a valid JSON string hence it only includes strings, numbers, arrays, objects, booleans, and null. str will not include invisible characters and escape characters.

Please solve it without using the built-in JSON.parse method.

### Example 1

```text
Input: str = '{"a":2,"b":[1,2,3]}'
Output: {"a":2,"b":[1,2,3]}
Explanation: Returns the object represented by the JSON string.
```

### Example 2

```text
Input: str = 'true'
Output: true
Explanation: Primitive types are valid JSON.
```

### Example 3

```text
Input: str = '[1,5,"false",{"a":2}]'
Output: [1,5,"false",{"a":2}]
Explanation: Returns the array represented by the JSON string.
```

## Constraints

- str is a valid JSON string
- 1 <= str.length <= 105

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| None listed |  |

<br>
<br>

---

<br>
<br>

# Editorial - 2759. Convert JSON String to Object

## Overview

This section follows the official LeetCode editorial approach list and uses the official code snippets for the available languages.

| Approach | Languages |
|---|---|
| Recursive Descent Parsing | JavaScript, TypeScript |
| Iterative Parsing with Stack | JavaScript, TypeScript |

## Approach 1: Recursive Descent Parsing

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var jsonParse = function(str) {
   let i = 0;

   return parseValue();

   function parseValue() {
      switch (str[i]) {
         case '"':
            return parseString();
         case '{':
            return parseObject();
         case '[':
            return parseArray();
         case 't':
         case 'f':
         case 'n':
            return parseLiteral();
         default:
            return parseNumber();
      }
   }

   function parseNumber() {
      let start = i;

      if (str[i] === '-') {
         i++;
      }

      while (i < str.length && isDigit(str[i])) {
         i++;
      }

      if (str[i] === '.') {
         i++;
         while (i < str.length && isDigit(str[i])) {
            i++;
         }
      }

      return Number(str.slice(start, i));
   }

   function isDigit(n) {
      return n >= '0' && n <= '9';
   }

   function parseString() {
      let result = '';
      i++;

      while (i < str.length && str[i] != '"') {
         result += str[i];
         i++;
      }

      i++;
      return result;
   }

   function parseObject() {
      i++;

      const result = {};

      while (i < str.length && str[i] !== '}') {
         const key = parseString();
         expectChar(':');
         const value = parseValue();

         result[key] = value;
         if (str[i] === ',') {
            i++;
         }
      }

      i++;
      return result;
   }

   function parseArray() {
      i++;

      const result = [];

      while (i < str.length && str[i] !== ']') {
         const value = parseValue();
         result.push(value);
         if (str[i] === ',') {
            i++;
         }
      }

      i++;
      return result;
   }

   function parseLiteral() {
      if (str.startsWith('true', i)) {
         i += 4; // length of 'true'
         return true;
      } else if (str.startsWith('false', i)) {
         i += 5; // length of 'false'
         return false;
      } else if (str.startsWith('null', i)) {
         i += 4; // length of 'null'
         return null;
      }
   }

   function expectChar(char) {
      if (str[i] !== char) {
         throw new Error(`Expected '${char}' at position ${i}`);
      }
      i++;
   }
}
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function jsonParse(str: string): any {
   let i = 0;

   return parseValue();

   function parseValue(): any {
      switch (str[i]) {
         case '"':
            return parseString();
         case '{':
            return parseObject();
         case '[':
            return parseArray();
         case 't':
         case 'f':
         case 'n':
            return parseLiteral();
         default:
            return parseNumber();
      }
   }

   function parseNumber(): number {
      let start = i;

      if (str[i] === '-') {
         i++;
      }

      while (i < str.length && isDigit(str[i])) {
         i++;
      }

      if (str[i] === '.') {
         i++;
         while (i < str.length && isDigit(str[i])) {
            i++;
         }
      }

      return Number(str.slice(start, i));
   }

   function isDigit(n: string): boolean {
      return n >= '0' && n <= '9';
   }

   function parseString(): string {
      let result = '';
      i++;

      while (i < str.length && str[i] !== '"') {
         result += str[i];
         i++;
      }

      i++;
      return result;
   }

   function parseObject(): Object {
      i++;

      const result: any = {};

      while (i < str.length && str[i] !== '}') {
         const key = parseString();
         expectChar(':');
         const value = parseValue();

         result[key] = value;
         if (str[i] === ',') {
            i++;
         }
      }

      i++;
      return result;
   }

   function parseArray(): any[] {
      i++;

      const result: any[] = [];

      while (i < str.length && str[i] !== ']') {
         const value = parseValue();
         result.push(value);
         if (str[i] === ',') {
            i++;
         }
      }

      i++;
      return result;
   }

   function parseLiteral(): boolean | null {
      if (str.startsWith('true', i)) {
         i += 4;
         return true;
      } else if (str.startsWith('false', i)) {
         i += 5;
         return false;
      } else if (str.startsWith('null', i)) {
         i += 4;
         return null;
      }
      throw new Error(`Unexpected token at position ${i}`);
   }

   function expectChar(char: string): void {
      if (str[i] !== char) {
         throw new Error(`Expected '${char}' at position ${i}`);
      }
      i++;
   }
}
```

</details>

<br>

## Approach 2: Iterative Parsing with Stack

### Implementation

<details>
<summary><strong>JavaScript</strong></summary>

```javascript
var jsonParse = function(str) {
   const length = str.length;
   const stack = [];  // Stack to maintain the hierarchy of nested structures.
   let currentStruct = null;  // Current structure being processed (either an array or an object).
   let root = null;  // Root structure of the parsed JSON.
   let currentKey = null;  // Key for the current object value being processed.

   for(let i = 0; i < length; i++){
      if(str[i] === ",") continue;  // Skip commas.

      switch(str[i]) {
         case '[':
         case '{':
            const newStruct = str[i] === '[' ? [] : {};

            // If this is the first structure, set it as root.
            if (root === null) root = newStruct;

            if (currentStruct !== null) {
               if (Array.isArray(currentStruct)) {
                  currentStruct.push(newStruct);
               } else {
                  currentStruct[currentKey] = newStruct;
                  currentKey = null;
               }
            }

            stack.push(currentStruct);
            currentStruct = newStruct;  // Update the current structure.
            break;

         case ']':
         case '}':
            // End of current structure. Pop from the stack to go up one level.
            currentStruct = stack.pop();
            break;

         default:
            // Parse a value (either string, number, boolean, or null).
            let value = null;

            if(str[i] === '"') {  // String value.
               let j = i + 1;
               while(i + 1 < length && str[i + 1] !== '"') i++;
               value = str.substring(j, i + 1);
               i++;
            } else if(str[i] === '-' || ('0' <= str[i] && str[i] <= '9')) {  // Number value.
               let j = i;
               while(i + 1 < length && (str[i + 1] === '-' ||
                       ('0' <= str[i + 1] && str[i + 1] <= '9') ||
                       str[i + 1] === '.')) {
                  i++;
               }
               value = Number(str.substring(j, i + 1));
            } else {  // Boolean or null value.
               if(i + 4 <= length && str.substring(i, i + 4) === "true") {
                  value = true;
                  i += 3;
               } else if(i + 5 <= length && str.substring(i, i + 5) === "false") {
                  value = false;
                  i += 4;
               } else {
                  value = null;
                  i += 3;
               }
            }

            if (root === null) root = value;  // If this is the first value, set it as root.

            if(str[i + 1] === ":") {  // Object key.
               currentKey = value;
               i++;
            } else if(Array.isArray(currentStruct)) {  // Array value.
               currentStruct.push(value);
            } else if(currentKey !== null) {  // Object value.
               currentStruct[currentKey] = value;
               currentKey = null;
            } else {
               currentStruct = value;
            }
            break;
      }
   }

   return root;
};
```

</details>

<details>
<summary><strong>TypeScript</strong></summary>

```typescript
function jsonParse(str: string): any {
   const length = str.length;
   const stack: any[] = [];  // Stack to maintain the hierarchy of nested structures.
   let currentStruct: any = null;  // Current structure being processed (either an array or an object).
   let root: any = null;  // Root structure of the parsed JSON.
   let currentKey: string | null = null;  // Key for the current object value being processed.

   for(let i = 0; i < length; i++){
      if(str[i] === ",") continue;  // Skip commas.

      switch(str[i]) {
         case '[':
         case '{':
            const newStruct = str[i] === '[' ? [] : {};

            // If this is the first structure, set it as root.
            if (root === null) root = newStruct;

            if (currentStruct !== null) {
               if (Array.isArray(currentStruct)) {
                  currentStruct.push(newStruct);
               } else {
                  currentStruct[currentKey as string] = newStruct;
                  currentKey = null;
               }
            }

            stack.push(currentStruct);
            currentStruct = newStruct;  // Update the current structure.
            break;

         case ']':
         case '}':
            // End of current structure. Pop from the stack to go up one level.
            currentStruct = stack.pop();
            break;

         default:
            // Parse a value (either string, number, boolean, or null).
            let value: any = null;

            if(str[i] === '"') {  // String value.
               let j = i + 1;
               while(i + 1 < length && str[i + 1] !== '"') i++;
               value = str.substring(j, i + 1);
               i++;
            } else if(str[i] === '-' || ('0' <= str[i] && str[i] <= '9')) {  // Number value.
               let j = i;
               while(i + 1 < length && (str[i + 1] === '-' ||
                       ('0' <= str[i + 1] && str[i + 1] <= '9') ||
                       str[i + 1] === '.')) {
                  i++;
               }
               value = Number(str.substring(j, i + 1));
            } else {  // Boolean or null value.
               if(i + 4 <= length && str.substring(i, i + 4) === "true") {
                  value = true;
                  i += 3;
               } else if(i + 5 <= length && str.substring(i, i + 5) === "false") {
                  value = false;
                  i += 4;
               } else {
                  value = null;
                  i += 3;
               }
            }

            if (root === null) root = value;  // If this is the first value, set it as root.

            if(str[i + 1] === ":") {  // Object key.
               currentKey = value as string;
               i++;
            } else if(Array.isArray(currentStruct)) {  // Array value.
               currentStruct.push(value);
            } else if(currentKey !== null) {  // Object value.
               currentStruct[currentKey] = value;
               currentKey = null;
            } else {
               currentStruct = value;
            }
            break;
      }
   }

   return root;
};
```

</details>
