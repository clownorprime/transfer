#include <iostream>
#include <thread>
#include <unistd.h>
#include <mutex>

using namespace std;
mutex mtx_1;
mutex mtx_2;
int num = 0;


void thread1() {
    mtx_1.lock();
    for (int i = 0; i < 100000; i++) {
        num++;
    }
    mtx_1.unlock();
    cout << "thread1" << endl;
}

void thread2(char c) {
    mtx_1.lock();
    for (int i = 0; i < 100000; i++) {
        num++;
    }
    mtx_1.unlock();
    cout << c << endl;
    cout << "thread2" << endl;
}

int main() {
    thread first(thread1);
    thread second(thread2, 97);
    first.join();
    second.join();
    cout << num << endl;
    cout << "thread1 finished" << endl;
    cout << "thread2 still working" << endl;
}
