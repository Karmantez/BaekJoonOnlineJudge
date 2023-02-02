#include<iostream>
using namespace std;

// Node��� Class ����
class Node {
public:
	Node* next;
	int value;
	Node(int value) {
		this->value = value;
		this->next = NULL;
	}
};
// Node�� ���� ù ��° ��ġ�� �����ϴ� ����
Node* head = NULL;

// list�� ���� �����ϴ� �Լ�
void insert(int value);
// list�� ���� ù ��° element�� �����ϰ�
// �ش� Node�� ������ �ִ� value�� ��ȯ�ϴ� �Լ�
int remove();

int main(void) {

	insert(1);
	insert(2);
	insert(3);

	cout << remove() << endl;
	cout << remove() << endl;
	cout << remove() << endl;

	return 0;
}

void insert(int value) {

	Node* node = new Node(value);

	if (head == NULL) {
		head = node;
		return;
	}
	// �� ���⸦ ���� �� �� ����� ���ô�.
	Node* search = head;

	while (search->next != NULL) search = search->next;
	search->next = node;
}

int remove() {
	// �� ���⸦ ���� �� �� ����� ���ô�.
	Node* node = head;
	head = node->next;
	return node->value;
}