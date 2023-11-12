在学习emplace\_back和push\_back区别时，看到了以下这两篇文章，然而这两篇文章都会或多或少的问题，反而是评论区中给出了更为准确的答案。

第二篇文章中的竹子酒，他认为，push\_back和emplace\_back的区别在于一个仅能接收value\_type&& 类型的参数，另一个参数类型是形参包(可以接收任意参数)，因此才引发的一系列后续区别。

我们首先来看gcc-11中的stl\_vector.h中push\_back的源码, 其余容器的push\_back的源码类似：
```c++
void
push_back(const value_type& __x)
      {
	if (this->_M_impl._M_finish != this->_M_impl._M_end_of_storage)
	  {
	    _GLIBCXX_ASAN_ANNOTATE_GROW(1);
	    _Alloc_traits::construct(this->_M_impl, this->_M_impl._M_finish,
				     __x);
	    ++this->_M_impl._M_finish;
	    _GLIBCXX_ASAN_ANNOTATE_GREW(1);
	  }
	else
	  _M_realloc_insert(end(), __x);
      }

#if __cplusplus >= 201103L
      void
      push_back(value_type&& __x)
      { emplace_back(std::move(__x)); }

      template<typename... _Args>
#if __cplusplus > 201402L
	reference
#else
	void
#endif
	emplace_back(_Args&&... __args);
#endif
```
我们可以看到，这里push\_back可以接受两种类型的参数，一是左值引用，二是右值引用.
而vector.tcc中emplace\_back的源码为, 其他容器的emplace\_back的源码类似：
```c++
if __cplusplus >= 201103L
  template<typename _Tp, typename _Alloc>
    template<typename... _Args>
#if __cplusplus > 201402L
      typename vector<_Tp, _Alloc>::reference
#else
      void
#endif
      vector<_Tp, _Alloc>::
      emplace_back(_Args&&... __args)
      {
	if (this->_M_impl._M_finish != this->_M_impl._M_end_of_storage)
	  {
	    _GLIBCXX_ASAN_ANNOTATE_GROW(1);
	    _Alloc_traits::construct(this->_M_impl, this->_M_impl._M_finish,
				     std::forward<_Args>(__args)...);
	    ++this->_M_impl._M_finish;
	    _GLIBCXX_ASAN_ANNOTATE_GREW(1);
	  }
	else
	  _M_realloc_insert(end(), std::forward<_Args>(__args)...);
#if __cplusplus > 201402L
	return back();
#endif
      }
#endif
```
这里可以看到，emplace\_back的形参为一个名为\_Args&&的模板参数包，而在construct中使用std::forward将模板参数包强制类型转换为\_Args类型的对象，在这个过程中调用了\_Args class的构造函数. 以下是std::forward的源代码:
```c++
template<typename _Tp>
    _GLIBCXX_NODISCARD
    constexpr _Tp&&
    forward(typename std::remove_reference<_Tp>::type& __t) noexcept
    { return static_cast<_Tp&&>(__t); }
```
又因为，forward能够接受左值引用、右值引用、value\_type的实参，所以，emplace\_back也可以接受左值引用、右值引用、value\_type类型的实参.
综上，在c++11中，emplace\_back和push\_back本质的区别是emplace\_back能够接收模板参数包，所以emplace\_back能够construct in place, 而push\_back只能先construct再转换为右值再copy.

