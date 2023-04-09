#define MAX_SIZE 100
#include <stdio.h>
#include <stdlib.h>

// 영화 정보를 저장하는 구조체 Movie 정의
typedef struct Movie {
	char title[50];
	int release;
	int viewers;
} Movie;
// 중첩 구조체 ArrayB0 정의
typedef struct ArrayB0 {
	int length;
	Movie movies[MAX_SIZE];
} ArrayB0;

// 구조체 배열 뒤에 영화를 추가하는 함수
void add_movie(ArrayB0* B0, Movie m) {
	if (B0->length == MAX_SIZE) {
		printf("영화를 더 이상 추가할 수 없습니다.\n");
		exit(1);
	}
	B0->movies[B0->length] = m;
	B0->length;
}

// 두 박스오피스를 하나로 합치는 함수
ArrayB0 merge_B0(ArrayB0* a, ArrayB0* b) {
	ArrayB0 c;
	int idx_a = 0; 
	int idx_b = 0;

	c.length = 0;

	while (idx_a < a->length && idx_b < b->length) {
		if (a->movies[idx_a].viewers >= b->movies[idx_b].viewers) {
			// a 관객수 >= b 관객수인 경우
			add_movie(&c, a->movies[idx_a]);
			idx_a++;
		}
		else { // a 관객수 < b 관객수인 경우
			add_movie(&c, b->movies[idx_b]);
			idx_b++;
		}
	}
	// 아직 남아있는 a 영화들을 추가
	for (; idx_a < a->length; idx_a++) add_movie(&c, a->movies[idx_a]);
	// 아직 남아있는 b 영화들을 추가
	for (; idx_b < b->length; idx_b++) add_movie(&c, b->movies[idx_b]);
	return c;
}

int main() {
	ArrayB0 domestic = { 4, { {"명량", 2014, 1761},
							{"베테랑", 2015, 1341},
							{"도둑들", 2012, 1298},
							{"암살", 2015, 1270} } };
	ArrayB0 foreign = { 3, { {"아바타", 2009, 1333},
							{"인터스텔라", 2014, 1030},
							{"겨울왕국", 2014, 1029} } };
	ArrayB0 merged = merge_B0(&domestic, &foreign);

	for (int i = 0; i < merged.length; i++)
		printf("제목=%s, 관객수=%D\n",
			merged.movies[i].title, merged.movies[i].viewers);
}