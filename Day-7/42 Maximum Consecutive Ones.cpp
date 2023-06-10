#include <queue>

int longestSubSeg(vector<int> &arr , int n, int k){
    // Write your code here.
    if(k==n) return n;

    queue<int> q; //index;

    int ans = 0, count = 0;

    for(int i=0; i<n; i++){
        if(arr[i]==1){
            count++;
        }else if(arr[i]==0){
            if(k==0 && q.empty()){
                ans = max(ans, count);
                count = 0;
                continue;
            }
            if(k>0){
                k--;
                q.push(i);
                count++;
            }else{
                ans = max(ans, count);
                count = i - q.front();
                q.pop();
                q.push(i);
            }
        }
    }

    ans = max(ans, count);

    return ans;
}
