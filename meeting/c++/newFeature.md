## auto和decltype
### source
https://zhuanlan.zhihu.com/p/13766277://zhuanlan.zhihu.com/p/137662774
### 为什么使用auto和decltype
可以在编译器就推导出变量或者表达式的类型，方便开发者编写代码，同时也简化了代码
### 怎么使用
auto = 可以根据=右边的类型推导出变量的类型
一些复杂类型使用auto从而提高程序可读性
dectype根据括号中的表达式结果推导出表达式的类型
### auto特点
auto的特点：
auto修饰的变量必须马上初始化，否则无法推导出类型  
auto在一行定义多个变量时，各个变量的推导不能具有二义性，否则编译失败
auto无法推导出函数模板
在类中auto无法用作非静态成员变量

在不声明为引用或者指针时，auto会忽略等号右边的引用类型和CV限定
在声明为引用或者指针时，auto会保留右边的引用和CV限定

### decltype
decltype用来推导表达式类型，

