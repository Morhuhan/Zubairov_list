#include <stdio.h>
#include <malloc.h>
#include <locale.h>

typedef struct node {
	int info;
	struct node* link;
}node;

void show_menu() {
	printf("\n");
	printf("1. �������� � ������ ������\n");
	printf("2. �������� � ����� ������\n");
	printf("3. ������� ������� � ������ ������\n");
	printf("4. ������� ������� � ����� ������\n");
	printf("5. ����������� ���������� ������\n");
	printf("0. �����\n");
	printf("�������� ��������: ");
	printf("\n");
}

void view(node** first) {

	node* temp = *first;

	int i = 0;

	if (*first != NULL) {

		do {

			printf("\nELEMENT #%d\n", i);

			printf("info =  %d\n", temp->info);

			temp = (temp->link);

			i++;
		
		} while (temp->link != NULL);
	}

	else {
		printf("\n������ ����!\n");
	}
}

node* create_node(int number) {
	node* new_node = (node*)malloc(1 * sizeof(node));
	new_node->info = number;
	new_node->link = NULL;
	return new_node;
}

void add_first(node** first, int number) {

	node* new_node = create_node(number);
	node* temp;

	if (*first == NULL) {  // ���� ������� ������������
		*first = new_node;
	}

	else {  // ���� ������� �� ������������
		temp = *first;
		new_node->link = temp;
		*first = new_node;
	}
}

void add_last(node** first, int number) {						// Trouble!

	node* new_node = create_node(number);
	node* temp = *first;

	new_node->link = NULL;

	if (*first == NULL) {  // ���� ������� ������������
		*first = new_node;
	}

	else {  // ���� ������� �� ������������

		while (temp -> link != NULL) {
			temp = temp->link;
		}

		temp->link = new_node;
	}
}

int delete_first(node **first) {

	int number;
	node* temp;

	if (*first != NULL) {
		temp = *first;
		*first = (*first)->link;
		number = temp->info;
		free(temp);
		return number;
	}

	else {
		printf("\n������ ����!\n");
		return 0;
	}
}



int delete_last(node** first) {

	int number;
	node* temp1 = *first;
	node* temp2 = *first;

	if (*first != NULL) {

		while (temp1->link != NULL) {
			temp1 = temp1->link;
		}

		while (temp2->link != temp1) {					// Trouble!
			temp2 = temp2->link;
		}

		temp2->link = NULL;
		number = temp1->info;
		free(temp1);
		return number;
	}

	else {
		printf("\n������ ����!\n");
		return 0;
	}
}


int main() {

	setlocale(LC_ALL, ".1251");
	int key;
	int number;
	node* first = NULL;

	do {
		show_menu(); 
		scanf_s("%d", &key);

		switch (key) {

		case 0:
			break;

		case 1:

			printf("\n");

			printf("������� ����� ����� ��� ���������� � ������ ������: ");

			scanf_s("%d", &number);

			add_first(&first, number);

			break;

		case 2:

			printf("\n");

			printf("������� ����� ����� ��� ���������� � ����� ������: ");

			scanf_s("%d", &number);

			add_last(&first, number);

			break;

		case 3:

			printf("\n�������: %d ������ �� ������\n", delete_first(&first));

			break;
		case 4:
			printf("\n�������: %d ������ �� ������\n", delete_last(&first));
			break;
		case 5:
			view(&first);
			break;
		default:
			printf("\n");
			printf("����� �������� �� ����������.");
			break;
		}
	} while (key != 0);

	return 0;
}

