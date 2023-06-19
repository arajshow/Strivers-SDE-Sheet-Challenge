
string common(string s1, string s2){

    int n = min(s1.size(), s2.size());

    for(int i=0; i<n; i++){
        if(s1[i]!=s2[i]){
            return s1.substr(0, i);
        }
    }

    if(s1.size()<s2.size()) return s1;
    return s2;
}

string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    string ans = arr[0];

    for(int i=1; i<n; i++){

        ans = common(ans, arr[i]);
    }
    return ans;
}


