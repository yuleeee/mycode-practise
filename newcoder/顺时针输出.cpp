/*
题目描述
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
例如，如果输入如下4 X 4矩阵： 
1 2 3 4
5 6 7 8 
9 10 11 12 
13 14 15 16 
则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
*/
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> res;
        int x,y=0;
        int leftx= 0;
        int downy= 1;
        int times = 0;
        
        int row = matrix.size();
        if(row <= 1)
            return matrix[0];
        int len = matrix[0].size();
        if(len == 1)
        {
            for(int  i = 0;i<row;i++)
                res.push_back(matrix[i][0]);
            return res;
        }
        int total = row *len;
        while(times<total)
        {
            for(;x<len;x++)
            {
                res.push_back(matrix[y][x]);
                times++;
                if(times>=total)
                    return res;
            }
            x = len-1;
            y++;
            len--;
            for(;y<row;y++)
            {
                res.push_back(matrix[y][x]);
                times++;
                                if(times>=total)
                    return res;
            }
            y = row-1;
            row--;
            x--;
            for(;x>=leftx;x--)
            {
                res.push_back(matrix[y][x]);
                times++; 
                                if(times>=total)
                    return res;
            }
            x = leftx;
            y--;
            leftx++;
            for(;y>=downy;y--)
            {
                res.push_back(matrix[y][x]);
                times++; 
                                if(times>=total)
                    return res;
            }
            y = downy;
            x++;
            downy++;
        }
        return res;
    }
};