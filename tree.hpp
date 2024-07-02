//Lbalad13@gmail.com
//211801220 
//Liraz balas
#ifndef TREE_HPP
#define TREE_HPP

#include "node.hpp"
#include "Bfs.hpp"
#include "Dfs.hpp"
#include "Preorder.hpp"
#include "Postorder.hpp"
#include "Inorder.hpp"
#include "Heap.hpp"
#include <queue>
#include <vector>
#include <algorithm>
#include <stdexcept>

template <typename T>
class tree {
private:
    std::unique_ptr<Node<T>> root;
    int k;

public:
//constractor
//default k=2 binary tree
    tree(int k = 2) : root(nullptr), k(k) {}
    
//add root
    void add_root(const T& value) {root = std::make_unique<Node<T>>(value, k);}
    
//add sub node
    void add_sub_node(const T& parent_value, const T& child_value) {
        if (!root) {throw std::runtime_error("Tree empty error");}
        std::queue<Node<T>*> q;
        q.push(root.get());
        while (!q.empty()) {
            Node<T>* f = q.front();
            q.pop();
            if (f->value == parent_value) {
                for (int i = 0; i < k; ++i) {
                    if (!f->childrens_node[i]) {
                        f->childrens_node[i] = std::make_unique<Node<T>>(child_value, k);
                        return;
                    }
                }
                throw std::runtime_error("Number childrens is bigger that k");
            }

            for (auto& ch : f->childrens_node) {
                if (ch){q.push(ch.get());}
            }
        }
        throw std::runtime_error("Error");
    }
    
    
//all begin and end of all iterators
    Node<T>* get_root() const { return root.get();}
    bfs_iterator<T> begin_bfs_scan(){return bfs_iterator<T>(root.get());}
    bfs_iterator<T> end_bfs_scan() {return bfs_iterator<T>(nullptr);}
    dfs_iterator<T> begin_dfs_scan() {return dfs_iterator<T>(root.get());}
    dfs_iterator<T> end_dfs_scan() {return dfs_iterator<T>(nullptr);}
    pre_order_iterator<T> begin_pre_order() {return pre_order_iterator<T>(root.get());}
    pre_order_iterator<T> end_pre_order() {return pre_order_iterator<T>(nullptr);}
    post_order_iterator<T> begin_post_order() {return post_order_iterator<T>(root.get(), k);}
    post_order_iterator<T> end_post_order() {return post_order_iterator<T>(nullptr, k);}
    in_order_iterator<T> begin_in_order() {return in_order_iterator<T>(root, k);}
    in_order_iterator<T> end_in_order() {return in_order_iterator<T>(nullptr, k);}
    heap_iterator<T> begin_heap() {return heap_iterator<T>(root.get(), k);}
    heap_iterator<T> end_heap() {return heap_iterator<T>(nullptr, k);}
    ~tree() = default;
};

#endif 
