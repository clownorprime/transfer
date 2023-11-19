#include <iostream>
#include "complex.h"

using namespace std;

int main() {
    Complex<int> c(1, 2);
    cout << "Real part is " << c.getReal() << endl;
    cout << "Imag part is " << c.getImag() << endl;
    Complex<int> c1(2, 3);
    Complex<int> c2;
    (c2 = c1) = c;
    cout << "Real part is " << c1.getReal() << endl;
    cout << "Imag part is " << c1.getImag() << endl;
    cout << "Real part is " << c2.getReal() << endl;
    cout << "Imag part is " << c2.getImag() << endl;
}
