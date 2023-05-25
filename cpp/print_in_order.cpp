// Copyright (c) 2019, eniac
// All rights reserved.
//
// Author: eniac <roboteniac@163.com>
// Created: 2023/02/15 20:01:14
// Description: https://leetcode.cn/problems/print-in-order/

#include <iostream>
#include <vector>
#include <string>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <chrono>

#include "util.h"

using namespace std;

std::mutex m;
std::condition_variable cv;
std::string data;
bool ready = false;
int turn = 1;

void p1() {
	printf("first");
}
void p2() {
	printf("second");
}
void p3() {
	printf("third");
}

void first(function<void()> printFirst) {
	std::unique_lock<std::mutex> lk(m);
	cv.wait(lk, [] { 
			if (turn == 1) {
			turn = 2;
			return true;
			}
			return false;
			});
	cv.notify_all();

	// printFirst() outputs "first". Do not change or remove this line.
	printFirst();
}

void second(function<void()> printSecond) {
	std::unique_lock<std::mutex> lk(m);
	cv.wait(lk, [] {
			if (turn == 2) {
			turn = 3;
			return true;
			}
			return false;
			});
	turn = 3;
	cv.notify_all();

	// printSecond() outputs "second". Do not change or remove this line.
	printSecond();
}

void third(function<void()> printThird) {
	std::unique_lock<std::mutex> lk(m);
	cv.wait(lk, [] { return turn == 3; });
	// printThird() outputs "third". Do not change or remove this line.
	printThird();
}

int main(int argc, char *argv[]) {
	std::thread t1([] {
		std::this_thread::sleep_for(std::chrono::seconds(1));
		first(p1);
	});
	std::thread t3([] {
		std::this_thread::sleep_for(std::chrono::seconds(2));
		third(p3);
	});
	std::thread t2([] {
		std::this_thread::sleep_for(std::chrono::seconds(3));
		second(p2);
	});
	t1.join();
	t2.join();
	t3.join();
}
