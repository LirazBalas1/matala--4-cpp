//Lbalad13@gmail.com
//211801220 
//Liraz balas
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "tree.hpp"
#include "complex.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


TEST_CASE("Tree with k-arry") {
    tree<int> t(3);
    t.add_root(2);
    t.add_sub_node(2, 4);
    t.add_sub_node(2, 6);
    t.add_sub_node(2, 8);
    Node<int>* root = t.get_root();

    CHECK(t.get_root()->value == 2);
    CHECK(root->childrens_node[0]->value == 4);
    CHECK(root->childrens_node[1]->value == 6);
    CHECK(root->childrens_node[2]->value == 8);
}


TEST_CASE("Tree with number children great than k") {
    tree<int> t(2);
    t.add_root(1);
    t.add_sub_node(1, 2);
    t.add_sub_node(1, 3);

    CHECK_THROWS_AS(t.add_sub_node(1, 4), std::runtime_error); 
}



TEST_CASE("Tree with int") {
    tree<int> t(2);
    t.add_root(1);
    t.add_sub_node(1, 2);
    t.add_sub_node(1, 3);

    Node<int>* root = t.get_root();
    CHECK(t.get_root()->value == 1);
    CHECK(root->childrens_node[0]->value == 2);
    CHECK(root->childrens_node[1]->value == 3);
}


TEST_CASE("Tree with double") {
    tree<double> t(3);
    t.add_root(1.1);
    t.add_sub_node(1.1, 2.2);
    t.add_sub_node(1.1, 3.3);
    t.add_sub_node(1.1, 4.4);
    Node<double>* root = t.get_root();

    CHECK(t.get_root()->value == 1.1);
    CHECK(root->childrens_node[0]->value == 2.2);
    CHECK(root->childrens_node[1]->value == 3.3);
    CHECK(root->childrens_node[2]->value == 4.4);
}


TEST_CASE("Tree with complex number ") {
    tree<Complex> t(3);
    t.add_root(Complex(1, 1));
    t.add_sub_node(Complex(1, 1), Complex(2, 2));
    t.add_sub_node(Complex(1, 1), Complex(3, 3));
    Node<Complex>* root = t.get_root();

    CHECK(t.get_root()->value == Complex(1, 1));
    CHECK(root->childrens_node[0]->value == Complex(2, 2));
}



TEST_CASE("Iterator BFS(Int)") {
    tree<int> t(3);
    t.add_root(1);
    t.add_sub_node(1, 2);
    t.add_sub_node(1, 3);
    t.add_sub_node(1, 4);
    t.add_sub_node(2, 5);
    t.add_sub_node(2, 6);

    std::vector<int> ans = {1, 2, 3, 4, 5, 6};
    int i = 0;
    for (auto it = t.begin_bfs_scan(); it != t.end_bfs_scan(); ++it) {
        CHECK(*it == ans[i]);
        ++i;
    }
}


TEST_CASE("Iterator BFS (double)") {
    tree<double> t(3);
    t.add_root(1.1);
    t.add_sub_node(1.1, 2.2);
    t.add_sub_node(1.1, 3.3);
    t.add_sub_node(1.1, 4.4);
    t.add_sub_node(2.2, 5.5);
    t.add_sub_node(2.2, 6.6);
    t.add_sub_node(2.2, 7.7);

    std::vector<double> ans = {1.1, 2.2, 3.3, 4.4, 5.5,6.6,7.7};
    int i = 0;
    for (auto it = t.begin_bfs_scan(); it != t.end_bfs_scan(); ++it) {
        CHECK(*it == ans[i]);
        ++i;
    }
}

TEST_CASE("Iterator BFS(complex)") {
    tree<Complex> t(3);
    t.add_root(Complex(1, 1));
    t.add_sub_node(Complex(1, 1), Complex(2, 2));
    t.add_sub_node(Complex(1, 1), Complex(3, 3));
    t.add_sub_node(Complex(1, 1), Complex(4, 4));
    t.add_sub_node(Complex(2, 2), Complex(5, 5));
    t.add_sub_node(Complex(2, 2), Complex(6, 6));
    t.add_sub_node(Complex(2, 2), Complex(7, 7));
    t.add_sub_node(Complex(3, 3), Complex(8, 8));
    t.add_sub_node(Complex(4, 4), Complex(9, 9));
    t.add_sub_node(Complex(4, 4), Complex(10, 10));
    
    std::vector<Complex> ans = {Complex(1, 1), Complex(2, 2), Complex(3, 3), Complex(4, 4), Complex(5, 5), Complex(6, 6),Complex(7, 7),Complex(8, 8),Complex(9, 9),Complex(10, 10)};
    int i = 0;
    for (auto it = t.begin_bfs_scan(); it != t.end_bfs_scan(); ++it) {
        CHECK(*it == ans[i]);
        ++i;
    }
}

TEST_CASE("Postorder(Int)") {
    tree<int> t(2);
    t.add_root(1);
    t.add_sub_node(1, 2); 
    t.add_sub_node(1, 3);
    t.add_sub_node(2, 4); 
    t.add_sub_node(2, 5); 
    t.add_sub_node(3, 6);
    t.add_sub_node(3, 7); 

    std::vector<int> ans5 = {4, 5, 2, 6, 7, 3, 1};
    int i = 0;
    for (auto it = t.begin_post_order(); it != t.end_post_order(); ++it) {
        CHECK(*it == ans5[i]);
        ++i;
    }
}

TEST_CASE("PostOrder(double)") {
    tree<double> t(2);
    t.add_root(1.1);
    t.add_sub_node(1.1, 2.2); 
    t.add_sub_node(1.1, 3.3); 
    t.add_sub_node(2.2, 4.4); 
    t.add_sub_node(2.2, 5.5); 
    t.add_sub_node(3.3, 6.6);
    t.add_sub_node(3.3, 7.7);

    std::vector<double> ans5 = {4.4, 5.5, 2.2, 6.6, 7.7, 3.3, 1.1};
    int i = 0;
    for (auto it = t.begin_post_order(); it != t.end_post_order(); ++it) {
        CHECK(*it == ans5[i]);
        ++i;
    }
}
TEST_CASE("Postorder (string)") {
    tree<std::string> t(2);
    t.add_root("a");
    t.add_sub_node("a", "b");
    t.add_sub_node("a", "c");
    t.add_sub_node("b", "d");
    t.add_sub_node("b", "e");
    t.add_sub_node("c", "f");
    t.add_sub_node("c", "g");

    std::vector<std::string> ans3 = {"d", "e", "b", "f", "g","c","a"};
    int i = 0;
    for (auto it = t.begin_post_order(); it != t.end_post_order(); ++it) {
        CHECK(*it == ans3[i]);
        ++i;
    }
}


TEST_CASE("PostOrder(complex)") {
    tree<Complex> t(2);
    t.add_root(Complex(1, 1));
    t.add_sub_node(Complex(1, 1), Complex(2, 2)); 
    t.add_sub_node(Complex(1, 1), Complex(3, 3)); 
    t.add_sub_node(Complex(2, 2), Complex(4, 4)); 
    t.add_sub_node(Complex(3, 3), Complex(6, 6)); 

    std::vector<Complex> ans5 = {Complex(4, 4), Complex(2, 2), Complex(6, 6), Complex(3, 3), Complex(1, 1)};
    int i = 0;
    for (auto it = t.begin_post_order(); it != t.end_post_order(); ++it) {
        CHECK(*it == ans5[i]);
        ++i;
    }
}

TEST_CASE("Preorder (string)") {
    tree<std::string> t(2);
    t.add_root("a");
    t.add_sub_node("a", "b");
    t.add_sub_node("a", "c");
    t.add_sub_node("b", "d");
    t.add_sub_node("b", "e");
    t.add_sub_node("c", "f");
    t.add_sub_node("c", "g");

    std::vector<std::string> ans3 = {"a", "b", "d", "e", "c","f","g"};
    int i = 0;
    for (auto it = t.begin_pre_order(); it != t.end_pre_order(); ++it) {
        CHECK(*it == ans3[i]);
        ++i;
    }
}



TEST_CASE("Preorder(double)") {
    tree<double> t(3);
    t.add_root(1.1);
    t.add_sub_node(1.1, 2.2);
    t.add_sub_node(1.1, 3.3);
    t.add_sub_node(1.1, 4.4);
    t.add_sub_node(2.2, 5.5);
    t.add_sub_node(2.2, 6.6);
    t.add_sub_node(3.3, 7.7);
    t.add_sub_node(3.3, 8.8);

    std::vector<double> ans2 = {1.1, 2.2, 5.5, 6.6, 3.3, 7.7,8.8,4.4};
    int i = 0;
    for (auto it = t.begin_pre_order(); it != t.end_pre_order(); ++it) {
        CHECK(*it == ans2[i]);
        ++i;
    }
}



TEST_CASE("Preorder (Complex))") {
    tree<Complex> t(3);
    t.add_root(Complex(1, 1));
    t.add_sub_node(Complex(1, 1), Complex(2, 2));
    t.add_sub_node(Complex(1, 1), Complex(3, 3));
    t.add_sub_node(Complex(1, 1), Complex(4, 4));
    t.add_sub_node(Complex(2, 2), Complex(5, 5));
    t.add_sub_node(Complex(2, 2), Complex(6, 6));
    t.add_sub_node(Complex(3, 3), Complex(7, 7));
    t.add_sub_node(Complex(3, 3), Complex(8, 8));

    std::vector<Complex> ans2 = {Complex(1, 1), Complex(2, 2), Complex(5, 5), Complex(6, 6), Complex(3, 3),Complex(7, 7) ,Complex(8, 8),Complex(4, 4)};
    int i = 0;
    for (auto it = t.begin_pre_order(); it != t.end_pre_order(); ++it) {
        CHECK(*it == ans2[i]);
        ++i;
    }
}


TEST_CASE("Inorder (int)") {
    tree<int> t(2);
    t.add_root(1);
    t.add_sub_node(1, 2);
    t.add_sub_node(1, 3);
    t.add_sub_node(2, 4);
    t.add_sub_node(2, 5);
    t.add_sub_node(3, 6);
    t.add_sub_node(3, 7);

    std::vector<int> ans3 = {4, 2, 5, 1, 6, 3,  7};
    int i = 0;
    for (auto it = t.begin_in_order(); it != t.end_in_order(); ++it) {
        CHECK(*it == ans3[i]);
        ++i;
    }
}

TEST_CASE("Inorder (string)") {
    tree<std::string> t(2);
    t.add_root("a");
    t.add_sub_node("a", "b");
    t.add_sub_node("a", "c");
    t.add_sub_node("b", "d");
    t.add_sub_node("b", "e");
    t.add_sub_node("c", "f");
    t.add_sub_node("c", "g");

    std::vector<std::string> ans3 = {"d", "b", "e", "a", "f","c","g"};
    int i = 0;
    for (auto it = t.begin_in_order(); it != t.end_in_order(); ++it) {
        CHECK(*it == ans3[i]);
        ++i;
    }
}

TEST_CASE("Heap(Int)") {
    tree<int> t(3);
    t.add_root(5);
    t.add_sub_node(5, 3);
    t.add_sub_node(5, 8);
    t.add_sub_node(5, 7);
    t.add_sub_node(3, 1);
    t.add_sub_node(3, 2);

    std::vector<int> ans4 = {1, 2, 3, 5, 7, 8};
    int i = 0;
    for (auto it = t.begin_heap(); it != t.end_heap(); ++it) {
        CHECK(*it == ans4[i]);
        ++i;
    }
}

TEST_CASE("Iterator DFS(Int)") {
    tree<int> t(3);
    t.add_root(1);
    t.add_sub_node(1, 2);
    t.add_sub_node(1, 3);
    t.add_sub_node(2, 4);
    t.add_sub_node(2, 5);
    t.add_sub_node(2, 6);
    t.add_sub_node(3, 8);
    t.add_sub_node(3, 9);
    t.add_sub_node(4, 10);
    t.add_sub_node(4, 11);
    t.add_sub_node(4, 12);

    std::vector<int> ans1 = {1, 2,4,10,11,12,5,6,3,8,9};
    int i = 0;
    for (auto it = t.begin_dfs_scan(); it != t.end_dfs_scan(); ++it) {
        CHECK(*it == ans1[i]);
        ++i;
    }
}

TEST_CASE("Iterator DFS(double)") {
    tree<double> t(3);
    t.add_root(1.1);
    t.add_sub_node(1.1, 2.2);
    t.add_sub_node(1.1, 3.3);
    t.add_sub_node(1.1, 4.4);
    t.add_sub_node(2.2, 5.5);
    t.add_sub_node(2.2, 6.6);
     t.add_sub_node(2.2, 7.7);
    t.add_sub_node(3.3, 8.8);
    t.add_sub_node(3.3, 9.9);
    t.add_sub_node(4.4, 10.10);

    std::vector<double> ans1 = {1.1, 2.2, 5.5, 6.6,7.7, 3.3, 8.8,9.9,4.4,10.10};
    int i = 0;
    for (auto it = t.begin_dfs_scan(); it != t.end_dfs_scan(); ++it) {
        CHECK(*it == ans1[i]);
        ++i;
    }
}

TEST_CASE("DFS (string)") {
    tree<std::string> t(2);
    t.add_root("a");
    t.add_sub_node("a", "b");
    t.add_sub_node("a", "c");
    t.add_sub_node("b", "d");
    t.add_sub_node("b", "e");
    t.add_sub_node("c", "f");
    t.add_sub_node("c", "g");

    std::vector<std::string> ans3 = {"a", "b", "d", "e", "c","f","g"};
    int i = 0;
    for (auto it = t.begin_dfs_scan(); it != t.end_dfs_scan(); ++it) {
        CHECK(*it == ans3[i]);
        ++i;
    }
}

TEST_CASE("Iterator DFS(complex)") {
    tree<Complex> t(3);
    t.add_root(Complex(1, 1));
    t.add_sub_node(Complex(1, 1), Complex(2, 2));
    t.add_sub_node(Complex(1, 1), Complex(3, 3));
    t.add_sub_node(Complex(1, 1), Complex(4, 4));
    t.add_sub_node(Complex(2, 2), Complex(5, 5));
    t.add_sub_node(Complex(2, 2), Complex(6, 6));
    t.add_sub_node(Complex(3, 3), Complex(7, 7));
    t.add_sub_node(Complex(3, 3), Complex(8, 8));
    t.add_sub_node(Complex(3, 3), Complex(9, 9));
    t.add_sub_node(Complex(4, 4), Complex(10, 10));

    std::vector<Complex> ans1 = {Complex(1, 1), Complex(2, 2), Complex(5, 5), Complex(6, 6), Complex(3, 3),Complex(7, 7), Complex(8, 8),Complex(9, 9),Complex(4, 4),Complex(10, 10)};
    int i = 0;
    for (auto it = t.begin_dfs_scan(); it != t.end_dfs_scan(); ++it) {
        CHECK(*it == ans1[i]);
        ++i;
    }
}
