/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL)
            return "";
        queue<TreeNode*> q;
        string temp="";
        string s="";
        s+=to_string(root->val)+",";
        q.push(root);
        while(!q.empty())
        {
            TreeNode *temp=q.front();
            q.pop();
            if(temp->left)
            {
                s+=to_string(temp->left->val)+",";
                q.push(temp->left);
            }
            else
                s+="#,";
            if(temp->right)
            {
                s+=to_string(temp->right->val)+",";
                q.push(temp->right);
            }
            else
                s+="#,";
        }
        cout<<s<<" ";
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)
            return NULL;
        
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode *root=new TreeNode(stoi(str));
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode *it=q.front();
            q.pop();
            getline(s,str,',');
            
             if (str == "#")
             {
                it->left = NULL;
             }
            else 
            {
                TreeNode* leftNode = new TreeNode(stoi(str));
                it->left = leftNode;
                q.push(leftNode);
            } 
              
            getline(s,str,',');
            if (str == "#")
            {
                it->right = NULL;
            }
            else 
            {
                TreeNode* rightNode = new TreeNode(stoi(str));
                it->right = rightNode;
                q.push(rightNode);
            } 
        
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));