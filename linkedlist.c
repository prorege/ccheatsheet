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
void displayNode();
int main()
{
	int choice;
	while (1)
	{
		system("cls");
		printf("\n\n  *** ���� ���� ����Ʈ(Singly Linked List) ***\n\n");
		printf("=====================================\n");
		printf(" 1. �� �� ����\n");
		printf(" 2. �� �� ����\n");
		printf(" 3. �տ������� N��° ����\n");
		printf(" 4. �������� ���� ����\n");
		printf("=====================================\n");
		printf(" 5. �� �� ����\n");
		printf(" 6. �� �� ����\n");
		printf(" 7. ��ü ��� ����\n");
		printf(" 8. Ư�� �� ����\n");
		printf(" 9. �տ������� N��° ����\n");
		printf("=====================================\n");
		printf("10. ���� ���� ����Ʈ ���(��� ��ȸ)\n");
		printf("11. ����� ���� ���ϱ�\n");
		printf("12. ��� �˻�\n");
		printf(" 0. ���α׷� ����\n");
		printf("=====================================\n");
		printf("\n�޴� ���� : ");
		scanf("%d", &choice);
		while (getchar() != '\n');
        
        int data;

		switch (choice)
		{
		case 1:
            printf("�߰��� �����͸� �Է��ϼ��� : ");
            scanf("%d", &data);
            insertFrontNode(data);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		case 10:
            displayNode();
			break;
		case 11:
			break;
		case 12:
			break;
		case 0:
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