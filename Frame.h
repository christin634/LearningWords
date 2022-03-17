#pragma once
#include "HardWords.h"
#include "LearnedWords.h"
#include "wordbase.h"

class Frame
{
public:
	Frame();
	void ShowMenu()const;
	void Import();	//���뵥�ʿ�
	void SetPlan();	//����ѧϰ�ƻ�
	void LearnMenu();	//ѧϰĿ¼
	void Learn();	//ѧϰ
	void Review();	//��ϰ
	void Save();	//���浽�ļ�
	void ShowRecord();	//��ʾ�򿨼�¼
private:
	HardWords hw;	//���ʱ�
	LearnedWords lw;	//��ѧϰ���ʱ�
	WordBase wb;	//δ���䵥�ʱ�
	int n,nd;	//�ռƻ�ѧϰ������,������
	char c;	//ѧϰ˳��
};

