#include "BaseArray.h"

BaseArray::BaseArray() {
	num = 0;
	list = NULL;
	file_name = "";
}

Word& BaseArray::operator[] (int index) {
	assert(index >= 0&&index<=num);
	return list[index];
}

BaseArray::~BaseArray() {
	delete[] list;
}

void BaseArray::AddWords(Word& w) {
	int size=num+1,i;
	Word* ls = new Word[size];
	for (i=0; i < num; i++)
		ls[i] = list[i];
	ls[i] = w;
	delete[] list;
	list = ls;
	num = size;
}

int BaseArray::GetNum()const { return num; }

void BaseArray::SetFile_name(string file_name) {
	this->file_name = file_name;
}

void BaseArray::Save() {
	ofstream fout(file_name);
	assert(fout.is_open());
	for (int i = 0; i < num; i++)
		fout << list[i] ;
	fout.close();
}