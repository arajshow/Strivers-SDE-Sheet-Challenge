
void solve(int st, int sm, int n, int k, vector<int> arr, vector<vector<int>> &ans, vector<int> &v){

    if(sm==k){
        ans.push_back(v);
    }
    for(int i=st; i<n; i++){

        v.push_back(arr[i]);
        solve(i+1, sm + arr[i], n, k, arr, ans, v);

        v.pop_back();

    }
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    vector<vector<int>> ans;

    int sm = 0, st = 0;
    vector<int> temp;

    solve(st, sm, n, k, arr, ans, temp);

    return ans;
}
