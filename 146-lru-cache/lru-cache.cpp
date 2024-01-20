/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *next;
    Node *prev;
    int key;
    int value;
    Node(int key, int value)
    {
        this->value = value;
        this->key = key;
        this->next = NULL;
        prev = NULL;
    }
};

class LRUCache
{
private:
    int size;
    unordered_map<int, Node *> mp;
    Node *head;
    Node *tail;
    int currCount = 0;

public:
    LRUCache(int capacity)
    {
        size = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (mp.find(key) == mp.end())
        {
            return -1;
        }
        Node *node = mp[key];
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = NULL;
        node->prev = NULL;
        Node *newEstNode = head->next;
        head->next = node;
        node->prev = head;
        newEstNode->prev = node;
        node->next = newEstNode;
        return node->value;
    }

    void put(int key, int value)
    {
        if (mp.find(key) == mp.end())
        {
            Node *node = new Node(key, value);
            mp[key] = node;
            Node *newEstNode = head->next;
            head->next = node;
            node->prev = head;
            newEstNode->prev = node;
            node->next = newEstNode;
            if(currCount+1>size){
                Node* lruNode = tail->prev;
                mp.erase(lruNode->key);
                lruNode->prev->next = tail;
                tail->prev = lruNode->prev;
                lruNode->next = NULL;
                lruNode->prev = NULL;
            }else{
                currCount++;
            }
        }
        else
        {
            Node *node = mp[key];
            node->value = value;
            node->prev->next = node->next;
            node->next->prev = node->prev;
            node->next = NULL;
            node->prev = NULL;
            Node *newEstNode = head->next;
            head->next = node;
            node->prev = head;
            newEstNode->prev = node;
            node->next = newEstNode;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
