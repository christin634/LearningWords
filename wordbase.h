#pragma once
#include "BaseArray.h"
using namespace std;
class WordBase:public BaseArray{	//未记忆单词
public:
	static int day, wordnum;	//学习到第几天，单词索引
	WordBase();
	void ImportWords(string base_name,int num);	//单词库导入
	void SetBase_name(string Base_name);	//设置词库名
	void DeleteWord(int index);	//将已记忆单词删除
	Word& GetWord(int index)const;
	~WordBase();	//析构函数
private:
	string base_name;
};

