# Lexicographically Largest String After Pair Transformations

**Difficulty:** Medium
**Language:** plaintext
**Runtime:** N/A
**Memory:** N/A
**Submission Date:** Sep 2, 2026, 5:51 PM
**Problem URL:** [https://leetcode.com/problems/lexicographically-largest-string-after-pair-transformations/](https://leetcode.com/problems/lexicographically-largest-string-after-pair-transformations/)

---

## Problem Statement

You are given an integer array nums.

For each integer x in nums, start with a string consisting of exactly x lowercase 'a' characters.

You may perform the following operation any number of times (including zero):

- Choose two adjacent equal letters and replace them with the next letter in the alphabet.

For example, "aa" can be replaced with "b", and "bb" can be replaced with "c". The pair "zz" cannot be replaced.

For each x, determine the lexicographically largest string that can be obtained.

Return an array of strings where the i^th string is the answer for nums[i].

A string a is lexicographically larger than a string b if, at the first position where they differ, a contains a letter that appears later in the alphabet than the corresponding letter in b. If the first min(a.length, b.length) characters are equal, the longer string is lexicographically larger.

Example 1:

Input: nums = [2,5,7]

Output: ["b","ca","cba"]

Explanation:

- nums[0] = 2: "aa" → "b".

- nums[1] = 5: "aaaaa" → "baaa" → "bba" → "ca".

- nums[2] = 7: "aaaaaaa" → "baaaaa" → "bbaaa" → "bbba" → "cba".

- Therefore, ans = ["b", "ca", "cba"].

Example 2:

Input: nums = [3,9,1]

Output: ["ba","da","a"]

Explanation:

- nums[0] = 3: "aaa" → "ba".

- nums[1] = 9: "aaaaaaaaa" → "baaaaaaa" → "bbaaaaa" → "bbbaaa" → "bbbba" → "cbba" → "cca" → "da".

- nums[2] = 1: No transformation can be applied, so the result is "a".

- Therefore, ans = ["ba", "da", "a"].

Constraints:

- 1 <= nums.length <= 10^5

- 1 <= nums[i] <= 10^8

---

## Examples

_Not available._

---

## Constraints

_Not available._

---

## My Solution

```plaintext
class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
            int n = nums.size();
            vector<int> base;
            int t = 1;
            for(int i=0;i<26;i++){
                base.push_back(t);
                t = t*2;
            }
            vector<string> ans;
            for(auto it : nums){
                int temp = it;
                string s = "";
                while(temp>0){
                    int i=25;
                    while(base[i]>temp){
                        i--;
                    }
                    s.push_back(i+'a');
                    temp -= base[i];
                }
                ans.push_back(s);
            }
            return ans;
    }
};
```
