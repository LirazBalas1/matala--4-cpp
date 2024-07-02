//Lbalad13@gmail.com
//211801220 
//Liraz balas
#ifndef HEAP_ITERATOR_HPP
#define HEAP_ITERATOR_HPP
#include "node.hpp"
#include <vector>
#include <algorithm>
#include <iostream>


template <typename T>
class heap_iterator {
private:
    std::vector<Node<T>*> my_heap; 
    struct CompareNodes {
        bool operator()(const Node<T>* a, const Node<T>* b) const {return a->value > b->value;}
    };

    void collect_nodes(Node<T>* node) {
        if (node) {
            my_heap.push_back(node);
            for (auto& ch : node->childrens_node) {
                if (ch) {collect_nodes(ch.get());}
            }
        }
    }

public:
    heap_iterator(Node<T>* n, int k) {
        if (k == 2) {
            if (n) {
                collect_nodes(n);
                std::make_heap(my_heap.begin(), my_heap.end(), CompareNodes());
            }
        } 
        else if (k > 2) {std::cout << "Error .The k must to be 2." << std::endl;}
    }
 
    heap_iterator& operator++() {
        std::pop_heap(my_heap.begin(), my_heap.end(), CompareNodes());
        my_heap.pop_back();
        return *this;
    }

    heap_iterator& operator=(const heap_iterator& other) {
        if (this != &other) {my_heap = other.my_heap;}
        return *this;
    }

    bool operator==(const heap_iterator& other) const{return my_heap == other.my_heap;}
    bool operator!=(const heap_iterator& other) const {return !(*this == other);}
    T& operator*() const {return my_heap.front()->value;}
    T* operator->() const { return &(my_heap.front()->value);}
};

#endif 
