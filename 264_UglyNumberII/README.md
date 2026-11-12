# Ugly Number II

**Difficulty:** Medium
**Language:** plaintext
**Runtime:** N/A
**Memory:** N/A
**Submission Date:** Nov 12, 2026, 5:18 PM
**Problem URL:** [https://leetcode.com/problems/ugly-number-ii/](https://leetcode.com/problems/ugly-number-ii/)

---

## Problem Statement

An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return the n^th ugly number.

Example 1:

Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.

Example 2:

Input: n = 1
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.

Constraints:

- 1 <= n <= 1690

---

## Examples

Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.

Input: n = 1
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.

---

## Constraints

_Not available._

---

## My Solution

```plaintext
class Solution {
public:
    int nthUglyNumber(int n) {
         vector<int> arr(n+1,1);
         arr[1] = 1;
         int a = 1;
         int b = 1;
         int c = 1;
         for(int i=2;i<=n;i++){
            int x = arr[a]*2;
            int y = arr[b]*3;
            int z = arr[c]*5;
            int v = min({x,y,z});
            arr[i] = v;
            if(x==v) a++;
            if(y==v) b++;
            if(z==v) c++;
         }
         return arr[n];
    }
};
```
