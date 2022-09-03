/*
 * @Description:
 * @Author: lierenzhu
 * @Date: 2022-03-04 10:54:28
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-03-05 21:47:54
 * @FilePath: /leetcode/48.旋转图像.cpp
 */
/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {

        int m = matrix.size(), n = matrix[0].size();

        //利用栈瞎JB做的
        // if (m == 1)
        // {
        //     return;
        // }
        // stack<int> st;
        // for (int j = n - 1; j >= 0; --j)
        // {
        //     for (int i = 0; i < m; ++i)
        //     {
        //         st.push(matrix[i][j]);
        //     }
        // }

        // for (int i = 0; i < m; ++i)
        // {
        //     for (int j = 0; j < n; ++j)
        //     {
        //         matrix[i][j] = st.top();
        //         st.pop();
        //     }
        // }

        //按找到的规律修改原数组
        int temp=0;
        for(int i=0;i<m/2;++i)
        {
            for(int j=0;j<(m+1)/2;++j)
            {
                temp=matrix[i][j];
                matrix[i][j]=matrix[n-1-j][i];
                matrix[n-1-j][i]=matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j]=matrix[j][n-1-i];
                matrix[j][n-1-i]=temp;
            }
        }

    }
};
// @lc code=end
