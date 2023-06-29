#include <bits/stdc++.h> 

void update(vector<vector<int>> &ans, vector<vector<int>> &path, int n){
  vector<int> v;

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      v.push_back(path[i][j]);
    }
  }

  ans.push_back(v);
}

// 1 0 1
// 1 1 1
// 1 1 1

void solve(int row, int col, int n, vector<vector<int>> &maze, vector<vector<int>> &ans, vector<vector<int>> &path){

  if(row==n-1 && col==n-1){
    update(ans, path, n);
    return;
  }
  int x[] = {1, -1, 0, 0};
  int y[] = {0, 0, 1, -1};

  for(int i=0; i<4; i++){
    int r = row + x[i];
    int c = col + y[i];

    if(r>=0 && r<n && c>=0 && c<=n && maze[r][c]==1){
      path[r][c] = 1;
      maze[r][c] = 0;
      solve(r, c, n, maze, ans, path);
      path[r][c] = 0;
      maze[r][c] = 1;
    }
  }
}

vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  // Write your code here.59

  if(maze[0][0]==0 || maze[n-1][n-1]==0) return {};

  int r =0, c = 0;

  vector<vector<int>> ans;
  vector<vector<int>> path(n, vector<int>(n, 0));
  path[0][0] =1;
  maze[0][0] = 0;

  solve(r, c, n, maze, ans, path);

  return ans;
}
