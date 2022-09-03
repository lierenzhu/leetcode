/*
 * @Description: 
 * @Author: lierenzhu
 * @Date: 2022-08-28 23:48:00
 * @LastEditors: lierenzhu
 * @LastEditTime: 2022-09-03 16:39:12
 * @FilePath: /leetcode-autumn/146.lru-缓存.cpp
 */
/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
struct DListNode {
    DListNode* prev;
    DListNode* next;
    int key,value;
    DListNode():prev(nullptr),next(nullptr),key(0),value(0){}
    DListNode(int k,int v): prev(nullptr),next(nullptr),key(k),value(v){}
};
class LRUCache {
private:
    DListNode* dummyHead;
    DListNode* dummyTail;
    int caps,size;
    unordered_map<int,DListNode*> cache;
public:
    LRUCache(int capacity):caps(capacity),size(0) {
        dummyHead=new DListNode();
        dummyTail=new DListNode();
        dummyHead->next=dummyTail;
        dummyTail->prev=dummyHead;
    }
    
    int get(int key) {
        if(!cache.count(key))
        {
            return -1;
        }
        DListNode* curNode=cache[key];
        removeNode(curNode);
        addToHead(curNode);
        return curNode->value;
    }
    
    void put(int key, int value) {
        if(cache.count(key)){
            DListNode* curNode=cache[key];
            curNode->value=value;
            removeNode(curNode);
            addToHead(curNode);
            return;
        }
        DListNode* curNode=new DListNode(key,value);
        if(size<caps){
            size++;
            cache[key]=curNode;
            addToHead(curNode);
        }else{
            cache.erase(cache.find(dummyTail->prev->key));
            cache[key]=curNode;
            removeNode(dummyTail->prev);
            addToHead(curNode);
        }
    }

    void removeNode(DListNode* node){
        node->next->prev=node->prev;
        node->prev->next=node->next;
    }

    void addToHead(DListNode* node){
        node->next=dummyHead->next;
        node->prev=dummyHead;
        dummyHead->next->prev=node;
        dummyHead->next=node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

