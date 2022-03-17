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
	int num;	//单词数目
	Word* list;	//动态数组头指针
	string file_name;	//保存的文件名
};

