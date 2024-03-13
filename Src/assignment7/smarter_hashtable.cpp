#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

// Define a structure for key-value pairs
struct KeyValuePair {
    string key;
    string value;
};

class Hashtable {
private:
    int capacity;
    vector<list<KeyValuePair>> table;

    // Hash function 1
    int hash1(string key) {
        int seed = 131;
        unsigned long hash = 0;
        for (int i = 0; i < key.length(); i++) {
            hash = (hash * seed) + key[i];
        }
        return hash % capacity;
    }

    // Hash function 2
    int hash2(string key) {
        // Prime number slightly smaller than the capacity
        return 13 - (hash1(key) % 13);
    }

public:
    // Constructor
    Hashtable(int initialSize) {
        capacity = initialSize;
        table.resize(capacity);
    }

    // Destructor
    ~Hashtable() {}

    // Add a new key-value pair to the hashtable
    void add(string key, string value) {
        int index = hash1(key);
        KeyValuePair pair = {key, value};
        table[index].push_back(pair);
    }

    // Remove a key-value pair from the hashtable
    void remove(string key) {
        int index = hash1(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->key == key) {
                table[index].erase(it);
                break;
            }
        }
    }

    // Find a value by key in the hashtable
    string find(string key) {
        int index = hash1(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->key == key) {
                return it->value;
            }
        }
        return key + " Not Found";
    }

    // Get the number of elements in the hashtable
    int getSize() {
        int size = 0;
        for (int i = 0; i < capacity; ++i) {
            size += table[i].size();
        }
        return size;
    }

    // Get the capacity of the hashtable
    int getCapacity() {
        return capacity;
    }
};

int main() {
    Hashtable table(10);

    table.add("key1", "value1");
    table.add("key2", "value2");
    table.add("key3", "value3");

    cout << "Size: " << table.getSize() << endl;
    cout << "Capacity: " << table.getCapacity() << endl;

    cout << "Finding key2: " << table.find("key2") << endl;

    table.remove("key2");

    cout << "Size after removing key2: " << table.getSize() << endl;

    cout << "Finding key2 after removal: " << table.find("key2") << endl;

    return 0;
}