//Lbalad13@gmail.com
//211801220 
//Liraz balas
#ifndef NODE_HPP
#define NODE_HPP
#include <vector>
#include <memory>

//declaration
template <typename T>
class Node {
public:
     T value;
    std::vector<std::unique_ptr<Node<T>>> childrens_node;
    Node(T val, int k);
};

//implementation
template <typename T>
Node<T>::Node(T val, int k) : value(val), childrens_node(k) {}

#endif 
