#include <bits/stdc++.h> 
vector<int> findSpans(vector<int> &price) {
    // Write your code here.
    stack<pair<int, int>> s;  //element, span
    int n = price.size();

    vector<int> ans;
    for(int i=0; i<n; i++){
        if(i==0){
            s.push({price[i], 1});
            ans.push_back(1);
            continue;
        }

        if(s.top().first>price[i]){
            s.push({price[i], 1});
            ans.push_back(1);
            continue;
        }else if(s.top().first==price[i]){
            int span = s.top().second + 1;
            ans.push_back(span);
            s.pop();
            s.push({price[i], span});
        }else{
            int span = 0;
            while(!s.empty() && s.top().first<price[i]){
                span+= s.top().second;
                s.pop();
            }

            if(s.empty()){
                s.push({price[i], span + 1});
                ans.push_back(span + 1);
            }else if(s.top().first==price[i]){
                span+= s.top().second;
                ans.push_back(span + 1);
                s.pop();
                s.push({price[i], span+ 1});               
            }else{
                s.push({price[i], span + 1});
                ans.push_back(span + 1);
            }
        }
    }

    return ans;
}
