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
	printf("5. �������� ����� ���������� ��������\n");
	printf("6. ������� ��������� �������\n");
	printf("7. ����������� ���������� ������\n");
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
		} while (temp != NULL);
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

node* search_node(int number_in_list, node** first) {

	node* ptr = *first;

	for (int i = 0; i < number_in_list; i++) {

		if ((*first == NULL) || (ptr->link == NULL)) {
			return NULL;
		}

		ptr = ptr->link;
	}

	return ptr;
}

void add_first(node** first, int number) {

	node* new_node = create_node(number);
	node* temp;

	if (*first == NULL) {
		*first = new_node;
	}

	else {
		temp = *first;
		new_node->link = temp;
		*first = new_node;
	}
}

void add_last(node** first, int number) {					

	node* new_node = create_node(number);
	node* temp = *first;

	if (*first == NULL) {
		*first = new_node;
	}

	else {

		while (temp -> link != NULL) {
			temp = temp->link;
		}

		temp->link = new_node;
	}
}

void add_after_target(node* target, node** first, int number) {

	node* ptr = *first;
	node* new_node = create_node(number);
	node* temp;

	while (ptr != target) {
		ptr = ptr->link;
	}

	if (ptr->link == NULL) {
		printf("\n������� �������� � ����� ������!\n");
		add_last(first, number);
	}

	else {
		temp = ptr->link;
		ptr->link = new_node;
		new_node->link = temp;
	}

}

int delete_first(node **first) {

	int number;
	node* temp = *first;

	if (*first != NULL) {

		if (temp->link == NULL) {
			number = temp->info;
			*first = NULL;
		}

		else {
			*first = (*first)->link;
			number = temp->info;
		}

		return number;
	}

	else {
		printf("\n������ ����!\n");
		return 0;
	}
}

int delete_last(node** first) {

	int number;
	int flag = 0;
	node* temp1 = *first;
	node* temp2 = *first;

	if (*first != NULL) {

		while ((temp1 -> link) != NULL) {
			temp2 = temp1;
			temp1 = temp1->link;
			flag = 1;
		}

		if (flag != 1) {
			*first = NULL;
			number = temp1->info;
			return number;
		}

		temp2->link = NULL;
		number = temp1->info;
		return number;
	}

	else {
		printf("\n������ ����!\n");
		return 0;
	}
}

int delete_target(node** first, node* target) {

	node* ptr = *first;
	node* temp = NULL;
	int number;

	while (ptr != target) {
		temp = ptr;
		ptr = ptr->link;
		number = ptr->info;
	}

	if (temp == NULL) {
		number = delete_first(first);
	}

	else if (ptr->link == NULL) {
		number = delete_last(first);
	}

	else {
		number = ptr->info;
		temp->link = ptr->link;
	}

	return number;
}


int main() {

	setlocale(LC_ALL, ".1251");
	int key;
	int number;
	int number_in_list;
	node* first = NULL;

	do {
		show_menu(); 
		scanf_s("%d", &key);

		switch (key) {

		case 0:
			break;

		case 1:
			printf("\n������� ����� ����� ��� ���������� � ������ ������: \n");
			scanf_s("%d", &number);
			add_first(&first, number);
			break;

		case 2:
			printf("\n������� ����� ����� ��� ���������� � ����� ������: \n");
			scanf_s("%d", &number);
			add_last(&first, number);
			break;

		case 3:
			if(first != NULL) {
				printf("\n�������: %d ������ �� ������\n", delete_first(&first));
			}
			else {
				printf("\n������ ����!\n");
			}
			break;

		case 4:
			if (first != NULL) {
				printf("\n�������: %d ������ �� ������\n", delete_last(&first));
			}
			else {
				printf("\n������ ����!\n");
			}
			break;

		case 5:

			printf("\n������� ����� ��������:\n");
			scanf_s("%d", &number_in_list);

			if (search_node(number_in_list, &first) != NULL) {
				printf("\n������� �����:\n");
				scanf_s("%d", &number);
				add_after_target(search_node(number_in_list, &first), &first, number);
			}

			else {
				printf("\n���������� �������� �� ����������!\n");
			}
			
			break;

		case 6:
			printf("\n������� ����� ��������:\n");
			scanf_s("%d", &number_in_list);

			if (search_node(number_in_list, &first) != NULL) {
				printf("\n����� %d ������� �� ������\n", delete_target(&first, search_node(number_in_list, &first)));
			}

			else {
				printf("\n���������� �������� �� ����������!\n");
			}

			break;

		case 7:
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
