#include <vector>
#include <iostream>
using namespace std;
const int MAX_1 = 10;
const int MAX_2 = 8;
int main() {
    vector<int> table(MAX_1);
    for (int i = 0; i < MAX_2; i++)
        table.push_back(i);

    for (int i = 0; i < MAX_2; i++)
        cout<<table[i]<<" ";
    cout<<endl;
    for (vector<int>::iterator it = table.begin(); it < table.end(); it++) {
        cout<<*it<<" ";
    }
    cout<<endl;
    for (int i = 0; i < MAX_2; i++)
        cout<<table[i]<<" ";
    cout<<endl;
}
