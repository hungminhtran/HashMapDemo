#ifndef HASHMAP_H
#define HASHMAP_H
#include "HashNode.h"
#include "KeyHash.h"
#include <vector>
#include <climits>
#include <iostream>
#include <cmath>

template <typename K, typename V, typename F = struct KeyHash<K> >
class HashMap {
private:
    HashNode<K, V>** table;
    float factor;
    int numElements;
    F hashFunc;
public:

    HashMap() {
        this->factor = 0.75;
        this->numElements = 0;
        table = new HashNode<K, V>*[TABLE_SIZE];
        //        for (int i = 0; i < TABLE_SIZE; i++)
        //            table[i] = NULL;
    };
    // HashMap(float factor): factor(factor), numElements(0) {};

    ~HashMap() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            //get a node in table
            HashNode<K, V> *temp = this->table[i];
            while (temp != NULL) {
                HashNode<K, V> *temp2 = temp;
                //get next node
                temp = temp->getNext();
                //delete current node
                delete temp2;
            }
        }
        delete [] this->table;
    }

    float getFactor() {
        return this->factor;
    }

    void setFactor(float new_factor) {
        this->factor = new_factor;
    }

    void test() {
        std::cout << "run successfully" << std::endl;
        return;
    }
    //return true if push back successful else return false

    bool put(const K &key, const V &value) {

        unsigned int index = this->hashFunc(key);
        //check if key is equal, replace value
        HashNode<K, V> *temp = this->table[index];
        
        while (temp!= NULL && temp->getKey() != key)
            temp = temp->getNext();
        if (temp != NULL) {
            temp->setValue(value);
            return true;
        }
        if (this->table[index] == NULL) {
            this->table[index] = new HashNode<K, V>(key, value, true, NULL);
        }//collision
        else {
            //go to the lastest node
            temp = this->table[index];
            while (temp->getNext() != NULL)
                temp = temp->getNext();
            HashNode<K, V> *temp2 = new HashNode<K, V>(key, value, true, NULL);
            temp->setNext(temp2);
            if (temp->getNext() == NULL)
                return false;
        }
        this->numElements++;
        return true;
    }

    //return 1 if remove successful else return -1, return 0 if key not found

    int remove(const K &key) {
        unsigned int index = this->hashFunc(key);
        HashNode<K, V> *temp = this->table[index];
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
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (this->table[i] != NULL) {
                std::cout << "key: " << this->table[i]->getKey() << "; value: " << this->table[i]->getValue();
                HashNode<K, V> *temp = this->table[i]->getNext();
                while (temp != NULL) {
                    std::cout << "\tkey linkedlist: " << temp->getKey() << "; value linkedlist: " << temp->getValue();
                    temp = temp->getNext();
                }
                std::cout << std::endl;
            }
        }
    }

    int get(const K &key, V &value) {
        unsigned int index = this->hashFunc(key);
        HashNode<K, V> *temp = this->table[index];
        while (temp != NULL) {
            if (temp->getKey() == key) {
                value = temp->getValue();
                return 0;
            }
            temp = temp->getNext();
        }
        return -1;
    }
};
#endif