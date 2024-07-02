//Lbalad13@gmail.com
//211801220 
//Liraz balas
#include "tree.hpp"
#include "complex.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <SFML/Graphics.hpp>
#include <cmath> 
#include <sstream> 
using namespace std;


//depth tree
template <typename T>
int levels_tree(Node<T>* node) {
    if (!node) return 0;
    int result = 0;
    for (auto& ch : node->childrens_node) {
        result = max(result, levels_tree(ch.get()));
    }
    return result + 1;
}

//draw tree
template <typename T>
void draw(sf::RenderWindow &window, Node<T>* node, sf::Vector2f position, float horizontal, float verticale) {

    if (!node) return;
    //part for load the font 
     sf::Font font;
    if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf")){
        cerr << "Error in the load of font" << endl;
        return;
    }
    
    //part for the circle
    sf::CircleShape c(30);
    c.setFillColor(sf::Color::Red); 
    c.setPosition(position.x - c.getRadius(), position.y - c.getRadius()); 
   
//part for the value of the node
    sf::Text t;
    t.setFont(font);
    std::ostringstream s;
    s << node->value;
    //characteristic :color , size 
    t.setFillColor(sf::Color::Black); 
    t.setString(s.str());
    t.setCharacterSize(14); 
    //bounds
    sf::FloatRect bounds = t.getLocalBounds();
    t.setOrigin(bounds.left + bounds.width / 2.6f, bounds.top + bounds.height / 2.6f); 
    t.setPosition(position);
    //draw 
     window.draw(c);
    window.draw(t);
    //draw the childrens of the node
    int childs = node->childrens_node.size();
    float f = -70.0f - (childs - 1) * 20.0f; 
    for (int i = 0; i < childs ; ++i) {
        auto& ch = node->childrens_node[i];
        if (ch) { 
        //line for the 2 childrens 
            sf::Vector2f v2 = position + sf::Vector2f(cos((f + i * 30.0f )* M_PI / 180.0f) * horizontal, verticale);
            sf::Vertex lines_childrens[] = {
                sf::Vertex(position + sf::Vector2f(0, 30)),
                sf::Vertex(v2 + sf::Vector2f(0, -30))
            };
            //draw the two lines 
            lines_childrens->color = sf::Color::Red; 
            window.draw(lines_childrens, 2, sf::Lines);
            
            draw(window, ch.get(), v2, horizontal / 2.2f, verticale * 1.2f); 
        }
    }
}


template <typename T>
void visualize(sf::RenderWindow& window, tree<T>& tree) {
    sf::Font font;
    if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf")){
        cerr << "Error in load font" << endl;
        return;
    }

    Node<T>* root_tree = tree.get_root();
    int d = levels_tree(root_tree);
    sf::Vector2f v(window.getSize().x / 2, 50);
    float horizontal = window.getSize().x / (pow(2, d - 1) + 1) * 2.5; 
    float verticale = window.getSize().y / (d + 1) * 1.5;
    draw(window, root_tree, v,  horizontal, verticale);
}

int main() {


 tree<int> tree_int(2);
    tree_int.add_root(1);
    tree_int.add_sub_node(1, 2); 
    tree_int.add_sub_node(1, 3); 
    tree_int.add_sub_node(2, 4); 
    tree_int.add_sub_node(2, 5); 
    tree_int.add_sub_node(3, 6); 
    tree_int.add_sub_node(3, 7); 

    cout << "Preorder iterator(Tree Int) : ";
    for (auto it = tree_int.begin_pre_order(); it != tree_int.end_pre_order(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Postorder iterator(Tree Int): ";
    for (auto it = tree_int.begin_post_order(); it != tree_int.end_post_order(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    cout << "Inorder iterator(Tree Int): ";
    for (auto it = tree_int.begin_in_order(); it != tree_int.end_in_order(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    cout << "Bfs iterator(Tree Int): ";
    for (auto it = tree_int.begin_bfs_scan(); it != tree_int.end_bfs_scan(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Dfs iterator(Tree Int): ";
    for (auto it = tree_int.begin_dfs_scan(); it != tree_int.end_dfs_scan(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    cout << "Heap iterator(Tree Int): ";
    for (auto it = tree_int.begin_heap(); it != tree_int.end_heap(); ++it) {
        cout << *it << " ";
    }
    cout << endl;


tree<double> tree_double(2);
    tree_double.add_root(1.1);
    tree_double.add_sub_node(1.1, 2.2); 
    tree_double.add_sub_node(1.1, 3.3); 
    tree_double.add_sub_node(2.2, 4.4); 
    tree_double.add_sub_node(2.2, 5.5); 
    tree_double.add_sub_node(3.3, 6.6); 
    tree_double.add_sub_node(3.3, 7.7); 

    cout << "Preorder iterator(Tree double) : ";
    for (auto it = tree_double.begin_pre_order(); it != tree_double.end_pre_order(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Postorder iterator(Tree double): ";
    for (auto it = tree_double.begin_post_order(); it != tree_double.end_post_order(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    cout << "Inorder iterator(Tree double): ";
    for (auto it = tree_double.begin_in_order(); it != tree_double.end_in_order(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    cout << "Bfs iterator(Tree double): ";
    for (auto it = tree_double.begin_bfs_scan(); it != tree_double.end_bfs_scan(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Dfs iterator(Tree double): ";
    for (auto it = tree_double.begin_dfs_scan(); it != tree_double.end_dfs_scan(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    cout << "Heap iterator(Tree double): ";
    for (auto it = tree_double.begin_heap(); it != tree_double.end_heap(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    
    
    tree<Complex> tree_complex(2);
    tree_complex.add_root(Complex(1, 1));
    tree_complex.add_sub_node(Complex(1, 1), Complex(2, 2)); 
    tree_complex.add_sub_node(Complex(1, 1), Complex(3, 3)); 
    tree_complex.add_sub_node(Complex(2, 2), Complex(4, 4)); 
    tree_complex.add_sub_node(Complex(2, 2), Complex(5, 5)); 
    tree_complex.add_sub_node(Complex(3, 3), Complex(6, 6)); 
    tree_complex.add_sub_node(Complex(3, 3), Complex(7, 7)); 

    cout << "Preorder iterator(Tree Complex Number): ";
    for (auto it = tree_complex.begin_pre_order(); it != tree_complex.end_pre_order(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Postorder iterator(Tree Complex Number): ";
    for (auto it = tree_complex.begin_post_order(); it != tree_complex.end_post_order(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Inorder iterator(Tree Complex Number): ";
    for (auto it = tree_complex.begin_in_order(); it != tree_complex.end_in_order(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Bfs iterator(Tree Complex Number): ";
    for (auto it = tree_complex.begin_bfs_scan(); it != tree_complex.end_bfs_scan(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    cout << "Dfs iterator(Tree Complex Number): ";
    for (auto it = tree_complex.begin_dfs_scan(); it != tree_complex.end_dfs_scan(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Heap iterator(Tree Complex Number): ";
    for (auto it = tree_complex.begin_heap(); it != tree_complex.end_heap(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    tree<int> tree_3_ary(3);

    tree_3_ary.add_root(1);
    tree_3_ary.add_sub_node(1, 2);
    tree_3_ary.add_sub_node(1, 3);
    tree_3_ary.add_sub_node(1, 4);
    tree_3_ary.add_sub_node(2, 5);
    tree_3_ary.add_sub_node(2, 6);
    tree_3_ary.add_sub_node(3, 7);
    tree_3_ary.add_sub_node(3, 8);
    tree_3_ary.add_sub_node(4, 9);
    

    cout << "Preorder (3-ary): ";
    for (auto it = tree_3_ary.begin_pre_order(); it != tree_3_ary.end_pre_order(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    cout << "Postorder (3-ary): ";
    for (auto it = tree_3_ary.begin_post_order(); it != tree_3_ary.end_post_order(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    cout << "Inorder (3ary): ";
    for (auto it = tree_3_ary.begin_in_order(); it != tree_3_ary.end_in_order(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    cout << "Bfs (3-ary): ";
    for (auto it = tree_3_ary.begin_bfs_scan(); it != tree_3_ary.end_bfs_scan(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    cout << "Dfs (3-ary): ";
    for (auto it = tree_3_ary.begin_dfs_scan(); it != tree_3_ary.end_dfs_scan(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    cout << "Heap (3-ary): ";
    for (auto it = tree_3_ary.begin_heap(); it != tree_3_ary.end_heap(); ++it){
        cout << *it << " ";
    }
    cout << endl;


    tree<string> tree_string(2);
    tree_string.add_root("a");
    tree_string.add_sub_node("a", "b"); 
    tree_string.add_sub_node("a", "c"); 
    tree_string.add_sub_node("b", "d"); 
    tree_string.add_sub_node("b", "e"); 
    tree_string.add_sub_node("c", "f"); 
    tree_string.add_sub_node("c", "g"); 

    cout << "Preorder (string): ";
    for (auto it = tree_string.begin_pre_order(); it != tree_string.end_pre_order(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Postorder  (string): ";
    for (auto it = tree_string.begin_post_order(); it != tree_string.end_post_order(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    cout << "Inorder  (string): ";
    for (auto it = tree_string.begin_in_order(); it != tree_string.end_in_order(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    cout << "Bfs  (string): ";
    for (auto it = tree_string.begin_bfs_scan(); it != tree_string.end_bfs_scan(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Dfs  (string): ";
    for (auto it = tree_string.begin_dfs_scan(); it != tree_string.end_dfs_scan(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Heap  (string): ";
    for (auto it = tree_string.begin_heap(); it != tree_string.end_heap(); ++it){
        cout << *it << " ";
    }
    cout << endl;

    sf::RenderWindow w1(sf::VideoMode(1800, 1400), "Tree(Int)"); 
    while (w1.isOpen()) {
        sf::Event e;
        while (w1.pollEvent(e)) 
        {
            if (e.type == sf::Event::Closed)
                w1.close();
        }

        w1.clear(sf::Color::Black);
        visualize(w1, tree_int);
        w1.display();
    }
    sf::RenderWindow w2(sf::VideoMode(1800, 1400), "Tree(Complex Number)"); 
    while (w2.isOpen()) 
    {
        sf::Event e;
        while (w2.pollEvent(e)){
            if (e.type == sf::Event::Closed)
                w2.close();
        }

        w2.clear(sf::Color::Black);
        visualize(w2, tree_complex);
        w2.display();
    }

    sf::RenderWindow w3(sf::VideoMode(1800, 1400), "Tree (k-3 arry)"); 
    while (w3.isOpen()) {
        sf::Event e;
        while (w3.pollEvent(e)) {
            if (e.type == sf::Event::Closed)
                w3.close();
        }

        w3.clear(sf::Color::Black);
        visualize(w3, tree_3_ary);
        w3.display();
    }

    sf::RenderWindow w4(sf::VideoMode(1800, 1400), "Tree (string)"); 
    while (w4.isOpen()) {
        sf::Event e;
        while (w4.pollEvent(e)) {
            if (e.type == sf::Event::Closed)
                w4.close();
        }
        w4.clear(sf::Color::Black);
        visualize(w4, tree_string);
        w4.display();
    }
      sf::RenderWindow w5(sf::VideoMode(1800, 1400), "Tree (double)"); 
    while (w5.isOpen()) {
        sf::Event e;
        while (w5.pollEvent(e)) {
            if (e.type == sf::Event::Closed)
                w5.close();
        }
        w5.clear(sf::Color::Black);
        visualize(w5, tree_double);
        w5.display();
    }

    return 0;}
