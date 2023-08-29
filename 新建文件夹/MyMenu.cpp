#include "MyMenu.h"

void mainMenu(char& opt) {

	static HashList lists[55];			//���нڵ�Ĺ�ϣ������
	static vector<vector<string>> data;	//���ļ�������
	static bool isFirstRun = true;		//�Ƿ��ǵ�һ������Ŀ¼
	static bool isChainSpawn = false;	//��ϣ�����Ƿ�������ϣ�ֻ����ϲ��ܽ��к������

	//��������
	if (isFirstRun) {
		data = read();		//���ļ�
		Sleep(1000);
		isFirstRun = false;
	}

	system("cls");			//��������ʾ�˵������ְ취��ȱ���ǳ����������ϵͳ����ִ�������������ӳ��˳���ִ��ʱ�䡣
	cout << "------���������ı����ȶȵ���------\n";
	cout << "[1]���ɹ�ϣ��\n";
	cout << "[2]չʾĳ�������Ĵ�Ƶ\n";
	cout << "[3]ͳ��ÿ��������Ƶ����ǰ20�Ĵ�(������)\n";
	cout << "[4]չʾ���о����Ĵ�Ƶ(�ϲ�����)\n";
	cout << "[0]�˳�\n";
	cout << "----------------------------------\n";
	cout << "���������:__\b\b"; cin >> opt;

	//��ת��ָ������
	switch (opt)
	{
		case '0':
			opt = '0';
		break;
		case '1':
			showHashLists(lists, data);
			isChainSpawn = true;
			opt = -1;
		break;
		case '2':
			if (!isChainSpawn) {
				cout << "[����]��ϣ����δ���ɣ�ǿ�ҽ��������ɹ�ϣ����\n";
				break;
			}
			showAHashList(lists);
			opt = -1;
		break;
		case '3':
			if (!isChainSpawn) {
				cout << "[����]��ϣ����δ���ɣ�ǿ�ҽ��������ɹ�ϣ����\n";
				break;
			}
			showHeapSort(lists);
			opt = -1;
		break;
		case '4':
			if (!isChainSpawn) {
				cout << "[����]��ϣ����δ���ɣ�ǿ�ҽ��������ɹ�ϣ����\n";
				break;
			}
			showMergeSort();
			opt = -1;
			break;
		default:
			cout << "�����������������!\n";
			opt = -1;
		break;
	}

	system("pause");//�����������
	cin.ignore((std::numeric_limits< streamsize >::max)(),'\n');//���������,ʹ�ϴε���������µ�����û��Ӱ�쵽��һ�ε�����
}
/*���ɹ�ϣ��
lists[]��������Ĺ�ϣ����
data��ȡ��csv�ļ�����*/
void showHashLists(HashList lists[], vector<vector<string>>& data) {
	system("cls");//����
	cout << "���ڴ�����ϣ����...\n";
	createHashLists(lists, data);

//	ԭ���ƻ�չʾ��ϣ��������ϸ�ڣ���������̫���ȡ����
//	for (int i = 1; i <= 50; i++)
//		showDetails(lists[i], i, true);
	for (int i = 1; i <= 50; i++)
		write(lists[i], i);
	cout << "ȫ������Ĺ�ϣ��������ɣ�\n�ļ�������.\\data\\������HashWord.txt\n";
}
/*չʾĳ�������Ĵ�Ƶ
lists[]��������Ĺ�ϣ����*/
void showAHashList(HashList lists[]) {
	system("cls");
	cout << "������Ҫչʾ��������:__\b\b";
	string str;
	int listNum = 0;
	while (cin >> str) {
		listNum = atoi(str.c_str());//�����ָ�ʽ���ַ���ת��Ϊ��������
		if (listNum < 1 || listNum > 50) {
			cout << "��������������������룡\n";
		}
		else 
			break;
	}
	showDetails(lists[listNum], listNum, false);
	cout << "����" << listNum << "�Ĵ�Ƶȫ��չʾ��ɣ�";
}
/*ͳ��ÿ��������Ƶ����ǰ20�Ĵ�(������)
lists[]��������Ĺ�ϣ����*/
void showHeapSort(HashList lists[]) {
	system("cls");
	cout << "�ö�����չʾÿ������ǰ20�����Ĵ�Ƶ��\n";
	for (int i = 1; i <= 50; i++) {
		cout << "����" << i << endl;
		if (lists[i].list.empty())
			continue;
		heapSort(lists[i], i);
	}
	cout << "չʾ���!\n";
}
/*չʾ���о����Ĵ�Ƶ(�ϲ�����)
lists[]��������Ĺ�ϣ����*/
void showMergeSort() {
	int totalWordsNum, cnt = 0;		//������������Ƶ����
	getDictionary(totalWordsNum);	//��ȡ��������
	vector<pair<string, int>> vec;	//�鲢�������ճɹ�
	mergeSort(vec,0, totalWordsNum - 1, true);
	cout << "���о����Ĵ�Ƶǰ20����\n";
	int size = vec.size();
	while (cnt < 20 && size) {
		cout << (cnt+1) << ": " << vec[cnt].first << "\t\t" << vec[cnt].second << " ��\n";
		size--,cnt++;
	}
	cout << "չʾ���!\n";
}