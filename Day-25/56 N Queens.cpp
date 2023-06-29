
void update(int n, vector<vector<int>> &ans, vector<vector<int>> &arr){
    vector<int> v;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            v.push_back(arr[i][j]);          
        }
    }
    ans.push_back(v);
}


void solve(int n, vector<vector<int>> &ans, vector<vector<int>> &arr, vector<int> &row, vector<int> &down, vector<int> &up, int st, int mn){
    //st -> row
    // mn ->col

    if(mn + 1 == n){
        update(n, ans, arr);
        return;
    }

    row[st] = 1;

    down[st + mn] = 1;

    up[n + mn - st] = 1;

    for(int i=0; i<n; i++){
        if(row[i] || down[i + mn +1] || up[n + mn -i +1]) continue;
        else{
            arr[i][mn+1] = 1;
            solve(n, ans, arr, row, down, up, i, mn + 1);
            arr[i][mn+1] = 0;
        }
    }


    row[st] = 0;

    down[st + mn] = 0;

    up[n + mn - st] = 0;


}

vector<vector<int>> solveNQueens(int n) {
    // Write your code here.  56
    if(n==1) return {{1}};
    else if(n<4) return {{}};

    vector<vector<int>> arr(n, vector<int>(n, 0));

    vector<vector<int>> ans;

    vector<int> rowFill(n, 0);
    vector<int> downDig(2*n, 0);  // r + c
    vector<int> upDig(2*n, 0);   // n + ;

    for(int i=0; i<n; i++){
        arr[i][0] = 1;
        solve(n, ans, arr, rowFill, downDig, upDig, i, 0);

        arr[i][0] = 0;
    }

    return ans;

    
}
