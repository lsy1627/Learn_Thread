#include<iostream>
#include<thread>
#include<mutex>

//lock_guard和std::unique_lock
//1.lock_guard：
//当使用该函数，互斥量会被自动锁定
//当该作用域结束后会自动调用un_lock

int num = 0;
std::mutex mtx;
void func(){
    for(int i =0; i<100000;i++)
    {
        std::lock_guard<std::mutex> lg(mtx);
        num += 1;
    }
}

//2.std::unique_lock

int main()                                                                   
{
    std::thread t1(func);
    std::thread t2(func);

    t1.join();
    t2.join();

    std::cout <<"num = "<<num << std::endl;
    return 0;
}