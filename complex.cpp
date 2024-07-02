//Lbalad13@gmail.com
//211801220 
//Liraz balas
#include "complex.hpp"
#include <stdexcept>
#include <iomanip> 

Complex::Complex(double re, double im) : real(re), image(im) {}
double Complex::get_real() const {return real;}
double Complex::get_image() const {return image;}
bool Complex::operator==(const Complex& other) const {return real == other.real && image == other.image;}

bool Complex::operator>(const Complex& other) const {
    return (real > other.get_real()) || (real == other.get_real() && image> other.get_image());
}

std::ostream& operator<<(std::ostream& os, const Complex& c) {
    //os << std::fixed << std::setprecision(2); 
    os << "(" << c.real << " + " << c.image<< "i)";
    return os;
}
