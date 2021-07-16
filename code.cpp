1. Approch with max height reference
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int res;
    void findbottom(TreeNode *root,int current_height,int &max_height)
    {
        if(root!=NULL)
        {
            if(root->left==NULL && root->right==NULL)
            {
                if(current_height>max_height)
                {
                    res=root->val;
                    max_height=current_height;
                }
            }
            else
            {
                findbottom(root->left,current_height+1,max_height);
                findbottom(root->right,current_height+1,max_height);
            }
        }
    }
    int findBottomLeftValue(TreeNode* root) {
        int max_height=-1;
            findbottom(root,0,max_height);   
        return res;
    }
};


2nd Approch
by level order traversal find last row

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        vector<vector<int>>res;
        queue<TreeNode *>A;
        A.push(root);
        vector<int>B;
        while(!A.empty())
        {
            int size=A.size();
            for(int i=0;i<size;i++)
            {
                TreeNode *temp=A.front();
                B.push_back(temp->val);
                A.pop();
                if(temp->left){A.push(temp->left);}
                if(temp->right){A.push(temp->right);}
            }
            res.push_back(B);
            B.clear();
        }
        return res[res.size()-1][0];
    }
};
