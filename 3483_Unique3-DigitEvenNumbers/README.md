# Unique 3-Digit Even Numbers

**Difficulty:** Easy
**Language:** cpp
**Runtime:** 430 (beats 5.23%)
**Memory:** 192880000 (beats 6.76%)
**Submission Date:** Sep 11, 2026, 9:16 AM
**Problem URL:** [https://leetcode.com/problems/unique-3-digit-even-numbers/](https://leetcode.com/problems/unique-3-digit-even-numbers/)

---

## Problem Statement

You are given an array of digits called digits. Your task is to determine the number of distinct three-digit even numbers that can be formed using these digits.

Note: Each copy of a digit can only be used once per number, and there may not be leading zeros.

Example 1:

Input: digits = [1,2,3,4]

Output: 12

Explanation: The 12 distinct 3-digit even numbers that can be formed are 124, 132, 134, 142, 214, 234, 312, 314, 324, 342, 412, and 432. Note that 222 cannot be formed because there is only 1 copy of the digit 2.

Example 2:

Input: digits = [0,2,2]

Output: 2

Explanation: The only 3-digit even numbers that can be formed are 202 and 220. Note that the digit 2 can be used twice because it appears twice in the array.

Example 3:

Input: digits = [6,6,6]

Output: 1

Explanation: Only 666 can be formed.

Example 4:

Input: digits = [1,3,5]

Output: 0

Explanation: No even 3-digit numbers can be formed.

Constraints:

- 3 <= digits.length <= 10

- 0 <= digits[i] <= 9

---

## Examples

_Not available._

---

## Constraints

_Not available._

---

## My Solution

```cpp
class Solution {
public:
    bool check(int i,unordered_map<int,int> mp){
            while(i>0){
                int rem = i%10;
                if(mp.find(rem)!=mp.end()){
                    mp[rem]--;
                    if(mp[rem]==0) mp.erase(rem);
                }
                else return false;
                i = i/10;
            }
            return true;
    }
    int totalNumbers(vector<int>& digits) {
         int n = digits.size();
         unordered_map<int,int> mp;
         for(int i=0;i<n;i++){
            mp[digits[i]]++;
        }
        int count = 0;
        for(int i=100;i<=999;i+=2){
            if(check(i,mp)) count++;
        }
        return count;
    }
};
```
