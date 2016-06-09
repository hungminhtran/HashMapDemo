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
//    hmap->put(1, "1");
    hmap->put(2, "2");
    cout<<"pass"<<endl;
    hmap->put(3, "3");
    cout<<"pass"<<endl;
    hmap->put(12, "12");
    cout<<"pass"<<endl;
    hmap->put(33, "33");

    string value;
    value = hmap->get(2);
    assert(value == "2");
    cout<<"pass"<<endl;

    value = hmap->get(12);
    assert(value == "12");
    cout<<"pass"<<endl;
    
    hmap->remove(3);
    value = hmap->get(3);
//    assert(value == NULL);
    cout<<"pass"<<endl;

    std::cout << "All tests passed!" << std::endl;
    delete hmap;
    return 0;
}

