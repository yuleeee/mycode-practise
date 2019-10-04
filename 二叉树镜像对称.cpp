// /*
// 请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
// */
// //递归
// boolean isSymmetrical(TreeNode pRoot)
//     {
//         if(pRoot == null) return true;
//         return isSymmetrical(pRoot.left, pRoot.right);
//     }
//     private boolean isSymmetrical(TreeNode left, TreeNode right) {
//         if(left == null && right == null) return true;
//         if(left == null || right == null) return false;
//         return left.val == right.val //为镜像的条件：左右节点值相等
//                 && isSymmetrical(left.left, right.right) //2.对称的子树也是镜像
//                 && isSymmetrical(left.right, right.left);
//     }

 //   链接：https://www.nowcoder.com/questionTerminal/ff05d44dfdb04e1d83bdbdab320efbcb?f=discussion
//来源：牛客网
//非递归
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

// boolean isSymmetricalBFS(TreeNode pRoot)
//     {
//         if(pRoot == null) return true;
//         Queue<TreeNode> s = new LinkedList<>();
//         s.offer(pRoot.left);
//         s.offer(pRoot.right);
//         while(!s.isEmpty()) {
//             TreeNode left= s.poll();//成对取出
//             TreeNode right= s.poll();
//             if(left == null && right == null) continue;
//             if(left == null || right == null) return false;
//             if(left.val != right.val) return false;
//             //成对插入
//             s.offer(left.left);
//             s.offer(right.right);
//             s.offer(left.right);
//             s.offer(right.left);
//         }
//         return true;
//     }

    /*我的非递归*/
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(pRoot == NULL)
            return true;
        queue<TreeNode*> q;
        q.push(pRoot);
        vector<int> cnt;
        vector<int> value;
        int c= 0;
        cnt.push_back(1);
        int i = 0;
        int k = 0;
        int l= 0 ;
        int r =0;
        while(!q.empty())
        {
            
            if(q.front()->left!=NULL)
            {
                q.push(q.front()->left);
                value.push_back(q.front()->left->val);
                c++;
                l++;
            }
            if(q.front()->right!=NULL)
            {
                q.push(q.front()->right);
                value.push_back(q.front()->right->val);
                c++;
                r++;
            }
            cnt[i]--;
            if(cnt[i]==0)
            {
                cnt.push_back(c);
                c=0;
                i++;
                if(l!=r)
                return false;
                l=0;r=0;
                if(i!=0)
                {

                    for(int j = 0;j<cnt[i]/2;j++)
                        if(value[k+j]!=value[k+cnt[i]-1-j])
                            return false;
                    k+=cnt[i];
                    
                }
            }
            q.pop();

        }
        return true;
        
    }

};
