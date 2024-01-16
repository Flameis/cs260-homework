/*
Author: Luke Scovel X00513112
Date: 1/15/2023 */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class BagOfMarbles {
private:
    std::vector<std::string> marbles;
    
public:
    void addMarble(const std::string& marble) {
        marbles.push_back(marble);
    }
    
    void removeMarble() {
        if (!marbles.empty()) {
            srand(time(0));
            int randomIndex = rand() % marbles.size();
            marbles.erase(marbles.begin() + randomIndex);
        }
        else {
            std::cout << "Error, bag is already empty." << std::endl;
        }
    }
    
    bool isEmpty() const {
        return marbles.empty();
    }
    
    int getNumberOfMarbles() const {
        return marbles.size();
    }
};

int main() {
    BagOfMarbles bag;
    
    // Create an empty bag and verify that isEmpty() returns true.
    if (bag.isEmpty()) {
        std::cout << "Bag is empty." << std::endl;
    } else {
        std::cout << "Bag is not empty." << std::endl;
    }
    
    // Add a marble with known properties using addMarble() and verify that getNumberOfMarbles() returns 1.
    bag.addMarble("Red");
    std::cout << "Number of marbles in the bag: " << bag.getNumberOfMarbles() << std::endl;
    
    // Remove the marble using removeMarble() and verify that getNumberOfMarbles() returns 0.
    bag.removeMarble();
    std::cout << "Number of marbles in the bag: " << bag.getNumberOfMarbles() << std::endl;
    
    // Try to remove a marble from an empty bag and verify that it handles the case by returning an error code or throwing an exception.
    bag.removeMarble();
    
    return 0;
}

