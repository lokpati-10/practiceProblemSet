#include <vector>
vector<int> Bits(int num){
	int p = 1;
	int pow = 1;
	for(int i = 1; i <= num ; i++) {
		if(i == pow ) {
			Bits[i] = 1;
			pow <<= 1;
		} else {
			Bits[i] += Bits[p] + 1;
			p++;
		}
	}

	return Bits;
}
