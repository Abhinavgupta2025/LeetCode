# Number of Sub-arrays With Odd Sum

**Difficulty:** Medium
**Language:** plaintext
**Runtime:** N/A
**Memory:** N/A
**Submission Date:** Aug 20, 2026, 11:52 PM
**Problem URL:** [https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/](https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/)

---

## Problem Statement

Given an array of integers arr, return the number of subarrays with an odd sum.

Since the answer can be very large, return it modulo 10^9 + 7.

Example 1:

Input: arr = [1,3,5]
Output: 4
Explanation: All subarrays are [[1],[1,3],[1,3,5],[3],[3,5],[5]]
All sub-arrays sum are [1,4,9,3,8,5].
Odd sums are [1,9,3,5] so the answer is 4.

Example 2:

Input: arr = [2,4,6]
Output: 0
Explanation: All subarrays are [[2],[2,4],[2,4,6],[4],[4,6],[6]]
All sub-arrays sum are [2,6,12,4,10,6].
All sub-arrays have even sum and the answer is 0.

Example 3:

Input: arr = [1,2,3,4,5,6,7]
Output: 16

Constraints:

- 1 <= arr.length <= 10^5

- 1 <= arr[i] <= 100

---

## Examples

Input: arr = [1,3,5]
Output: 4
Explanation: All subarrays are [[1],[1,3],[1,3,5],[3],[3,5],[5]]
All sub-arrays sum are [1,4,9,3,8,5].
Odd sums are [1,9,3,5] so the answer is 4.

Input: arr = [2,4,6]
Output: 0
Explanation: All subarrays are [[2],[2,4],[2,4,6],[4],[4,6],[6]]
All sub-arrays sum are [2,6,12,4,10,6].
All sub-arrays have even sum and the answer is 0.

Input: arr = [1,2,3,4,5,6,7]
Output: 16

---

## Constraints

_Not available._

---

## My Solution

```plaintext
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long sum = 0;
        long long even = 1;
        long long odd = 0;
        long long ans = 0;

        for (int x : arr) {
            sum += x;

            if (sum % 2 == 0) {
                ans += odd;
                even++;
            } else {
                ans += even;
                odd++;
            }
        }

        return ans % 1000000007;
    }
};
//even+odd = odd
```
