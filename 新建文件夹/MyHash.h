#ifndef MYHASH_H
#define MYHASH_H
#include <iostream>
#include <map>//有序容器
#include <vector>
#include <unordered_map>//无序容器
#include <algorithm>//算法库，方便容器和向量使用
using namespace std;

//哈希链表的一般节点
typedef struct HashNode {
	int number = 0;			//评论序号
	HashNode* next = NULL;	
} HashNode;
//哈希链表的第一个节点
typedef struct HashFirst {
	string str;				//储存这条链的分词
	int wordCnt = 0;		//储存这条链的节点数
	HashNode* first = NULL;
}HashFirst;
//一个景点的哈希链表们
typedef struct HashList {
	vector<HashFirst> list;			//储存所有中文词的哈希链表首节点
	unordered_map<string, int> hash;//为中文词和对应数组下标提供对应关系
	map<string, int> wordsCnt;		//此景点各个分词及其个数
	int wordsTotal = 1;				//此景点所有分词个数
}HashList;

typedef map<string, int> MP;

void insertElem(HashList&, int, int, string);
void createHashLists(HashList[], vector<vector<string>>&);
void showDetails(HashList, int, bool);
void getDictionary(MP&, int&);
void getDictionary(int&);

#endif 

