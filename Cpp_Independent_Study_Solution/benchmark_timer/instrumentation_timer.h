#pragma once

#include <fstream>
#include <iostream>
#include <chrono>
#include <algorithm>
#include <thread>

struct InstrumentationSession {
	// not used, if you're wondering
	std::string sessionName;
};

struct ProfileResult {
	std::string profileName;
	long long start, end;
	size_t threadID;
};

class InstrumentalTimer {
private:
	std::ofstream m_OutputStream;
	size_t m_ProfileCount;
	InstrumentationSession* m_InstrumentationSession;

	// necessary for Singleton
	InstrumentalTimer(const InstrumentalTimer&) = delete;
	InstrumentalTimer operator=(const InstrumentalTimer&) = delete;

	InstrumentalTimer() : m_ProfileCount(0), m_InstrumentationSession(nullptr) {}

public:
	static InstrumentalTimer& Get() {
		static InstrumentalTimer it;
		return it;
	}

	void beginSession(const std::string& name, const std::string& filepath = "benchmark.json") {
		m_InstrumentationSession = new InstrumentationSession{ name };
		m_OutputStream.open(filepath);
		writeHeader();
	}

	void writeHeader() {
		m_OutputStream << "{\"otherData\": {}, \"traceEvents\" : [";
		m_OutputStream.flush();
	}

	void writeProfile(const ProfileResult& profile) {
		if (m_ProfileCount++ > 0)
			m_OutputStream << ",";

		std::string profileName = profile.profileName;
		std::replace(profileName.begin(), profileName.end(), '"', '\'');

		m_OutputStream << "{";
		m_OutputStream << "\"cat\":\"function\",";
		m_OutputStream << "\"dur\":\"" << (profile.end - profile.start) << "\",";
		m_OutputStream << "\"name\":\"" << profileName << "\",";
		m_OutputStream << "\"ph\":\"X\",";
		m_OutputStream << "\"pid\":\"" << 0 << "\",";
		m_OutputStream << "\"tid\":\"" << profile.threadID << "\",";
		//m_OutputStream << "\"tid\":\"" << 0 << "\",";
		m_OutputStream << "\"ts\":\"" << profile.start << "\"";
		m_OutputStream << "}";

		m_OutputStream.flush();
	}

	void writeFooter() {
		m_OutputStream << "]}";
		m_OutputStream.flush();
	}

	void endSession() {
		writeFooter();
		m_OutputStream.close();
		delete m_InstrumentationSession;
		m_InstrumentationSession = nullptr;
	}
};

class Timer {
private:
	std::string profileName;
	std::chrono::steady_clock::duration temp_start;

public:
	Timer(const std::string& name) : 
		profileName(name), temp_start(std::chrono::high_resolution_clock::now().time_since_epoch()) {}

	~Timer() {
		auto temp_end = std::chrono::high_resolution_clock::now().time_since_epoch();
		auto end = std::chrono::duration_cast<std::chrono::microseconds>(temp_end).count();
		auto start = std::chrono::duration_cast<std::chrono::microseconds>(temp_start).count();

		auto threadID = std::hash<std::thread::id>{}(std::this_thread::get_id());

		InstrumentalTimer::Get().writeProfile(
			ProfileResult{profileName, start, end, threadID }
		);
	}
};