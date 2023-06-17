 int largestRectangle(vector < int > & heights) {
   // Write your code here.
   int ans  = 0, n = heights.size();

   for(int i=0; i<n; i++){
    if(heights[i]==0) continue;

    int rt = i;

    while(rt<n && heights[rt]>=heights[i]){
      rt++;
    }

    int lt = i;
    while(lt>=0 && heights[lt]>=heights[i]){
      lt--;
    }

    ans = max(ans, (rt -lt - 1)*heights[i]);
  }


  return ans;

 }
