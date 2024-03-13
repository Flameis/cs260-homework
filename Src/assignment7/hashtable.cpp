#include <iostream>
#include "hashtable.h"

// Simple Hashtable implementation
Hashtable::Hashtable(int initialSize) {
    size = 0;
    capacity = initialSize;

    values = new string[capacity];
}

Hashtable::~Hashtable() {
    delete[] values;
}

// Find the index by taking a seed and multiplying it by the unicode value of each character in the key, then modding by the table capacity.
int Hashtable::hash(string key)
{
    int seed = 131; 
    unsigned long hash = 0;
    // for each character in the key, multiply the hash by the seed and add the unicode value of the character
    for(int i = 0; i < key.length(); i++)
    {
        hash = (hash * seed) + key[i];
    }
    // return the hash modded by the capacity
    return hash % capacity;
}

// Add a new key to the hashtable
int Hashtable::add(string key) {
    int index = hash(key);
    // if the index is already taken, find the next available index
    while (values[index] != "") {
        index = (index + 1) % capacity;
    }
    // add the key to the index
    values[index] = key;
    size++;
    return index;
}

// Remove a key from the hashtable
string Hashtable::remove(string oldKey) {
    int index = hash(oldKey);
    // if the index is already taken, find the next available index
    while (values[index] != "") {
        // if the value at the index is the key to be removed, remove it and return the key
        if (values[index] == oldKey) {
            string temp = values[index];
            values[index] = "";
            size--;
            return temp+" Removed";
        }
        // if the value at the index is not the key to be removed, find the next available index
        index = (index + 1) % capacity;
    }
    return "";
}

// Check if a key is in the hashtable
string Hashtable::find(string key) {
    int index = hash(key);
    // if the index is already taken, find the next available index
    while (values[index] != "") {
        // if the value at the index is the key, return the key
        if (values[index] == key) {
            return values[index];
        }
        // if the value at the index is not the key, find the next available index
        index = (index + 1) % capacity;
    }
    return key+" Not Found";
}

// Return the number of keys in the hashtable
int Hashtable::getSize() {
    return size;
}

// Return the capacity of the hashtable
int Hashtable::getCapacity() {
    return capacity;
}

// int main()
// {
//     Hashtable table;
    
//     std::cout << table.getSize() << std::endl;
//     table.add("hello");
//     table.add("world");
    
//     std::cout << table.find("hello") << std::endl;
//     std::cout << table.find("world") << std::endl;
//     std::cout << table.find("foo") << std::endl;

//     std::cout << table.remove("hello") << std::endl;
//     std::cout << table.find("hello") << std::endl;
//     std::cout << table.getSize() << std::endl;
//     std::cout << table.getCapacity() << std::endl;
//     return 0;  
// }