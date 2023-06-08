bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size(), m = mat[0].size();

        int total = n*m, st = 1, en = total;

        //mat[i][j] => i*m + j

        while(st<en){
            int md = st + (en - st)/2;

            int a = md/m;
            int b = md%m;

            if(mat[a][b]==target) return true;
            else if(mat[a][b]<target){
                st = md+1;
            }else{
                en = md - 1;
            }
        }

        return false;

}
