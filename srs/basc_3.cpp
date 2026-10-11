#include<iostream>
#include<thread>
#include<memory>

class A{
public:
    
private:
    //友元函数
    friend void foo();//为了让外部能够访问到类中的private
    void test() {
        std::cout<<"private"<<std::endl;
    }
};
void foo() 
{
    std::shared_ptr<A> a = std::make_shared<A>();//为了避免a的地址被释放，使用智能指针来保证
    std::thread t(&A::test,a);
    t.join();
}
 
int main(){
    foo();
    return 0;
}