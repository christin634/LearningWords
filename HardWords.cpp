#include "HardWords.h"
#include <sstream>

int HardWords::day = 0;
int HardWords::nword = 0;

HardWords::HardWords(){
	SetFile_name("HardWords.txt");
}

void HardWords::Save() {
	BaseArray::Save();	//整体保存
	stringstream ss;	//按天保存
	string name="day";
	int n= BaseArray::GetNum() ;
	ss << day;	//将int类型转换为字符串
	name =name+ss.str()+".txt";
	ofstream fout(name);
	assert(fout.is_open());
	for(int i=nword;i<n;i++)
		fout << list[i];
	nword = BaseArray::GetNum();
	fout.close();
}

void HardWords::ReviewByDay(int d) {
	system("cls");
	string name = "day";
	stringstream ss;
	ss << d;
	name = name + ss.str() + ".txt";
	ifstream in(name);
	assert(in.is_open());
	string  s;
	while (getline(in, s)){
		cout << s << endl;
	}
	in.close();
}

void HardWords::ReviewAll() {
	system("cls");
	string  s;
	ifstream in(file_name);
	assert(in.is_open());
	while (getline(in, s)){
		cout << s << endl;
	}
	in.close();
}

HardWords::~HardWords() {}