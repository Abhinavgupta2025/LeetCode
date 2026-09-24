# Smallest Index With Digit Sum Equal to Index

**Difficulty:** Easy
**Language:** cpp
**Runtime:** 0 (beats 100.00%)
**Memory:** 30948000 (beats 52.36%)
**Submission Date:** Sep 24, 2026, 6:32 PM
**Problem URL:** [https://leetcode.com/problems/smallest-index-with-digit-sum-equal-to-index/](https://leetcode.com/problems/smallest-index-with-digit-sum-equal-to-index/)

---

## Problem Statement

You are given an integer array nums.

Return the smallest index i such that the sum of the digits of nums[i] is equal to i.

If no such index exists, return -1.

Example 1:

Input: nums = [1,3,2]

Output: 2

Explanation:

- For nums[2] = 2, the sum of digits is 2, which is equal to index i = 2. Thus, the output is 2.

Example 2:

Input: nums = [1,10,11]

Output: 1

Explanation:

- For nums[1] = 10, the sum of digits is 1 + 0 = 1, which is equal to index i = 1.

- For nums[2] = 11, the sum of digits is 1 + 1 = 2, which is equal to index i = 2.

- Since index 1 is the smallest, the output is 1.

Example 3:

Input: nums = [1,2,3]

Output: -1

Explanation:

- Since no index satisfies the condition, the output is -1.

Constraints:

- 1 <= nums.length <= 100

- 0 <= nums[i] <= 1000

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
    int smallestIndex(vector<int>& nums) {
         int n = nums.size();
        int ans = -1;
        
        for(int i=0;i<n;i++){
            int x = nums[i];
            int sum = 0;
            while(x>0){
                sum += x%10;
                 x = x/10;
            }
        if(i==sum){
            ans = i;
           break;
        }
        }
        return ans;
    }
};
```
