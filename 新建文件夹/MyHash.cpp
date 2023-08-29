#include "MyHash.h"

map<string, int> dictionary;//总词典，记录所有景点的分词和对应的分词数(合并排序用)
int wholeWordsCnt = 0;		//所有景点所有分词的总数


/*在对应的哈希链表中利用头插法插入对应的一个元素
list此景点的HashList
wordNum分词在HashList中的数组下标
number评论序号
words分词内容*/


void insertElem(HashList &list, int wordNum, int number, string words) {
	//新建节点，用于插入操作
	HashNode* tmp = new HashNode;
	tmp->number = number;
	wordNum--;
	//此分词首次出现，记录分词内容
	if (list.list[wordNum].first == NULL) {
		list.list[wordNum].str = words;
	}
	//更新分词数
	list.list[wordNum].wordCnt++;
	list.wordsCnt[list.list[wordNum].str] = list.list[wordNum].wordCnt;
	//更新总词典数据
	if (dictionary[words] == 0)
		wholeWordsCnt++;
	dictionary[words]++;
	//头插法插入元素
	tmp->next = list.list[wordNum].first;
	list.list[wordNum].first = tmp;
}
/*根据读入的数据，建立各个景点对应的哈希链表
lists[]所有景点的哈希链表们
data从csv文档中读取的数据*/
void createHashLists(HashList lists[], vector<vector<string>>& data) {
	//景点1~50
	for (int i = 1; i < data.size(); i++) {
		//此景点无数据
		if (data[i].empty())
			return;
		int number = atoi(data[i][0].c_str());				//评论序号
		int listNum = atoi(data[i][1].substr(1).c_str());	//景点号
		string wordsToDivide = data[i][4] + ",";			//将分词们再次划分前的数据
		string tmp = "";									//划分后的单个分词
		for (int j = 0; wordsToDivide[j] != '\0'; j++) {
			wchar_t ch = wordsToDivide[j];
			if (ch != ',' && ch != '\0')
				tmp += ch;
			else {
				//获得一个完整的分词，对其进行插入操作
				//为首次出现的分词开辟空间
				if (lists[listNum].list.size() < lists[listNum].wordsTotal) {
					HashFirst s;
					lists[listNum].list.push_back(s);
				}
				//首次出现，为其分配数组下标
				if (lists[listNum].hash[tmp] == 0)
					lists[listNum].hash[tmp] = lists[listNum].wordsTotal++;
				//进行单个元素的插入
				insertElem(lists[listNum], lists[listNum].hash[tmp], number, tmp);
				tmp.clear();
			}
		}
	}
}
/*展示一个景点的哈希链表数据（分词+链表+个数）
lists景点的哈希链表
listNum景点序号
showList是否展示链表部分*/
void showDetails(HashList list, int listNum, bool showList) {
	//输出当前景点
	cout << "景点" << listNum << endl;
	//当前景点数据为空
	if (list.list.empty())
		return;
	//输出所有哈希链表数据
	for (int i = 0; i < list.list.size()-1; i++) {
		HashNode* tmp = list.list[i].first;
		string str = list.list[i].str;
		//分词部分
		cout << str;
		//是否展示链表部分
		if (showList) {
			while (tmp) {
				cout << "->" << tmp->number;
				tmp = tmp->next;
			}
		}
		//个数部分
		cout << "\t\t" << list.list[i].wordCnt << "个\n";
	}
}
/*重载，多函数同名
dic对应dictionary
dicNum对应wholeWordCnt*/
void getDictionary(MP& dic, int& dicNum) {
	dic = dictionary;
	dicNum = wholeWordsCnt;
}
void getDictionary(int& dicNum) {
	dicNum = wholeWordsCnt;
}