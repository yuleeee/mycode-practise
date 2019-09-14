// -*- coding: utf-8 -*-
/*题目描述
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
/*我的做法*/

class Solution {
public:
    TreeNode* root;
    bool findroot(TreeNode* pRoot1,TreeNode* pRoot2)
    {
        if(pRoot1 == NULL||pRoot2 == NULL)
            return false;
        if(pRoot1->val == pRoot2 ->val)
        {
            root = pRoot1;
            return true;
        }
        else
            return findroot(pRoot1->left,pRoot2)||findroot(pRoot1->right,pRoot2);
        
    }
    bool subtree(TreeNode* pRoot1,TreeNode* pRoot2)
    {
        if(pRoot2==NULL)
            return true;
        if(pRoot1==NULL)
            return false;
        if(pRoot1->val != pRoot2 ->val)
            return false;
         
        return subtree(pRoot1->left,pRoot2->left)&&subtree(pRoot1->right,pRoot2->right);
    }
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(findroot(pRoot1,pRoot2))
        {
            if(subtree(root->left,pRoot2->left)&&subtree(root->right,pRoot2->right))
                return true;
            else
                return HasSubtree(pRoot1->left,pRoot2)||HasSubtree(pRoot1->right,pRoot2);
        }
        else 
            return false;
    }
};

/*另外做法*/
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(!pRoot1 || !pRoot2) return false;
        bool result=false;
        if(pRoot1->val == pRoot2->val)result=isSubtree(pRoot1,pRoot2); // 找到判断子树
        if(!result) result=HasSubtree(pRoot1->left,pRoot2); // 未找到匹配的根节点以及匹配的子树，则继续向下递归
        if(!result) result=HasSubtree(pRoot1->right,pRoot2);
        return result;
    }
     
    bool isSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(!pRoot2) return true; // 子树遍历完成（关键语句）
        if(!pRoot1) return false; // 主树异常时的输出（关键语句：提高鲁棒性）
        bool result=true;
        if(pRoot1->val!=pRoot2->val) result=false;
        if(result) result=isSubtree(pRoot1->left,pRoot2->left);
        if(result) result=isSubtree(pRoot1->right,pRoot2->right);
        return result;
    }
};
