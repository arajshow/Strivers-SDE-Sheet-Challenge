int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.

    priority_queue<int, vector<int>, greater<int>> p;
    vector<pair<int, int>> time;

    for(int i=0; i<n; i++){
        time.push_back({at[i], dt[i]});
    }

    sort(time.begin(), time.end());

    int count = 1;
    p.push(time[0].second);

    for(int i=1; i<n; i++){
        if(p.top() < time[i].first){
            p.pop();
            p.push(time[i].second);
        }else{
            count++;
            p.push(time[i].second);
        }
    }

    return count;
}
