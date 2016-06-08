#include "HashMap"
#include <climits>
#include <iostream>

bool HashMap::extend() {
    //find the prime number larger than 2*current_table_size
    int new_size = TABLE_SIZE * 2 + 1
    for (; new_size < MAX_INT; new_size++)
        for (int j = 2; j < (int)sqrt(i); j++)
            if (new_size % j == 0)
                break;
    if (new_size == MAX_INT)
        return false;
    //resize table to this size
    this.table.resize(new_size, 0);
    return true;

}
HashMap::~HashMap() {
    //iterator all element in table
    for (std::vector::iterator it = this.table.begin(); it != this.table.end(); it++) {
        //get a node in table
        HashNode *temp = *it;
        while (temp != NULL) {
            HashNode *temp2 = temp;
            //get next node
            temp = temp.getNext()
            //delete current node
            delete *temp2;
        }
    }
}
//return true if push back successful else return false
bool HashMap::push_back(const K &key, const V &value) {
    unsigned int index = this.hashFunc(key);
    //if not colusion
    if (!this.table[index].isUsed()) {
        this.table[index].setKey(key);
        this.table[index].setValue(value);
        this.table[index].setUsed(true);
    }
    //collision
    else
    {
        this.table[index].nextNode = new HashNode(key, value, true, NULL);
        if (this.table[index].nextNode == NULL)
            return false;
    }
    this.numElements++;
    if (this.numElements/TABLE_SIZE > this.factor)
        return this.extend()
    return true;
}
V HashMap::get(const K &key) {
    unsigned int index = this.hashFunc(key);
    HashNode *temp = this.table[index];
    while (temp != NULL) {
        if (temp.key == key)
            return temp.V;
        temp = temp.getNext();
    }
    if (temp == NULL)
        return NULL;
}
//return 1 if remove successful else return -1, return 0 if key not found
int HashMap::remove(const K &key) {
    unsigned int index = this.hashFunc(key);
    HashNode *temp = this.table[index];
    if (temp.key == key) {
        temp.key = temp.getNext().getKey();
        temp.value = temp.getNext().getValue();
        temp.nextNode = temp.getNext();
        delete temp.getNext();
        return 1;
    }
    else {
        while (temp.getNext() != NULL) {
            HashNode *prev = temp;
            temp = temp.getNext()
            if (temp.key == key) {
                prev.setNext(temp.getNext());
                delete temp;
                return 1;
                }
            }
        return 0;
        }
    return -1;
}
//print all key to stream
void HashMap::print() {
    for (std::vector::iterator it = this.table.begin(); it !=  this.table.end(); it++) {
        std::cout<<"key: "<<*it.getKey()<<"; value: "<<*it.getValue();
        HashNode *temp = *it;
        while (temp->getNext() != NULL) {
            std::cout<<"\tkey linkedlist: "<<*it.getKey()<<"; value linkedlist: "<<*it.getValue();
            temp = temp->getNext();
        }
        std::cout<<std::endl;
    }
}
