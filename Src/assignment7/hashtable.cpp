#include <iostream>
#include <vector>

class SimpleHashtable {
public:
    std::vector<int> table;

    SimpleHashtable(int size) {
        table.resize(size, -1);
    }

    int hash(int value) {
        return value % table.size();
    }

    void insert(int value) {
        int index = hash(value);
        table[index] = value;
    }

    bool contains(int value) {
        int index = hash(value);
        return table[index] == value;
    }

    void remove(int value) {
        int index = hash(value);
        if (table[index] == value) {
            table[index] = -1;
        }
    }
};

int main() {
    SimpleHashtable hashtable(10);

    hashtable.insert(5);
    hashtable.insert(15);
    hashtable.insert(25);

    std::cout << "Contains 5: " << hashtable.contains(5) << std::endl;
    std::cout << "Contains 15: " << hashtable.contains(15) << std::endl;
    std::cout << "Contains 25: " << hashtable.contains(25) << std::endl;

    // List whole table hashes
    for (int i = 0; i < hashtable.table.size(); i++) {
        std::cout << "Index " << i << ": " << hashtable.table[i] << std::endl;
    }
    

    hashtable.remove(15);

    std::cout << "Contains 15 after removal: " << hashtable.contains(15) << std::endl;

    return 0;
}