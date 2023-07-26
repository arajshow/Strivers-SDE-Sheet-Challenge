#include <bits/stdc++.h>

string fourSum(vector<int> arr, int target, int n) {
    // Write your code here.20

    
        if (arr.empty())
            return "No";
    
        sort(arr.begin(),arr.end());
    
        for (int i = 0; i < arr.size(); i++) {
        
            int target_3 = target - arr[i];
        
            for (int j = i + 1; j < arr.size(); j++) {
            
                int target_2 = target_3 - arr[j];
            
                int front = j + 1;
                int back = arr.size() - 1;
            
                while(front < back) {
                
                    int two_sum = arr[front] + arr[back];
                
                    if (two_sum < target_2) front++;
                
                    else if (two_sum > target_2) back--;
                
                    else {
                        return "Yes";
                
                    }
                }
                
                // Processing the duplicates of arrber 2
                while(j + 1 < arr.size() && arr[j + 1] == arr[j]) ++j;
            }
        
            // Processing the duplicates of arrber 1
            while (i + 1 < arr.size() && arr[i + 1] == arr[i]) ++i;
        
        }
    
        return "No";
}
