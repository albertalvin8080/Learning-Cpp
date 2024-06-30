#include <iostream>
#include <mutex>
#include <future>
#include <vector>
#include <algorithm>
#include "timer.h"

int main() {
	const size_t size = 1000000000;
	std::vector<std::future<void>> futures;

	{
		Timer timer("Async Test");
		for (size_t i = 0; i < 10; ++i) {
			#define ASYNC 1
			#ifdef ASYNC
				futures.push_back(std::async(std::launch::async, simulateHeavyProcessing, size));
			#else
				simulateHeavyProcessing(size);
			#endif
		}
		
		std::for_each(futures.begin(), futures.end(), [](std::future<void>& f) {
				f.wait();
		});
	}

	return 0;
}