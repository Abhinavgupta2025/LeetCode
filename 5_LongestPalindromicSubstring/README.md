# Longest Palindromic Substring

**Difficulty:** Medium
**Language:** plaintext
**Runtime:** N/A
**Memory:** N/A
**Submission Date:** Jul 24, 2026, 10:05 AM
**Problem URL:** [https://leetcode.com/problems/longest-palindromic-substring/](https://leetcode.com/problems/longest-palindromic-substring/)

---

## Problem Statement

Given a string s, return the longest palindromic substring in s.

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:

Input: s = "cbbd"
Output: "bb"

Constraints:

- 1 <= s.length <= 1000

- s consist of only digits and English letters.

---

## Examples

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Input: s = "cbbd"
Output: "bb"

---

## Constraints

_Not available._

---

## My Solution

```plaintext
        }
        int n = t.length();
        vector<int> p(n,0);
        int center = 0;
        int right = 0;
        int maxRadius = 0;
        int maxCenter = 0;
        for(int i=0;i<n;i++){
            int mirror = 2*center-i;
            if(i<right){
                p[i] = min(right-i,p[mirror]);
            }
            while(i-p[i]-1>=0 && i+p[i]+1<n &&
                t[i-p[i]-1] == t[i+p[i]+1]){
                    p[i]++;
                }
            if(i+p[i]>right){
                center = i;
                right = i+p[i];
            }
            if(p[i]>maxRadius){
                maxRadius = p[i];
                maxCenter = i;
            }
        }
        int start = (maxCenter - maxRadius)/2;

```
