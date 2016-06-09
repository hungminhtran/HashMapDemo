#ifndef HASHNODE_H
#define HASHNODE_H
#include <iostream>

template <typename K, typename V>
class HashNode {
private:
    K key;
    V value;
    HashNode *nextNode;
    bool isInUse;
public:
    HashNode(): isInUse(false), nextNode(NULL) {}
    HashNode(K key, V value, bool isUsed, HashNode *nextNode ): 
    key(key), value(value), isInUse(isUsed), nextNode(nextNode) {};

    V getValue() const { return value; }

    K getKey() const { return key; }

    void setKey(K key) {this->key = key; }

    void setValue(V value) { this ->value = value; }

    HashNode* getNext() { return nextNode;}

    void setNext(HashNode *nextNode) { this->nextNode = nextNode;}

    bool isUsed(void) { return isInUse;}

    void setUsed(bool isUse) { this->isInUse = isUse;}
};
#endif