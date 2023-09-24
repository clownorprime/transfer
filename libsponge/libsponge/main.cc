#include <iostream>
#include "wrapping_integers.hh"

using namespace std;

int main() {
	WrappingInt32 n(2147486348);
	WrappingInt32 isn(2147486347);
	cout << n << endl;
	uint64_t checkpoint = 0;
	cout << hex << n << endl;
	cout << hex << checkpoint << endl;
	cout << hex << unwrap(n, isn, checkpoint) << endl;
}


