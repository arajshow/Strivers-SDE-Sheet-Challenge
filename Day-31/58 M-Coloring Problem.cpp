
bool safe(int node, vector<int> &color, vector<vector<int>> &mat){

    int n = mat.size();

    for(int i=0; i<n; i++){
        if(mat[node][i]==1 && color[i]==color[node]) return false;
    }

    return true;
}


bool solve(int node, vector<int> &color, vector<vector<int>> &mat, int m){
    if(node==mat.size()) return true;
    for(int i=1; i<=m; i++){
        color[node] = i;
        if(safe(node, color, mat)){
            if(solve(node+1, color, mat, m)) return true;
        }
        color[node] = 0;
    }

    return false;
}


string graphColoring(vector<vector<int>> &mat, int m) {
    // Write your code here

    int n = mat.size();
    vector<int> color(n, 0);

    if(solve(0, color, mat, m)) return "YES";
    return "NO";
}
