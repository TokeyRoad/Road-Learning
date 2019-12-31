#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <condition_variable>
#include <thread>
#include <atomic>

std::condition_variable cv;
std::mutex mtx;
std::atomic<int> count;

void ThreadFirst() {
	printf("before ThreadFirst Print \n");
	for (int i = 0; i < 120; i++) {
		count++;
		cv.notify_all();
	}
	printf("End ThreadFirst Print \n");
}

void ThreadSecond() {
	printf("before ThreadSecond Print \n");
	std::unique_lock<std::mutex> lck(mtx);
	cv.wait(lck, [] {return count > 100; });
	printf("Print Count:%d\n", count);
	printf("End ThreadSecond Print \n");
}

int main(){
	count = 0;
	std::vector<std::thread*> v_pthread;
	std::thread* p1 = new std::thread(ThreadFirst);
	std::thread* p2 = new std::thread(ThreadSecond);

	v_pthread.push_back(p1);
	v_pthread.push_back(p2);
	p1->join();
	p2->join();

	system("pause");
	return 0;
}