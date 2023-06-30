#define INT_MAX 1e9

int max(int a, int b){
    if(a>b) return a;
    return b;
}
int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    // Write your code here.
    if(m>n){
        return ninjaAndLadoos(row2, row1, n, m, k);
    }

    int low = 0, high = m;

    if(k==(n+m)) return max(row1[m-1], row2[n-1]);

    while(low<=high){
        int cut1 = low + (high-low)/2;
        if(cut1>k){
            high = cut1-1;
            continue;
        }

        int l1 = (cut1==0)? -1 : row1[cut1-1];
        int r1 = (cut1==m)? INT_MAX : row1[cut1];

        int cut2 = k - cut1;
        if(cut2>n){
            low = cut1 + 1;
            continue;
        }

        int l2 = (cut2==0)? -1 : row2[cut2-1];
        int r2 = (cut2==n)? INT_MAX : row2[cut2];

        if(l2<= r1 && l1<=r2){
            return max(l1, l2);
        }else if(l2>r1){
            low = cut1 + 1;
        }else{
            high = cut1 -1;
        }
    }
    return 0;
}
