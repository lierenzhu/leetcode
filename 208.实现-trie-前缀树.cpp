/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-03-16 19:57:03
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-03-16 20:51:36
 * @FilePath: /leetcode/208.实现-trie-前缀树.cpp
 */
/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
class Trie {
private:
    bool isEnd;
    Trie* next[26];
public:
    Trie() {
        isEnd = false;
        for(int i=0; i<26;++i)
        {
            next[i] = nullptr;
        }

    }
    
    void insert(string word) {
        Trie* node=this;
        for(char c : word)
        {
            if(node->next[c-'a']==nullptr)
            {
                node->next[c-'a']=new Trie();
            }
            node=node->next[c-'a'];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        Trie* node=this;
        for(char c : word)
        {
            if(node->next[c-'a']==nullptr)
            {
                return false;
            }
            node=node->next[c-'a'];
        }
        if(node->isEnd)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    bool startsWith(string prefix) {
        Trie* node=this;
        for(char c:prefix)
        {
            if(node->next[c-'a']==nullptr)
            {
                return false;
            }
            node=node->next[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

