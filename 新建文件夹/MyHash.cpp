#include "MyHash.h"

map<string, int> dictionary;//�ܴʵ䣬��¼���о���ķִʺͶ�Ӧ�ķִ���(�ϲ�������)
int wholeWordsCnt = 0;		//���о������зִʵ�����


/*�ڶ�Ӧ�Ĺ�ϣ����������ͷ�巨�����Ӧ��һ��Ԫ��
list�˾����HashList
wordNum�ִ���HashList�е������±�
number�������
words�ִ�����*/


void insertElem(HashList &list, int wordNum, int number, string words) {
	//�½��ڵ㣬���ڲ������
	HashNode* tmp = new HashNode;
	tmp->number = number;
	wordNum--;
	//�˷ִ��״γ��֣���¼�ִ�����
	if (list.list[wordNum].first == NULL) {
		list.list[wordNum].str = words;
	}
	//���·ִ���
	list.list[wordNum].wordCnt++;
	list.wordsCnt[list.list[wordNum].str] = list.list[wordNum].wordCnt;
	//�����ܴʵ�����
	if (dictionary[words] == 0)
		wholeWordsCnt++;
	dictionary[words]++;
	//ͷ�巨����Ԫ��
	tmp->next = list.list[wordNum].first;
	list.list[wordNum].first = tmp;
}
/*���ݶ�������ݣ��������������Ӧ�Ĺ�ϣ����
lists[]���о���Ĺ�ϣ������
data��csv�ĵ��ж�ȡ������*/
void createHashLists(HashList lists[], vector<vector<string>>& data) {
	//����1~50
	for (int i = 1; i < data.size(); i++) {
		//�˾���������
		if (data[i].empty())
			return;
		int number = atoi(data[i][0].c_str());				//�������
		int listNum = atoi(data[i][1].substr(1).c_str());	//�����
		string wordsToDivide = data[i][4] + ",";			//���ִ����ٴλ���ǰ������
		string tmp = "";									//���ֺ�ĵ����ִ�
		for (int j = 0; wordsToDivide[j] != '\0'; j++) {
			wchar_t ch = wordsToDivide[j];
			if (ch != ',' && ch != '\0')
				tmp += ch;
			else {
				//���һ�������ķִʣ�������в������
				//Ϊ�״γ��ֵķִʿ��ٿռ�
				if (lists[listNum].list.size() < lists[listNum].wordsTotal) {
					HashFirst s;
					lists[listNum].list.push_back(s);
				}
				//�״γ��֣�Ϊ����������±�
				if (lists[listNum].hash[tmp] == 0)
					lists[listNum].hash[tmp] = lists[listNum].wordsTotal++;
				//���е���Ԫ�صĲ���
				insertElem(lists[listNum], lists[listNum].hash[tmp], number, tmp);
				tmp.clear();
			}
		}
	}
}
/*չʾһ������Ĺ�ϣ�������ݣ��ִ�+����+������
lists����Ĺ�ϣ����
listNum�������
showList�Ƿ�չʾ������*/
void showDetails(HashList list, int listNum, bool showList) {
	//�����ǰ����
	cout << "����" << listNum << endl;
	//��ǰ��������Ϊ��
	if (list.list.empty())
		return;
	//������й�ϣ��������
	for (int i = 0; i < list.list.size()-1; i++) {
		HashNode* tmp = list.list[i].first;
		string str = list.list[i].str;
		//�ִʲ���
		cout << str;
		//�Ƿ�չʾ������
		if (showList) {
			while (tmp) {
				cout << "->" << tmp->number;
				tmp = tmp->next;
			}
		}
		//��������
		cout << "\t\t" << list.list[i].wordCnt << "��\n";
	}
}
/*���أ��ຯ��ͬ��
dic��Ӧdictionary
dicNum��ӦwholeWordCnt*/
void getDictionary(MP& dic, int& dicNum) {
	dic = dictionary;
	dicNum = wholeWordsCnt;
}
void getDictionary(int& dicNum) {
	dicNum = wholeWordsCnt;
}