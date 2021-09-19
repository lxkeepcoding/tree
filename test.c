#define _CRT_SECURE_NO_WARNINGS   1

#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

typedef char BTDataType;

typedef struct BinaryTreeNode
{
	struct BinaryTreeNode*left;
	struct BinaryTreeNode*right;
	BTDataType data;
}BTNode;

BTNode*CreateTreeNode(BTDataType x)
{
	BTNode*node = malloc(sizeof(BTNode));
	node->data = x;
	node->left = NULL;
	node->right = NULL;
	return node;
}
//ǰ��
void PrevOrder(BTNode*root)
{
	if (root == NULL)
	{
		printf("NULL  ");
		return;
	}
	printf("%c  ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}
//����
void InOrder(BTNode*root)
{
	if (root == NULL)
	{
		printf("NULL  ");
		return;
	}
	InOrder(root->left);
	printf("%c  ", root->data);
	InOrder(root->right);
}
//����
void PostOrder(BTNode*root)
{
	if (root == NULL)
	{
		printf("NULL  ");
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c  ", root->data);
}

////���������ʹ��ʱ��Ҫ������е�ͷ�ļ�
//void TreeLevelOrder(BTNode*root)
//{
//	Queue q;
//	QueueInit(&q);
//	if (root)
//	{
//		QueuePush(&q, root);
//	}
//	while (!QueueEmpty(&q))
//	{
//		BTNode*front = QueueFront(&q);
//		QueuePop(&q);
//		printf("%c  ", front->data);
//		if (front->left)
//		{
//			QueuePush(&q, front->left);
//		}
//		if (front->right)
//		{
//			QueuePush(&q, front->right);
//		}
//	}
//}
//��ڵ����:˼·һ  ��������
void TreeSize1(BTNode*root,int *psize)
{
	if (root == NULL)
	{
		return;
	}
	++(*psize);
	TreeSize1(root->left,psize);
	TreeSize1(root->right,psize);
}
//��ڵ����:˼·��  ������
int TreeSize2(BTNode*root)
{
	return root == NULL ?0: TreeSize2(root->left) + TreeSize2(root->right) + 1;
}
// ������Ҷ�ӽڵ����
int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL&&root->right == NULL)
	{
		return 1;
	}
	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}
// ��������k��ڵ����
int TreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return TreeLevelKSize(root->left, k - 1) + TreeLevelKSize(root->right, k - 1);
}
// ����������ֵΪx�Ľڵ�
BTNode* TreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->data == x)
	{
		return root;
	}
	BTNode*lret = TreeFind(root->left, x);
	if (lret)
	{
		return lret;
	}
	BTNode*rret = TreeFind(root->right, x);
	if (rret)
	{
		return rret;
	}
	return NULL;
}
int TreeMaxDepth(BTNode*root)
{
	if (root == NULL)
	{
		return 0;
	}
	int LeftDepth = TreeMaxDepth(root->left);
	int Rightdepth = TreeMaxDepth(root->right);
	return LeftDepth > Rightdepth ? LeftDepth + 1 : Rightdepth + 1;
}

//void TreeDestroy(BTNode*root)
//{
//	if (root == NULL)
//	{
//		return;
//	}
//	TreeDestroy(root->left);
//	TreeDestroy(root->right);
//	free(root);
//}

void TreeDestroy(BTNode**pproot)
{
	if (*pproot == NULL)
	{
		return;
	}
	TreeDestroy(&(*pproot)->left);
	TreeDestroy(&(*pproot)->right);
	free(*pproot);
	*pproot = NULL;
}
//�жϵ�ֵ��
bool TreeSingle(BTNode*root)
{
	if (root == NULL)
	{
		return true;
	}
	if (root->left&&root->left->data != root->data)
	{
		return false;
	}
	if (root->right&&root->right->data != root->data)
	{
		return false;
	}
	return TreeSingle(root->left) && TreeSingle(root->right);
}
//�ж��Ƿ�Ϊ�Գ���
bool _TreeSymmertic(BTNode*left, BTNode*right)
{
	if (left == NULL&&right == NULL)
	{
		return true;
	}
	if (left == NULL || right == NULL)
	{
		return false;
	}
	if (left->data != right->data)
	{
		return false;
	}
	return _TreeSymmertic(left->right, right->left);
}

bool TreeSymmertic(BTNode*root)
{
	if (root == NULL)
	{
		return true;
	}
	return _TreeSymmertic(root->left, root->right);
}
//�ж��������Ƿ���ͬ
bool TreeSame(BTNode*root1,BTNode*root2)
{
	if (root1 == NULL && root2== NULL) 
	{
		return true;
	}
	else if (root1 == NULL || root2== NULL)
	{
		return false;
	}
	else if (root1->data != root2->data) 
	{
		return false;
	}
	else 
	{
		return TreeSame(root1->left, root2->left) &&TreeSame(root1->right, root2->right);
	}
}

//�ж�һ����Ϊ��һ����������
bool TreeSub(BTNode*root, BTNode*subroot)
{
	if (root == NULL)
	{
		return false;
	}
	if (TreeSame(root, subroot))
	{
		return true;
	}
	return TreeSub(root->left,subroot) || TreeSub(root->right,subroot);
}
//�ж�ƽ�������
bool _TreeBalance(BTNode*root,int *ph)
{
	if (root == NULL)
	{
		*ph = 0;
		return true;
	}
	int LeftHeight = 0;
	if (_TreeBalance(root->left, &LeftHeight) == false)
		return false;
	int RightHeight = 0;
	if (_TreeBalance(root->right, &RightHeight) == false)
		return false;
	*ph = fmax(LeftHeight, RightHeight) + 1;
	return abs(LeftHeight - RightHeight) < 2;
}

bool TreeBalance(BTNode*root)
{
	if (root == NULL)
	{
		return true;
	}
	int height = 0;
	return _TreeBalance(root, &height);
}
int main()
{
	BTNode*A = CreateTreeNode('A');
	BTNode*B = CreateTreeNode('B');
	BTNode*C = CreateTreeNode('C');
	BTNode*D = CreateTreeNode('D');
	BTNode*E = CreateTreeNode('E');
	BTNode*F = CreateTreeNode('F');

	A->left = B;
	A->right = C;
	B->left = D;
	C->left = E;
	C->right = F;
	PrevOrder(A);
	printf("\n");
	InOrder(A);
	printf("\n");
	PostOrder(A);
	printf("\n");
	int size = 0;
	TreeSize1(A,&size);
	printf("TreeSize1:%d\n", size);
	printf("TreeSize2:%d\n", TreeSize2(A));
	printf("TreeLeafSize:%d\n", TreeLeafSize(A));
	printf("TreeMaxDepth:%d\n", TreeMaxDepth(A));
	printf("TreeLevelKSize:%d\n", TreeLevelKSize(A,2));
	BTNode*ret=TreeFind(A, 'E');
	printf("TreeFind:%c\n", ret->data);
	printf("TreeSingle:%d\n", TreeSingle(A));
	printf("TreeSymmertic:%d\n", TreeSymmertic(A));
	printf("TreeSame:%d\n", TreeSame(A,A));
	printf("TreeSub:%d\n", TreeSub(A, B));
	printf("TreeBalance:%d\n", TreeBalance(A));
	TreeDestroy(A);
	//A = NULL;
	return 0;
}