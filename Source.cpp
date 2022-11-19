#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <fstream>
using namespace std;

void GetInput(int& x) {
	fstream out;
	string path = "logs.txt";
	auto now = std::chrono::system_clock::now();
	std::time_t end_time = std::chrono::system_clock::to_time_t(now);
	out.open(path, fstream::in | fstream::out | fstream::app);
#pragma warning(suppress : 4996)
	out << endl << std::ctime(&end_time) << "Pol'zovatel' vvel: " << x << endl;
}
void GetNum(int& x) {
	fstream out;
	string path = "logs.txt";
	auto now = std::chrono::system_clock::now();
	std::time_t end_time = std::chrono::system_clock::to_time_t(now);
	out.open(path, fstream::in | fstream::out | fstream::app);
#pragma warning(suppress : 4996)
	out << endl << x;
}
void GetOutput(string& xx) {
	fstream out;
	string path = "logs.txt";
	auto now = std::chrono::system_clock::now();
	std::time_t end_time = std::chrono::system_clock::to_time_t(now);
	out.open(path, fstream::in | fstream::out | fstream::app);
#pragma warning(suppress : 4996)
	out << endl << std::ctime(&end_time) << xx << endl;
}

int main() {
	setlocale(LC_ALL, "rus");
	int n, k, num, input, temp;
	string xx;
ENTERNUM:
	xx = "Do kakogo chisla budet zagadano chislo?(1-n): ";
	GetOutput(xx);
	cout << xx;
	cin >> n;
	GetInput(n);
	if (n <= 0) {
		xx = "Vvedite chislo ot 1!";
		cout << xx;
		GetOutput(xx);
		goto ENTERNUM;
	}
	num = rand() % n + 1;
	GetNum(num);
	xx = "Vvedite kolichestvo popytok: ";
	GetOutput(xx);
	cout << xx;
	cin >> k;
	GetInput(k);
	temp = k;
	if (k <= 0) {
		xx = "Minimal'noe kolichestvo popytok - 1";
		cout << xx;
		GetOutput(xx);
	}
	for (int i = 0; i < k; i++) {
		xx = "Vvedite vashe chislo: ";
		cout << xx;
		GetOutput(xx);
		cin >> input;
		GetInput(input);
		if (input > num) {
			xx = "Vashe chislo bol'she chem zagadannoe";
			cout << xx << endl;
			GetOutput(xx);
			temp = temp - 1;
			xx = "Ostalos' popytok - ";
			cout << xx << temp << endl;
			GetOutput(xx);
			GetNum(temp);
		}
		else if (input < num) {
			xx = "Vashe chislo men'she chem zagadannoe";
			cout << xx << endl;
			GetOutput(xx);
			temp = temp - 1;
			xx = "Ostalos' popytok - ";
			cout << xx << temp << endl;
			GetOutput(xx);
			GetNum(temp);
		}
		else if (input == num) {
			xx = "Pozdravlyaem! Vy otgadali chislo";
			cout << xx << endl;
			GetOutput(xx);
			goto END;
		}
	}
	xx = "K sozhaleniyu, vy ne otgadali chislo(";
	cout << xx << endl;
	GetOutput(xx);
END:
	xx = " Zagadannoe chislo bylo - ";
	cout << xx << num << endl;
	GetOutput(xx);
	GetNum(num);
}