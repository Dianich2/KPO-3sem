#include <iostream>
#include <Windows.h>
#include "stdafx.h"
#include <locale>
#include <cwchar>
#include <TCHAR.h>
#include "Error.h"
#include "Parm.h"
#include "Log.h"
#include "In.h"
#include "Out.h"
using namespace std;
int _tmain(int argc, _TCHAR* argv[]) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");
	/*cout << "---- ���� Error::geterror  ---" << '\n';
	try {
		throw ERROR_THROW(100);
	}
	catch (Error::ERROr e) {
		cout << "������ " << e.id << ": " << e.message << '\n';
	};
	cout << "---- ���� Error::geterrorin ---" << '\n';
	try {
		throw ERROR_THROW_IN(111, 7, 7);
	}
	catch (Error::ERROr e) {
		cout << "������ " << e.id << ": " << e.message << ", ������ " << e.inext.line <<
			", ������� " << e.inext.col << '\n';
	};*/
	/*cout << "---- ���� Parm::getparm ---" << '\n';
	try {
		Parm::PARm parm = Parm::getparm(argc, argv);
		wcout << "-in:" << parm.in << " -out:" << parm.out << " -log:" << parm.log << '\n';
	}
	catch (Error::ERROr e) {
		cout << "������ " << e.id << ": " << e.message << '\n';
	};*/
	cout << "---- ���� In::getin ---" << '\n';
	try {
		Parm::PARm parm = Parm::getparm(argc, argv);
		In::iN in = In::getin(parm.in);
		cout << in.text << '\n';
		cout << "����� ��������: " << in.size << '\n';
		cout << "����� �����: " << in.lines << '\n';
		cout << "���������: " << in.ignor << '\n';
	}
	catch (Error::ERROr e) {
		cout << "������ " << e.id << ": " << e.message << '\n';
		cout << "������ " << e.inext.line << " ������� " << e.inext.col << '\n';
	}

	Log::LOG log = Log::INITLOG;
	Out::OUt out = Out::INITOUT;
	Parm::PARm parm = Parm::getparm(argc, argv);
	try {
		log = Log::getlog(parm.log);
		Log::WriteLine(log, (char*)"����: ", (char*)"��� ������ \n", "");
		Log::WriteLine(log, (wchar_t*)L"����: ", (wchar_t*)L"��� ������ \n", L"");
		Log::WriteLog(log);
		Log::WriteParm(log, parm);
		In::iN in = In::getin(parm.in);
		Log::WriteIn(log, in);
		Out::WriteOut(in, parm.out);
		Log::Close(log);
	}
	catch (Error::ERROr e) {
		Log::WriteError(log, e);
		Out::OUt out = Out::getout(parm.out);
		Out::WriteError(out, e);
		Out::Close(out);
	}
	return 0;
}