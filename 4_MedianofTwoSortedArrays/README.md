# Median of Two Sorted Arrays

**Difficulty:** Hard
**Language:** plaintext
**Runtime:** N/A
**Memory:** N/A
**Submission Date:** Jul 8, 2026, 11:14 PM
**Problem URL:** [https://leetcode.com/problems/median-of-two-sorted-arrays/](https://leetcode.com/problems/median-of-two-sorted-arrays/)

---

## Problem Statement

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

Constraints:

- nums1.length == m

- nums2.length == n

- 0 <= m <= 1000

- 0 <= n <= 1000

- 1 <= m + n <= 2000

- -10^6 <= nums1[i], nums2[i] <= 10^6

---

## Examples

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

---

## Constraints

_Not available._

---

## My Solution

```plaintext
            int b = n2.size();
            if(a>b) return findMedianSortedArrays(n2,n1);
            int n = a + b;
            int low = 0;
            int high = a;
            int left = (a + b + 1)/2;
            while(low<=high){
                int mid1 = (low + high) >> 1;
                int mid2 = left - mid1;
                int l1 = INT_MIN,l2 = INT_MIN;
                int r1 = INT_MAX,r2 = INT_MAX;
                if(mid1 < a) r1 = n1[mid1];
                if(mid2 < b) r2 = n2[mid2];
                if(mid1-1>=0) l1 = n1[mid1-1];
                if(mid2-1>=0) l2 = n2[mid2-1];
                if(l1<=r2 && l2<=r1){
                    if(n%2==0){
                        return ((double)(max(l1,l2) + min(r1,r2)))/2.0;
                    }
                    else return max(l1,l2);
                }
                else if(l1>r2) high = mid1-1;
                else low = mid1 + 1;


            }

```
