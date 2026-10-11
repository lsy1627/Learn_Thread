#include<iostream>
#include<thread>
#include<mutex>

//互斥量解决多线程数据共享问题（std::mutex�?

int num = 0;
std::mutex mtx,mtx1,mtx2;
//1.单纯理解一下互斥量
void func(){
    for(int i =0; i<100000;i++)
    {
        mtx.lock();
        num += 1;
        mtx.unlock();
    }
}

//2.满足：目前有两个进程t1和t2，它们需要对两个互斥量mtx1和mtx2进行访问，而且需要按照以下顺�?
//获取互斥量的所有权
//t1:先获取mtx1，再获取mtx2
//t2:先获取mtx2，在获取mtx1

void func_1 (){
    for(int i = 0; i < 500 ;i++)
    {
        mtx1.lock();
        mtx1.unlock();
        mtx2.lock();
        mtx2.unlock();
    }
    
}
void func_2 (){
    for(int i = 0; i < 500 ;i++)
    {
        mtx2.lock();
        mtx2.unlock();
        mtx1.lock();
        mtx1.unlock();
    }
}

int main(){
    std::thread t1(func_1);
    std::thread t2(func_2);

    t1.join();
    t2.join();
    std::cout<<"num ="<< num <<std::endl;
    return 0;
}

