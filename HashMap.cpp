#include "HashMap.h"
#include <climits>
#include <iostream>
#include <cmath>

template <typename K, typename V, typename F>
HashMap<K, V, F>::~HashMap() {
    //iterator all element in table
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

template <typename K, typename V, typename F>
//return true if push back successful else return false
void HashMap<K, V, F>::test(){
    std::cout<<"rung successfully"<<std::endl;
    return;
}

template <typename K, typename V, typename F>
bool HashMap<K, V, F>::put(const K &key, const V &value) {

    unsigned int index = this->hashFunc(key);
    //if not colusion
    if (!this->table[index].isUsed()) {
        this->table[index].setKey(key);
        this->table[index].setValue(value);
        this->table[index].setUsed(true);
    }
    //collision
    else
    {
        //go to the lastest node
        HashNode<K,V> *temp = this->table[index];
        while (temp->getNext() != NULL)
            temp  = temp->getNext();
        temp->setNext(new HashNode<K, V>(key, value, true, NULL));
        if (temp->getNext() == NULL)
            return false;
    }
    this->numElements++;
    return true;
}

template <typename K, typename V, typename F>
V HashMap<K, V, F>::get(const K &key) {
    unsigned int index = this->hashFunc(key);
    HashNode<K, V> *temp = this->table[index];
    while (temp->getNext() != NULL) {
        if (temp->getKey() == key)
            return temp->getValue();
        temp = temp->getNext();
    }
    if (temp == NULL)
        return NULL;
}

template <typename K, typename V, typename F>
//return 1 if remove successful else return -1, return 0 if key not found
int HashMap<K, V, F>::remove(const K &key) {
    unsigned int index = this->hashFunc(key);
    HashNode<K, V> *temp = this->table[index];
    if (temp->getKey() == key) {
        temp->setKey(temp->getNext()->getKey());
        temp->setValue(temp->getNext()->getValue());
        temp->setNext(temp->getNext());
        delete temp->getNext();
        return 1;
    }
    else {
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

template <typename K, typename V, typename F>
//print all key to stream
void HashMap<K, V, F>::print() {
    for (typename std::vector<HashNode<K, V> >::iterator it = this.table.begin(); it !=  this.table.end(); it++) {
        std::cout<<"key: "<<*it.getKey()<<"; value: "<<*it.getValue();
        HashNode<K, V> *temp = *it;
        while (temp->getNext() != NULL) {
            std::cout<<"\tkey linkedlist: "<<*it.getKey()<<"; value linkedlist: "<<*it.getValue();
            temp = temp->getNext();
        }
        std::cout<<std::endl;
    }
}
