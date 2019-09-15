/*
题目描述
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
假设压入栈的所有数字均不相等。
例如序列1,2,3,4,5是某栈的压入顺序，
序列4,5,3,2,1是该压栈序列对应的一个弹出序列，
但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）
*/
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        int len = pushV.size();
        stack<int> test;
        if(len==0)
            return true;
        int i =0;
        int j =0;
        
        for(;j<len;j++)//在遍历压栈时，遇到可弹出的先弹出
        {
            if(pushV[j]==popV[i])
            {
                //test.push(pushV[j]);
                //test.pop();
                i++;
                continue;
            }
            else
            {
                test.push(pushV[j]);
            }

        }
        while(!test.empty()&&test.top()==popV[i])//遍历完成后，全部弹出
                {
                    test.pop();
                    i++;
                }
        if(i!=len)//若未能完全弹出，则false
            return false;
        return true;
    }
};
