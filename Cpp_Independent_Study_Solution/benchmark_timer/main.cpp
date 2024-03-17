#include "instrumentation_timer.h"
#include "heavy_processing_functions.h"

int main() {
	InstrumentalTimer& it = InstrumentalTimer::Get();
	it.beginSession("Session1");

	runBenchmarks();

	it.endSession();

	return 0;
}