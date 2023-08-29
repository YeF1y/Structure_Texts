#include "MyMenu.h"

void mainMenu(char& opt) {

	static HashList lists[55];			//所有节点的哈希链表们
	static vector<vector<string>> data;	//读文件的数据
	static bool isFirstRun = true;		//是否是第一次运行目录
	static bool isChainSpawn = false;	//哈希链表是否生成完毕，只有完毕才能进行后序操作

	//初次运行
	if (isFirstRun) {
		data = read();		//读文件
		Sleep(1000);
		isFirstRun = false;
	}

	system("cls");			//清屏，显示菜单，这种办法的缺点是程序额外运行系统程序执行清屏操作，延长了程序执行时间。
	cout << "------景区评论文本的热度调查------\n";
	cout << "[1]生成哈希链\n";
	cout << "[2]展示某个景区的词频\n";
	cout << "[3]统计每个景区词频排名前20的词(堆排序)\n";
	cout << "[4]展示所有景区的词频(合并排序)\n";
	cout << "[0]退出\n";
	cout << "----------------------------------\n";
	cout << "请输入参数:__\b\b"; cin >> opt;

	//跳转至指定功能
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
				cout << "[警告]哈希链尚未生成，强烈建议先生成哈希链！\n";
				break;
			}
			showAHashList(lists);
			opt = -1;
		break;
		case '3':
			if (!isChainSpawn) {
				cout << "[警告]哈希链尚未生成，强烈建议先生成哈希链！\n";
				break;
			}
			showHeapSort(lists);
			opt = -1;
		break;
		case '4':
			if (!isChainSpawn) {
				cout << "[警告]哈希链尚未生成，强烈建议先生成哈希链！\n";
				break;
			}
			showMergeSort();
			opt = -1;
			break;
		default:
			cout << "输入参数有误，请重试!\n";
			opt = -1;
		break;
	}

	system("pause");//按任意键继续
	cin.ignore((std::numeric_limits< streamsize >::max)(),'\n');//清空输入流,使上次的输入残留下的数据没有影响到下一次的输入
}
/*生成哈希链
lists[]各个景点的哈希链表
data读取的csv文件数据*/
void showHashLists(HashList lists[], vector<vector<string>>& data) {
	system("cls");//美观
	cout << "正在创建哈希链表...\n";
	createHashLists(lists, data);

//	原本计划展示哈希链的链表细节，发现数据太多就取消了
//	for (int i = 1; i <= 50; i++)
//		showDetails(lists[i], i, true);
	for (int i = 1; i <= 50; i++)
		write(lists[i], i);
	cout << "全部景点的哈希链表创建完成！\n文件保存在.\\data\\景区名HashWord.txt\n";
}
/*展示某个景区的词频
lists[]各个景点的哈希链表*/
void showAHashList(HashList lists[]) {
	system("cls");
	cout << "请输入要展示景点的序号:__\b\b";
	string str;
	int listNum = 0;
	while (cin >> str) {
		listNum = atoi(str.c_str());//将数字格式的字符串转换为整数类型
		if (listNum < 1 || listNum > 50) {
			cout << "输入参数有误，请重新输入！\n";
		}
		else 
			break;
	}
	showDetails(lists[listNum], listNum, false);
	cout << "景点" << listNum << "的词频全部展示完成！";
}
/*统计每个景区词频排名前20的词(堆排序)
lists[]各个景点的哈希链表*/
void showHeapSort(HashList lists[]) {
	system("cls");
	cout << "用堆排序展示每个景点前20排名的词频：\n";
	for (int i = 1; i <= 50; i++) {
		cout << "景点" << i << endl;
		if (lists[i].list.empty())
			continue;
		heapSort(lists[i], i);
	}
	cout << "展示完毕!\n";
}
/*展示所有景区的词频(合并排序)
lists[]各个景点的哈希链表*/
void showMergeSort() {
	int totalWordsNum, cnt = 0;		//词语总数，词频排名
	getDictionary(totalWordsNum);	//获取词语总数
	vector<pair<string, int>> vec;	//归并排序最终成果
	mergeSort(vec,0, totalWordsNum - 1, true);
	cout << "所有景区的词频前20名：\n";
	int size = vec.size();
	while (cnt < 20 && size) {
		cout << (cnt+1) << ": " << vec[cnt].first << "\t\t" << vec[cnt].second << " 次\n";
		size--,cnt++;
	}
	cout << "展示完毕!\n";
}