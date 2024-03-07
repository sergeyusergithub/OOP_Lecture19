// main.cpp

#include <iostream>
#include <string>
#include <fstream>
#include <array> // ����������� ������
#include <vector> // ������������ ������
#include <deque> // ��������� ������ �������� � ������������ ��������

#include <conio.h>

// ��������� ����� �++
// ���������� � ��������� ����� � ����������� ������
// ����������� ������
// ������������ ������
// deque ������������� �������� �� 8 ��������
// ������ ������ � �������:
// vector ��� ������������� �������� ������, ��
// vector ����������� ���� ������ � 1.2-2 ����

// deque ��� ������������ �������� ����,
// �� ������ ������������� �� ���� ����.

// deque ������� ��������� � ���������� � �������� ��������� � �������� ������,
// � ��������� ����� ���������� � �������� ���������� ��������� �� �������

// vector ������ �������� ��� ���������� � ����� ������

// deque - ������������� -> ������ �������� � ���������� ������� � ������������ �����

#include <queue> // ������� FIFO
#include <stack> // ������� FILO
#include <list>

// ������� ����� ��� ������ ��������� - ����������� ������ ������� ���������� �������
class DemoGood {
public:
	// ����������� �� ���������
	DemoGood() {
		std::cout << this << " create by default constructor\n";
	}

	// ��������������� �����������
	DemoGood(int a, bool b) {
		std::cout << this << " create by parametric constructor\n";
	}

	// ����������� �����������
	DemoGood(const DemoGood& other) {
		std::cout << this << " create by copy constructor\n";
		std::cout << "from " << &other << " object\n";
	}

	// ����������
	~DemoGood() {
		std::cout << this << " destroyed\n";
	}

	int var;

};


// ������ ����� ��� ������ ��������� - ��� ����������� ������� ������� ���������� �������
class DemoBad {
public:
	// ����������� �� ���������
	DemoBad() = delete; // ������ �����������  ���������� ������������ �� ���������

	// ��������������� �����������
	DemoBad(int a, bool b) = delete;
	/*{
		std::cout << this << " create by parametric constructor\n";
	}*/

	// ����������� �����������
	DemoBad(const DemoGood& other) {
		std::cout << this << " create by copy constructor\n";
		std::cout << "from " << &other << " object\n";
	}

	// ����������
	~DemoBad() {
		std::cout << this << " destroyed\n";
	}

};

int mainOld() {

	/*DemoGood arr[10];
	std::cout << std::size(arr) << std::endl;*/

	std::array<DemoGood, 10> arrST;

	// ����������� ������ �������� ����� ��� ���� ����������� ����� ������ � ���������
	// ��� ��������� ���������� ������������� �� ���������

	std::vector<DemoGood> arrDin;
	arrDin.reserve(10);
	// ������ �� �������� ������ ���� ��� �� �������, �� ����� ���������
	// �������� ��������������� ����� �� �������� �������

	std::deque<DemoGood> arrDeque(10);
	// ���� ��� � ������� ����� ��� �������� ������� �� �����
	// ���������� ��������� ��� �������. ��� ���� ����� �������
	// ����������� ���������� �������� � ������� ������������ �� ���������

	//std::array<DemoBad, 10> arrST2{
	//							DemoBad(1,true),
	//							DemoBad(2,true),
	//							DemoBad(3,true), 
	//							DemoBad(4,true), 
	//							DemoBad(5,true), 
	//							DemoBad(6,true), 
	//							DemoBad(7,true), 
	//							DemoBad(8,true), 
	//							DemoBad(9,true), 
	//							DemoBad(0,true), 
	//// � ������ ���������� ������������ �� ��������� ��� ����������� ���������, ������� ��������� ����� ���� ������������ ������-��
	//// ���������, �������� ������� ������������ ����� ������ �������������.
	//// ������ ����� ������ �� ��������� � {}					
	//};

	// std::vector<DemoBad> nArr(arrST2.begin(),arrST2.end());


	arrDin.push_back(DemoGood(0, true)); // insert ������ �������� �� ���� ������������� �����������
	arrDin.emplace_back(0, true); //  emplace ������ �������� �� ���� ������������� � �����������

	std::vector<DemoBad> nArr;

	/*nArr.push_back(DemoBad(0, true));
	nArr.emplace_back(0, true);*/
	// ��� ��� ����������� � ����������� �� �������� ������ ��������� emplace ����� �������� ������ ������ � ���������
	// �� ������������� ��������� � ������� ������������


	std::cout << "=============================================================\n";
	std::vector<DemoGood> example;

	for (int i = 0; i < 17; i++) {
		//example.emplace_back(i, bool(i % 2));
		example.push_back(DemoGood(i, bool(i % 2)));
	}


	return 0;
}


int main() {
	// queue ������� �������� api, �������� �� ������� ������� ���� �������� ������� �� �������������
	/*std::queue<int, std::list<int>> qwe;

	for (int i = 0; i < 7; ++i) {
		qwe.push(i);
		std::cout << i << ' ';
	}
	std::cout << '\n';

	for (int i = 0; i < 7; ++i) {
		std::cout << qwe.front() << ' ';
		qwe.pop();
	}
	std::cout << "\n\n";*/
	std::ifstream input;

	input.open("ListHuman.txt");

	std::queue<std::string> qlist1;
	std::queue<std::string> qlist2;

	//std::stack<std::string> slist;

	std::string str;

	int count{};
	while (std::getline(input,str)) {
		qlist1.push(str);
		//slist.push(str);
		qlist2.push(str);
		count++;
	}

	str = qlist1.front();
	qlist1.pop();
	qlist1.push(str);
	size_t size = qlist1.size();
	for (size_t i = 0; i < size; i++) {
		std::cout << qlist1.front() << "     " << qlist2.front() << '\n';
		qlist1.pop();
		qlist2.pop();
	}
	//std::cout << "count " << count << '\n';

	/*if (count % 2) {
		str = qlist.front();
		qlist.pop();
		qlist.push(str);
		size_t size = qlist.size();
		for (size_t i = 0; i < size; i++) {
			std::cout << qlist.front() << "     " << slist.top() << '\n';
			qlist.pop();
			slist.pop();
		}
	}
	else {
		size_t size = qlist.size();
		for (size_t i = 0; i < size; i++) {
			std::cout << qlist.front() << "     " << slist.top() << '\n';
			qlist.pop();
			slist.pop();
		}
		

	}*/

	// stack 
	//std::stack<DemoGood, std::list<DemoGood>> qwe;

	//// ��������� ����� ������� ��������� � ������� ��������� ������
	//// �� �����, ����� � ����� �� ���� ����������� �������� � ����������� ���������� �������.
	//{
	//	//DemoGood tmp;
	//	//for (int i = 0; i < 7; ++i) {
	//	/*tmp.var = i;
	//	qwe.push(tmp);
	//}*/
	//	for (struct { int i = 0; DemoGood tmp; } count; count.i < 7; count.i++) {
	//		
	//		count.tmp.var = count.i;
	//		qwe.push(count.tmp);
	//	}

	//}
	//

	//for (int i = 0; i < 7; ++i) {
	//	std::cout << qwe.top().var << ' ';
	//	qwe.pop();
	//}
	//std::cout << "\n\n";



	return 0;
}