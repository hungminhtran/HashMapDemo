#ifndef KEYHASH_H
#define KEYHASH_H
template <typename K, typename S>
 struct KeyHash {
     unsigned int operator () (const K &key, const S &TABLE_SIZE ) const {
         return key % TABLE_SIZE;
     }
 };
#endif
