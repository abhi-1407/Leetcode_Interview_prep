class Node{
  Node* links[26];
  bool flag=false;
  
  public:
  
  void createNode(char c,Node *n)
  {
      links[c-'a']=n;
  }

  bool exists(char c)
  {
      return links[c-'a']!=NULL;
  }
  Node* getNode(char c)
  {
      return links[c-'a'];
  }
  void setEnd()
  {
      flag=true;
  }
  bool getEnd()
  {
      return flag;
  }
    
 
};
class Trie {
    Node *root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
         Node *temp=root;
         for(int i=0;i<word.size();i++)
         {
             if(!(temp->exists(word[i])))
             temp->createNode(word[i],new Node());
             temp=temp->getNode(word[i]);//now new temp points to the next addr
         }
         temp->setEnd();
    }

    bool search(string word)
    {
        Node *node=root;
        for(int i=0;i<word.size();i++)
        {
            if(!(node->exists(word[i])))
                return false;
            node=node->getNode(word[i]);
            if(node->getEnd()==false)
                return false;
            else 
                continue;
        }
        return node->getEnd();
    }
    
};
class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie t;
        for(auto it:words)
        {
            t.insert(it);
        }
        string ans="";
        for(auto it:words)
        {
            if(t.search(it))
            {
                if(it.length() > ans.length())
                    ans=it;
                else if(it.length()==ans.length() && it<ans)
                    ans=it;
            }
        }
        return ans;
    }
};