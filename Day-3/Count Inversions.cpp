#include <bits/stdc++.h> 

long long merge(long long *arr, int st, int ed)

{

    int mid = st + (ed - st) / 2;

    long long ans = 0;

    int len1 = mid - st + 1;

    int len2 = ed - mid;


    int *arr1 = new int[len1];

    int *arr2 = new int[len2];


    int idx = st;

    for (int i = 0; i < len1; i++)

    {

        arr1[i] = arr[idx++];
    }

    idx = mid + 1;

    for (int i = 0; i < len2; i++)

    {

        arr2[i] = arr[idx++];
    }

    

    int id1 = 0;

    int id2 = 0;

    idx = st;

    while (id1 < len1 && id2 < len2)

    {

        if (arr1[id1] < arr2[id2])

        {

            arr[idx++] = arr1[id1++];
        }

        else

        {

            arr[idx++] = arr2[id2++];

            ans += len1 - id1;
        }
    }

    while (id1 < len1)

    {

        arr[idx++] = arr1[id1++];
    }

    while (id2 < len2)

    {

        arr[idx++] = arr2[id2++];
    }

    delete[] arr1;

    delete[] arr2;

    return ans;
}

long long mergeSort(long long *arr, int st, int ed)

{

    long long ans = 0;

    // Base Case

    if (st >= ed)

    {

        return ans;
    }

    int mid = st + (ed - st) / 2;

    ans += mergeSort(arr, st, mid);

    ans += mergeSort(arr, mid + 1, ed);

    ans += merge(arr, st, ed);

    return ans;
}

long long getInversions(long long *arr, int n){

    return mergeSort(arr, 0, n - 1);
}
