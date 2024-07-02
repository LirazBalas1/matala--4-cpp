//Lbalad13@gmail.com
//211801220 
//Liraz balas
#ifndef IN_ORDER_ITERATOR_HPP
#define IN_ORDER_ITERATOR_HPP
#include <stack>
#include <memory>
#include "node.hpp"

template <typename T>
class in_order_iterator {
private:
    std::stack<Node<T>*> stack_heap;
    Node<T>* temp;
    int k;

    void push_left(Node<T>* t) {
        while (t) {
            stack_heap.push(t);
            if (!t->childrens_node.empty()) {t = t->childrens_node[0].get();} 
            else {break;}
        }
    }

public:
    in_order_iterator(const std::unique_ptr<Node<T>>& t, int k) : temp(nullptr), k(k) {
        if (k == 2) {push_left(t.get());} 
        else if (t) {stack_heap.push(t.get());}
        ++(*this); 
    }
     in_order_iterator& operator++() {
        if (k == 2) {
            if (temp && temp->childrens_node.size() > 1) {push_left(temp->childrens_node[1].get());}
            if (!stack_heap.empty()) {
                temp = stack_heap.top();
                stack_heap.pop();
            } 
            else {temp = nullptr;}
        }
        else {
            //DFS
            if (!stack_heap.empty()) {
                Node<T>* t = stack_heap.top();
                stack_heap.pop();
                temp = t;
                for (auto it = t->childrens_node.rbegin(); it != t->childrens_node.rend(); ++it) {
                    if (*it) {stack_heap.push(it->get());}
                }
            } 
            else {temp = nullptr;}
        }
        return *this;
    }


    bool operator!=(const in_order_iterator& other) const {return temp != other.temp;}
    T& operator*(){return temp->value;}
   

};

#endif 
