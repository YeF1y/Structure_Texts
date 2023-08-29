#ifndef MYHASH_H
#define MYHASH_H
#include <iostream>
#include <map>//��������
#include <vector>
#include <unordered_map>//��������
#include <algorithm>//�㷨�⣬��������������ʹ��
using namespace std;

//��ϣ�����һ��ڵ�
typedef struct HashNode {
	int number = 0;			//�������
	HashNode* next = NULL;	
} HashNode;
//��ϣ����ĵ�һ���ڵ�
typedef struct HashFirst {
	string str;				//�����������ķִ�
	int wordCnt = 0;		//�����������Ľڵ���
	HashNode* first = NULL;
}HashFirst;
//һ������Ĺ�ϣ������
typedef struct HashList {
	vector<HashFirst> list;			//�����������ĴʵĹ�ϣ�����׽ڵ�
	unordered_map<string, int> hash;//Ϊ���ĴʺͶ�Ӧ�����±��ṩ��Ӧ��ϵ
	map<string, int> wordsCnt;		//�˾�������ִʼ������
	int wordsTotal = 1;				//�˾������зִʸ���
}HashList;

typedef map<string, int> MP;

void insertElem(HashList&, int, int, string);
void createHashLists(HashList[], vector<vector<string>>&);
void showDetails(HashList, int, bool);
void getDictionary(MP&, int&);
void getDictionary(int&);

#endif 

