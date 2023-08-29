
#ifndef MYFILE_H

#define MYFILE_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "MyHash.h"
using namespace std;
/*读取csv文件数据到record字符串向量中，方便下一步操作
record读入的数据
line文件行输入
delimiter文本分隔符（,) */
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
        //碰到分词时，开头结尾都是\"，将文本分隔符改变成\"，方便读入整串分词
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