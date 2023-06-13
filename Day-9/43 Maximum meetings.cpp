#include <bits/stdc++.h> 
#define pi pair<pair<int, int>, int>

static bool comp(pi p1, pi p2){
    if(p1.first.first<p2.first.first) return true;
    else if(p1.first.first>p2.first.first) return false;
    else{
        return p1.second< p2.second;
    }
}
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    // Write your code here.
    int n = start.size();
    vector<pi> meet;

    for(int i=0; i<n; i++){
        meet.push_back({{end[i], start[i]}, i+1});
    }

    sort(meet.begin(), meet.end(), comp);
    vector<int> ans;

    ans.push_back(meet[0].second);
    int pre = meet[0].first.first;

    for(int i=1; i<n; i++){
        int en = meet[i].first.first;
        int st = meet[i].first.second;
        int pos = meet[i].second;

        if(st> pre){
            ans.push_back(pos);
            pre = en;
        }
    }

    return ans;



}
