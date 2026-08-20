# Subarray Sums Divisible by K

**Difficulty:** Medium
**Language:** plaintext
**Runtime:** N/A
**Memory:** N/A
**Submission Date:** Aug 20, 2026, 6:34 PM
**Problem URL:** [https://leetcode.com/problems/subarray-sums-divisible-by-k/](https://leetcode.com/problems/subarray-sums-divisible-by-k/)

---

## Problem Statement

Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

A subarray is a contiguous part of an array.

Example 1:

Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]

Example 2:

Input: nums = [5], k = 9
Output: 0

Constraints:

- 1 <= nums.length <= 3 * 10^4

- -10^4 <= nums[i] <= 10^4

- 2 <= k <= 10^4

---

## Examples

Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]

Input: nums = [5], k = 9
Output: 0

---

## Constraints

_Not available._

---

## My Solution

```plaintext
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
            int n = nums.size();
            unordered_map<int,int> mp;
            long long presum = 0;
            int count = 0;
              mp[0] = 1;
            for(int i=0;i<n;i++){
                presum+=nums[i];
                int rem = ((presum % k) + k) % k;
                if(mp.find(rem)!=mp.end()){
                    count += mp[rem];
                }
                mp[rem]++;
            }
            return count;
    }

    
};
```
