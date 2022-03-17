#pragma once
#include<iostream>
#include<string>
using namespace std;
class Word{
public:
	Word();
	Word(int id, string name, string content);
	Word& operator=(const Word &w);
	friend ostream& operator<<(ostream& out,const Word &word);
private:
	int id;    //单词编号
	string name;	//单词
	string content;	   //单词解释
};

