#include <bits/stdc++.h>

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{

    int pre = mat[0][0], r1=0, c1=0, r2=n-1, c2=m-1;


    while(r1<r2 && c1<c2){
        pre = mat[r1][c1];
        // row1 
        for(int j=1+c1; j<=c2; j++){
            int temp = mat[r1][j];
            mat[r1][j] = pre;
            pre = temp;
        }
        r1++;


        // col2
        for(int i=r1; i<=r2; i++){
            int temp = mat[i][c2];
            mat[i][c2] = pre;
            pre = temp;
        }
        c2--;


        //row2 -rev
        for(int j=c2; j>=c1; j--){
            int temp = mat[r2][j];
            mat[r2][j] = pre;
            pre = temp;
        }
        r2--;


        //col1 -rev
        for(int i=r2; i>=r1-1; i--){
            int temp = mat[i][c1];
            mat[i][c1] = pre;
            pre = temp;
        }
        c1++;
    }


}
