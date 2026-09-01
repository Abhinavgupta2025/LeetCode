# Minimum Bishop Moves to Reach Target

**Difficulty:** Medium
**Language:** plaintext
**Runtime:** N/A
**Memory:** N/A
**Submission Date:** Sep 1, 2026, 10:13 PM
**Problem URL:** [https://leetcode.com/problems/minimum-bishop-moves-to-reach-target/](https://leetcode.com/problems/minimum-bishop-moves-to-reach-target/)

---

## Problem Statement

There is an 8 x 8 empty chessboard with 1-indexed rows and columns.

You are given an array source = [sr, sc] representing the starting position of a bishop, and an array target = [tr, tc] representing the target position.

In one move, the bishop travels one or more squares along a single diagonal direction, staying within the board.

Return the minimum number of moves for the bishop to land exactly on target. If it can never reach target, return -1.

Example 1:

Input: source = [8,1], target = [1,8]

Output: 1

Explanation:

​​​​​​​​​​​​​​

A single diagonal move takes the bishop straight from (8, 1) to (1, 8).

Example 2:

Input: source = [4,2], target = [1,3]

Output: 2

Explanation:

The bishop moves from (4, 2) to (3, 1), then from (3, 1) to (1, 3), reaching the target in 2 moves.

Example 3:

Input: source = [1,1], target = [3,4]

Output: -1

Explanation:

No matter how many diagonal moves it makes, the bishop starting at (1, 1) can never land on (3, 4). Thus, the answer is -1.

Constraints:​​​​​​​

- source.length == target.length == 2

- 1 <= sr, sc, tr, tc <= 8

- source != target

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
    int minBishopMoves(vector<int>& source, vector<int>& target) {
           int row1 = source[0];
           int col1 = source[1];
           int row2 = target[0];
           int col2 = target[1];
           int sum1 = row1+col1;
           int sum2 = row2+col2;
           if(sum1%2 != sum2%2) return -1;
           if(sum1 == sum2) return 1;
           int i=1;
           int r1 = row1;
           int c1 = col1;
           while(r1<=8 && c1<=8 ){
                r1  = r1+i;
                c1 = c1+i;
                
                if(r1==row2 && c1 == col2) return 1;
              
           }
           r1 = row1;
           c1 = col1;
           i=1;
           while(r1>=0 && c1>=0 ){
                r1  = r1-i;
                c1 = c1-i;
                if(r1==row2 && c1 == col2) return 1;
                
           }
           return 2;
    }
};
```
