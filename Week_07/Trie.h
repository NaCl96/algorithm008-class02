/*
 * @Author: your name
 * @Date: 2020-06-02 13:41:54
 * @LastEditTime: 2020-06-02 13:57:34
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \algorithm008-class02\Week_07\Trie.h
 */ 
#ifndef TRIE_H
#define TRIE_H

#include <string>
using namespace std;

class Trie {
public:
    bool isEnd = false;
    Trie* next[26] = {nullptr};
    string str = "";
    /** Initialize your data structure here. */
    Trie() {

    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node = this;
        for(auto w : word){
            if(node->next[w-'a'] == nullptr){
                node->next[w-'a'] = new Trie();
            }
            node = node->next[w-'a'];
        }
        node->str = word;
        node->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node = this;
        for(auto w : word){
            if(node->next[w-'a'] == nullptr){
                return false;
            }
            node = node->next[w-'a'];
        }
        return node->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *node = this;
        for(auto w : prefix){
            node = node->next[w-'a'];
            if(node == nullptr) return false;
        }
        return true;
    }
};


#endif