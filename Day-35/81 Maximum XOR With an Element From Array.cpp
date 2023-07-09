#define pi pair<int, int>
#include <bits/stdc++.h>

class Node{

	public:
	Node* bit[2]; 

	void put(int c, Node *node){
		bit[c] = node;
	}

	Node *get(int c){
		return bit[c];
	}
};

class Trie{

	public:
	Node *root;

	Trie(){
		root = new Node();
	}

	void insert(int n){

		Node *node = root;

		for(int i= 31; i>=0; i--){
			int c = (n>>i) & 1;

			if(node->bit[c]==NULL){
				node->put(c, new Node());
			}

			node = node->get(c);
		}
	}

	int maxInArray(int n){

		Node *node = root;
		int ans = 0;
		for(int i=31; i>=0; i--){
			int c = (n>>i) & 1;
			c = 1 - c;
			if(node->bit[c]!=NULL){
				ans = (ans | (1<<i));
			}else if(node->bit[1 - c]!=NULL){
				c = 1 - c;
			}else return -1;
			node = node->get(c);
		}

		return ans;
	}
};

static bool comp(vector<int> p1, vector<int> p2){
	if(p1[1]<p2[1]) return true;
	return false;
}

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	//	Write your coode here.

	int q = queries.size(), n = arr.size(), arr_i=0;

	vector<int> ans(q, 0);
	for(int i=0; i<q; i++){
		queries[i].push_back(i);
		// cout<<i<<endl;
	}

	sort(queries.begin(), queries.end(), comp);
	sort(arr.begin(), arr.end());
	Trie *root = new Trie();

	for(auto it : queries){
		int ai = it[1];
		int xi = it[0];
		int idx = it[2];
		// cout<<ai<<"ai"<<endl;

		while(arr_i<n && arr[arr_i]<=ai){
			// cout<<"arr"<<arr_i<<endl;
			root->insert(arr[arr_i]);
			arr_i++;
		}
		

		ans[idx] = root->maxInArray(xi);


	}

	return ans;


}
