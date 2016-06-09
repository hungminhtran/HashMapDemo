#include "HashMap.h"
#include <iostream>
#include <string>
#include <assert.h>

using namespace std;
struct MyKeyHash {
    unsigned long operator()(const int& k) const
    {
        return k % 10;
    }
};


int main() {
    HashMap<int, std::string, struct MyKeyHash > *hmap = new HashMap<int, std::string, struct MyKeyHash >();
    hmap->test();
    ;
    hmap->put(1, "1");
    
    hmap->put(2, "2");
    
    hmap->put(3, "3");
    
    hmap->put(12, "112");
    
    hmap->put(33, "333");
    
    hmap->print();
    
    string value;
    hmap->get(2, value);
    assert(value == "2");
   

    hmap->get(12, value);
    assert(value == "112");
   
    
    hmap->remove(3);
    if (hmap->get(3, value) == 0)
        assert(value == "");
   

    std::cout << "All tests passed!" << std::endl;
    delete hmap;
    return 0;
}

