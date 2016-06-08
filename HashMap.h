#ifndef HASHMAP_H
#define HASHMAP_H

#include "HashNode.h"
#include "KeyHash.h"
#include <vector>

template <typename K, typename V, typename F = struct KeyHash<K, V>>

class HashMap {
private:
    int TABLE_SIZE = 11; //should be prime for better performace
    std::vector<HashNode<K, V>> table;
    float factor;
    int numElements;
    F hashFunc;
    //extend table size to make the factor
    bool extend();

public:
    HashMap(): factor(0.75), TABLE_SIZE(11), numElements(0) {};
    HashMap(float factor, int TABLE_SIZE): factor(factor), TABLE_SIZE(TABLE_SIZE), numElements(0) {};
    ~HashMap();
    float getFactor() { return this.factor; }
    void setFactor(float new_factor) { this.factor = new_factor; }
    int getTableSize() { return this.TABLE_SIZE; }
    void setTableSize(int new_size) { this.TABLE_SIZE = new_size; }
    //return true if push back successful else return false
    bool push_back(const K &key, const V &value);
    //return 1 if remove successful else return -1, return 0 if key not found
    int remove(const K &key);
    //print all key to stream
    void print();
    V get(const K &key);

};
#endif
