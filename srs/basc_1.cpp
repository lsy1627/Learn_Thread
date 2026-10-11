#include<iostream>
#include<thread>
#include<string>

void print() {
	for (int i = 0;i < 1000;i++)
	{
		std::cout << i;
	}
	std::cout << std::endl;
}

int main() {
	//1.创建一个线程
	std::thread print_thread(print);

	//2.join：告诉主程序等待线程结束;如果没有join程序会报错
	//原因：没有join的话主程序不会等待线程是否结束，这里就会直接执行return 0；而线程可能未运行完毕
	//用法：print_thread.join();

	//3.detach(),分离线程          join常用detach不常用
	//那有没有可以让主程序不用等待线程结束，但线程仍然可以运行且不会报错的；那就用到detach
	//用法:print_thread.detach()

	//4.joinable();判断一个线程是否可以调用join,返回值类型为bool
	bool isJoin = print_thread.joinable();
	if (isJoin) {
		print_thread.join();
	}

	//可以看出join()是一个阻塞函数，只有将线程结束主程序才可以执行下一步动作
	std::cout << "over" << std::endl;
	return 0;

}