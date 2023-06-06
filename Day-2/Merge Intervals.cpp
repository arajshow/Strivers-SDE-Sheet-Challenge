#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Write your code here.
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> ans;

    int st = intervals[0][0], en = intervals[0][1], n = intervals.size();

    for(int i=1; i<n; i++){
        int u = intervals[i][0], v = intervals[i][1];

        if(u<=en){
            en = max(en, v);
        }else{
            ans.push_back({st, en});
            st = u;
            en = v;
        }
    }

    ans.push_back({st, en});

    return ans;
}
