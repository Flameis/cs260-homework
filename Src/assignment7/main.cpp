#include <iostream>
#include <string>

#include "hashtable.cpp"

using std::cout;
using std::endl;

int main(int argc, char **argv) {
    Hashtable ht;

    // empty getSize test
    cout << "getSize() on empty hashtable: " << ht.getSize() << " (0 expected)" << endl;

    // empty default getCapacity test
    cout << "getCapacity() on empty hashtable: " << ht.getCapacity() << " (16 expected)" << endl;

    // empty find test
    cout << "find hello in empty hashtable: \"" << ht.find("hello") << "\" (\"hello Not Found\" is expected)" << endl;

    // add test
    cout << "insert hello:world into hashtable" << endl;
    ht.add("hello");
    ht.add("world");

    // getSize test after add
    cout << "getSize() after add: " << ht.getSize() << " (2 expected)" << endl;

    // getCapacity test after insert
    cout << "getCapacity() after insert: " << ht.getCapacity() << " (16 expected)" << endl;

    // find test after insert
    cout << "find hello in hashtable: \"" << ht.find("hello") << "\" (\"hello\" is expected)" << endl;

    // remove test
    ht.remove("hello");
    cout << "remove hello from hashtable" << endl;

    // find test after removal
    cout << "find hello in hashtable: \"" << ht.find("hello") << "\" (\"hello Not Found\" is expected)" << endl;

    // getSize test after remove
    cout << "getSize() after remove: " << ht.getSize() << " (1 expected)" << endl;

    // getCapacity test after remove
    cout << "getCapacity() after remove: " << ht.getCapacity() << " (16 expected)" << endl;

    return 0;
}