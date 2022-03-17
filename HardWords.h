#pragma once
#include "BaseArray.h"
class HardWords :public BaseArray
{
public:
	static int day,nword;	//天数，单词数
	HardWords();
	void Save();
	void ReviewByDay(int d);	//按天浏览
	void ReviewAll();	//整体浏览
	~HardWords();
};

