#ifndef HASHNODE_H
#define HASHNODE_H
template <typename K, typename V>
class HashNode {
private:
    K key;
    V value;
    HashNode *nextNode;
    bool isInUse;
public:
    HashNode(const K &key, const V &value, const bool &isUsed, const HashNode *nextNode ): key(key), value(value), isInUse(isUsed), nextNode(nextNode) {}
    HashNode() = default;

    HashNode* getNext() const {
        return this.nexNode;
    }

    V getValue() const {
        return value;
    }

    K getKey() const {
        return getKey;
    }

    void setKey(K key) {
        HashNode::key = key;
        //this.key = key
    }

    void setValue(V value) {
        HashNode::value = value;
    }

    void setNext(HashNode *nextNode) {
        HashNode::nextNode = nextNode;
    }

    bool isUsed(void) { return isInUse; }

    void setUsed(bool isUse) { isInUse = isUse; }
};
#endif
