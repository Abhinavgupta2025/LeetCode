# Maximum Profit in Job Scheduling

**Difficulty:** Hard
**Language:** plaintext
**Runtime:** N/A
**Memory:** N/A
**Submission Date:** Sep 30, 2026, 5:22 PM
**Problem URL:** [https://leetcode.com/problems/maximum-profit-in-job-scheduling/](https://leetcode.com/problems/maximum-profit-in-job-scheduling/)

---

## Problem Statement

We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.

If you choose a job that ends at time X you will be able to start another job that starts at time X.

Example 1:

Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
Output: 120
Explanation: The subset chosen is the first and fourth job.
Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.

Example 2:

Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
Output: 150
Explanation: The subset chosen is the first, fourth and fifth job.
Profit obtained 150 = 20 + 70 + 60.

Example 3:

Input: startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
Output: 6

Constraints:

- 1 <= startTime.length == endTime.length == profit.length <= 5 * 10^4

- 1 <= startTime[i] < endTime[i] <= 10^9

- 1 <= profit[i] <= 10^4

---

## Examples

Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
Output: 120
Explanation: The subset chosen is the first and fourth job.
Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.

Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
Output: 150
Explanation: The subset chosen is the first, fourth and fifth job.
Profit obtained 150 = 20 + 70 + 60.

Input: startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
Output: 6

---

## Constraints

_Not available._

---

## My Solution

```plaintext
class Solution {
public:
    int check2(int idx,vector<pair<int,pair<int,int>>>& v){
        int low = idx;
        int high = v.size()-1;
        int ans = v.size();
        while(low<=high){
            int mid = low + (high-low)/2;
            if(v[mid].first>=idx){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
            
        }
        return ans;
    }
    int check(int idx,vector<int>& dp,vector<pair<int,pair<int,int>>>& v){
        if(idx>=v.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int next = check2(v[idx].second.first,v);
        int take = v[idx].second.second + check(next,dp,v);
        int nottake = check(idx+1,dp,v);
        return dp[idx] = max(take,nottake);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
            int n = startTime.size();
            vector<pair<int,pair<int,int>>> v;
            vector<int> dp(n,-1);
            for(int i=0;i<n;i++){
                v.push_back({startTime[i],{endTime[i],profit[i]}});
            }
            sort(v.begin(),v.end());
            return check(0,dp,v);
    }
};
```
