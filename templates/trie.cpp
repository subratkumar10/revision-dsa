//Trie template 

class TrieNode {

    public:
    vector<TrieNode*>next;
    int count;
    TrieNode(){
        // vector<Trie*>next1(26,NULL); 
        next.resize(26,NULL);
       count=0;
    }

};


class Trie {
   TrieNode* root;
    public:

  Trie(TrieNode* root) {
    this->root = root;
    
  }

    
void create_trie(string&s){
  
head=root;
int n=s.length();

    for(int i=0;i<s.length();i++)
    {

        if(head->next[s[i]-'a']!=NULL){
            head=head->next[s[i]-'a'];
            head->count++;
            
        }else{

            head->next[s[i]-'a']= new TrieNode();
            head=head->next[s[i]-'a'];
            head->count++;
         
        }

    }


}

int calc(string&s){
    head=root;
    int tot=0;
    for(int i=0;i<s.length();i++)
    {
        // cout<<s<<endl;
        if(head->next[s[i]-'a']){
            head=head->next[s[i]-'a'];
            tot+=head->count;
            // cout<<"tot"<<tot<<endl;
        }else{
            break;
        }
    }
    return tot;
}
};


