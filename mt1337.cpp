#include "mt1337.hpp"
#include <iostream>
#include <cstdlib>


MT1337::MT1337(int seed) {
	index = 624;
	mt[0] = seed;
	
	for (int n = 1; n < 624; n++) {
		mt[n] = 0;
	} //Maybe unneccesary
	
	for (int n = 1; n < 624; n++) {
		mt[n] = 1812433253 * ( mt[n-1] ^ mt[n -1] >> 30) + n; 
	} 
};

int MT1337::extract_number() {
	int y = 0;
	if (index >= 624) {
		twist_it();
	}
	y = mt[index];
	y = y ^ y >> 11;
	y = y ^ (y << 7 & 2636928640);
	y = y ^ (y << 15 & 4022730752);
	y = y ^ y >> 18;

	index++;

	return y;
}

void MT1337::twist_it() {
	int y = 0;
	for (int n = 0; n < 624; n++) {
		y = (mt[n] & 0x80000000) + (mt[n+1 % 624] & 0x7fffffff);
		mt[n] = mt[(n + 397) % 624] ^ y >> 1;

		if (y % 2 != 0) {
			mt[n] = mt[n] ^ 0x9908b0df;
		}
	}

	index = 0;
}

int main(int argc, char **argv) {
	int seed = atoi(argv[1]);	
	MT1337 mnt(seed);
	std::cout << mnt.extract_number() % 100 << std::endl;
	std::cout << mnt.extract_number() % 100 << std::endl;

}
