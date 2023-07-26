#include <bits/stdc++.h>

int modularExponentiation(int x, int n, int m) {
  // Write your code here.
  int res = 1 % m;

  x = x % m;

  while (n > 0) {

    if (n & 1) {

      res = static_cast<long long>(res) * x % m;
    }

    x = static_cast<long long>(x) * x % m;

    n >>= 1;
  }

  return res;
}
