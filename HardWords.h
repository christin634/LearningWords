#pragma once
#include "BaseArray.h"
class HardWords :public BaseArray
{
public:
	static int day,nword;	//������������
	HardWords();
	void Save();
	void ReviewByDay(int d);	//�������
	void ReviewAll();	//�������
	~HardWords();
};

