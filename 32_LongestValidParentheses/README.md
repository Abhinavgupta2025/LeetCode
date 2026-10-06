# Longest Valid Parentheses

**Difficulty:** Hard
**Language:** plaintext
**Runtime:** N/A
**Memory:** N/A
**Submission Date:** Oct 6, 2026, 5:54 PM
**Problem URL:** [https://leetcode.com/problems/longest-valid-parentheses/](https://leetcode.com/problems/longest-valid-parentheses/)

---

## Problem Statement

Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.

Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".

Example 2:

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".

Example 3:

Input: s = ""
Output: 0

Constraints:

- 0 <= s.length <= 3 * 10^4

- s[i] is '(', or ')'.

---

## Examples

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".

Input: s = ""
Output: 0

---

## Constraints

_Not available._

---

## My Solution

```plaintext
class Solution {
public:
    int longestValidParentheses(string s) {
            int n = s.length();
            int idx = 0;
            int ans = 0;
            while(s[idx]==')') idx++;
            for(int i=idx;i<n;i++){
                int left = 0;
                int right = 0;
                for(int j=i;j<n;j++){
                    if(s[j]=='(') left++;
                    else left--;
                    if(left<0) break;
                    if(left==0) ans = max(ans,j-i+1);
                }
            }
            return ans;

    }
};
```
