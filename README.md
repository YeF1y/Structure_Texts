景区评论热度调查分析

一、问题或系统概述
1.1.问题描述：基于词汇的哈希链，然后基于哈希链统计每个词出现的频率。
1.2.功能概述：
   如图所示为“景区评论.csv”数据。现在要求统计50个景区的热度词。词的热度主要以词出现的频率表示。要求设计数据结构为：基于词汇的哈希链，然后基于哈希链统计每个词出现的频率。实现功能：
1.2.1. 以中文词作为关键字，设计每个文件的哈希链，并存入文件景区名“HashWord.txt”中。存入格式如下：（主要用分词那列的数据）
亲子->1->20->50->1245   //表示“亲子”这个词在编号为1,20,50,1245的评论出现。
票价->12->120->150->1245->2345
注意：共有50个景区，故最后需要有50个哈希链文件展示。
输入一个景区，展示对应的哈希链。
1.2.2. 输入一个景区，展示所有词的词频。可以用线性表保存。
1.2.3. 基于堆排序，统计每个景区词频排名前20的词。展示结果如下：![image](https://github.com/YeF1y/Structure_Texts/assets/134665013/112c0489-687b-45f0-9323-44c818407749)
1.2.4. 基于合并排序，对50个景区的评论进行合并排序，并展示结果。注意，相同的词要合并计算。如“不错”，合并后应该是3000多。
 ![image](https://github.com/YeF1y/Structure_Texts/assets/134665013/715b4380-a691-4c0a-9638-26eb5a82ca2a)

二、问题分析或系统分析
2.1 数据分析
一个包含50个景区的评论的文件   景区评论.csv
部分如下![image](https://github.com/YeF1y/Structure_Texts/assets/134665013/3c14abe1-82c8-44dd-b04c-a500c266c808)

2.2 系统开发重难点分析
建立哈希链表	*
读取csv文件	*
堆排序	*
归并排序	*

三、数据存储结构
3.1.介绍结构体描述哪种数据
hashfirst保存分词，hashnode保存评论序号，hashlist保存一个景点的每个链表
3.2. 哈希链表结合map以及unordered_map为每一个分词提供“分词——hashlist下标”的映射关系；

四、程序运行结果及调试
4.1.创建哈希链表![image](https://github.com/YeF1y/Structure_Texts/assets/134665013/04f5339e-233a-482c-887e-b5cfad139dae)
![image](https://github.com/YeF1y/Structure_Texts/assets/134665013/bae07662-546b-42d4-a56e-6a41e8eb55fe)

4.2.展示某个景区的词频![image](https://github.com/YeF1y/Structure_Texts/assets/134665013/a0e6349c-90b7-4be5-a2bd-4ca2213ebeb6)

4.3.统计每个景区词频排名前20的词![image](https://github.com/YeF1y/Structure_Texts/assets/134665013/0d14cf90-4e6a-4495-af7a-0981ff01cc44)

4.4.展示所有景区的词频前20名![image](https://github.com/YeF1y/Structure_Texts/assets/134665013/860f3605-2382-4f9b-bd01-977dd97c877a)

