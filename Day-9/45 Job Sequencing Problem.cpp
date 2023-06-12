#include <bits/stdc++.h> 

static bool comp(vector<int> v1, vector<int> v2){
    if(v1[0]==v2[0]){
        return v1[1]>=v2[1];
    }else return v1[0] <= v2[0];
}

int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here

    int n = jobs.size();
    sort(jobs.begin(), jobs.end(), comp);
    int profit = jobs[0][1], time=2;

    priority_queue<int, vector<int>, greater<int>> q;
    q.push(jobs[0][1]);

    for(int i=1; i<n; i++){
        int t = jobs[i][0], p = jobs[i][1];

        if(t<time){
            if(q.top()<p){
                profit-=q.top();
                q.pop();
                q.push(p);
                profit+=p;
            }
        }else{
            profit+=p;
            q.push(p);
            time++;
        }
    }

    return profit;

}
