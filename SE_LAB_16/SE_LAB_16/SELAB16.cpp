#include <iostream>
#include <Windows.h>
#include "FST.h"

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// Примеры из лабораторной 16 для проверки
	FST::FST fst1(
		"aaabbbbaba",
		4,
		FST::NODE(3, FST::RELATION('a', 0), FST::RELATION('b', 0), FST::RELATION('a', 1)),
		FST::NODE(1, FST::RELATION('b', 2)),
		FST::NODE(1, FST::RELATION('a', 3)),
		FST::NODE()
	);

	if (FST::execute(fst1)) {
		cout << "Цепочка " << fst1.strin << " распознана\n";
	}
	else {
		cout << "Цепочка " << fst1.strin << " не распознана\n";
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
		cout << "Цепочка " << fst2.strin << " распознана\n";
	}
	else {
		cout << "Цепочка " << fst2.strin << " не распознана\n";
	}


	// Цепочки из лабораторной работы 13
	// Обозначения While – a; ? – b; read – c; seek – d; do – e; write – f;? – l;
	//1 цепочка     while?do{write};
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
		cout << "Цепочка " << fst3.strin << " распознана\n";
	}
	else {
		cout << "Цепочка " << fst3.strin << " не распознана\n";
	}

	// Вторая цепочка    while??read???do{write?};
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
		cout << "Цепочка " << fst4.strin << " распознана\n";
	}
	else {
		cout << "Цепочка " << fst4.strin << " не распознана\n";
	}

	// Третья цепочка    while?readread????do{write};
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
		cout << "Цепочка " << fst5.strin << " распознана\n";
	}
	else {
		cout << "Цепочка " << fst5.strin << " не распознана\n";
	}

	// Четвертая цепочка   while??seek?do{write?};
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
		cout << "Цепочка " << fst6.strin << " распознана\n";
	}
	else {
		cout << "Цепочка " << fst6.strin << " не распознана\n";
	}

	// Пятая цепочка   while?readseek??do{write?};
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
		cout << "Цепочка " << fst7.strin << " распознана\n";
	}
	else {
		cout << "Цепочка " << fst7.strin << " не распознана\n";
	}

	// Шестая цепочка   while?readreadread???do{write???}
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
		cout << "Цепочка " << fst8.strin << " распознана\n";
	}
	else {
		cout << "Цепочка " << fst8.strin << " не распознана\n";
	}

	// Седьмая цепочка   while?seek?do{write?}
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
		cout << "Цепочка " << fst9.strin << " распознана\n";
	}
	else {
		cout << "Цепочка " << fst9.strin << " не распознана\n";
	}

	// Проходит все символы, но цепочка не распознается    while?readseek?do{write?};;
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
		cout << "Цепочка " << fst10.strin << " распознана\n";
	}
	else {
		cout << "Цепочка " << fst10.strin << " не распознана\n";
	}
	// разбор завершается, не перебрав все символы входной цепочки       while?readseek?do{write?};;
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
		cout << "Цепочка " << fst11.strin << " распознана\n";
	}
	else {
		cout << "Цепочка " << fst11.strin << " не распознана\n";
	}
}