#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &matrix)
{
	// Write your code here.
	int n = matrix.size(), m = matrix[0].size();
	unordered_map<int, bool> row;
	unordered_map<int, bool> col;

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(matrix[i][j]==0){
				row[i] = true;
				col[j] = true;
			}
		}
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(row.count(i)>0){
				matrix[i][j] = 0;
			}else if(col.count(j)>0){
				matrix[i][j] = 0;
			}
		}
	}
}
