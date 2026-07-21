# Transform Binary String Using Subsequence Sort

**Difficulty:** Medium
**Language:** plaintext
**Runtime:** N/A
**Memory:** N/A
**Submission Date:** Jul 21, 2026, 9:36 PM
**Problem URL:** [https://leetcode.com/problems/transform-binary-string-using-subsequence-sort/](https://leetcode.com/problems/transform-binary-string-using-subsequence-sort/)

---

## Problem Statement

You are given a binary string s.

You are also given an array of strings strs, where each strs[i] has the same length as s and consists of characters '0', '1', and '?'. Each '?' can be replaced by either '0' or '1'.

You may perform the following operation any number of times (including zero):

- Choose any subsequence sub of s.

- Sort sub in non-decreasing order.

- Replace the chosen subsequence in s with the sorted sub, keeping all other characters unchanged.

Return a boolean array ans, where ans[i] is true if it's possible to replace all '?' in strs[i] with '0' or '1' and transform s into the resulting string using the allowed operation above, otherwise return false.

Example 1:

Input: s = "101", strs = ["1?1","0?1","0?0"]

Output: [true,true,false]

Explanation:

i
strs[i]
Replacement
Result strs[i]
Operation(s)
Result

0
"1?1"
? → 0
"101"
Matches s.
true

1
"0?1"
? → 1
"011"
Select the subsequence at indices [0..2] of s → "101".

Sort "101" to get "011" = strs[i].
true

2
"0?0"
? → 0 or 1
"000" or "010"
Not feasible.
false

Thus, ans = [true, true, false].

Example 2:

Input: s = "1100", strs = ["0011","11?1","1?1?"]

Output: [true,false,true]

Explanation:

i
strs[i]
Replacement
Result strs[i]
Operation(s)
Result

0
"0011"
-
"0011"
Select the subsequence at indices [0..3] of s → "1100".

Sort "1100" to get "0011" = strs[i].
true

1
"11?1"
? → 0
"1101"
Not feasible.
false

2
"1?1?"
First ? → 0

Second ? → 0
"1010"
Select the subsequence at indices [1, 2] of s → "10".

Sort "10" to get "01", so s = "1010".
true

Thus, ans = [true, false, true].

Example 3:

Input: s = "1010", strs = ["0011"]

Output: [true]

Explanation:

i
strs[i]
Replacement
Result strs[i]
Operation(s)
Result

0
"0011"
-
"0011"
Select the subsequence at indices [0, 2, 3] of s → "110".

Sort "110" to get "011", so s = "0011" = strs[i].
true

Thus, ans = [true].

Constraints:

- 1 <= n == s.length <= 2000

- s[i] is either '0' or '1'.

- 1 <= strs.length <= 2000

- strs[i].length == n

- strs[i] is either '0', '1', or '?'​​​​​​​.

---

## Examples

_Not available._

---

## Constraints

_Not available._

---

## My Solution

```plaintext
                }
                    else it[i] = '1';
                    }
                        need--;
                        it[i] = '0';
                    if(need) {
            for(int i=0;i<n;i++){
                if(it[i]=='?'){
            }
            int need = zeroes-zeroes2;
                continue;
            if(zeroes2>zeroes || zeroes2+quesMark<zeroes){
                ans.push_back(false);
            int zeroes2 = count(it.begin(),it.end(),'0');
            int quesMark = count(it.begin(),it.end(),'?');
            }
            vector<int> v;
            for(int i=0;i<n;i++){
                if(it[i]=='0') v.push_back(i);
            }
            bool flag = true;
            cout<<orig.size()<<" "<<v.size()<<endl;
            for(int i=0;i<v.size();i++){
                if(orig[i]<v[i]){
                    flag = false;
                    break;

```
