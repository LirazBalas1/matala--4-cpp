//Lbalad13@gmail.com
//211801220 
//Liraz balas
#ifndef PRE_ORDER_ITERATOR_HPP
#define PRE_ORDER_ITERATOR_HPP
#include <stack>
#include "node.hpp"


template <typename T>
class pre_order_iterator {
private:
    std::stack<Node<T>*> stack_preorder;
    Node<T>* temp;

public:
    pre_order_iterator(Node<T>* root);
    bool operator!=(const pre_order_iterator& other) const;
    T& operator*();
    pre_order_iterator& operator++();
};

template <typename T>
pre_order_iterator<T>::pre_order_iterator(Node<T>* root) : temp(root) {
    if (root){stack_preorder.push(root);}
}



template <typename T>
pre_order_iterator<T>& pre_order_iterator<T>::operator++() {
    if (!stack_preorder.empty()) {
        Node<T>* t = stack_preorder.top();
        stack_preorder.pop();
        for (auto it = t->childrens_node.rbegin(); it != t->childrens_node.rend(); ++it){
            if (*it){stack_preorder.push(it->get());}
        }

        if (!stack_preorder.empty()){temp = stack_preorder.top();} 
        else{temp = nullptr;}
    }
    return *this;
}
template <typename T>
bool pre_order_iterator<T>::operator!=(const pre_order_iterator& other) const{return temp != other.temp;}

template <typename T>
T& pre_order_iterator<T>::operator*(){return temp->value;}


#endif 
