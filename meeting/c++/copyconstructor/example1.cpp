#include<iostream>
using namespace std;
class CExample
{
private:
    int a;
public:
    CExample(int b)
    {
        a=b;
        printf("constructor is called\n");
    }
    CExample(const CExample& c)
    {
        a=c.a;
        printf("copy constructor is called\n");
    }
    ~CExample()
    {
     cout<<"destructor is called\n";
    }
    void Show()
    {
     cout<<a<<endl;
    }
};
CExample fun() {	
	cout << "fun" << endl;
	CExample C(0);
	return C;
}
void g_fun(CExample c)
{
    cout<<"g_func"<<endl;
}
int main()
{
    CExample A(100);
    CExample B=A;
    B.Show(); 
    g_fun(A);
	fun();
    cout << "hello" << endl;
    return 0;
}
