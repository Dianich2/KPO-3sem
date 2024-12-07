#include "Deserializer.h"
#include <iostream>
using namespace std;

int main() {
	ifstream rd;
	rd.open("..\\asm4\\ser.bin", ios::binary);
	vector<pair<int, char*>> res = Deserializer::Deserialize(rd);

}