static int TABLE_SIZE = 11; //should be prime for better performace
template <typename K>
 struct KeyHash {
     unsigned int operator () (const K &key) const {
         return key % TABLE_SIZE;
     }
 };