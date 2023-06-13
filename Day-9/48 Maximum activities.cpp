#include <bits/stdc++.h> 


static bool comp(pair<int, int> p1, pair<int, int> p2){
    if(p1.second<p2.second) return true;
    else if(p1.second>p2.second) return false;
    else{
        return p1.first>p2.first;
    }
}

int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
    vector<pair<int, int>> arr;
    int n = start.size();

    for(int i=0; i<n; i++){
        arr.push_back({start[i], finish[i]});
    }

    sort(arr.begin(), arr.end(), comp);

    int ans = 1, pre = arr[0].second, count =1;

    while(count<n){
        int st = arr[count].first;
        int en = arr[count].second;
        count++;

        if(st>=pre){
            ans++;
            pre = en;
        }
    }

    return ans;
}
