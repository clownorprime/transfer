template <class T>
class Complex {
    private:
        T real;
        T imag;
    public:
        Complex(T real, T imag) : real(real), imag(imag) {}
        Complex() : real(0), imag(0) {}
        Complex(Complex &c) : real(c.real), imag(c.imag) {};
        T getReal() { return real; }
        T getImag() { return imag; }
        Complex operator+ (Complex c) {
            Complex temp;
            temp.real = this->real + c.real;
            temp.imag = this->imag + c.imag;
            return temp;
        }
        Complex& operator* (const Complex c) {
            T realPart = this->real * c.real - this->imag * c.imag;
            T imagPart = this->real * c.imag + this->imag * c.real;
            this->real = realPart;
            this->imag = imagPart;
            return *this;
        }
        Complex operator-(const Complex c) {
            T realPart = this->real - c.real;
            T imagPart = this->imag - c.imag;
            this->real = realPart;
            this->imag = imagPart;
            return *this;
        }
        Complex operator=(const Complex& c) {
            this->real = c.real;
            this->imag = c.imag;
            return *this;
        }
};
