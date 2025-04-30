class Solution {
public:
#define ll long long

class TrieNode {

    public:
    unordered_map<int,TrieNode*>next;
    ll count;
    TrieNode(){
       count=0LL;
    }

};

    class Trie {

        TrieNode* root;

        public:

        Trie(TrieNode* root){
            this->root= root;
        }


 TrieNode* head;
    ll create_trie(string&s){

     head =root;
    ll count_sub=0;

    int n=s.length();

    for(int i=0;i<s.length();i++)
    {

    if(head->next[(s[i]-'a')*26 + s[n-i-1]-'a']){
        head=head->next[(s[i]-'a')*26 + s[n-i-1]-'a'];
        if(head->count>0){
            count_sub+=(ll)(head->count);
        }
        
    }else{
        head->next[(s[i]-'a')*26 + s[n-i-1]-'a'] = new TrieNode();
        head=head->next[(s[i]-'a')*26 + s[n-i-1]-'a'];
        
    }

    }

    head->count++;
    return count_sub;

    }
    };

 



    long long countPrefixSuffixPairs(vector<string>& words) {

        TrieNode* root = new TrieNode();

        Trie* trie = new Trie(root);

        int n = words.size();
        ll tot=0;

        for(int i=0;i<n;i++){

           tot+=trie->create_trie(words[i]);
           cout<<tot<<endl;
        }
        return tot;


        
    }
};
