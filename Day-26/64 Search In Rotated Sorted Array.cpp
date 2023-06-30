int search(int* arr, int n, int key) {
    // Write your code here.64
    int low = 0, high = n-1;

    while(low<=high){
        int md = low + (high -low)/2;

        if(arr[md]>=arr[low]){
            if(key<=arr[md] && arr[low]<=key){
                if(key==arr[md]) return md;
                if(key==arr[low]) return low;
                high = md-1;
            }else{
                low = md+1;
            }
        }
        
        if(arr[md]<=arr[high]){
            if(key>=arr[md] && arr[high]>=key){
                if(key==arr[md]) return md;
                if(key==arr[high]) return high;
                low = md + 1;
            }else{
                high = md-1;
            }
        }
    }

    return -1;
    
}
