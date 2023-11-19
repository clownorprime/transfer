#include <iostream>

using namespace std;

class A {
    public:
        virtual void func1() {
            cout << "I am class A" << endl;
        }
        virtual void func3() {
            cout << "class A, func3" << endl;
        }
};

class B {
    public:
        virtual void func2() {
            cout << "I am class B" << endl;
        }
};

class C : public A, public B{
    public:
        void func1() {
            cout << "I am class c" << endl;
        }
        void func2() {
            cout << "I am class C" << endl;
        }
};

int main() {
    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;
    cout << sizeof(C) << endl;
}
