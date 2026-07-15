# Largest Rectangle in Histogram

**Difficulty:** Hard
**Language:** cpp
**Runtime:** 11 (beats 94.48%)
**Memory:** 81288000 (beats 79.84%)
**Submission Date:** Jul 15, 2026, 12:30 PM
**Problem URL:** [https://leetcode.com/problems/largest-rectangle-in-histogram/](https://leetcode.com/problems/largest-rectangle-in-histogram/)

---

## Problem Statement

Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

Example 1:

Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.

Example 2:

Input: heights = [2,4]
Output: 4

Constraints:

- 1 <= heights.length <= 10^5

- 0 <= heights[i] <= 10^4

---

## Examples

Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.

Input: heights = [2,4]
Output: 4

---

## Constraints

_Not available._

---

## My Solution

```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
            int n = heights.size();
            stack<int> st;
            int ans = 0;
            for(int i=0;i<n;i++){
                while(st.size()>0 && heights[st.top()]>heights[i]){
                    int x = heights[st.top()];
                    st.pop();
                    int pse = st.size()>0?st.top():-1;
                    int nse = i;
                    ans = max(ans,(nse-pse-1)*x);
                }
                st.push(i);
            }
            while(st.size()>0){
                   int x = heights[st.top()];
                    st.pop();
                    int pse = st.size()>0?st.top():-1;
                    int nse = n;
                    ans = max(ans,(nse-pse-1)*x);
            }
            return ans;
    }
};
```
