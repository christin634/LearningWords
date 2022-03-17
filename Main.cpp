#include <iostream>
#include "Frame.h"
using namespace std;

int main()
{        
	Frame frame;
	while (1) {
		system("cls");
		frame.ShowMenu();
		int c;
		cin >> c;
		switch (c) {
		case 1:frame.Import(); break;
		case 2:frame.SetPlan(); break;
		case 3:frame.LearnMenu(); break;
		case 4:frame.ShowRecord(); break;
		case 0:frame.Save(); exit(0); break;
		default:cout << "\t输入错误！" << endl; 
			system("pause");
			continue;
		}
	}
	return 0;
}
