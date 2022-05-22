#include <stdio.h>
#include <malloc.h>
#include <locale.h>

typedef struct node {
	int info;
	struct node* link;
}node;

void show_menu() {
	printf("1. Добавить в начало списка\n");
	printf("2. Добавить в конец списка\n");
	printf("3. Удалить элемент в начале списка\n");
	printf("4. Удалить элемент в конце списка\n");
	printf("5. Просмотреть содержимое очереди\n");
	printf("0. Выход\n\n");
	printf("Выберите операцию: ");
}

void view(node** first) {

	node* temp = *first;

	int i = 0;

	/*if (is_empty(root) == 1) {
		printf("List is empty");
	}*/

	while (temp->link != NULL) {

		printf("\nELEMENT #%d\n", i);

		printf("info =  %d\n", temp->info);

		temp = (temp->link);

		i++;

	}

}

node* create_node(int number) {
	node* new_node = (node*)malloc(1 * sizeof(node));
	new_node->info = number;
	return new_node;
}

void add_first(node** first, int number) {

	node* new_node = create_node(number);
	node* temp;

	if (*first == NULL) {  // Если элемент единственный
		new_node->link = NULL;
		*first = new_node;
	}

	else {  // Если элемент не единственный
		temp = *first;
		new_node->link = temp;
		*first = new_node;
	}

	printf("\nnew node -> link = %d\n", new_node->link);

}

void add_last(node** first, int number) {

	node* new_node = create_node(number);
	node* temp = *first;

	new_node->link = NULL;

	if (*first == NULL) {  // Если элемент единственный
		*first = new_node;
	}

	else {  // Если элемент не единственный

		while (temp -> link != NULL) {
			temp = temp->link;
		}

		temp->link = new_node;
	}

	printf("\nnew node -> link = %d\n", new_node->link);
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

			printf("Введите целое число для добавления в начало списка: ");

			scanf_s("%d", &number);

			add_first(&first, number);

			break;

		case 2:

			printf("Введите целое число для добавления в конец списка: ");

			scanf_s("%d", &number);

			add_last(&first, number);

			break;
		case 3:

			break;
		case 4:

			break;
		case 5:
			view(&first);
			break;
		default:
			printf("Такой операции не существует.");
			break;
		}
	} while (key != 0);

	return 0;
}

