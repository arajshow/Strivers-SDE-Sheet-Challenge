bool valid(int matrix[9][9], int r,int c, int k){
    for(int i=0; i<9; i++){
        if(matrix[r][i]==k) return false;
    }

    for(int i=0; i<9; i++){
        if(matrix[i][c]==k) return false;
    }
    int row = (r/3)*3;
    int col = (c/3)*3;
    for(int i=row; i<row+3; i++){
        for(int j=col; j<col+3; j++){
            if(matrix[row][col]==k) return false;
        }
    }

    return true;
}

bool solve(int matrix[9][9], int st){

    for(int i=st; i<9; i++){
        for(int j=0; j<9; j++){
            if(matrix[i][j]==0){
                for(int k=1; k<10; k++){
                    if(valid(matrix, i, j, k)){
                        matrix[i][j] = k;
                        if(solve(matrix, i)) return true;
                        matrix[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }

    return true;
}

bool isItSudoku(int matrix[9][9]) {
    // Write your code here. 57

    return solve(matrix, 0);
}
