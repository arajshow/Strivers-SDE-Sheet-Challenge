#include <bits/stdc++.h> 


class disjointSet{

	public:
	vector<int> size,parent;

	disjointSet(int n){
		size.resize(n+1, 1);
		parent.resize(n+1, 0);

		for(int i=1; i<=n; i++){
			parent[i] = i;
		}
	}

	int findPar(int node){
		if(node==parent[node]) return node;

		return parent[node]=findPar(parent[node]);
	}

	void unionBySize(int u, int v){
		int pu = findPar(u);
		int pv = findPar(v);
		if(pu==pv) return;

		if(size[pu]<size[pv]){
			parent[pu] = pv;
			size[pv]+=size[pu];
		}else{
			parent[pv] = pu;
			size[pu]+=size[pv];			
		}
	}
};

static bool comp(vector<int> g1, vector<int> g2){
	if(g1[2]<g2[2]) return true;
	return false;
}

int kruskalMST(int n, int m, vector<vector<int>> &graph) {
	// Write your code here. 170
	int edge = n-1, total=0, ans=0;


	sort(graph.begin(), graph.end(), comp);
	disjointSet *input = new disjointSet(n);

	for(auto it: graph){
		if(total==edge) break;

		int u = it[0];
		int v = it[1];
		int wt = it[2];

		if(input->findPar(u)!=input->findPar(v)){
			ans+=wt;
			total++;
			input->unionBySize(u, v);
		}


	}

	return ans;
}
