#Data Structure: MAP 
**Using map of vector and map of map.**
Problem: having a vector of elemnts e.g. 1 2 3 4 3 2 5 6.. We want to count all ordered paires such as (a, b) whose elements are in the vector and index(a)<index(b)
(1,2) (1, 3) (1,4)(1, 2) (1, 5) (1, 6)
(2,3)(2,4) (2,5) (2, 6)
(3,4) (3,3) (3, 2) (3,5) (3,6)
(2, 5) (2,6)
(5,6)
mapofvector.cpp
