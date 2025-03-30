


// longest prefix and suffix, very useful for string matching algorithm

vector<int> calc_lps(string &s){

    int n = s.length();
    vector<int>lps(n,0);
    int l=0;
    for(int i=1;i<n;i++){

        while(l>0 && s[l]!=s[i]){
            l=lps[l-1];
        }
        if(s[l]==s[i])
        {
            l++;
        }
        lps[i]=l;
    }
    return lps;
}

vector<int> search(string &pat, string &txt) {
    int n = txt.length();
    int m = pat.length();

    vector<int> lps(m);
    vector<int> res;

    vector<int>lps = calc_lps(pat);

    int i = 0;
    int j = 0;

    while (i < n) {

        if (txt[i] == pat[j]) {
            i++;
            j++;

            if (j == m) {
                res.push_back(i - j);

                j = lps[j - 1];
            }
        }

        else {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return res;
}















