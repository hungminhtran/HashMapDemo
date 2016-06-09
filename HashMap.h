#include "HashNode.h"
#include "KeyHash.h"
#include <vector>
#include <climits>
#include <iostream>
#include <cmath>

template <typename K, typename V, typename F = struct KeyHash<K> >
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

    ~HashMap() {
        for (typename std::vector<HashNode<K, V> >::iterator it = this->table.begin(); it != this->table.end(); it++) {
            //get a node in table
            HashNode<K, V> *temp = &*it;
            while (temp != NULL) {
                HashNode<K, V> *temp2 = temp;
                //get next node
                temp = temp->getNext();
                //delete current node
                delete temp2;
            }
        }
    }

    float getFactor() {
        return this.factor;
    }

    void setFactor(float new_factor) {
        this.factor = new_factor;
    }

    void test() {
        std::cout << "run successfully" << std::endl;
        return;
    }
    //return true if push back successful else return false

    bool put(const K &key, const V &value) {

        unsigned int index = this->hashFunc(key);
        //if not colusion
        if (!this->table[index].isUsed()) {
            this->table[index].setKey(key);
            this->table[index].setValue(value);
            this->table[index].setUsed(true);
        }            //collision
        else {
            //go to the lastest node
            HashNode<K, V> *temp;
            *temp = this->table[index];
            while (temp->getNext() != NULL)
                temp = temp->getNext();
            temp->setNext(new HashNode<K, V>(key, value, true, NULL));
            if (temp->getNext() == NULL)
                return false;
        }
        this->numElements++;
        return true;
    }

    //return 1 if remove successful else return -1, return 0 if key not found

    int remove(const K &key) {
        unsigned int index = this->hashFunc(key);
        HashNode<K, V> *temp;
        *temp = this->table[index];
        if (temp->getKey() == key) {
            temp->setKey(temp->getNext()->getKey());
            temp->setValue(temp->getNext()->getValue());
            temp->setNext(temp->getNext());
            delete temp->getNext();
            return 1;
        } else {
            while (temp->getNext() != NULL) {
                HashNode<K, V> *prev = temp;
                temp = temp->getNext();
                if (temp->getKey() == key) {
                    prev->setNext(temp->getNext());
                    delete temp;
                    return 1;
                }
            }
            return 0;
        }
        return -1;
    }
    //print all key to stream

    void print() {
        for (typename std::vector<HashNode<K, V> >::iterator it = this.table.begin(); it != this.table.end(); it++) {
            std::cout << "key: " << *it.getKey() << "; value: " << *it.getValue();
            HashNode<K, V> *temp = *it;
            while (temp->getNext() != NULL) {
                std::cout << "\tkey linkedlist: " << *it.getKey() << "; value linkedlist: " << *it.getValue();
                temp = temp->getNext();
            }
            std::cout << std::endl;
        }
    }

    V get(const K &key) {
        unsigned int index = this->hashFunc(key);
        HashNode<K, V> *temp;
        *temp = this->table[index];
        while (temp->getNext() != NULL) {
            if (temp->getKey() == key)
                return temp->getValue();
            temp = temp->getNext();
        }
        if (temp == NULL)
            return NULL;
    }
};
