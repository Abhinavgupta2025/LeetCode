# Maximum Valid Split Positions I

**Difficulty:** Medium
**Language:** plaintext
**Runtime:** N/A
**Memory:** N/A
**Submission Date:** Sep 1, 2026, 10:14 PM
**Problem URL:** [https://leetcode.com/problems/maximum-valid-split-positions-i/](https://leetcode.com/problems/maximum-valid-split-positions-i/)

---

## Problem Statement

You are given an integer array nums.

You may remove at most one element from nums. Let arr be the array of remaining elements in their original order, and let m be its length.

A split position i of arr is valid if:

- 0 <= i < m - 1, and

- gcd(arr[0..i]) == gcd(arr[i + 1..m - 1]).

An array of length 1 has no valid split positions.

The score of arr is the number of valid split positions in it.

Return the maximum possible score of arr.

Here, gcd(a) denotes the greatest common divisor of all elements in the array a.

Example 1:

Input: nums = [10,30,15,10]

Output: 2

Explanation:

One optimal solution is to remove nums[2] = 15. Then arr = [10, 30, 10].

The split positions are:

Split Position i
gcd(arr[0..i])
gcd(arr[i + 1..m - 1])

0
10
10

1
10
10

All split positions are valid. Thus, the answer is 2.

Example 2:

Input: nums = [2,10,14]

Output: 1

Explanation:

One optimal solution is to not remove any element. Then arr = [2, 10, 14].

The split positions are:

Split Position i
gcd(arr[0..i])
gcd(arr[i + 1..m - 1])

0
2
2

1
2
14

Only the split position at index 0 is valid. Thus, the answer is 1.

Example 3:

Input: nums = [2,4]

Output: 0

Explanation:

The only remaining array that has a split position is arr = [2, 4].

The split positions are:

Split Position i
gcd(arr[0..i])
gcd(arr[i + 1..m - 1])

0
2
4

There are no valid split positions. Thus, the answer is 0.

Constraints:

- 2 <= nums.length <= 1000

- 1 <= nums[i] <= 10^9​​​​​​​

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
    

    int remove(vector<int>& nums){
        int n = nums.size();

        vector<int> pref(n), suff(n);

        pref[0] = nums[0];
        for (int i = 1; i < n; i++)
            pref[i] = gcd(pref[i - 1], nums[i]);

        suff[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
            suff[i] = gcd(nums[i], suff[i + 1]);

        int ans = 0;

        // No removal
        for (int i = 0; i < n - 1; i++) {
            if (pref[i] == suff[i + 1])
                ans++;
        }

        return ans;
    }
    int maxValidSplits(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;
        ans = max(ans,remove(nums));
        for(int i=0;i<n;i++){
            vector<int> temp = nums;
            temp.erase(temp.begin()+i);
            ans = max(ans,remove(temp));
        }
        
        return ans;
    }
};
```
