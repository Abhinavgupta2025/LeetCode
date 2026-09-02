# Minimum Operations to Form Subset Sum II

**Difficulty:** Hard
**Language:** plaintext
**Runtime:** N/A
**Memory:** N/A
**Submission Date:** Sep 2, 2026, 5:59 PM
**Problem URL:** [https://leetcode.com/problems/minimum-operations-to-form-subset-sum-ii/](https://leetcode.com/problems/minimum-operations-to-form-subset-sum-ii/)

---

## Problem Statement

You are given an integer array nums and an integer sum.

In one operation, choose an element with current value x and replace it with either 2 * x or floor(x / 2).

For each element, multiplication and division operations may be performed in any order.

Return the minimum number of operations needed so that some subset of the resulting array has a sum exactly equal to sum. If it is impossible, return -1.

The floor() function returns the integer part of the division.

Example 1:

Input: nums = [10,2], sum = 13

Output: 3

Explanation:

- Divide nums[0] = 10 once: 10 → 5, costing 1 operation.

- Multiply nums[1] = 2 twice: 2 → 4 → 8, costing 2 operations.

- After these operations, nums = [5, 8]. The subset {5, 8} sums to 13 using 3 operations in total.

Example 2:

Input: nums = [6,3], sum = 8

Output: 2

Explanation:​​​​​​​

- Turn nums[1] = 3 into 2 using 2 operations:

- Divide nums[1] to get 1.

- Multiply nums[1] = 1 to get 2.

- After these operations, nums = [6, 2]. The subset {6, 2} sums to 8 using 2 operations in total.

Example 3:

Input: nums = [2,2], sum = 7

Output: -1

Explanation:

- No sequence of operations lets a subset of nums sum to 7, so the answer is -1.

Constraints:

- 1 <= nums.length <= 100

- 1 <= nums[i] <= 500

- 1 <= sum <= 5000

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
    int solve(int idx, int sum, vector<int>& nums,
              vector<vector<int>>& dp,
              vector<map<int,int>>& options) {

        if (sum == 0)
            return 0;

        if (sum < 0 || idx == nums.size())
            return INT_MAX;

        if (dp[idx][sum] != -1)
            return dp[idx][sum];

        int ans = INT_MAX;


        ans = min(ans,
                  solve(idx + 1, sum, nums, dp, options));

  
        for (auto [val, cost] : options[idx]) {

            if (val > sum)
                continue;

            int c = solve(idx + 1,
                          sum - val,
                          nums,
                          dp,
                          options);

            if (c != INT_MAX) {
                ans = min(ans, cost + c);
            }
        }

        return dp[idx][sum] = ans;
    }

    int minOperations(vector<int>& nums, int sum) {

        int n = nums.size();

        // IMPORTANT: size must be n
        vector<map<int,int>> v(n);

        vector<vector<int>> dp(
            n,
            vector<int>(sum + 1, -1)
        );

        for (int i = 0; i < n; i++) {

            int ele = nums[i];
            int op = 0;

            while (ele > 0) {

                int curr = ele;
                int mul = 0;

                while (curr <= sum) {

                    int cost = op + mul;

                    if (!v[i].count(curr) ||
                        v[i][curr] > cost) {

                        v[i][curr] = cost;
                    }

                    if (curr > sum / 2)
                        break;

                    curr *= 2;
                    mul++;
                }

                op++;
                ele /= 2;
            }
        }

        int ans = solve(0, sum, nums, dp, v);

        return ans == INT_MAX ? -1 : ans;
    }
};
```
