#pragma once
#include "HardWords.h"
#include "LearnedWords.h"
#include "wordbase.h"

class Frame
{
public:
	Frame();
	void ShowMenu()const;
	void Import();	//导入单词库
	void SetPlan();	//设置学习计划
	void LearnMenu();	//学习目录
	void Learn();	//学习
	void Review();	//复习
	void Save();	//保存到文件
	void ShowRecord();	//显示打卡记录
private:
	HardWords hw;	//生词表
	LearnedWords lw;	//已学习单词表
	WordBase wb;	//未记忆单词表
	int n,nd;	//日计划学习单词数,总天数
	char c;	//学习顺序
};

