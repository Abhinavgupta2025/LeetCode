# Sliding Window Maximum

**Difficulty:** Hard
**Language:** cpp
**Runtime:** 2341 (beats 5.06%)
**Memory:** 142852000 (beats 20.05%)
**Submission Date:** Jul 11, 2026, 6:49 PM
**Problem URL:** [https://leetcode.com/problems/sliding-window-maximum/](https://leetcode.com/problems/sliding-window-maximum/)

---

## Problem Statement

You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation:
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
1 [3  -1  -3] 5  3  6  7       3
1  3 [-1  -3  5] 3  6  7       5
1  3  -1 [-3  5  3] 6  7       5
1  3  -1  -3 [5  3  6] 7       6
1  3  -1  -3  5 [3  6  7]      7

Example 2:

Input: nums = [1], k = 1
Output: [1]

Constraints:

- 1 <= nums.length <= 10^5

- -10^4 <= nums[i] <= 10^4

- 1 <= k <= nums.length

---

## Examples

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation:
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
1 [3  -1  -3] 5  3  6  7       3
1  3 [-1  -3  5] 3  6  7       5
1  3  -1 [-3  5  3] 6  7       5
1  3  -1  -3 [5  3  6] 7       6
1  3  -1  -3  5 [3  6  7]      7

Input: nums = [1], k = 1
Output: [1]

---

## Constraints

_Not available._

---

## My Solution

```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            int n = nums.size();
            vector<int> nge(n,n);
            stack<int> st;
            st.push(n-1);
            for(int i=n-2;i>=0;i--){
                while(st.size()>0 && nums[st.top()]<nums[i]) st.pop();
                if(st.size()!=0) nge[i] = st.top();
                st.push(i);
            }
            vector<int> ans;
            for(int i=0;i<=n-k;i++){
                int mx = 0;
                int idx = i;
                while(idx<i+k){
                    mx = idx;
                    idx = nge[idx];
                }
                ans.push_back(nums[mx]);
            }
            return ans;

    }
};
```
