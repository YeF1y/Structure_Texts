#include "MyFile.h"
/*读取csv文件数据,将这些数据分组添加到结果向量a中，并返回*/
vector<vector<string>> read()
{
    vector<vector<string>>a;  //二维数组存储读入变量
    vector<string>b;

    cout << "初次运行，读取csv数据中...\n";
    vector<string> row;
    string line;
    ifstream in(".\\data\\景区评论.csv");
    if (in.fail()) { cout << "File not found" << endl; return a; }
    while (getline(in, line) && in.good())
    {
        file_to_string(row, line, ',');  //把line里的单元格数字字符提取出来，“,”为单元格分隔符
        for (int i = 0, leng = row.size(); i < leng; i++) {
            b.push_back(row[i]);
        }
        a.push_back(b);
        b.clear();
    }
    in.close();
    cout << "读取完成！\n";
    return a;
}
/*按照"词语:评论序号->... 频数"的格式，将每个景点的哈希链表写入对应文件
list此景点的HashList
listNum此景点的序号*/
void write(HashList list, int listNum) {
    //合成文件名
    string fileName = ".\\shuju\\A";
    fileName += to_string(listNum);
    fileName += "HashWord.txt";
    //文件写入操作
    ofstream fout(fileName.c_str());
    fout << "景点" << listNum << endl;
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
        fout << "\t\t" << list.list[i].wordCnt << "个\n";
    }
    //结束文件写入
    fout.close();
}