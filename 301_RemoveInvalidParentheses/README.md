# Remove Invalid Parentheses

**Difficulty:** Hard
**Language:** plaintext
**Runtime:** N/A
**Memory:** N/A
**Submission Date:** Oct 7, 2026, 2:35 PM
**Problem URL:** [https://leetcode.com/problems/remove-invalid-parentheses/](https://leetcode.com/problems/remove-invalid-parentheses/)

---

## Problem Statement

Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.

Return a list of unique strings that are valid with the minimum number of removals. You may return the answer in any order.

Example 1:

Input: s = "()())()"
Output: ["(())()","()()()"]

Example 2:

Input: s = "(a)())()"
Output: ["(a())()","(a)()()"]

Example 3:

Input: s = ")("
Output: [""]

Constraints:

- 1 <= s.length <= 25

- s consists of lowercase English letters and parentheses '(' and ')'.

- There will be at most 20 parentheses in s.

---

## Examples

Input: s = "()())()"
Output: ["(())()","()()()"]

Input: s = "(a)())()"
Output: ["(a())()","(a)()()"]

Input: s = ")("
Output: [""]

---

## Constraints

_Not available._

---

## My Solution

```plaintext
class Solution {
public:

    void check(int idx, int open, int closed,
               int rem, int k, string &s2,
               unordered_set<string>& ans, string &s) {

        if(rem > k) return;

        if(idx == s.length()) {

            if(rem == k && open == closed) {
                ans.insert(s2);
            }

            return;
        }

     
        if(s[idx] == '(') {

            s2.push_back('(');

            check(idx + 1, open + 1, closed,
                  rem, k, s2, ans, s);

            s2.pop_back();
        }

        else if(s[idx] == ')') {

            if(open > closed) {

                s2.push_back(')');

                check(idx + 1, open, closed + 1,
                      rem, k, s2, ans, s);

                s2.pop_back();
            }
        }

        else {

            s2.push_back(s[idx]);

            check(idx + 1, open, closed,
                  rem, k, s2, ans, s);

            s2.pop_back();
        }


        if(rem < k) {

            check(idx + 1, open, closed,
                  rem + 1, k, s2, ans, s);
        }
    }


    vector<string> removeInvalidParentheses(string s) {

        int n = s.length();

        int invalid = 0;
        stack<int> st;

        for(int i = 0; i < n; i++) {

            if(s[i] == '(') {
                st.push(i);
            }

            else if(s[i] == ')') {

                if(!st.empty())
                    st.pop();
                else
                    invalid++;
            }
        }

        invalid += st.size();

        unordered_set<string> ans;

        string s2 = "";

        check(0, 0, 0, 0, invalid,
              s2, ans, s);

        return vector<string>(ans.begin(), ans.end());
    }
};
```
