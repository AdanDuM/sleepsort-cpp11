#include <chrono>
#include <cstdint>
#include <iostream>
#include <mutex>
#include <sstream>
#include <string>
#include <thread>
#include <vector>

std::mutex output;

void func(unsigned int value) {
	using std::chrono::seconds;
	using std::cout;
	using std::endl;
	using std::lock_guard;
	using std::mutex;

	std::this_thread::sleep_for(seconds(value));

	{
		lock_guard<mutex> lock{output};
		cout << value << endl;
	}
}

int main(int argc, char** argv) {
	using std::cout;
	using std::endl;
	using std::string;
	using std::stringstream;
	using std::thread;
	using std::vector;

	vector<thread>::size_type amount = argc - 1;
	vector<thread> threads;
	threads.reserve(amount);
	for (auto i = 1; i < argc; ++i) {
		stringstream ss;
		ss << argv[i];

		unsigned int value;
		if (!(ss >> value)) {
			string invalid;
			ss >> invalid;
			cout << "You input a non-integer: " << invalid << endl;
		} else {
			threads.emplace_back(func, value);
		}
	}

	for (auto& thread : threads) {
		thread.join();
	}

	return 0;
}
