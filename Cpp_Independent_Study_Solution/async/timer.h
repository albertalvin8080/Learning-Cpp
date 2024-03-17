#pragma once
#include <chrono>
#include <future>
//#include <iostream>

//static std::mutex s_mutex;

void simulateHeavyProcessing(const size_t& size) {
	//std::lock_guard<std::mutex> lock{s_mutex};
	for (size_t i = 0; i < size; ++i);
}

class Timer {
private:
	std::string name;
	std::chrono::high_resolution_clock::time_point start;
public:
	Timer(const std::string& name) : name(name), start(std::chrono::high_resolution_clock::now()) {}

	~Timer() {
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		std::cout << duration << "\n";
		std::cout << name << " : [" << duration/1000000 << "s], ["
			<< duration/1000 % 1000 << "ms], ["
			<< duration % 1000 << "us]" << "\n";
	}
};