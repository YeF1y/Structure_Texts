
#ifndef MYFILE_H

#define MYFILE_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "MyHash.h"
using namespace std;
/*��ȡcsv�ļ����ݵ�record�ַ��������У�������һ������
record���������
line�ļ�������
delimiter�ı��ָ�����,) */
inline void file_to_string(vector<string>& record, const string& line, char delimiter)
{
    wchar_t c;
    int linepos = 0;
    int linemax = line.length();
    string curstring;
    record.clear();

    while (linepos < linemax)
    {
        c = line[linepos];
        //�����ִ�ʱ����ͷ��β����\"�����ı��ָ����ı��\"��������������ִ�
        if (c == wchar_t('\"'))
            delimiter = '\"';
        else if (c != delimiter)
            curstring += c;
        if (c == delimiter && curstring.size()) {
            record.push_back(curstring);
            curstring = "";
        }
        ++linepos;
    }
    if (curstring.size())
        record.push_back(curstring);
    return;
}

vector<vector<string>> read();
void write(HashList, int);

#endif