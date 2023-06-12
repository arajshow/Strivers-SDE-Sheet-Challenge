int NthRoot(int n, int m) {
  // Write your code here.

  int lt = 1;
  int ht = m;

  while(lt <= ht)
  {
    int md = lt + (ht-lt)/2;

    if(pow(md, n) == m)
      return md;
    else if(pow(md, n) > m)
      ht = md - 1;
    else
      lt = md + 1;
  }

  return -1;
}
