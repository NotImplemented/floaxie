#include <iostream>
#include <random>
#include <limits>
#include <cstdlib>

#include "floaxie/ftoa.h"
#include "floaxie/atof.h"

#include "short_numbers.h"

using namespace std;
using namespace floaxie;

int main(int, char**)
{
	char buffer[128];
	const char* str_end;

	random_device rd;
	default_random_engine gen(rd());
	uniform_real_distribution<> dis(0, 2);

	size_t fault_number = 0;

	for (size_t i = 0; i < short_numbers_length; ++i)
	{
		double pi = short_numbers[i];
		ftoa(pi, buffer);
		double ret = atof<double>(buffer, &str_end);
		double ref_value = strtod(buffer, nullptr);

		if (ref_value != pi || ref_value != ret)
		{
			cerr << "not equal [i = " << i << "] "
			<< "pi: " << pi
			<< ", buffer: "
			<< buffer << ", ref_value: "
			<< ref_value << ", ret: "
			<< ret << endl;
			++fault_number;
// 			return -1;
		}
	}
	cout << "crosh failed " << fault_number << " times out of " << short_numbers_length << endl;

	return 0;
}
