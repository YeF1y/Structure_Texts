#include "MyFile.h"
/*��ȡcsv�ļ�����,����Щ���ݷ�����ӵ��������a�У�������*/
vector<vector<string>> read()
{
    vector<vector<string>>a;  //��ά����洢�������
    vector<string>b;

    cout << "�������У���ȡcsv������...\n";
    vector<string> row;
    string line;
    ifstream in(".\\data\\��������.csv");
    if (in.fail()) { cout << "File not found" << endl; return a; }
    while (getline(in, line) && in.good())
    {
        file_to_string(row, line, ',');  //��line��ĵ�Ԫ�������ַ���ȡ��������,��Ϊ��Ԫ��ָ���
        for (int i = 0, leng = row.size(); i < leng; i++) {
            b.push_back(row[i]);
        }
        a.push_back(b);
        b.clear();
    }
    in.close();
    cout << "��ȡ��ɣ�\n";
    return a;
}
/*����"����:�������->... Ƶ��"�ĸ�ʽ����ÿ������Ĺ�ϣ����д���Ӧ�ļ�
list�˾����HashList
listNum�˾�������*/
void write(HashList list, int listNum) {
    //�ϳ��ļ���
    string fileName = ".\\shuju\\A";
    fileName += to_string(listNum);
    fileName += "HashWord.txt";
    //�ļ�д�����
    ofstream fout(fileName.c_str());
    fout << "����" << listNum << endl;
    if (list.list.empty())
        return;
    for (int i = 0; i < list.list.size() - 1; i++) {
        HashNode* tmp = list.list[i].first;
        string str = list.list[i].str;
        fout << str;
            while (tmp) {
                fout << "->" << tmp->number;
                tmp = tmp->next;
            }
        fout << "\t\t" << list.list[i].wordCnt << "��\n";
    }
    //�����ļ�д��
    fout.close();
}