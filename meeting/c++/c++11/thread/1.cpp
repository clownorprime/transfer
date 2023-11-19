#include <iostream>
#include <thread>

using namespace std;

void fun() {
    cout << "world" << endl;
}
int main() {
    //a接受一个函数对象为参数，b接受一个函数指针为参数
    thread a([](){ cout << "hello" << endl; });
    thread b(fun);
    a.join();
    b.join();
    return 0;
}
