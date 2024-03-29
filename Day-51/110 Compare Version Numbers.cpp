#include <bits/stdc++.h>

int compareVersions(string a, string b)

{

    // 110
    int i = 0;

    int j = 0;

    while (i < a.size() || j < b.size())
    {

        long x = 0;

        long y = 0;

        while (i < a.size() && a[i] != '.')
            x = x * 10 + (a[i++] - '0');

        while (j < b.size() && b[j] != '.')
            y = y * 10 + (b[j++] - '0');

        if (x > y)
            return 1;

        else if (x < y)
            return -1;

        i++;

        j++;
    }

    return 0;
}
