#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include <windows.h>
#include <assert.h>
#define TEST_HEADER printf("\n============%s============\n",__FUNCTION__)

typedef int DataType;
typedef struct SlistNode
{
	struct SlistNode* _next;
	DataType _data;
}SlistNode;

void SlistPrintf(SlistNode* pHead);
void SlistPushBack(SlistNode** pHead, DataType x);
void SlistPushFront(SlistNode** pHead, DataType x);
void SlistPopBack(SlistNode** pHead);
void SlistPopFront(SlistNode** pHead);
void SlistDestory(SlistNode** pHead);
SlistNode* SlistFind(SlistNode* pHead, DataType x);
SlistNode* SlistFind(SlistNode* pHead, DataType x);
void SlistInsert(SlistNode** pHead, SlistNode* pos, DataType x);
void SlistErase(SlistNode** pHead, SlistNode* pos);

void SlistInit(SlistNode** pHead)
{
	assert(pHead != NULL);
	*pHead = NULL;
}

SlistNode *BuySlistNode(DataType x)
{
	SlistNode* node = (SlistNode*)malloc(sizeof(SlistNode));
	assert(node);
	node->_data = x;
	node->_next = NULL;
	return node;
}

void SlistPushBack(SlistNode** pHead, DataType x)
{
	if (*pHead == NULL)
	{
		*pHead = BuySlistNode(x);
	}
	else
	{
		SlistNode* cur = *pHead;
		while (cur->_next != NULL)
		{
			cur = cur->_next;
		}
		cur->_next = BuySlistNode(x);;
	}
}

void SlistPushFront(SlistNode** pHead, DataType x)
{
	if (*pHead == NULL)
	{
		*pHead = BuySlistNode(x);
	}
	else
	{
		SlistNode* newNode = BuySlistNode(x);
		newNode->_next = *pHead;
		*pHead = newNode;
	}
}

void SlistPopBack(SlistNode** pHead)
{
	SlistNode* cur = NULL;
	SlistNode* prev = NULL;

	if (*pHead == NULL)
	{
		return;
	}
	else if ((*pHead)->_next == NULL)
	{
		free(*pHead);
		*pHead = NULL;
	}
	else
	{
		SlistNode* cur = *pHead;
		SlistNode* prev = NULL;
		while (cur->_next)
		{
			prev = cur;
			cur = cur->_next;
		}
		free(cur);
		prev->_next = NULL;
	}
}

void SlistPopFront(SlistNode** pHead)
{
	if (*pHead == NULL)
	{
		return;
	}
	else
	{
		SlistNode* next = (*pHead)->_next;
		free(*pHead);
		*pHead = next;
	}
}

void SlistDestory(SlistNode** pHead)
{
	SlistNode* cur = *pHead;
	while (cur)
	{
		free(cur);
		cur = cur->_next;
	}
	*pHead = NULL;
}

SlistNode* SlistFind(SlistNode* pHead, DataType x)
{
	SlistNode* cur = pHead;
	while (cur)
	{
		if (cur->_data == x)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}

void SlistInsert(SlistNode** pHead, SlistNode* pos, DataType x)
{
	assert(pos && *pHead);

	//ͷ��
	if (pos == *pHead)
	{
		SlistPushFront(pHead, x);
	}
	else
	{
		SlistNode* newnode = BuySlistNode(x);
		SlistNode* prev = *pHead;
		while (prev->_next != pos)
		{
			prev = prev->_next;
		}
		prev->_next = newnode;
		newnode->_next = pos;
	}
}

void SlistErase(SlistNode** pHead, SlistNode* pos)
{
	assert(pos && *pHead);

	if (pos == *pHead)
	{
		SlistPopFront(pHead);
	}
	else if (pos->_next == NULL)
	{
		SlistPopBack(pHead);
	}
	else
	{
		SlistNode* prev = *pHead;
		while (prev->_next != pos)
		{
			prev = prev->_next;
		}
		prev->_next = pos->_next;
		free(pos);
	}
}


////////////////////////////////////////////
////������
///////////////////////////////////////////

//////////////////////////////////////////
//���÷ǵݹ�
void SlistNodePrintReverseNor(SlistNode* pHead)
{
	SlistNode* end = NULL;
	while (end != pHead)
	{
		SlistNode* cur = pHead;
		while (cur->_next != end)
		{
			cur = cur->_next;
		}
		printf("%d->", cur->_data);
		end = cur;
	}
}

//////////////////////////////////////////
//���õݹ�
void SlistNodePrintReverse(SlistNode* pHead)
{
	if (pHead == NULL)
	{
		return;
	}
	SlistNodePrintReverse(pHead->_next);
	printf("%d->", pHead->_data);
}

//////////////////////////////////////////
//��ת
SlistNode* SlistNodeReverse(SlistNode* pHead)
{
	/*SlistNode *p1, *p2, *p3;
	p1 = NULL;
	p2 = pHead;
	p3 = pHead->_next;
	while (p2 != NULL)
	{
		p2->_next = p1;
		p1 = p2;
		p2 = p3;
		if (p3 != NULL)
		{
			p3 = p3->_next;
		}
	}
	return p1;*/
	SlistNode* cur = pHead;
	SlistNode* node;
	SlistNode* result = NULL;

	while (cur != NULL)
	{
		//����ͷɾ��û��ɾ��,nodeΪȡ�µĽ��
		node = cur;
		cur = cur->_next;

		node->_next = result;
		result = node;
	}
	return result;
}

//////////////////////////////////////////
//��ͷ�����ɾ��
void RemoveNoFirst(SlistNode* pos)
{
	assert(pos != NULL);
	pos->_data = pos->_next->_data;
	SlistNode* del = pos->_next;
	pos->_next = pos->_next->_next;
	/*SlistNode *del = (SlistNode *)malloc(sizeof(SlistNode));
	del = pos->_next;

	pos->_next = del->_next;

	pos->_data = del->_data;*/
	free(del);
}

////////////////////////////////////////
//��ͷ����Ĳ���
void InsertNoFirst(SlistNode* pos, DataType data)
{ 
	assert(pos != NULL);
	SlistNode *NewNode = (SlistNode *)malloc(sizeof(SlistNode));
	NewNode->_next = pos->_next;
	pos->_next = NewNode;
	NewNode->_data = data;
}

//////////////////////////////////////////
//Լɪ��
SlistNode *JosephCircle(SlistNode* pHead, int m)
{
	//�����ɻ�
	SlistNode* tail = pHead;
	while (tail->_next != NULL)
	{
		tail = tail->_next;
	}
	//tail�������һ�����
	tail->_next = pHead;

	SlistNode* cur = pHead;
	while (cur->_next != cur)
	{
		SlistNode* prev = NULL;
		int i = 1;
		for (; i < m; ++i)
		{
			prev = cur;
			cur = cur->_next;
		}
		//cur����Ҫɾ���Ľ��
		prev->_next = cur->_next;
		free(cur);
		cur = prev->_next;
	}
	cur->_next = NULL;
	return cur;
}

//////////////////////////////////////////
//�ϲ��������������ϲ�����Ȼ����
SlistNode* MergeOrderedList(SlistNode* list1, SlistNode* list2)
{
	SlistNode* cur1 = list1;
	SlistNode* cur2 = list2;

	SlistNode* result = NULL;//�������
	SlistNode* tail = NULL;//��������е����һ�����
	SlistNode* next = NULL;//������������е���һ�����

	while (cur1 != NULL && cur2 != NULL)
	{
		if (cur1->_data <= cur2->_data)
		{
			//Ӧ��ȡ����1�Ľ��
			if (result != NULL)
			{
				//�����Ϊ�գ������һ��������

				//��������1����һ����㣬��ѭ������
				next = cur1->_next;

				//�������
				tail->_next = cur1;
				cur1->_next = NULL;
				//�������һ�����
				tail = cur1;

				cur1 = next;
			}
			else
			{
				//��������1����һ����㣬��ѭ������
				next = cur1->_next;
				result = cur1;
				cur1->_next = NULL;
				//�����µ����һ�����
				tail = cur1;

				cur1 = next;
			}
		}
		else
		{
			//Ӧ��ȡ����2�Ľ��
			if (result != NULL)
			{
				//�����Ϊ�գ������һ��������

				//��������1����һ����㣬��ѭ������
				next = cur2->_next;

				//�������
				tail->_next = cur2;
				cur2->_next = NULL;
				//�������һ�����
				tail = cur2;

				cur2 = next;
			}
			else
			{
				//��������1����һ����㣬��ѭ������
				next = cur2->_next;
				result = cur2;
				cur2->_next = NULL;
				//�����µ����һ�����
				tail = cur2;

				cur2 = next;
			}
		}
	}
	//һ������Ϊ��
	if (cur1 == NULL)
	{
		tail->_next = cur2;
	}
	if (cur2 == NULL)
	{
		tail->_next = cur1;
	}
	return result;
}

SlistNode* MergeOrderedListAd(SlistNode* list1, SlistNode* list2)
{
	SlistNode* cur1 = list1;
	SlistNode* cur2 = list2;

	SlistNode* result = NULL;//�������
	SlistNode* tail = NULL;//��������е����һ�����
	SlistNode* next = NULL;//������������е���һ�����
	SlistNode* node = NULL;
	while (cur1 != NULL && cur2 != NULL)
	{
		if (cur1->_data <= cur2->_data)
		{
			node = cur1;
		}
		else
		{
			node = cur2;
		}
		//��������node����һ����㣬��ѭ������
		next = node->_next;
		//Ӧ��ȡ����node�Ľ��
		if (result != NULL)
		{
			//�����Ϊ�գ������һ��������
			//�������
			tail->_next = node;
		}
		else
		{
			result = node;
		}
		node->_next = NULL;
		//�������һ�����
		tail = node;
		if (node == cur1)
		{
			cur1 = next;
		}
		else
		{
			cur2 = next;
		}
	}
	//һ������Ϊ��
	if (cur1 == NULL)
	{
		tail->_next = cur2;
	}
	if (cur2 == NULL)
	{
		tail->_next = cur1;
	}
	return result;
}

//////////////////////////////////////////
//��ӡ����������������ͬ������
void PrintfIntersection(SlistNode* list1, SlistNode* list2)
{
	SlistNode* cur1 = list1;
	SlistNode* cur2 = list2;

	//һ������Ϊ��
	if (cur1 == NULL || cur2 == NULL)
	{
		printf("һ������Ϊ��\n");
	}
	while (cur1 != NULL && cur2 != NULL)
	{
		if (cur1->_data < cur2->_data)
		{
			cur1 = cur1->_next;
		}
		else if (cur1->_data > cur2->_data)
		{
			cur2 = cur2->_next;
		}
		else
		{
			printf("%d ", cur1->_data);
			cur1 = cur1->_next;
			cur2 = cur2->_next;
		}
	}
	printf("\n");
}

void PrintfIntersectionAd(SlistNode* list1, SlistNode* list2)
{
	SlistNode* cur1 = list1;
	SlistNode* cur2 = list2;
	DataType data;

	//һ������Ϊ��
	if (cur1 == NULL || cur2 == NULL)
	{
		printf("һ������Ϊ��\n");
	}
	while (cur1 != NULL && cur2 != NULL)
	{
		if (cur1->_data < cur2->_data)
		{
			cur1 = cur1->_next;
		}
		else if (cur1->_data > cur2->_data)
		{
			cur2 = cur2->_next;
		}
		else
		{
			printf("%d ", cur1->_data);
			data = cur1->_data;
			while (cur1 != NULL && cur1->_data == data)
			{
				cur1 = cur1->_next;
			}
			while (cur2 != NULL && cur2->_data == data)
			{
				cur2 = cur2->_next;
			}
		}
	}
	printf("\n");
}

void FindMid(SlistNode* pHead)
{
	SlistNode* fast = pHead;
	SlistNode* slow = pHead;
	while (1)
	{
		fast = fast->_next;
		if (fast == NULL)
		{
			break;
		}
		fast = fast->_next;
		if (fast == NULL)
		{
			break;
		}
		slow = slow->_next;
	}
	printf("%d\n", slow->_data);
}
//SlistNode *JosephCircle(SlistNode* pHead, int m)
//{
//	if (pHead == NULL)
//	{
//		return NULL;
//	}
//	SlistNode* cur = pHead;
//	while (cur->_next != cur)
//	{
//		int i = 1;
//		for (; i < m; ++i)
//		{
//			cur = cur->_next;
//		}
//		printf("%d \n", cur->_data);
//		cur->_data = cur->_next->_data;
//		SlistNode* to_delete = cur->_next;
//		cur->_next = to_delete->_next;
//		SlistDestory(to_delete);
//	}
//	return cur;
//}
void FindTailK(SlistNode* pHead, int k)
{
	SlistNode* forward = pHead;
	SlistNode* backward = pHead;
	while (k--)
	{
		forward = forward->_next;
	}
	while (forward != NULL)
	{
		forward = forward->_next;
		backward = backward->_next;
	}
	printf("%d\n", backward->_data);
}

void BubbleSort(SlistNode *pHead)
{
	SlistNode *cur = pHead;
	SlistNode *last = pHead;
	if (pHead == NULL)
	{
		return;
	}
	for (cur; cur->_next != NULL; cur = cur->_next)
	{
		for (last; last->_next != NULL; last = last->_next)
		{
			if (last->_data < last->_next->_data)
			{
				int temp = last->_data;
				last->_data = last->_next->_data;
				last->_next->_data = temp;
			}
		}
	}
	return;
}
void RemoveK(SlistNode *pHead, int k)
{
	assert(pHead);
	SlistNode *pNewNode = SlistFind(pHead, k);
	SlistErase(&pHead, pNewNode);
}
///////////////////////////////////
////���Դ���
//////////////////////////////////
void SlistPrint(SlistNode* pHead)
{
	SlistNode* cur = pHead;
	//while (cur->_next != NULL)
	while (cur)
	{
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
	printf("NULL\n");
}

void TestPushBack()
{
	TEST_HEADER;
	SlistNode* list = NULL;
	SlistPushBack(&list, 1);
	SlistPushBack(&list, 2);
	SlistPushBack(&list, 3);
	SlistPushBack(&list, 4);
	SlistPrint(list);
}

void TestPushFront()
{
	TEST_HEADER;
	SlistNode* list = NULL;
	SlistPushBack(&list, 1);
	SlistPushBack(&list, 2);
	SlistPushBack(&list, 3);
	SlistPushBack(&list, 4);
	SlistPrint(list);

	SlistPushFront(&list, 1);
	SlistPushFront(&list, 2);
	SlistPushFront(&list, 3);
	SlistPushFront(&list, 4);
	SlistPrint(list);
}

void TestPopFront()
{
	TEST_HEADER;
	SlistNode* list = NULL;

	SlistPushFront(&list, 1);
	SlistPushFront(&list, 2);
	SlistPushFront(&list, 3);
	SlistPushFront(&list, 4);
	SlistPrint(list);

	SlistPopFront(&list);
	SlistPopFront(&list);

	SlistPrint(list);
}

void TestPopBack()
{
	TEST_HEADER;
	SlistNode* list = NULL;

	SlistPushFront(&list, 1);
	SlistPushFront(&list, 2);
	SlistPushFront(&list, 3);
	SlistPushFront(&list, 4);
	SlistPrint(list);

	SlistPopBack(&list);
	SlistPopBack(&list);

	SlistPrint(list);
}


void TestInsert()
{
	TEST_HEADER;
	SlistNode* pos;
	SlistNode* list = NULL;
	SlistPushBack(&list, 1);
	SlistPushBack(&list, 2);
	SlistPushBack(&list, 3);
	SlistPushBack(&list, 4);
	SlistPrint(list);

	SlistFind(list, 3);
	pos = SlistFind(list, 3);
	SlistInsert(&list, pos, 30);
	SlistPrint(list);
	SlistInsert(&list, list, 10);
	SlistPrint(list);

}

void TestErase()
{
	TEST_HEADER;
	SlistNode* pos;
	SlistNode* list = NULL;
	SlistPushBack(&list, 1);
	SlistPushBack(&list, 2);
	SlistPushBack(&list, 3);
	SlistPushBack(&list, 4);
	SlistPushBack(&list, 5);

	SlistPrint(list);

	pos = SlistFind(list, 3);
	SlistErase(&list, pos);
	SlistPrint(list);
	pos = SlistFind(list, 1);
	SlistErase(&list, pos);
	SlistPrint(list);
	pos = SlistFind(list, 5);
	SlistErase(&list, pos);
	SlistPrint(list);
}


//////////////////////////////////////////////
////���������
//////////////////////////////////////////////
void TestPrintReverseNor()
{
	TEST_HEADER;
	SlistNode* list = NULL;
	SlistPushBack(&list, 5);
	SlistPushBack(&list, 6);
	SlistPushBack(&list, 7);
	SlistPushBack(&list, 8);
	SlistPrint(list);
	SlistNodePrintReverseNor(list);
	printf("NULL\n");
}

void TestPrintReverse()
{
	TEST_HEADER;
	SlistNode* list = NULL;
	SlistPushBack(&list, 5);
	SlistPushBack(&list, 6);
	SlistPushBack(&list, 7);
	SlistPushBack(&list, 8);
	SlistPrint(list);
	SlistNodePrintReverse(list);
	printf("NULL\n");
}

void TestReverse()
{
	TEST_HEADER;
	SlistNode* list = NULL;
	SlistPushBack(&list, 5);
	SlistPushBack(&list, 6);
	SlistPushBack(&list, 7);
	SlistPushBack(&list, 8);
	SlistPrint(list);
	SlistNodeReverse(list);
	SlistPrint(list);

}

void TestJosephCircle()
{
	TEST_HEADER;
	SlistNode* list = NULL;
	int i = 1;
	for (i = 1; i <= 7; i++)
	{
		SlistPushBack(&list, i);
	}
	SlistNode* survice = JosephCircle(list, 4);
	printf("survice is %d\n", survice->_data);
}

void TestMerge()
{
	TEST_HEADER;
	SlistNode* list1 = NULL;
	SlistNode* list2 = NULL;
	SlistPushBack(&list1, 1);
	SlistPushBack(&list1, 2);
	SlistPushBack(&list1, 3);
	SlistPushBack(&list1, 4);
	SlistPushBack(&list1, 5);

	SlistPushBack(&list2, 1);
	SlistPushBack(&list2, 2);
	SlistPushBack(&list2, 4);

	SlistNode* result = MergeOrderedList(list1, list2);
	SlistPrint(result);
}

void TestMergeAd()
{
	TEST_HEADER;
	SlistNode* list1 = NULL;
	SlistNode* list2 = NULL;
	SlistPushBack(&list1, 1);
	SlistPushBack(&list1, 2);
	SlistPushBack(&list1, 3);
	SlistPushBack(&list1, 4);
	SlistPushBack(&list1, 5);

	SlistPushBack(&list2, 1);
	SlistPushBack(&list2, 2);
	SlistPushBack(&list2, 4);

	SlistNode* result = MergeOrderedListAd(list1, list2);
	SlistPrint(result);
}

void TestPrintfIntersection()
{
	TEST_HEADER;
	SlistNode* list1 = NULL;
	SlistNode* list2 = NULL;
	SlistPushBack(&list1, 1);
	SlistPushBack(&list1, 2);
	SlistPushBack(&list1, 3);
	SlistPushBack(&list1, 4);
	SlistPushBack(&list1, 5);

	SlistPushBack(&list2, 1);
	SlistPushBack(&list2, 2);
	SlistPushBack(&list2, 4);
	PrintfIntersection(list1, list2);
}

void TestPrintfIntersectionAd()
{
	TEST_HEADER;
	SlistNode* list1 = NULL;
	SlistNode* list2 = NULL;
	SlistPushBack(&list1, 1);
	SlistPushBack(&list1, 2);
	SlistPushBack(&list1, 2);
	SlistPushBack(&list1, 4);
	SlistPushBack(&list1, 5);

	SlistPushBack(&list2, 1);
	SlistPushBack(&list2, 2);
	SlistPushBack(&list2, 4);
	PrintfIntersectionAd(list1, list2);
}

void TestFindMid()
{
	TEST_HEADER;
	SlistNode* list = NULL;
	SlistPushBack(&list, 1);
	SlistPushBack(&list, 2);
	SlistPushBack(&list, 3);
	SlistPushBack(&list, 4);
	SlistPushBack(&list, 5);
	FindMid(list);
	SlistPushBack(&list, 6);
	FindMid(list);
}

void TestFindTailK()
{
	TEST_HEADER;
	SlistNode* list = NULL;
	SlistPushBack(&list, 1);
	SlistPushBack(&list, 2);
	SlistPushBack(&list, 3);
	SlistPushBack(&list, 4);
	SlistPushBack(&list, 5);
	FindTailK(list,2);
}

void TestRemoveNoFirst()
{
	TEST_HEADER;
	SlistNode* list = NULL;
	SlistPushBack(&list, 1);
	SlistPushBack(&list, 2);
	SlistPushBack(&list, 3);
	SlistPushBack(&list, 4);
	SlistPushBack(&list, 5);
	RemoveNoFirst(SlistFind(list, 3));
	SlistPrint(list);
}

void TestInsertNoFirst()
{
	TEST_HEADER;
	SlistNode* list = NULL;
	SlistPushBack(&list, 1);
	SlistPushBack(&list, 2);
	SlistPushBack(&list, 3);
	SlistPushBack(&list, 4);
	SlistPushBack(&list, 5);
	InsertNoFirst(SlistFind(list, 2),9);
	SlistPrint(list);
}
void TestBubbleSort()
{
	TEST_HEADER;
	SlistNode* list = NULL;
	SlistPushBack(&list, 5);
	SlistPushBack(&list, 2);
	SlistPushBack(&list, 3);
	SlistPushBack(&list, 4);
	SlistPushBack(&list, 1);
	BubbleSort(list);
	SlistPrint(list);
}
void TestRemoveK()
{
	TEST_HEADER;
	SlistNode* list = NULL;
	SlistPushBack(&list, 1);
	SlistPushBack(&list, 2);
	SlistPushBack(&list, 3);
	SlistPushBack(&list, 4);
	SlistPushBack(&list, 5);
	RemoveK(list,3);
	SlistPrint(list);
}

//void TestReplaceMethod()
//{
//	SlistNode *pFirst = NULL;
//	PushBack(&pFirst, 1);
//	PushBack(&pFirst, 2);
//	PushBack(&pFirst, 3);
//	PushBack(&pFirst, 4);
//	PushBack(&pFirst, 5);
//	SlistNode *pFound = Find(pFirst, 4);
//	InsertNoFirst(pFound, 7);
//	Print(pFirst);
//	printf("\n");
//	printf("\n");
//	printf("ɾ����ͷ�����β�ڵ�7��Ľ���ǣ�");
//	EraseNoFirstNotTail(pFound);
//	Print(pFirst);
//	printf("\n");
//	printf("\n");
//
//}
int main()
{
	TestPushBack();
	TestPushFront();
	TestPopFront();
	TestPopBack();
	TestInsert();
	TestErase();
	TestPrintReverseNor();
	TestPrintReverse();
	TestReverse();
	TestJosephCircle();
	TestMerge();
	TestMergeAd();
	TestPrintfIntersection();
	TestPrintfIntersectionAd();
	TestFindMid();
	TestFindTailK();
	TestBubbleSort();
	TestRemoveNoFirst();
	TestInsertNoFirst();
	TestRemoveK();
	system("pause");
	return 0;
}