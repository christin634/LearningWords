#include "Frame.h"
#include <ctime>
#include <cstdlib>

Frame::Frame():c('0'),n(0),nd(0){}

void Frame::ShowMenu()const {
    cout << "|**********************************************|" << endl;
    cout << "|*|==========================================|*|" << endl;
    cout << "|*|                                          |*|" << endl;
    cout << "|*|          ��ӭ�����Ұ��ǵ���ϵͳ��        |*|" << endl;
    cout << "|*|                                          |*|" << endl;
    cout << "|*|       1.���ʿ⵼��   2.ѧϰ�ƻ�����      |*|" << endl;
    cout << "|*|                                          |*|" << endl;
    cout << "|*|       3.����ѧϰ     4.��ʾ�򿨼�¼      |*|" << endl;
    cout << "|*|                                          |*|" << endl;
    cout << "|*|       0.�˳�ϵͳ                         |*|" << endl;
    cout << "|*|                                          |*|" << endl;
    cout << "|*|==========================================|*|" << endl;
    cout << "	��ѡ��:  ";
}

void Frame::Import() {
    system("cls");
    cout << "\t���ʿ�ѡ��\t" << endl << endl;;
    cout << "  1.CET-6(a-f)" << endl << endl;;
    cout << "  2.CET-6(g-p)" << endl << endl;;
    cout << "  3.CET-6(q-z)" << endl << endl;;
    while (1) {
        cout << "��ѡ��:";
        int c;
        cin >> c;
        switch (c) {
        case 1:wb.SetBase_name("CET-6(a-f).txt"); wb.ImportWords("CET-6(a-f).txt", 938); break;
        case 2:wb.SetBase_name("CET-6(g-p).txt"); wb.ImportWords("CET-6(g-p).txt", 690); break;
        case 3:wb.SetBase_name("CET-6(q-z).txt"); wb.ImportWords("CET-6(q-z).txt", 592); break;
        default:cout << "�������" << endl;
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
    cout << "\tѧϰ�ƻ�����\t" << endl << endl;
    cout << "  �ռƻ�ѧϰ������:"; cin >> n;
    this->n = n;
    cout << endl;
    cout << "  ѧϰ˳��(A.���ʱ�˳�� B.���˳��):"; cin >> c;
    this->c = c;
    cout << endl;
    nd = (num % n) ? (num / n + 1) : (num / n);
    cout << "\tѧϰ�ƻ�������ɣ�" << endl << endl;;
    cout << "  ��ѧϰ������Ϊ" << n << ",Ԥ����Ҫ" <<nd<< "��\n\n";
    cout << "  ѧϰ˳��Ϊ";
    if (c == 'A')
    	cout << "�ʱ�˳��" << endl;
    else if(c=='B')
    	cout << "���˳��" << endl;
    cout << endl;
    system("pause");
}

void Frame::LearnMenu() {
    system("cls");
    cout <<"\t����ѧϰ\t\n"<<endl ;
    cout << "  1.ѧϰ�µ���" << endl << endl;
    cout << "  2.��ϰ���ʱ�" << endl << endl;
    while(1){
        int c;
        cout << "��ѡ��:"; cin >> c;
        switch (c) {
        case 1:Learn(); break;
        case 2:Review(); break;
        default:cout << "�������" << endl;
        }
        if (c == 1 || c == 2)
            break;
    }
}

void Frame::Learn() {
    hw.day++;   //��������
    wb.day++;   //��������
    if (c == 'A') {
        int i = 0;
        int n =this->n;
        for (int j=0; j < n&&wb.GetNum()>0;  j++,wb.wordnum++) {
            system("cls");
            Word w = wb.GetWord(i);
            cout << w << endl;
            cout << "1.���뵽���ʱ�\t2.��һ��" << endl;
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
            cout << "1.���뵽���ʱ�\t2.��һ��" << endl;
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
    cout << "����ѧϰ�ƻ�����ɣ�" << endl;
    hw.Save();  //�ֱ�������屣�浽�ļ���
    system("pause");
}

void Frame::Review() {
    system("cls");
    cout << "\t��ϰ���ʱ�\t\n" << endl;
    cout << "  1.���츴ϰ\t2.�������" << endl << endl;
    cout << "��ѡ��:";
    int c;
    cin >> c;
    switch (c) {
    case 1:while (1) {
        int d; cout << "����������:"; cin >> d;
        if (d <= hw.day && d > 0) {
            hw.ReviewByDay(d);
            break;
        }
        else
            cout << "�������" << endl;
    }break;
    case 2:hw.ReviewAll(); break;
    default:cout << "�������"<<endl;
    }
    system("pause");
}

void Frame::Save() {
    system("cls");
    lw.Save();
    wb.Save();
    cout << "����ɹ���" << endl;
}

void Frame::ShowRecord() {
    system("cls");
    cout << "�Ѵ�ѧϰ" << WordBase::day << "��" << endl;
    cout << "��ѧϰ����"<<WordBase::wordnum<<"��" << endl;
    cout << "��Ҫ�ص����ĵ�����"<<HardWords::nword<<"��"<<endl;
    system("pause");
}