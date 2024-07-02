//Lbalad13@gmail.com
//211801220 
//Liraz balas
#ifndef BFS_ITERATOR_HPP
#define BFS_ITERATOR_HPP
#include <queue>
#include "node.hpp"

//declaration
template <typename T>
class bfs_iterator {
private:
    std::queue<Node<T>*> queu_bfs;
    Node<T>* temp;

public:
    bfs_iterator(Node<T>* root);
    bool operator!=(const bfs_iterator& other) const;
    T& operator*();
    bfs_iterator& operator++();
};

//implementation
template <typename T>
bfs_iterator<T>::bfs_iterator(Node<T>* root) : temp(root) {
    if (root) {queu_bfs.push(root);}
}


template <typename T>
bfs_iterator<T>& bfs_iterator<T>::operator++() {
    if (!queu_bfs.empty()) {
        Node<T>* f = queu_bfs.front();
        queu_bfs.pop();
        for (auto& c : f->childrens_node) {
            if (c) {queu_bfs.push(c.get()); }
        }

        if (!queu_bfs.empty()){temp = queu_bfs.front();} 
        else { temp = nullptr;}
    }
    return *this;
}

template <typename T>
bool bfs_iterator<T>::operator!=(const bfs_iterator& other) const {return temp != other.temp;}

template <typename T>
T& bfs_iterator<T>::operator*(){return temp->value;}


#endif 
