#pragma once
#include "word.h"
#include <fstream>
#include <cassert>

class BaseArray
{
public:
	BaseArray();
	void AddWords(Word& w);
	Word& operator[] (int index);
	void SetFile_name(string file_name) ;
	void Save();
	int GetNum()const;
	~BaseArray();
protected:
	int num;	//������Ŀ
	Word* list;	//��̬����ͷָ��
	string file_name;	//������ļ���
};

