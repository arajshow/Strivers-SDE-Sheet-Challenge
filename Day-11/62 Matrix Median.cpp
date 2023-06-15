
vector<int> merge(vector<int> a, vector<int> b){

    int ia =0, ib= 0, n1 = a.size(), n2 = b.size();

    vector<int> v;

    while(ia<n1 && ib<n2){
        if(a[ia]<=b[ib]){
            v.push_back(a[ia]);
            ia++;
        }else{
            v.push_back(b[ib]);
            ib++;
        }
    }

    while(ia<n1){
            v.push_back(a[ia]);
            ia++;        
    }

    while(ib<n2){
            v.push_back(b[ib]);
            ib++;        
    }

    return v;

}

int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.
    int n = matrix.size(), m = matrix[0].size();
    int total = n*m;

    vector<int> arr(matrix[0]);

    for(int i=1; i<n; i++){
        arr = merge(arr, matrix[i]);
    }

    return arr[total/2];


}
