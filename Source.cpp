#include <stdio.h>
#include <iostream>

//struct Node {
//	int data;
//	Node *left;
//	Node *right;
//
//};
//
//struct BtreeNode {
//	int data;
//	BtreeNode *left;
//	BtreeNode *right;
//
//};

struct BitiriNode
{
	int *data;
	BitiriNode **leaf_ptr;
	bool leaf;
	int n;
}*rooter = NULL, *np = NULL, *x = NULL;

int display(void)
{
	int choose;
	printf("1- Add a new record to B+tree \n");
	printf("2- Remove a record given ID value \n");
	printf("3- Print the whole file in the order of the IDs \n");
	printf("0- Exit\n");
	scanf("%d", &choose);
	return choose;
}


BitiriNode* insertNode()
{

	np = new BitiriNode;
	np->data = new int[5];
	np->leaf_ptr = new BitiriNode *[4];
	np->leaf = true;
	np->n = 0;
	for (int i = 0; i < 4; i++)
	{
		np->leaf_ptr[i] = NULL;
	}
	return np;
}
void traverse(BitiriNode *p)
{
	int i;
	printf("\n");
	for (i = 0; i < p->n; i++)
	{
		if (p->leaf == 0)
		{
			traverse(p->leaf_ptr[i]);
		}
		printf( " ",p->data[i]);
	}
	if (p->leaf == 0)
	{
		traverse(p->leaf_ptr[i]);
	}
	printf("\n");
}
void sort(int *p, int n)
{
	int i, j, temp;
	for (i = 0; i < n; i++)
	{
		for (j = i; j <= n; j++)
		{
			if (p[i] > p[j])
			{
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
}
int split_child(BitiriNode *x, int i)
{
	int j, middle;
	BitiriNode *np1, *np3, *y;
	np3 = insertNode();
	np3->leaf = 1;//true
	if (i == -1)
	{
		middle = x->data[2];
		x->data[2] = 0;
		x->n--;
		np1 = insertNode();
		np1->leaf = 0; //false
		x->leaf = true;
		for (j = 3; j < 5; j++)
		{
			np3->data[j - 3] = x->data[j];
			np3->leaf_ptr[j - 3] = x->leaf_ptr[j];
			np3->n++;
			x->data[j] = 0;
			x->n--;
		}
		for (j = 0; j < 6; j++)
		{
			x->leaf_ptr[j] = NULL;
		}
		np1->data[0] = middle;
		np1->leaf_ptr[np1->n] = x;
		np1->leaf_ptr[np1->n + 1] = np3;
		np1->n++;
		rooter = np1;
	}
	else
	{
		y = x->leaf_ptr[i];
		middle = y->data[2];
		y->data[2] = 0;
		y->n--;
		for (j = 3; j < 5; j++)
		{
			np3->data[j - 3] = y->data[j];
			np3->n++;
			y->data[j] = 0;
			y->n--;
		}
		x->leaf_ptr[i + 1] = y;
		x->leaf_ptr[i + 1] = np3;
	}
	return middle;
}
// dosyayý okuma yazma iþlemi duruyor b+tree aplicanlarý yapan bitti 

int readFile( FILE &arr)
{
	char data[30];
	int key,flag=0;
	if (&arr == NULL)
		printf("Memory Allocation Error.\n");
	while (!feof(&arr))//data ve key
	{
		fscanf(&arr, "%s, %d", data, key);
		insertNode(data, key);
		flag = 1;
		return 1;
	}
	if (flag == 0)
	{
		printf("File is empty...\n");
		return 0;
	}
}

int main()
{
	
	FILE *arr = fopen("btree.txt", "a+");
	int num = readFile(*arr);
	//num=0 dosya bos =1ise dolu
	if (num == 1)


	int choose;
	choose = display();
	while ( choose!= 0)
	{
		if (choose == 1)//insert
		{

		}
		if (choose == 2)//remove
		{

		}
		if(choose==3)//print
	}

	



	
	fclose(arr);
	getchar();
	getchar();
	return 0;


}