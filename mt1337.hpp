#include <vector>

class MT1337 {
	int mt[624];
	int index;
public:
	MT1337(int seed);
	int extract_number();
	void twist_it();
};
