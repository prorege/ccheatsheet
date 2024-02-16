#include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

typedef struct node
{
    int value; //값을 저장하는 변수
    struct node* next; //다음 노드의 주소를 저장하는 변수(포인터변수 : 8byte)
}node;

node * head; //첫 노드의 주소를 저장하는 head(포인터 변수 : 8바이트)

void insertFrontNode(int data);
void displayNode();
int main()
{
	int choice;
	while (1)
	{
		system("cls");
		printf("\n\n  *** 단일 연결 리스트(Singly Linked List) ***\n\n");
		printf("=====================================\n");
		printf(" 1. 맨 앞 삽입\n");
		printf(" 2. 맨 뒤 삽입\n");
		printf(" 3. 앞에서부터 N번째 삽입\n");
		printf(" 4. 오름차순 정렬 삽입\n");
		printf("=====================================\n");
		printf(" 5. 맨 앞 삭제\n");
		printf(" 6. 맨 뒤 삭제\n");
		printf(" 7. 전체 노드 삭제\n");
		printf(" 8. 특정 값 삭제\n");
		printf(" 9. 앞에서부터 N번째 삭제\n");
		printf("=====================================\n");
		printf("10. 단일 연결 리스트 출력(노드 순회)\n");
		printf("11. 노드의 개수 구하기\n");
		printf("12. 노드 검색\n");
		printf(" 0. 프로그램 종료\n");
		printf("=====================================\n");
		printf("\n메뉴 선택 : ");
		scanf("%d", &choice);
		while (getchar() != '\n');
        
        int data;

		switch (choice)
		{
		case 1:
            printf("추가할 데이터를 입력하세요 : ");
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
			exit(0); //프로그램 강제 종료
		}//end switch

		//switch문을 빠져 나오면 일시 대기 시킨다.
		printf("\n\n\t\t");
		system("pause"); //일시 대기

	}//end while
	return 0;
}


void insertFrontNode(int data){
    node* newNode; //생성된 노드의 주소를 저장하는 변수(포인터 변수)
    newNode = (node*)malloc(sizeof(node)); //노드 생성
    newNode -> value = data;
    newNode -> next = NULL;
    if(head == NULL)//생성된 노드가 없다, 첫 노드!
    {
        head = newNode;
        printf("case 1. 노드 맨 앞 삽입(첫 노드로 연결)\n");
        return;//호출한 곳으로 돌아간다.(함수 종료)
    }
    newNode-> next = head;
    head = newNode;
    printf("case 2. 노드 맨 앞 삽입(첫 노드가 아닌 경우)\n");
}

void displayNode(){
    node*curNode; //방문 노드의 주소 저장하는 포인터변수
    if(head == NULL)
        return; //종료
    system("cls");//화면 지우기
    printf("\n\nSimply LinkedList : ");
    
    curNode = head; //첫번째 node 방문 노드로 설정
    while(curNode -> next != NULL){
        printf("%d =>", curNode -> value);
        curNode = curNode -> next;
    }
    printf("%d\n", curNode->value);
    
}