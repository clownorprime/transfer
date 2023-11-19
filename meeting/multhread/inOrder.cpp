#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

const int NTHREAD = 10;
int thread_num = 0;
using namespace std;
condition_variable cv;
mutex mtx;

void thread_func(int id) {
    unique_lock<mutex> lck(mtx);
    while(id != thread_num) { cv.wait(lck); }
    thread_num++;
    cv.notify_all();
    cout << "thread id is" << id << endl;
}
int main() {
    thread threads[NTHREAD];
    for (int i = 0; i < NTHREAD; i++) {
        threads[i] = thread(thread_func, i);
    }
    for (int i = 0; i < NTHREAD; i++) {
        threads[i].join();
    }
    cout << "all thread exited" << endl;
}
