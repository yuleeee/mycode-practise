/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree){
        if(pRootOfTree == NULL)
            return NULL;
        stack<TreeNode*> s;
        TreeNode* p = pRootOfTree;
        TreeNode* pre = NULL;
        bool isfirst = true;
        while(p!=NULL||!s.empty())
        {
            while(p!=NULL)
            {
                s.push(p);
                p = p->left;
            }
            p = s.top();
            s.pop();
            
            if(isfirst)
            {
                pRootOfTree = p;
                pre = pRootOfTree;
                isfirst = false;
            }
            else
            {
                pre ->right = p;
                p->left = pre;
                pre = p;
            }
            p = p->right;
        }
        return pRootOfTree;
    }
};

/*前序、中序、后序遍历的递归和非递归实现*/
void inorder(btree ptr)//中序（输出根节点次序）遍历（递归实现）
{
    if (ptr != nullptr)
    {
        inorder(ptr->left);
        cout << ptr->data << " ";
        inorder(ptr->right);
    }
}

void preorder(btree ptr)//前序遍历（递归实现）
{
    if (ptr != nullptr)
    {
        cout << ptr->data << " ";
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void postorder(btree ptr)//后序遍历（递归实现）
{
    if (ptr != nullptr)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        cout << ptr->data << " ";
    }
}

//非递归中序遍历（左节点->根节点->右节点）思想：即用栈实现  
// 因为中序遍历二叉树的特点，所以在当前节点cur不为空或栈不为空的条件下（在该条件下的原因：该条件说明  
// 未遍历完二叉树），开始执行循环体，进行遍历：  
//（1）从当前节点cur开始，以cur为循环条件，当cur不为空时，将cur入栈，然后以cur=cur->_left跟进，直至  
//     将该二叉树的最左节点入栈后，入栈操作结束  
//（2）取栈顶节点：先保存该节点（用top保存该节点的原因：还要考虑该节点的右孩子）并输出该节点的值，  
//     然后执行栈的pop操作。  
//（3）继续以top->_right为cur值，转（1）操作.  

void inorder2(btree ptr)//中序遍历的非递归实现
{
    stack<btree> st;
    while (ptr != nullptr || !st.empty())
    {
        while (ptr != nullptr)
        {
            st.push(ptr);
            ptr = ptr -> left;
        }
        btree tp = st.top();
        cout << tp -> data << " ";
        st.pop();
        ptr = tp -> right;
    }
}

//非递归先序遍历（根节点->左节点->右节点）思想：即用栈实现  
//遍历二叉树的前提条件是：该二叉树不为空。在满足该条件的情况下，进行以下步骤：  
//1.先将二叉树的根节点push进栈。  
//2.在该栈不为空的条件下，执行一个循环（先用top保存栈顶元素，再对栈进行pop操作，因为栈具有后进先出的特点  
//  ，所以先对top->_right进行判断是否入栈，再对top->_left进行判断是否入栈）。  
//3.当栈为空时，先序遍历该二叉树结束。

void preorder2(btree ptr)//前序遍历的非递归实现
{
    stack<btree> st;
    if (ptr != nullptr)
    {
        st.push(ptr);
    }
    while (!st.empty())
    {       
        btree tp = st.top();
        st.pop();
        cout << tp -> data << " ";
        if (tp->right != nullptr)
            st.push(tp->right);
        if (tp->left != nullptr)
            st.push(tp->left);
    }
}

//非递归后序遍历（左节点->右节点->根节点）思想：即用栈实现  
//（1）在当前节点cur不为空或栈不为空的条件下（在该条件下的原因：该条件说明未遍历完二叉树）。  
//（2）从当前节点cur开始，以cur为循环条件，当cur不为空时，将cur入栈，然后以cur=cur->_left跟进，直至  
//     将该二叉树的最左节点入栈后，入栈操作结束。取栈顶节点top：先保存该节点（用top保存该节点的原因：  
//     还要考虑该节点的右孩子），  
//（3）若top->_right==NULL || lastVisited == top->_right,则输出top->_value,执行栈的pop操作,并执行lastVisited = top(  
//    用lastVisited保存最近一个所输出的节点，待到下一次同样的操作时，若lastVisited == top->_right，则  
//    说明top的右节点已经访问过了，可以访问top了，否则会陷在cur = top->_right这步操作里）;  
//（4）若条件（3）不满足，则继续以top->_right为cur值，转（1）操作.  
void postorder2(btree ptr)//后序遍历的非递归实现
{
    stack<btree> st;
    btree lastVisited  = nullptr;
    while (ptr != nullptr || !st.empty())
    {
        while (ptr != nullptr)
        {
            st.push(ptr);
            ptr = ptr -> left;
        }
        btree tp = st.top();
        if (tp->right == nullptr || lastVisited == tp->right)
        {   
            st.pop();
            cout << tp -> data << " ";
            lastVisited = tp;
        }
        else 
            ptr = tp->right;
    }
}
————————————————
版权声明：本文为CSDN博主「lx青萍之末」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/daaikuaichuan/article/details/80367012
