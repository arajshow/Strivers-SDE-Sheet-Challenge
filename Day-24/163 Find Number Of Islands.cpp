
void solve(int row, int col, int** arr, int n, int m){
   arr[row][col] = 0;
   int x[] = {1,1, -1, -1, 1,-1, 0, 0};
   int y[] = {1,-1, -1, 1, 0, 0, 1, -1};

   for(int i=0; i<8; i++){
      int r = x[i] + row;
      int c = y[i] + col;

      if(r>=0 && r<n && c>=0 && c<m && arr[r][c]==1){
         solve(r,c, arr, n, m);
      }
   }
}

int getTotalIslands(int** arr, int n, int m)
{
   // Write your code here. 163


   int ans = 0;

   for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
         if(arr[i][j]==1){
            solve(i, j, arr, n, m);
            ans++;
         }
      }
   }

   return ans;
}
