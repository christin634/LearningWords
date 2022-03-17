#include "Frame.h"
#include <ctime>
#include <cstdlib>

Frame::Frame():c('0'),n(0),nd(0){}

void Frame::ShowMenu()const {
    cout << "|**********************************************|" << endl;
    cout << "|*|==========================================|*|" << endl;
    cout << "|*|                                          |*|" << endl;
    cout << "|*|          欢迎进入我爱记单词系统！        |*|" << endl;
    cout << "|*|                                          |*|" << endl;
    cout << "|*|       1.单词库导入   2.学习计划设置      |*|" << endl;
    cout << "|*|                                          |*|" << endl;
    cout << "|*|       3.单词学习     4.显示打卡记录      |*|" << endl;
    cout << "|*|                                          |*|" << endl;
    cout << "|*|       0.退出系统                         |*|" << endl;
    cout << "|*|                                          |*|" << endl;
    cout << "|*|==========================================|*|" << endl;
    cout << "	请选择:  ";
}

void Frame::Import() {
    system("cls");
    cout << "\t单词库选择\t" << endl << endl;;
    cout << "  1.CET-6(a-f)" << endl << endl;;
    cout << "  2.CET-6(g-p)" << endl << endl;;
    cout << "  3.CET-6(q-z)" << endl << endl;;
    while (1) {
        cout << "请选择:";
        int c;
        cin >> c;
        switch (c) {
        case 1:wb.SetBase_name("CET-6(a-f).txt"); wb.ImportWords("CET-6(a-f).txt", 938); break;
        case 2:wb.SetBase_name("CET-6(g-p).txt"); wb.ImportWords("CET-6(g-p).txt", 690); break;
        case 3:wb.SetBase_name("CET-6(q-z).txt"); wb.ImportWords("CET-6(q-z).txt", 592); break;
        default:cout << "输入错误！" << endl;
        }
        if(c==1||c==2||c==3)
            break;
    }
    system("pause");
}

void Frame::SetPlan() {
    system("cls");
    int n,num=wb.GetNum();
    char c;
    cout << "\t学习计划设置\t" << endl << endl;
    cout << "  日计划学习单词数:"; cin >> n;
    this->n = n;
    cout << endl;
    cout << "  学习顺序(A.按词表顺序 B.随机顺序):"; cin >> c;
    this->c = c;
    cout << endl;
    nd = (num % n) ? (num / n + 1) : (num / n);
    cout << "\t学习计划设置完成！" << endl << endl;;
    cout << "  日学习单词数为" << n << ",预计需要" <<nd<< "天\n\n";
    cout << "  学习顺序为";
    if (c == 'A')
    	cout << "词表顺序" << endl;
    else if(c=='B')
    	cout << "随机顺序" << endl;
    cout << endl;
    system("pause");
}

void Frame::LearnMenu() {
    system("cls");
    cout <<"\t单词学习\t\n"<<endl ;
    cout << "  1.学习新单词" << endl << endl;
    cout << "  2.复习生词表" << endl << endl;
    while(1){
        int c;
        cout << "请选择:"; cin >> c;
        switch (c) {
        case 1:Learn(); break;
        case 2:Review(); break;
        default:cout << "输入错误！" << endl;
        }
        if (c == 1 || c == 2)
            break;
    }
}

void Frame::Learn() {
    hw.day++;   //天数增加
    wb.day++;   //天数增加
    if (c == 'A') {
        int i = 0;
        int n =this->n;
        for (int j=0; j < n&&wb.GetNum()>0;  j++,wb.wordnum++) {
            system("cls");
            Word w = wb.GetWord(i);
            cout << w << endl;
            cout << "1.加入到生词表\t2.下一个" << endl;
            lw.AddWords(w); 
            wb.DeleteWord(i);
            int c;
            cin >> c;
            if (c == 1) {
                hw.AddWords(w);
            }
            else if (c == 2)
                continue;
        }
    }
    else if(c == 'B'){
        int times = this->n;
        for(int i=0;i < times && wb.GetNum()>0; i++) {
            system("cls");
            srand((unsigned)time(NULL));
            int index = rand() % wb.GetNum();
            Word w = wb.GetWord(index);
            wb.wordnum++;
            lw.AddWords(w);
            wb.DeleteWord(index);
            cout << w << endl;
            cout << "1.加入到生词表\t2.下一个" << endl;
            int c;
            cin >> c;
            if (c == 1) {
                hw.AddWords(w);
            }
            else if (c == 2)
                continue;
        }
    }
    system("cls");
    cout << "今日学习计划已完成！" << endl;
    hw.Save();  //分别按天和整体保存到文件中
    system("pause");
}

void Frame::Review() {
    system("cls");
    cout << "\t复习生词表\t\n" << endl;
    cout << "  1.按天复习\t2.整体浏览" << endl << endl;
    cout << "请选择:";
    int c;
    cin >> c;
    switch (c) {
    case 1:while (1) {
        int d; cout << "请输入天数:"; cin >> d;
        if (d <= hw.day && d > 0) {
            hw.ReviewByDay(d);
            break;
        }
        else
            cout << "输入错误！" << endl;
    }break;
    case 2:hw.ReviewAll(); break;
    default:cout << "输入错误！"<<endl;
    }
    system("pause");
}

void Frame::Save() {
    system("cls");
    lw.Save();
    wb.Save();
    cout << "保存成功！" << endl;
}

void Frame::ShowRecord() {
    system("cls");
    cout << "已打卡学习" << WordBase::day << "天" << endl;
    cout << "已学习单词"<<WordBase::wordnum<<"个" << endl;
    cout << "需要重点记忆的单词有"<<HardWords::nword<<"个"<<endl;
    system("pause");
}