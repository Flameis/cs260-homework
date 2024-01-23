Author: Luke Scovel X00513112 \
Date: 1/22/2023

# Queue Structure

* Create a Node with data, prev, and next.

* Create a contructor for front and rear

* Create enqueue method with value
    - Make new node with value
    - If empty 
        - make the front and rear the newNode
    - Else
        - Set rear to next node and rear to new node

* Create dequeue Method
    - If empty return
    - If one element
        - Delete element
    - Else 
        - change front to next
        - Delete front

* isEmpty Method

* Getfront method

# List structure
* Create a Node with data, prev, and next.

* Create a LinkedList with head and tail.

* Create a constructor that initializes head and tail to nullptr.

* Create a insert method that takes value and pos.
    - Create a new Node
    - If the list is empty:
        - Set head and tail to newNode.
    - if the position is less than 0:
        - Set newNode's next to head and head's prev to newNode.
        - Set head to newNode.
    - Else:
        - Create a Node called current and set it to head.
        - Create an integer called currentPosition and set it to 0.
        - While current is not nullptr and currentPosition is less than the given position:
            - Move current to the next node.
            - Increment currentPosition.
        - If current is nullptr:
            - Set newNode's prev to tail and tail's next to newNode.
            - Set tail to newNode.
        - Else:
            - Set newNode's prev to current's prev.
            - Set newNode's next to current.
            - Set current's prev's next to newNode.
            - Set current's prev to newNode.

* Create a remove method that takes pos.
    - If the position is less than or equal to 0:
        - Create a temp node and set it to head.
        - Set head to next.
        - If head is not null, set prev to null.
        - Else, set tail to nullptr.
        - Delete temp.
    - Else:
        - Create a Node pointer called current and set it to head.
        - Create an integer called currentPosition and set it to 0.
        - While current is not nullptr and currentPosition is less than the given position:
            - Move current to the next node.
            - Increment currentPosition.
        - If current is null, return.
        - Set current's prev's next to current's next.
        - If current's next is not null, set current's next's prev to current's prev.
        - Else, set tail to current's prev.
        - Delete current.


