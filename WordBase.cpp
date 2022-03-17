#include "wordbase.h"

int WordBase::day = 0;
int WordBase::wordnum = 0;

WordBase::WordBase(){
	BaseArray::SetFile_name("LeftWords.txt");
}

void WordBase::SetBase_name(string Base_name) {
	this->base_name = Base_name;
}

Word& WordBase::GetWord(int index)const { return list[index]; }

void WordBase::ImportWords(string base_name, int num) {
	system("cls");
	this->num = num;
	this->list = new Word[num];
	ifstream in(base_name);
	assert(in.is_open());
	for(int i=0;i<num;i++){
		int id;
		string name, content;
		in >> id >> name >> content;
		Word w(id, name, content);
		list[i] = w;
	}
	in.close();
	cout << "导入成功！"<<endl;
}

void WordBase::DeleteWord(int index) {
	if (num == 0)
		return;
	else if (num == 1) {
		num-=1;
		delete[] list;
	}
	else if(num>1){
		int size = num - 1;
		int i, j;
		Word* ls = new Word[size];
		for (i = 0; i < index; i++)
			ls[i] = list[i];
		for (j = index + 1; j < num; i++,j++)
			ls[i] = list[j];
		delete[] list;
		num = size;
		list = ls;
	}
}

WordBase::~WordBase() {}


