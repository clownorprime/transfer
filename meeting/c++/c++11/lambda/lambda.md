在c++11之前，要对一个数组中的奇数和偶数分别排序，且奇数要放在偶数后面，要使用以下方法：
```c++                  sort1.cpp
#include <iostream>
#include <algorithm>

using namespace std;
bool fun(int a, int b) {
    if ((a % 2 == 1) && (b % 2 == 0)) {
        return true;
    }
    if (a < b) { return true; }
    return false;
}
int main() {
    vector<int> data = {1,2,3,4,5,6,7,8,9};
    sort(data.begin(), data.end(), fun);
    for (auto val : data) {
        cout << val << " ";
    }
    cout << endl;
}
```
但是，我们没有必要再写一个函数，先来一个简单的例子
```c++              square.cpp
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    auto f = [](int a) { return a * a; }
    cout << f(5) << endl;
}
```

这里，f就是一个lambda表达式，lambda表达式的格式为：
    [捕获列表]<模板声明>(参数列表) mutable 异常说明->类型{函数体}
注：mutable是c++的一个关键字，其意思是可以在一个const成员函数中修改一个被定义为mutable变量的value.
在此处，mutable指的是以值传递的变量可以被修改，但是不能修改变量本身，而引用传递的变量不变。  
捕获列表语法：
1. []   什么也不捕获
2. [var]    捕获当前作用域中的var变量，以值传递
3. [&var]   捕获当前作用域中的var变量，以引用方式传递
4. [=]      捕获当前作用域中的所有变量，以值传递
5. [&]      捕获当前作用域中的所有变量，以引用方式传递
6. [=,&var] 捕获...全部变量，以引用方式传递var，其余以值传递
7. [this]   捕获class的this指针，如果捕获列表使用了[=]或[&],则this指针自动被包含

其实，这里lambda表达式是一个函数对象，也就是重载了operator()的一个仿函数.

