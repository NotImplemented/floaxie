#include "floaxie/dtoa.h"

#include "../test/short_numbers.h"

using namespace std;
using namespace floaxie;

int main(int, char**)
{
	char buffer[128];

	for (size_t i = 0; i < short_numbers_length; ++i)
	{
		dtoa(short_numbers[i], buffer);
	}

	return 0;
}
