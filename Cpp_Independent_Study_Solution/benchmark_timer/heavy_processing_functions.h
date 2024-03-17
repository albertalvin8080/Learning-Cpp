#pragma once

#include "instrumentation_timer.h"
#include <thread>

#define PROFILLING 1
#ifdef PROFILLING
#define PROFILE_SCOPE(name) Timer timer##__LINE__(name)
#define PROFILE_FUNCTION() PROFILE_SCOPE(__FUNCSIG__)
#else
#define PROFILE_FUNCTION()
#endif

void function1() {
	PROFILE_FUNCTION();
	for (int i = 0; i < 5000; ++i) {
		std::cout << "Exeution... #" << sqrt(i) << "\n";
	}
}

void function1(const size_t& size) {
	PROFILE_FUNCTION();
	for (int i = 0; i < size; ++i) {
		std::cout << "Exeution... #" << sqrt(i) << "\n";
	}
}

void runBenchmarks() {
	PROFILE_FUNCTION();
	std::thread a([]() { function1(); });
	std::thread b([]() {function1(4000); });

	function1(7000);

	a.join();
	b.join();

	/*std::thread c([]() { function1(); });
	c.join();*/
}