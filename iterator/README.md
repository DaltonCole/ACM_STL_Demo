# Iterator

An iterator is any object that, pointing to some element in a range of elements (such as an array or a container), has the ability to iterate through the elements of that range using a set of operators (with at least the increment (++) and dereference (*) operators).

## Notes:

### Iterators are classified into 5 categories

Random Access -> Bidirectional -> Forward -> Input, Output

Most limited -> Lease limited

Every higher level iterator has the functionality of the lower level iterators.

#### Random Access

*  Can access ranges non-sequentially
*  Most like a standard pointer

#### Bidirectional

*  Can iterate both forwards and backwards

#### Forward

*  Can only iterate forward

#### Input and Output

*  Most limited
*  Can perform sequential single-pass input or output operations 

## More information

http://www.cplusplus.com/reference/iterator/

## How to run:
```
g++ -std=c++11 iterator.cpp
./a.out
```