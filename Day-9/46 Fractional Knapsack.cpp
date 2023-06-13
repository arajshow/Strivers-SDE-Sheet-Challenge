#include <bits/stdc++.h> 

# define pi pair<double, pair<int, int>>

static bool comp(pi p1, pi p2){
    if(p1.first>=p2.first) return true;
    else if(p1.first<p2.first) return false;
}
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    // sort(items.begin(), items.end(), comp);
    vector<pi> item;

    for(auto it : items){
        int wt = it.first;
        int vlue = it.second;
        double res = (vlue*1.0)/wt;
        item.push_back({res, it});
    }

    sort(item.begin(), item.end(), comp);

    double ans = 0;

    for(auto it : item){
        int wt = it.second.first;
        int vlue = it.second.second; 
        // cout<<wt<<" "<<vlue<<endl;

        if(w>=wt){
            ans+=vlue;
            w-=wt;
        }else{
            if(w==0) break;
            double rem = (w*1.0)/wt;
            rem*=vlue;
            ans+=rem;
            break;
        }  
    }

    return ans;
}
