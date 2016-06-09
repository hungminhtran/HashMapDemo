#ifndef HASHMAP_H
#define HASHMAP_H

#include "HashNode.h"
#include "KeyHash.h"
#include <vector>

//template <typename K, typename V, typename F = struct KeyHash<K>>
template <typename K, typename V, typename F>
class HashMap {
private:
    std::vector<HashNode<K, V> > table;
    float factor;
    int numElements;
    F hashFunc;
public:

    HashMap() : factor(0.75), numElements(0) {
    };
    // HashMap(float factor): factor(factor), numElements(0) {};
    ~HashMap();

    float getFactor() {
        return this.factor;
    }

    void setFactor(float new_factor) {
        this.factor = new_factor;
    }
    void test();
    //return true if push back successful else return false
    bool put(const K &key, const V &value);
    //return 1 if remove successful else return -1, return 0 if key not found
    int remove(const K &key);
    //print all key to stream
    void print();
    V get(const K &key);
};
#endif