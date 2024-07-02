//Lbalad13@gmail.com
//211801220 
//Liraz balas
#ifndef COMPLEX_HPP
#define COMPLEX_HPP
#include <iostream>

class Complex {
    
private:
    double real;
    double image;

public:
    Complex(double real = 0.0, double image = 0.0);
    double get_real() const;
    double get_image() const;
    bool operator==(const Complex& other) const;
    bool operator>(const Complex& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
};

#endif 
