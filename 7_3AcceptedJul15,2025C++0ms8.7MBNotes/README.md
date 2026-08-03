# 3AcceptedJul 15, 2025C++0 ms8.7 MBNotes

**Difficulty:** Medium
**Language:** plaintext
**Runtime:** N/A
**Memory:** N/A
**Submission Date:** Aug 3, 2026, 11:57 PM
**Problem URL:** [https://leetcode.com/problems/reverse-integer/](https://leetcode.com/problems/reverse-integer/)

---

## Problem Statement

Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

Example 1:

Input: x = 123
Output: 321

Example 2:

Input: x = -123
Output: -321

Example 3:

Input: x = 120
Output: 21

Constraints:

- -2^31 <= x <= 2^31 - 1

---

## Examples

Input: x = 123
Output: 321

Input: x = -123
Output: -321

Input: x = 120
Output: 21

---

## Constraints

_Not available._

---

## My Solution

```plaintext
class Solution {
public:
    int reverse(int x) {
        long m = (abs)((long)x);
        int sign = +1;
        long ans = 0;
        if(x<0) sign = -1;
        while(m>0){
            int y = m%10;
            ans = ans*10 + y;
            m = m/10;
            if(sign==-1 && -1 * ans < INT_MIN) return 0;
            if(sign==+1 && ans>INT_MAX) return 0;
        }
        return (int)(sign*ans);
    }
};

```
