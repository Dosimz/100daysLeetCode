#include<iostream>
#include <unordered_map>

using namespace std;

struct DLinkedNode{
    int key, val;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode():key(0), val(0), next(nullptr), prev(nullptr){}
    DLinkedNode(int k, int v): key(k), val(v), prev(nullptr), next(nullptr){}
};

class LRUCache {
    unordered_map<int, DLinkedNode*> cache;
    DLinkedNode* head;
    DLinkedNode* tail;
    int cap;
    int size;

public:
    LRUCache(int _capacity):cap(_capacity),size(0) {
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(!cache.count(key)){
            return -1;
        }
        DLinkedNode* node = cache[key];
        makeRecently(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(cache.count(key)){
            DLinkedNode* node = cache[key];
            node->val = value;
            makeRecently(node);
        }
        else{
            DLinkedNode* node = new DLinkedNode(key, value);
            cache[key] = node;
            addToHead(node);
            size++;
            if(size>cap){
                DLinkedNode* removed = removeTail();

                cache.erase(removed->key);
                delete removed;
                size--;
            }
        }
    }

    void addToHead(DLinkedNode* node){
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(DLinkedNode* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void makeRecently(DLinkedNode* node){
        removeNode(node);
        addToHead(node);
    }

    DLinkedNode* removeTail(){
        DLinkedNode* node = tail->prev;
        removeNode(node);
        return node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */