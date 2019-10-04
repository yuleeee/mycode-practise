/*给定一棵二叉搜索树，请找出其中的第k小的结点。
例如， （5，3，7，2，4，6，8）中，按结点数值大小顺序第三小结点的值为4。*/
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {       //中序遍历恰好按顺序输出搜索树
public:
    vector<TreeNode*> res;
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        zhong(pRoot);
        if(k>=1&&k<=res.size())
        return res[k-1];
        return NULL;
    }
    void zhong(TreeNode* pRoot)
    {
        if(pRoot == NULL)
            return ;
        zhong(pRoot->left);
        res.push_back(pRoot);
        zhong(pRoot->right);
    }

    
};