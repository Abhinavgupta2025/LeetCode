# Sum of Decoded Numbers

**Difficulty:** Medium
**Language:** plaintext
**Runtime:** N/A
**Memory:** N/A
**Submission Date:** Aug 31, 2026, 6:36 PM
**Problem URL:** [https://leetcode.com/problems/sum-of-decoded-numbers/](https://leetcode.com/problems/sum-of-decoded-numbers/)

---

## Problem Statement

You are given an integer array nums.

Each nums[i] is an encoded integer representing two positive integers xi and yi. To decode nums[i], define:

- widthi = nums[i] % 10.

- di = floor(nums[i] / 10).

- xi as the integer formed by the first widthi digits of the decimal representation of di.

- yi as the integer formed by all remaining digits of the decimal representation of di.

It is guaranteed that the decimal representation of di contains more than widthi digits. Therefore, both xi and yi contain at least one digit.

The decoded value of nums[i] is xi^yi.

Return the sum of the decoded values of all elements in nums, modulo 10^9 + 7.

The floor() function returns the integer part of the division.

Example 1:

Input: nums = [231]

Output: 8

Explanation:

- For 231, we have width = 1, d = 23, x = 2, and y = 3.

- The decoded value of 231 is 2^3 = 8.

- Since there is only one element in nums, the sum of the decoded values is 8.

Example 2:

Input: nums = [2522,2101]

Output: 1649

Explanation:

- For 2522, we have width = 2, d = 252, x = 25, and y = 2.

- The decoded value of 2522 is 25^2 = 625.

- For 2101, we have width = 1, d = 210, x = 2, and y = 10.

- The decoded value of 2101 is 2^10 = 1024.

- The sum of the decoded values is 625 + 1024 = 1649.

Example 3:

Input: nums = [2301]

Output: 73741817

Explanation:

- For 2301, we have width = 1, d = 230, x = 2, and y = 30.

- The decoded value is 2^30 = 1073741824.

- Therefore, the answer is 1073741824 modulo (10^9 + 7) = 73741817.

Constraints:

- 1 <= nums.length <= 10^5

- 100 < nums[i] < 10^15

- 1 <= widthi <= 9

- 1 <= xi, yi < 10^9

- The digit sequences used to form xi and yi do not have leading zeros.

- It is guaranteed that every element in nums is a valid encoded integer.

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
    const int mod = 1e9+7;
    pair<long long,long long> getBase(long long d,long long width){
          string num = to_string(d);
          string num2 = num.substr(0,width);
          string num3 = num.substr(width);
          long long ans = stoi(num2);
          long long ans2 = stoi(num3);
           return{ans,ans2};
    }
    
    long long pow(long long b,long long p){
         if(p==0) return 1;
         long long half = pow(b,p/2);
         if(p%2==0) return ((half%mod)*half)%mod;
         return (((b*half)%mod)*half)%mod;
    }
    int sumDecoded(vector<long long>& nums) {
            long long n = nums.size();
            long long ans = 0;
            for(int i=0;i<n;i++){
                long long width = nums[i]%10;
                long long d = floor(nums[i]/10);
                auto  b = getBase(d,width);

                long long count = pow(b.first,b.second);
                ans = (ans + (count))%mod;
            }
            return ans;
    }
};
```
