#include <iostream>
#include <Windows.h>
#include "FST.h"

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// ������� �� ������������ 16 ��� ��������
	FST::FST fst1(
		"aaabbbbaba",
		4,
		FST::NODE(3, FST::RELATION('a', 0), FST::RELATION('b', 0), FST::RELATION('a', 1)),
		FST::NODE(1, FST::RELATION('b', 2)),
		FST::NODE(1, FST::RELATION('a', 3)),
		FST::NODE()
	);

	if (FST::execute(fst1)) {
		cout << "������� " << fst1.strin << " ����������\n";
	}
	else {
		cout << "������� " << fst1.strin << " �� ����������\n";
	}

	FST::FST fst2(
		"aaabbbabba",
		4,
		FST::NODE(3, FST::RELATION('a', 0), FST::RELATION('b', 0), FST::RELATION('a', 1)),
		FST::NODE(1, FST::RELATION('b', 2)),
		FST::NODE(1, FST::RELATION('a', 3)),
		FST::NODE()
	);

	if (FST::execute(fst2)) {
		cout << "������� " << fst2.strin << " ����������\n";
	}
	else {
		cout << "������� " << fst2.strin << " �� ����������\n";
	}


	// ������� �� ������������ ������ 13
	// ����������� While � a; ? � b; read � c; seek � d; do � e; write � f;? � l;
	//1 �������     while?do{write};
	FST::FST fst3(
		"allbe{fl};",
		11,
		FST::NODE(1, FST::RELATION('a', 1)),//0
		FST::NODE(2, FST::RELATION('b', 1), FST::RELATION('l', 2)),//1
		FST::NODE(3, FST::RELATION('c', 2), FST::RELATION('d', 2), FST::RELATION('l', 3)),//2
		FST::NODE(2, FST::RELATION('b', 3), FST::RELATION('b', 4)),//3
		FST::NODE(1, FST::RELATION('e', 5)),//4
		FST::NODE(1, FST::RELATION('{', 6)),//5
		FST::NODE(1, FST::RELATION('f', 7)),//6
		FST::NODE(2, FST::RELATION('b', 7), FST::RELATION('l', 8)),//7
		FST::NODE(1, FST::RELATION('}', 9)),//8
		FST::NODE(1, FST::RELATION(';', 10)),//9
		FST::NODE()
	);

	if (FST::execute(fst3)) {
		cout << "������� " << fst3.strin << " ����������\n";
	}
	else {
		cout << "������� " << fst3.strin << " �� ����������\n";
	}

	// ������ �������    while??read???do{write?};
	FST::FST fst4(
		"abblclbbbe{fbl};",
		11,
		FST::NODE(1, FST::RELATION('a', 1)),//0
		FST::NODE(2, FST::RELATION('b', 1), FST::RELATION('l', 2)),//1
		FST::NODE(3, FST::RELATION('c', 2), FST::RELATION('d', 2), FST::RELATION('l', 3)),//2
		FST::NODE(2, FST::RELATION('b', 3), FST::RELATION('b', 4)),//3
		FST::NODE(1, FST::RELATION('e', 5)),//4
		FST::NODE(1, FST::RELATION('{', 6)),//5
		FST::NODE(1, FST::RELATION('f', 7)),//6
		FST::NODE(2, FST::RELATION('b', 7), FST::RELATION('l', 8)),//7
		FST::NODE(1, FST::RELATION('}', 9)),//8
		FST::NODE(1, FST::RELATION(';', 10)),//9
		FST::NODE()
	);

	if (FST::execute(fst4)) {
		cout << "������� " << fst4.strin << " ����������\n";
	}
	else {
		cout << "������� " << fst4.strin << " �� ����������\n";
	}

	// ������ �������    while?readread????do{write};
	FST::FST fst5(
		"ablcclbbbbe{fl};",
		11,
		FST::NODE(1, FST::RELATION('a', 1)),//0
		FST::NODE(2, FST::RELATION('b', 1), FST::RELATION('l', 2)),//1
		FST::NODE(3, FST::RELATION('c', 2), FST::RELATION('d', 2), FST::RELATION('l', 3)),//2
		FST::NODE(2, FST::RELATION('b', 3), FST::RELATION('b', 4)),//3
		FST::NODE(1, FST::RELATION('e', 5)),//4
		FST::NODE(1, FST::RELATION('{', 6)),//5
		FST::NODE(1, FST::RELATION('f', 7)),//6
		FST::NODE(2, FST::RELATION('b', 7), FST::RELATION('l', 8)),//7
		FST::NODE(1, FST::RELATION('}', 9)),//8
		FST::NODE(1, FST::RELATION(';', 10)),//9
		FST::NODE()
	);

	if (FST::execute(fst5)) {
		cout << "������� " << fst5.strin << " ����������\n";
	}
	else {
		cout << "������� " << fst5.strin << " �� ����������\n";
	}

	// ��������� �������   while??seek?do{write?};
	FST::FST fst6(
		"abbldlbe{fbl};",
		11,
		FST::NODE(1, FST::RELATION('a', 1)),//0
		FST::NODE(2, FST::RELATION('b', 1), FST::RELATION('l', 2)),//1
		FST::NODE(3, FST::RELATION('c', 2), FST::RELATION('d', 2), FST::RELATION('l', 3)),//2
		FST::NODE(2, FST::RELATION('b', 3), FST::RELATION('b', 4)),//3
		FST::NODE(1, FST::RELATION('e', 5)),//4
		FST::NODE(1, FST::RELATION('{', 6)),//5
		FST::NODE(1, FST::RELATION('f', 7)),//6
		FST::NODE(2, FST::RELATION('b', 7), FST::RELATION('l', 8)),//7
		FST::NODE(1, FST::RELATION('}', 9)),//8
		FST::NODE(1, FST::RELATION(';', 10)),//9
		FST::NODE()
	);

	if (FST::execute(fst6)) {
		cout << "������� " << fst6.strin << " ����������\n";
	}
	else {
		cout << "������� " << fst6.strin << " �� ����������\n";
	}

	// ����� �������   while?readseek??do{write?};
	FST::FST fst7(
		"ablcdlbbe{fbl};",
		11,
		FST::NODE(1, FST::RELATION('a', 1)),//0
		FST::NODE(2, FST::RELATION('b', 1), FST::RELATION('l', 2)),//1
		FST::NODE(3, FST::RELATION('c', 2), FST::RELATION('d', 2), FST::RELATION('l', 3)),//2
		FST::NODE(2, FST::RELATION('b', 3), FST::RELATION('b', 4)),//3
		FST::NODE(1, FST::RELATION('e', 5)),//4
		FST::NODE(1, FST::RELATION('{', 6)),//5
		FST::NODE(1, FST::RELATION('f', 7)),//6
		FST::NODE(2, FST::RELATION('b', 7), FST::RELATION('l', 8)),//7
		FST::NODE(1, FST::RELATION('}', 9)),//8
		FST::NODE(1, FST::RELATION(';', 10)),//9
		FST::NODE()
	);

	if (FST::execute(fst7)) {
		cout << "������� " << fst7.strin << " ����������\n";
	}
	else {
		cout << "������� " << fst7.strin << " �� ����������\n";
	}

	// ������ �������   while?readreadread???do{write???}
	FST::FST fst8(
		"ablccclbbbe{fbbbl};",
		11,
		FST::NODE(1, FST::RELATION('a', 1)),//0
		FST::NODE(2, FST::RELATION('b', 1), FST::RELATION('l', 2)),//1
		FST::NODE(3, FST::RELATION('c', 2), FST::RELATION('d', 2), FST::RELATION('l', 3)),//2
		FST::NODE(2, FST::RELATION('b', 3), FST::RELATION('b', 4)),//3
		FST::NODE(1, FST::RELATION('e', 5)),//4
		FST::NODE(1, FST::RELATION('{', 6)),//5
		FST::NODE(1, FST::RELATION('f', 7)),//6
		FST::NODE(2, FST::RELATION('b', 7), FST::RELATION('l', 8)),//7
		FST::NODE(1, FST::RELATION('}', 9)),//8
		FST::NODE(1, FST::RELATION(';', 10)),//9
		FST::NODE()
	);

	if (FST::execute(fst8)) {
		cout << "������� " << fst8.strin << " ����������\n";
	}
	else {
		cout << "������� " << fst8.strin << " �� ����������\n";
	}

	// ������� �������   while?seek?do{write?}
	FST::FST fst9(
		"abldlbe{fbl};",
		11,
		FST::NODE(1, FST::RELATION('a', 1)),//0
		FST::NODE(2, FST::RELATION('b', 1), FST::RELATION('l', 2)),//1
		FST::NODE(3, FST::RELATION('c', 2), FST::RELATION('d', 2), FST::RELATION('l', 3)),//2
		FST::NODE(2, FST::RELATION('b', 3), FST::RELATION('b', 4)),//3
		FST::NODE(1, FST::RELATION('e', 5)),//4
		FST::NODE(1, FST::RELATION('{', 6)),//5
		FST::NODE(1, FST::RELATION('f', 7)),//6
		FST::NODE(2, FST::RELATION('b', 7), FST::RELATION('l', 8)),//7
		FST::NODE(1, FST::RELATION('}', 9)),//8
		FST::NODE(1, FST::RELATION(';', 10)),//9
		FST::NODE()
	);

	if (FST::execute(fst9)) {
		cout << "������� " << fst9.strin << " ����������\n";
	}
	else {
		cout << "������� " << fst9.strin << " �� ����������\n";
	}

	// �������� ��� �������, �� ������� �� ������������    while?readseek?do{write?};;
	FST::FST fst10(
		"ablcdlbee{fbl};",
		11,
		FST::NODE(1, FST::RELATION('a', 1)),//0
		FST::NODE(2, FST::RELATION('b', 1), FST::RELATION('l', 2)),//1
		FST::NODE(3, FST::RELATION('c', 2), FST::RELATION('d', 2), FST::RELATION('l', 3)),//2
		FST::NODE(2, FST::RELATION('b', 3), FST::RELATION('b', 4)),//3
		FST::NODE(1, FST::RELATION('e', 5)),//4
		FST::NODE(1, FST::RELATION('{', 6)),//5
		FST::NODE(1, FST::RELATION('f', 7)),//6
		FST::NODE(2, FST::RELATION('b', 7), FST::RELATION('l', 8)),//7
		FST::NODE(1, FST::RELATION('}', 9)),//8
		FST::NODE(1, FST::RELATION(';', 10)),//9
		FST::NODE()
	);

	if (FST::execute(fst10)) {
		cout << "������� " << fst10.strin << " ����������\n";
	}
	else {
		cout << "������� " << fst10.strin << " �� ����������\n";
	}
	// ������ �����������, �� �������� ��� ������� ������� �������       while?readseek?do{write?};;
	FST::FST fst11(
		"ablcdlbe{fbl};;",
		11,
		FST::NODE(1, FST::RELATION('a', 1)),//0
		FST::NODE(2, FST::RELATION('b', 1), FST::RELATION('l', 2)),//1
		FST::NODE(3, FST::RELATION('c', 2), FST::RELATION('d', 2), FST::RELATION('l', 3)),//2
		FST::NODE(2, FST::RELATION('b', 3), FST::RELATION('b', 4)),//3
		FST::NODE(1, FST::RELATION('e', 5)),//4
		FST::NODE(1, FST::RELATION('{', 6)),//5
		FST::NODE(1, FST::RELATION('f', 7)),//6
		FST::NODE(2, FST::RELATION('b', 7), FST::RELATION('l', 8)),//7
		FST::NODE(1, FST::RELATION('}', 9)),//8
		FST::NODE(1, FST::RELATION(';', 10)),//9
		FST::NODE()
	);

	if (FST::execute(fst11)) {
		cout << "������� " << fst11.strin << " ����������\n";
	}
	else {
		cout << "������� " << fst11.strin << " �� ����������\n";
	}
}