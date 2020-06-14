/*
 * @Author: your name
 * @Date: 2020-06-09 08:12:29
 * @LastEditTime: 2020-06-09 09:59:28
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \algorithm008-class02\Week_08\LRU-cache.cpp
 */

#include <algorithm>
#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
 public:
  LRUCache(int n) {
    this->max_cap = n;
    this->LRUmap.clear();
    this->LRUlist.clear();
  }
  int get(int key) {
    unordered_map<int, list<pair<int, int>>::iterator>::iterator iter =
        this->LRUmap.find(key);
    if (iter == this->LRUmap.end()) {
      return -1;
    } else {
      int val = iter->second->second;
      pair<int, int> pair_ = make_pair(key, val);
      LRUlist.erase(iter->second);
      LRUlist.push_front(pair_);
      this->LRUmap[key] = this->LRUlist.begin();
      return val;
    }
  }

  void put(int key, int val) {
    unordered_map<int, list<pair<int, int>>::iterator>::iterator iter =
        this->LRUmap.find(key);
    if (iter != this->LRUmap.end()) {
      list<pair<int, int>>::iterator it = iter->second;
      this->LRUlist.erase(it);
      this->LRUlist.push_front(pair<int, int>(key, val));
      this->LRUmap[key] = this->LRUlist.begin();
      return;
    }
    if (this->LRUmap.size() == this->max_cap) {
      int key_ = this->LRUlist.back().first;
      list<pair<int, int>>::iterator it = this->LRUmap[key_];
      this->LRUlist.erase(it);
      this->LRUmap.erase(key_);
    }
    this->LRUlist.push_front({key, val});
    this->LRUmap[key] = this->LRUlist.begin();
  }

 private:
  int max_cap;
  unordered_map<int, list<pair<int, int>>::iterator> LRUmap;
  list<pair<int, int>> LRUlist;
};

struct CacheNode {
  int key;
  int val;
  CacheNode *pre, *next;
  CacheNode(int k, int v) : key(k), val(v), pre(nullptr), next(nullptr){};
};

class LRUCache_2 {
 private:
  int max_cap;
  CacheNode *head, *tail;
  unordered_map<int, CacheNode *> map;

 public:
    LRUCache_2(int capacity){
        max_cap = capacity;
        head = nullptr;
        tail = nullptr;
    }

    int get(int key){
        unordered_map<int,CacheNode*>::iterator it = map.find(key);
        if(it == map.end()){
            cout<<"not find"<<endl;
            return -1;
        }
        else{
            CacheNode* nd = it->second;
            remove(nd);
            setHead(nd);
            cout<<"find:"<<nd->val<<endl;
            return nd->val;
        }
    }

    void put(int key,int val){
        unordered_map<int,CacheNode*>::iterator it =map.find(key);
        if(it != map.end()){
            CacheNode* nd = it->second;
            nd->val =val;
            remove(nd);
            setHead(nd);
        }else{
            CacheNode* node = new CacheNode(key,val);
            if(map.size() >= max_cap){
                unordered_map<int,CacheNode*>::iterator it_ = map.find(tail->key);
                remove(tail);
                map.erase(it_);
            }
            setHead(node);
            map[key] = node;
            cout<<"has put"<<endl;
        }
    }

    void remove(CacheNode* node){
        if(node->pre != nullptr){
            node->pre->next = node->next;
        }
        else{
            head = node->next;
        }
        if(node->next != nullptr){
            node->next->pre = node->pre;
        }else{
            tail = node->pre;
        }
    }

    void setHead(CacheNode* node){
        node->next = head;
        node->pre = nullptr;
        if(head != nullptr){
            head->pre = node;
        }
        head = node;
        if(tail == nullptr){
            tail = head;
        }
    }
};

int main(){
    LRUCache_2* cache = new LRUCache_2(2);
    cache->put(2,1);
    cache->put(2,2);
    cache->get(2);
    cache->put(1,1);
    cache->put(4,1);
    cache->get(2);

    return 0;
}