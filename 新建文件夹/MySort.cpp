#include "MySort.h"
/*实现堆排序，将list里的 map<string,int> wordsCnt 用vector<PAIR>排序。
list此景点的HashList
listNum此景点的序号*/
void heapSort(HashList list, int listNum) {
	vector<PAIR> vec;
	vec.push_back(make_pair("", 0));
	//建立大根堆
	for (auto it = list.wordsCnt.begin(); it != list.wordsCnt.end(); it++)
		vec.push_back(*it);
	//堆排序
	int cnt = 0, size = vec.size()-1;//不-1会报错
	for (int i = vec.size() / 2; i; i--)
		heapDown(vec, i, size);
	while (cnt < 20 && size) {
		cout << ++cnt << ": " << vec[1].first << "\t个数为 " << vec[1].second << endl;
		vec[1] = vec[size];
		size--;
		heapDown(vec, 1, size);
	}//统计20个
}
/*堆排序的down操作（递归）找出词频前20的
vec堆数组
pos要调整的位置
size堆的大小*/
void heapDown(vector<PAIR>& vec, int pos, int size) {
	int t = pos;
	if (pos * 2 <= size && vec[pos * 2].second > vec[t].second)
		t = pos * 2;
	if (pos * 2 + 1 <= size && vec[pos * 2 + 1].second > vec[t].second)
		t = pos * 2 + 1;
	if (pos != t) {
		swap(vec[pos], vec[t]);
		heapDown(vec, t, size);
	}
}
/* 实现归并排序，将总词典map<string, int> dictionary用vector<PAIR>排序
 vec归并数组
l左边界
r右边界
isFirstRun,	是否是第一次运行，方便数据初始化*/
void mergeSort(vector<PAIR>& vec,int l, int r, bool isFirstRun) {
	static map<string, int> dictionary;	//总词典
	static int wholeWordsCnt;			//总分词数
	//初次运行，数据初始化
	if (isFirstRun) {
		isFirstRun = false;
		getDictionary(dictionary, wholeWordsCnt);
		for (auto it = dictionary.begin(); it != dictionary.end(); it++)
			vec.push_back(*it);
	}
	static vector<PAIR> tmp(wholeWordsCnt);
	// 递归出口
	if (l >= r)
		return;
	int mid = (l + r) >> 1;
	mergeSort(vec,l,mid, false);
	mergeSort(vec,mid + 1, r, false);

	//归并部分
	int k = 0, i = l, j = mid + 1;
	while (i <= mid && j <= r) {
		if (vec[i].second >= vec[j].second)
			tmp[k++] = vec[i++];
		else
			tmp[k++] = vec[j++];
	}
	while (i <= mid)
		tmp[k++] = vec[i++];
	while (j <= r)
		tmp[k++] = vec[j++];
	for (int i = l, j = 0; i <= r; i++, j++)
		vec[i] = tmp[j];
}