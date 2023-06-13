#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
    // Write your code here
    int coin[] = {1, 2, 5, 10, 20, 50, 100, 500,  1000};
    int n = 9;

    int min = 0;
    for(int i=8; i>=0; i--){
        if(amount>=coin[i]){
            int rem = amount/coin[i];
            amount%=coin[i];
            min+=rem;
        }
    }

    return min;
}
