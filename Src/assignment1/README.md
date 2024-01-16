# Bag of Marbles

To model a bag of marbles in a C++ program, you can create a class.

## Properties:

* A container (e.g., an array, vector, or linked list) to store the marbles.
* An integer variable to keep track of the number of marbles in the bag.

## Methods:

* addMarble(): Adds a new marble to the bag. This method takes parameters representing a marble and adds it to the container.
* removeMarble(): Removes a random marble from the bag.
* isEmpty(): Checks if the bag is empty.
* getNumberOfMarbles(): Returns the number of marbles in the bag.

## Tests

* Create an empty bag and verify that isEmpty() returns true.
* Add a marble with known properties using addMarble() and verify that getNumberOfMarbles() returns 1.
* Remove the marble using removeMarble() and verify that getNumberOfMarbles() returns 0.
* Try to remove a marble from an empty bag and verify that it handles the case by returning an error code or throwing an exception.