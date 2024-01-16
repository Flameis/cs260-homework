# Bag of Marbles

To model a bag of marbles in a C++ program, you can create a class.

## Properties:

* A container (e.g., an array, vector, or linked list) to store the marbles.
* An integer variable to keep track of the number of marbles in the bag.

## Methods:

* Line 15: addMarble(): Adds a new marble to the bag. This method takes parameters representing a marble and adds it to the container.
* removeMarble(): Removes a random marble from the bag.
* isEmpty(): Checks if the bag is empty.
* getNumberOfMarbles(): Returns the number of marbles in the bag.

## Tests

* Create an empty bag and verify that isEmpty() returns true.
* Add a marble with known properties using addMarble() and verify that getNumberOfMarbles() returns 1.
* Remove the marble using removeMarble() and verify that getNumberOfMarbles() returns 0.
* Try to remove a marble from an empty bag and verify that it handles the case by returning an error code or throwing an exception.

## Met Requirements

1. some way of representing marbles (what makes up a marble in this program?),

line 12 marbles variable

2. a way to add new marbles into the bag (how do we interact with marbles and add them into the bag?),

line 15 addMarble()

3. a way to remove a marble out of the bag (perhaps a random marble taken out of the bag?),

line 19 removeMarble()

4. a few ways that we could use to show that our implementation should be working correctly (Tests)

lines 39-60 (create a bag and verify empty, add a marble and check number of marbles, remove a marble and check number of marbles, remove a marble and recieve error message)