/*
 * @Description:
 * @Author: lierenzhu
 * @Date: 2022-02-14 20:21:56
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-02-15 00:41:30
 * @FilePath: /leetcode/126.单词接龙-ii.cpp
 */
/*
 * @lc app=leetcode.cn id=126 lang=cpp
 *
 * [126] 单词接龙 II
 */

// @lc code=start
class Solution
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        vector<vector<string>> ans; //存放最后答案的容器
        unordered_set<string> dict; //存放单词列表

        /* 将单词列表中的单词拷贝到字典中 */
        for (const auto &w : wordList)
        {
            dict.insert(w);
        }

        /* 如果字典里没有最后一个单词则不存在解，直接返回空 */
        if (!dict.count(endWord))
        {
            return ans;
        }

        dict.erase(beginWord);
        dict.erase(endWord);

        /* q1存放下一次搜索要延伸的层，q2存放反向搜索到的层 */
        unordered_set<string> q1{beginWord}, q2{endWord};
        /* next存放每个单词的下一个单词 */
        unordered_map<string, vector<string>> next;
        bool reversed = false, found = false;

        while (!q1.empty())
        {
            /* q存放当前搜索的层内节点 */
            unordered_set<string> q;
            for (const auto &w : q1)
            {
                string s = w;
                for (size_t i = 0; i < s.size(); i++)
                {
                    char ch = s[i];
                    for (size_t j = 0; j < 26; j++)
                    {
                        s[i] = 'a' + j;
                        /* 如果q2和q1中都包含同一个单词，则说明两个方向的搜索相遇了 */
                        if (q2.count(s))
                        {
                            reversed ? next[s].push_back(w) : next[w].push_back(s);
                            found = true;       //相遇后设置已完成查找的标志
                        }
                        /* 字典中有替换后的单词 */
                        if (dict.count(s))
                        {
                            /* 如果是逆向搜索到的则说明修改后的s排在原单词w的前面，即s的下一个单词是w；反之如果是正向搜索到的s就排在w后面 */
                            reversed ? next[s].push_back(w) : next[w].push_back(s);
                            /* 将s存入当前层的存放集合q */
                            q.insert(s);
                        }
                    }
                    s[i] = ch;
                }
            }
            if (found)
            {
                break;
            }
            /* q中的单词已经访问过，如果下一层再次被搜索到则下一次的路径一定不是最短，所以可以直接删去防止再次被搜索到 */
            for (const auto &w : q)
            {
                dict.erase(w);
            }

            /* 当前层中节点数量小于等于反向（与当前搜索方向相反）搜索的节点数量时 */
            if (q.size() <= q2.size())
            {
                q1 = q;     //继续向当前搜索方向的下一层延伸
            }
            /* 当前层中节点数量大于反向（与当前搜索方向相反）搜索的节点数量时 */
            else
            {
                reversed = !reversed;   //设置从终点单词向起点单词搜索的标志
                q1 = q2;                //将存放着反向搜索得到的层的节点拷贝到下次存放待延伸层的q1中
                q2 = q;                 //将当前搜索到的层的节点拷贝到存放反向搜索的层节点的q2中
            }
        }
        /* 找到最短路径之后使用回溯法找到路径上每个单词 */
        if (found)
        {
            vector<string> path = {beginWord};
            backtracking(beginWord, endWord, next, path, ans);
        }

        return ans;
    }

    void backtracking(const string &src, const string &dst, unordered_map<string, vector<string>> &next, vector<string> &path, vector<vector<string>> &ans)
    {
        /* 如果当前单词就是最后一个单词说明这条路径回溯完毕，直接拷贝到结果容器ans中 */
        if (src == dst)
        {
            ans.push_back(path);
            return;
        }
        /* 寻找路径上当前单词的下一个单词，并将其拷贝到存放路径上单词的容器path中 */
        for (const auto &s : next[src])
        {
            path.push_back(s);
            backtracking(s, dst, next, path, ans);
            path.pop_back();
        }
    }
};
// @lc code=end
