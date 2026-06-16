# 2. Add Two Numbers

[![Medium](../../Miscellaneous/Badges/Med.svg)](https://leetcode.com/problems/add-two-numbers/)  
`Linked List` `Math` `Recursion`

**Problem Link:** [LeetCode 2 - Add Two Numbers](https://leetcode.com/problems/add-two-numbers/)

## Problem

You are given two non-empty linked lists, `l1` and `l2`, representing two non-negative integers.

The digits are stored in reverse order, and each node contains one digit. Add the two numbers and return the sum as a linked list in the same reverse-order format.

The input numbers do not contain leading zeroes, except for the number `0` itself.

## Examples

### Example 1

```text
Input: l1 = [2, 4, 3], l2 = [5, 6, 4]
Output: [7, 0, 8]
Explanation: 342 + 465 = 807.
```

### Example 2

```text
Input: l1 = [0], l2 = [0]
Output: [0]
```

### Example 3

```text
Input: l1 = [9, 9, 9, 9, 9, 9, 9], l2 = [9, 9, 9, 9]
Output: [8, 9, 9, 9, 0, 0, 0, 1]
```

## Constraints

- The number of nodes in each linked list is in the range `[1, 100]`.
- `0 <= Node.val <= 9`
- Each linked list represents a number without leading zeroes, except for the number `0`.

## Follow-Up

Can you solve the problem without converting the linked lists into integers?

## Hints

<details>
<summary><strong>Hint 1</strong></summary>

The lists store digits from least significant to most significant, so you can add from the head forward just like grade-school addition.

</details>

<details>
<summary><strong>Hint 2</strong></summary>

At every step, add the two current digits plus a `carry` from the previous step.

</details>

<details>
<summary><strong>Hint 3</strong></summary>

A dummy head node makes it easier to append result nodes without handling the first node as a special case.

</details>

## Similar Problems

| Problem | Difficulty |
|---|:---:|
| [Multiply Strings](https://leetcode.com/problems/multiply-strings/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Add Binary](https://leetcode.com/problems/add-binary/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Sum of Two Integers](https://leetcode.com/problems/sum-of-two-integers/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Add Strings](https://leetcode.com/problems/add-strings/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Add Two Numbers II](https://leetcode.com/problems/add-two-numbers-ii/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Add to Array-Form of Integer](https://leetcode.com/problems/add-to-array-form-of-integer/) | ![Easy](../../Miscellaneous/Badges/Easy.svg) |
| [Add Two Polynomials Represented as Linked Lists](https://leetcode.com/problems/add-two-polynomials-represented-as-linked-lists/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
| [Double a Number Represented as a Linked List](https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/) | ![Medium](../../Miscellaneous/Badges/Med.svg) |
