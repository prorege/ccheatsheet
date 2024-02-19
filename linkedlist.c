#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

typedef struct node
{
    int value; //���� �����ϴ� ����
    struct node* next; //���� ����� �ּҸ� �����ϴ� ����(�����ͺ��� : 8byte)
}node;

node * head; //ù ����� �ּҸ� �����ϴ� head(������ ���� : 8����Ʈ)

void insertFrontNode(int data);
void insertTailNode(int data);

void displayNode();
int getNodeCount();
void removeNodeFront();
void memoryFree();
void removeNodeValue(int target);


int main()
{
	int choice;
    int data;
    int count;
	while (1)
	{
		system("cls");
		printf("\n\n  *** ���� ���� ����Ʈ(Singly Linked List) ***\n\n");
		printf("=====================================\n");
		printf(" 1. �� �� ����\n"); // �Ϸ�
		printf(" 2. �� �� ����\n");
		printf(" 3. �տ������� N��° ����\n");
		printf(" 4. �������� ���� ����\n");
		printf("=====================================\n");
		printf(" 5. �� �� ����\n");//�Ϸ�
		printf(" 6. �� �� ����\n");
		printf(" 7. ��ü ��� ����\n");
		printf(" 8. Ư�� �� ����\n");
		printf(" 9. �տ������� N��° ����\n");
		printf("=====================================\n");
		printf("10. ���� ���� ����Ʈ ���(��� ��ȸ)\n"); //�Ϸ�
		printf("11. ����� ���� ���ϱ�\n"); //�Ϸ�
		printf("12. ��� �˻�\n");
		printf(" 0. ���α׷� ����\n");
		printf("=====================================\n");
		printf("\n�޴� ���� : ");
		scanf("%d", &choice);
		while (getchar() != '\n');
        
		switch (choice)
		{
		case 1:
            printf("�߰��� �����͸� �Է��ϼ��� : ");
            scanf("%d", &data);
            insertFrontNode(data);
			break;
		case 2:
            printf("�߰��� �����͸� �Է��ϼ��� : ");
            scanf("%d", &data);
            insertTailNode(data);
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
            removeNodeFront(data);
			break;
		case 6:

			break;
		case 7:
            memoryFree();
			break;
		case 8:
            printf("\n\n������ �� �Է� : ");
            scanf("%d", &data);
            removeNodeValue(data);
			break;
		case 9:
			break;
		case 10:
            displayNode();
			break;
		case 11:
            count = getNodeCount();
            printf("����� ������ %d���Դϴ�.", count);
			break;
		case 12:
			break;
		case 0:
            memoryFree();
			exit(0); //���α׷� ���� ����
		}//end switch

		//switch���� ���� ������ �Ͻ� ��� ��Ų��.
		printf("\n\n\t\t");
		system("pause"); //�Ͻ� ���

	}//end while
	return 0;
}


void insertFrontNode(int data){
    node* newNode; //������ ����� �ּҸ� �����ϴ� ����(������ ����)
    newNode = (node*)malloc(sizeof(node)); //��� ����
    newNode -> value = data;
    newNode -> next = NULL;
    if(head == NULL)//������ ��尡 ����, ù ���!
    {
        head = newNode;
        printf("case 1. ��� �� �� ����(ù ���� ����)\n");
        return;//ȣ���� ������ ���ư���.(�Լ� ����)
    }
    newNode-> next = head;
    head = newNode;
    printf("case 2. ��� �� �� ����(ù ��尡 �ƴ� ���)\n");
}

void displayNode(){
    node*curNode; //�湮 ����� �ּ� �����ϴ� �����ͺ���
    if(head == NULL)
        return; //����
    system("cls");//ȭ�� �����
    printf("\n\nSimply LinkedList : ");
    
    curNode = head; //ù��° node �湮 ���� ����
    while(curNode -> next != NULL){
        printf("%d =>", curNode -> value);
        curNode = curNode -> next;
    }
    printf("%d\n", curNode->value);
    
}

int getNodeCount(){
    int count = 0;
    node* curNode;
    if(head == NULL)
        return 0;

    curNode = head;
    while(curNode != NULL){
        count ++;
        curNode = curNode -> next;
    }
    return count;
}

void removeNodeFront(){
    node*delnode; //������ ���
    if(head == NULL) //��� ������
        return ;
    delnode = head;//head�� ����Ű�� ù��° ���
    head = head->next; //head�� �ι�°�� �Ѿ
    free(delnode); //ù��° ��� ����
    printf("\n\n\n\t ù ��° ��带 �����߽��ϴ�.");
}


void memoryFree(){
    node* delNode;

    if(head == NULL)
        return;
    
    while(head != NULL){
        delNode = head;
        head = head ->next;
        free(delNode);
    }
    printf("��� ��带 �����߽��ϴ�. \n");
}

void insertTailNode(int data){
    node*curNode;//�湮���
    node*newNode;//������ ���
    newNode = (node*)malloc(sizeof(node));//�� ��� ����
    newNode -> value = data;// �� ��� �� �Ҵ�
    newNode -> next = NULL; //�� ��� ������ �Ҵ�

    if(head == NULL){ //���� ��尡 �������� �ʴ´ٸ�
        head = newNode; //head�� �� newnode
        return;
    }
    curNode = head;//��尡 �����Ѵٸ� curNode�� head���� �־��ش�.
    while(curNode -> next != NULL) //�� ���� node�� ������ ����
        curNode = curNode ->next; //curnode�� �Ѿ��.
    curNode->next = newNode; //����
}

void removeNodeValue(int target){
    node*prevNode;
    node*delNode;
    //case1. ���Ḯ��Ʈ�� �������� ���� ���
    if(head == NULL)
    {
        printf("\n\n������ ����Ʈ�� �����ϴ�.");
        return;
    }
    //case2. ������ ��尡 ù��° ����� ���(head���� ����Ǿ�� �ϱ� ����)
    if(head->value == target)
    {
        delNode = head;
        head = head->next;
        free(delNode);
        return;
    }
    delNode = head;
    prevNode = head;

    while(prevNode->next != NULL)//�Ϲ����� ���(�߰� ����)
    {
        delNode = prevNode->next;
        if(delNode->value == target)
        {
            prevNode -> next = delNode -> next;
            free(delNode);
            return;
        }
        prevNode = delNode;
    }
}
