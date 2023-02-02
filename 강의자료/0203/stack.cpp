#include<iostream>
#include<stack>
using namespace std;

// stack�� �ִ� ũ�⸦ ����
const int MAX_SIZE = 10;

// 10���� int type�� ������ ���� �迭 ����
int my_stack[10] = { 0, };
// ���� stack�� element�� ����Ű�� ����
int top = -1;

// stack�� ���� �����ϴ� �Լ�
void push(int);
// stack�� top ���� ��ȯ�ϴ� �Լ�
int pop();


int main(void) {

	push(1);
	push(2);
	push(3);
	cout << pop() << endl;
	cout << pop() << endl;
	cout << pop() << endl;

	stack<int> s;

	s.push(10);
	s.push(11);
	s.push(12);

	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.pop();

	return 0;
}
/*
* �Ʒ� ���� �� ���� ���� �� ������ Ŀ�� ����
*/
void push(int value) {
	// ���� �� �Լ��� �Ҿ����� �����Դϴ�.
	// �� �ϱ��?
	my_stack[++top] = value;
}

int pop() {
	// ���� �� �Լ��� �Ҿ����� �����Դϴ�.
	// �� �ϱ��?
	return my_stack[top--];
}
