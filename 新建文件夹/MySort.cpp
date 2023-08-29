#include "MySort.h"
/*ʵ�ֶ����򣬽�list��� map<string,int> wordsCnt ��vector<PAIR>����
list�˾����HashList
listNum�˾�������*/
void heapSort(HashList list, int listNum) {
	vector<PAIR> vec;
	vec.push_back(make_pair("", 0));
	//���������
	for (auto it = list.wordsCnt.begin(); it != list.wordsCnt.end(); it++)
		vec.push_back(*it);
	//������
	int cnt = 0, size = vec.size()-1;//��-1�ᱨ��
	for (int i = vec.size() / 2; i; i--)
		heapDown(vec, i, size);
	while (cnt < 20 && size) {
		cout << ++cnt << ": " << vec[1].first << "\t����Ϊ " << vec[1].second << endl;
		vec[1] = vec[size];
		size--;
		heapDown(vec, 1, size);
	}//ͳ��20��
}
/*�������down�������ݹ飩�ҳ���Ƶǰ20��
vec������
posҪ������λ��
size�ѵĴ�С*/
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
/* ʵ�ֹ鲢���򣬽��ܴʵ�map<string, int> dictionary��vector<PAIR>����
 vec�鲢����
l��߽�
r�ұ߽�
isFirstRun,	�Ƿ��ǵ�һ�����У��������ݳ�ʼ��*/
void mergeSort(vector<PAIR>& vec,int l, int r, bool isFirstRun) {
	static map<string, int> dictionary;	//�ܴʵ�
	static int wholeWordsCnt;			//�ִܷ���
	//�������У����ݳ�ʼ��
	if (isFirstRun) {
		isFirstRun = false;
		getDictionary(dictionary, wholeWordsCnt);
		for (auto it = dictionary.begin(); it != dictionary.end(); it++)
			vec.push_back(*it);
	}
	static vector<PAIR> tmp(wholeWordsCnt);
	// �ݹ����
	if (l >= r)
		return;
	int mid = (l + r) >> 1;
	mergeSort(vec,l,mid, false);
	mergeSort(vec,mid + 1, r, false);

	//�鲢����
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