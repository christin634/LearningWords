#pragma once
#include "BaseArray.h"
using namespace std;
class WordBase:public BaseArray{	//δ���䵥��
public:
	static int day, wordnum;	//ѧϰ���ڼ��죬��������
	WordBase();
	void ImportWords(string base_name,int num);	//���ʿ⵼��
	void SetBase_name(string Base_name);	//���ôʿ���
	void DeleteWord(int index);	//���Ѽ��䵥��ɾ��
	Word& GetWord(int index)const;
	~WordBase();	//��������
private:
	string base_name;
};

