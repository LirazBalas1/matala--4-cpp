//Lbalad13@gmail.com
//211801220 
//Liraz balas
#ifndef DFS_ITERATOR_HPP
#define DFS_ITERATOR_HPP
#include <stack>
#include "node.hpp"

//declaration 
template <typename T>
class dfs_iterator {
private:
    std::stack<Node<T>*> stack_dfs;
    Node<T>* temp;
public:
    dfs_iterator(Node<T>* root);
    bool operator!=(const dfs_iterator& other) const;
    T& operator*();
    dfs_iterator& operator++();   
    
};

//implementation
template <typename T>
dfs_iterator<T>::dfs_iterator(Node<T>* root) : temp(root) {
    if (root) {stack_dfs.push(root);}
}

template <typename T>
dfs_iterator<T>& dfs_iterator<T>::operator++() {
    if (!stack_dfs.empty()) {
        Node<T>* t = stack_dfs.top();
        stack_dfs.pop();
        for (auto it = t->childrens_node.rbegin(); it != t->childrens_node.rend(); ++it) {
            if (*it) {stack_dfs.push(it->get());}
        }

        if (!stack_dfs.empty()) {temp = stack_dfs.top();} 
        else {temp = nullptr;}
    }
    return *this;
}

template <typename T>
bool dfs_iterator<T>::operator!=(const dfs_iterator& other) const {return temp != other.temp;}


template <typename T>
T& dfs_iterator<T>::operator*() {return temp->value;}


#endif 
