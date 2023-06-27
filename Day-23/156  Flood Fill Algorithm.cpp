void solve(vector<vector<int>> &image, int x, int y, int newColor, int pre, int n, int m){

    int row[] = {1,-1, 0, 0};
    int col[] = {0, 0, -1, 1};

    for(int i=0; i<4; i++){
        int r = row[i] + x;
        int c = col[i] + y;

        if(r>=0 && r<n && c>=0 && c<m && image[r][c]==pre){
            image[r][c] = newColor;
            solve(image, r, c, newColor, pre, n, m);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    // Write your code here.
    int pre = image[x][y], n = image.size(), m = image[0].size();

    if(pre==newColor) return image;

    image[x][y] = newColor;

    solve(image, x, y, newColor, pre, n, m);

    return image;
}
