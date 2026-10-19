# Buddy Strings

**Difficulty:** Easy
**Language:** plaintext
**Runtime:** N/A
**Memory:** N/A
**Submission Date:** Oct 19, 2026, 6:24 PM
**Problem URL:** [https://leetcode.com/problems/buddy-strings/](https://leetcode.com/problems/buddy-strings/)

---

## Problem Statement

Given two strings s and goal, return true if you can swap two letters in s so the result is equal to goal, otherwise, return false.

Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at s[i] and s[j].

- For example, swapping at indices 0 and 2 in "abcd" results in "cbad".

Example 1:

Input: s = "ab", goal = "ba"
Output: true
Explanation: You can swap s[0] = 'a' and s[1] = 'b' to get "ba", which is equal to goal.

Example 2:

Input: s = "ab", goal = "ab"
Output: false
Explanation: The only letters you can swap are s[0] = 'a' and s[1] = 'b', which results in "ba" != goal.

Example 3:

Input: s = "aa", goal = "aa"
Output: true
Explanation: You can swap s[0] = 'a' and s[1] = 'a' to get "aa", which is equal to goal.

Constraints:

- 1 <= s.length, goal.length <= 2 * 10^4

- s and goal consist of lowercase letters.

---

## Examples

Input: s = "ab", goal = "ba"
Output: true
Explanation: You can swap s[0] = 'a' and s[1] = 'b' to get "ba", which is equal to goal.

Input: s = "ab", goal = "ab"
Output: false
Explanation: The only letters you can swap are s[0] = 'a' and s[1] = 'b', which results in "ba" != goal.

Input: s = "aa", goal = "aa"
Output: true
Explanation: You can swap s[0] = 'a' and s[1] = 'a' to get "aa", which is equal to goal.

---

## Constraints

_Not available._

---

## My Solution

```plaintext
class Solution {
    public boolean check(String s) {
        char[] arr = new char[26];
        for (int i = 0; i < s.length(); i++) {
            if (arr[s.charAt(i) - 'a'] > 0)
                return true;
            arr[s.charAt(i) - 'a']++;
        }
        return false;
    }

    public boolean buddyStrings(String s, String goal) {
         int n = s.length();
         int m = goal.length();
         ArrayList<Character> arr = new ArrayList<>();
         if(n!=m) return false;
         for(int i=0;i<n;i++){
            if(!(s.charAt(i).equals(goal.charAt(i)))) arr.add(i);
         }
         if(arr.length>) return false;
         if(arr.length()==0) return check(s);
         if (arr.size() == 2) {
            int i = arr.get(0);
            int j = arr.get(1);

            StringBuilder sb = new StringBuilder(s);

            char temp = sb.charAt(i);
            sb.setCharAt(i, sb.charAt(j));
            sb.setCharAt(j, temp);

            s = sb.toString();
}
    }
}
```
