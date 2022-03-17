#include "word.h"

Word::Word():id(0),name(""),content(""){}

Word::Word(int id, string name, string content) {
	this->id = id;
	this->name = name;
	this->content = content;
}

Word& Word::operator=(const Word& w) {
	id = w.id;
	name = w.name;
	content = w.content;
	return *this;
}

ostream& operator<<(ostream& out, const Word &word)
{
	out <<word.id<<"\t"<< word.name << "\t" << word.content << endl;
	return out;
}