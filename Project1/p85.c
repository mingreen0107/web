#define MAX_SIZE 100
#include <stdio.h>
#include <stdlib.h>

// ��ȭ ������ �����ϴ� ����ü Movie ����
typedef struct Movie {
	char title[50];
	int release;
	int viewers;
} Movie;
// ��ø ����ü ArrayB0 ����
typedef struct ArrayB0 {
	int length;
	Movie movies[MAX_SIZE];
} ArrayB0;

// ����ü �迭 �ڿ� ��ȭ�� �߰��ϴ� �Լ�
void add_movie(ArrayB0* B0, Movie m) {
	if (B0->length == MAX_SIZE) {
		printf("��ȭ�� �� �̻� �߰��� �� �����ϴ�.\n");
		exit(1);
	}
	B0->movies[B0->length] = m;
	B0->length;
}

// �� �ڽ����ǽ��� �ϳ��� ��ġ�� �Լ�
ArrayB0 merge_B0(ArrayB0* a, ArrayB0* b) {
	ArrayB0 c;
	int idx_a = 0; 
	int idx_b = 0;

	c.length = 0;

	while (idx_a < a->length && idx_b < b->length) {
		if (a->movies[idx_a].viewers >= b->movies[idx_b].viewers) {
			// a ������ >= b �������� ���
			add_movie(&c, a->movies[idx_a]);
			idx_a++;
		}
		else { // a ������ < b �������� ���
			add_movie(&c, b->movies[idx_b]);
			idx_b++;
		}
	}
	// ���� �����ִ� a ��ȭ���� �߰�
	for (; idx_a < a->length; idx_a++) add_movie(&c, a->movies[idx_a]);
	// ���� �����ִ� b ��ȭ���� �߰�
	for (; idx_b < b->length; idx_b++) add_movie(&c, b->movies[idx_b]);
	return c;
}

int main() {
	ArrayB0 domestic = { 4, { {"��", 2014, 1761},
							{"���׶�", 2015, 1341},
							{"���ϵ�", 2012, 1298},
							{"�ϻ�", 2015, 1270} } };
	ArrayB0 foreign = { 3, { {"�ƹ�Ÿ", 2009, 1333},
							{"���ͽ��ڶ�", 2014, 1030},
							{"�ܿ�ձ�", 2014, 1029} } };
	ArrayB0 merged = merge_B0(&domestic, &foreign);

	for (int i = 0; i < merged.length; i++)
		printf("����=%s, ������=%D\n",
			merged.movies[i].title, merged.movies[i].viewers);
}