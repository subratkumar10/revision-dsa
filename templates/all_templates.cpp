


// SieveOfEratosthenes - to calculate prime integers in a within a given range 1 to n
vector<bool> siev(int n)
{

    vector<bool> prime(n + 1, true);

    for (int p = 2; p * p <= n; p++) {


        if (prime[p] == true) {
            
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

 return prime;
}


//******************************************************************************************************************************

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

//******************************************************************************************************************************

// find gcd / hcf of 2 numbers
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);    
}


















