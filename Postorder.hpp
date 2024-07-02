//Lbalad13@gmail.com
//211801220 
//Liraz balas
#ifndef POST_ORDER_ITERATOR_HPP
#define POST_ORDER_ITERATOR_HPP
#include <stack>
#include "node.hpp"

template <typename T>
class post_order_iterator {
private:
    std::stack<Node<T>*> stack_postorder;
    Node<T>* temp;
    int k;

    void pushLeftmostPath(Node<T>* t) {
        while (t) {
            stack_postorder.push(t);
            if (!t->childrens_node.empty()) {t = t->childrens_node[0].get();} 
            else {break;}
        }
    }

public:
    post_order_iterator(Node<T>* root, int k) : temp(nullptr), k(k) {
        if (root) {
            if (k == 2) {pushLeftmostPath(root);} 
            else {stack_postorder.push(root);}
        }
        ++(*this);
    }

    post_order_iterator& operator++() {
        if (k == 2) {
            if (!stack_postorder.empty()) {
                Node<T>* t = stack_postorder.top();
                stack_postorder.pop();
                if (!stack_postorder.empty()) {
                    Node<T>* p = stack_postorder.top();
                    if (p->childrens_node.size() > 1 && t == p->childrens_node[0].get()) {
                        pushLeftmostPath(p->childrens_node[1].get());
                    }
                }
                temp = t;
            } 
            else {temp = nullptr;}
        } 
        else {
            // DFS 
            if (!stack_postorder.empty()) {
                Node<T>* t = stack_postorder.top();
                stack_postorder.pop();
                for (auto it = t->childrens_node.rbegin(); it != t->childrens_node.rend(); ++it) {
                    if (*it) {stack_postorder.push(it->get());}
                }
                temp = t;
            } 
            else{temp = nullptr;}
        }
        return *this;
    }
       bool operator!=(const post_order_iterator& other) const{return temp != other.temp;}
    T& operator*(){return temp->value;}
};


#endif 
