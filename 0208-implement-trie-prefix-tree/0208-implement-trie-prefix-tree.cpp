struct Node{
    public:    
    Node *links[26];    
    bool flag=false;    
    bool containsKey(char ch)//if there's a key present
    {
       return links[ch-'a']!=NULL;
    }    
    void put(char ch,Node *ref)//adds a new node
    {
       links[ch-'a']=ref;
    }    
    void setEnd()
    {
       flag=true;
    }    
    Node *get(char ch)
    {
       return links[ch-'a'];
    }     
    bool isEnd()
    {
       return flag;
    }
};

class Trie {
private:
Node *root;
public:
    Trie() 
    {
        root=new Node();        
    }    
    void insert(string word)
    {
        Node *node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i]))
            {
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
        }
        node->setEnd();        
    }
       
    bool search(string word) {
        Node *node=root;
        for(int i=0;i<word.size();i++)
        {
            if(!node->containsKey(word[i]))
            {
                return false;
            }
            node=node->get(word[i]);
        }
        if(node->isEnd())//if we have successfully found the whole word
            return true;
        else
            return false;
            
    }
    
    bool startsWith(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++)
        {
            if(!node->containsKey(word[i]))
            {
                return false;
            }
            node=node->get(word[i]);
        }
        return true;//no need to check for the whole word       
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */