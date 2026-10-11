#include<iostream>
#include<thread>

//二、线程函数中的数据未定义错误

//1.传递临时变量的问题;就是注意类型一致
void foo(int& x) //传参为引用
{
    x += 1;
}

//2.传递指针或引用指向局部变量的问题
//（1）局部变量：
/*
eg:
    std::thread t;
    void foo(int& x) //传参为引用
    {
        x += 1;
    }
    void test()
    {
        int a = 1;
        t = std::thread(foo,std::ref(a));
    }
    会报错空指针，要避免引用的参数为空
*/

//（2）传递指针
void test(int* x)
{
    *x += 1;
}

int main()
{   
    //问题1：
    //为了解决传递临时变量问题，从而引入std::ref来给函数传递引用类型
    int a = 1;
    std::thread t (foo,std::ref(a));
    //如果运行下方的那一条代码会直接报错
    //std::thread t(foo,1);
    t.join();
    std::cout << "a = "<< a << std::endl;

    //问题2.(2)：
    int* p = &a;
    std::thread t1 (test,p);
    std::cout<<"a = "<<*p<<std::endl;
    t1.join();
    return 0;
}