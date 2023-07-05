
bool safe(int node, int n, vector<vector<int>> edges, vector<int> &color){

	for(int i=0; i<n; i++){
		if((edges[i][node]==1 || edges[node][i]==1) && color[i]==color[node]) return false;
	}

	return true;
}

bool solve(int node, int n, vector<vector<int>> edges, vector<int> &color){

	if(node==n) return true;

	for(int i=1; i<3; i++){
		color[node] = i;
		if(safe(node, n, edges, color)){
			if(solve(node+1, n, edges, color)) return true;
		}
		color[node] = 0;
	}
	return false;
}

bool isGraphBirpatite(vector<vector<int>> &edges) {
	// Write your code here. 164

	// if cycle with odd nodes then not bypertite
	int n = edges.size();
	vector<int> color(n, 0);

	if(solve(0, n, edges, color)) return true;
	return false;
}
