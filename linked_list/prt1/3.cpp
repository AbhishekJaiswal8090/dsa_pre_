#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

// The conclusion of this class is that there exist an list STL in c++ which
// lets you use linked list without scratch implementation

int main()
{
    std::list<int> ll;
    ll.push_back(10);
    ll.push_front(23);
    ll.push_back(45);
    ll.push_front(7);
    ll.pop_front();
}
