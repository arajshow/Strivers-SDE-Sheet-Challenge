// #include <bits/stdc++.h>

int singleNonDuplicate(vector<int> &arr) {
  // Write your code here
  int start = 0;

  int end = arr.size() - 1;

  while (start < end)

  {

    int mid = (start + end) / 2;

    if ((mid % 2 == 0 && arr[mid] == arr[mid + 1]) ||
        (mid % 2 == 1 && arr[mid] == arr[mid - 1]))

    {

      start = mid + 1;

    }

    else

      end = mid;
  }

  return arr[start];
}
