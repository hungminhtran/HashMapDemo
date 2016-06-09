template <typename K, typename V>
class HashNode {
private:
    K key;
    V value;
    HashNode *nextNode;
    bool isInUse;
public:
    HashNode(const K &key, const V &value, const bool &isUsed, const HashNode *nextNode ): key(key), value(value), isInUse(isUsed), nextNode(nextNode) {}
//    HashNode() = default;

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

    HashNode* getNext() const {
        return this.nexNode;
    }

    void setNext(HashNode *nextNode) {
        HashNode::nextNode = nextNode;
    }

    bool isUsed(void) { return isInUse; }

    void setUsed(bool isUse) { this->isInUse = isUse; }
};