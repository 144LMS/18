#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#include <math.h>
#include <time.h>

struct Point {
	int x;
	int y;
	char name;
};
struct player {
	char sname[10];
	char dataa[20];
	char place[50];
	char amplua[20];
	int games;
	int ycard;
};

void put_point(struct Point z) {

	printf("point %c (%d, %d)", z.name, z.x, z.y);
}

void dist(struct Point z, struct Point w) {
	int dal = 0;
	dal = sqrt(pow(w.y - z.y, 2) + pow(w.x - z.x, 2));
	printf("\nРасстояние > %d", dal);
}
void mid(struct Point z, struct Point w) {
	float M1, M2;
	M1 = (w.x + z.x) / 2.;
	M2 = (w.y + z.y) / 2.;
	printf("\nСередина > M (%.1f ;%.1f)", M1, M2);
}
void qvrt(struct Point w) {
	if (w.x > 0 && w.y > 0) printf("\n Принадлежит 1 четверти");
	if (w.x > 0 && w.y < 0) printf("\n Принадлежит 4 четверти");
	if (w.x < 0 && w.y > 0) printf("\n Принадлежит 2 четверти");
	if (w.x < 0 && w.y < 0) printf("\n Принадлежит 3 четверти");
	if (w.x == 0 || w.y == 0) printf("\nЛежит на одной из осей");
}

void task1() {

	struct 	Point a, b;
	a.name = 'A';
	b.name = 'B';
	puts("Введите координаты точки A");
	scanf("%d %d", &a.x, &a.y);
	puts("Введите координаты точки B");
	scanf("%d %d", &b.x, &b.y);
	put_point(a);
	put_point(b);
	dist(a, b);
	mid(a, b);
	qvrt(a);
}

void task2() {
	struct tm* mytime;
	time_t t;
	char buffer[200];
	char* start;
	char* finish;
	t = time(NULL);
	mytime = localtime(&t);
	int i = 0;
	printf("Время %02d:%02d:%02d \n", mytime->tm_hour, mytime->tm_min, mytime->tm_sec); 
	sprintf(buffer, "День > %d | Месяц > %d | Год > %d", mytime->tm_mday, mytime->tm_mon, mytime->tm_year - 100 + 2000);
	for (i = 0; buffer[i] != '\0'; i++);																			
	printf("%d", i);
	start = malloc(77 - 2 * i * sizeof(char));																					
	finish = malloc(81 - 2 * i * sizeof(char));
	for (int j = 0; j < 81 - 2 * i; j++) {
		start[j] = '*';
	}

	for (int j = 0; j < 81 - 2 * i; j++) {
		finish[j] = '*';
	}
	printf("\n");
	sprintf(buffer, "%sДень > %d | Месяц > %d | Год > %d%s", start, mytime->tm_mday, mytime->tm_mon, mytime->tm_year - 100 + 2000, finish);
	printf("%s", buffer);
}
void task3() {
	srand(time(0));
	int flag = 0;

	struct player p1, p2, p3, p4, p5;
	sprintf(p1.sname, "Воронов");
	sprintf(p1.dataa, "03.05.1991");
	sprintf(p1.place, "Подольск");
	sprintf(p1.amplua, "пророк");
	p1.games = ((float)rand() / RAND_MAX) * (49 - 0) + 1;
	p1.ycard = ((float)rand() / RAND_MAX) * (5 - 0);

	sprintf(p2.sname, "Насонов");
	sprintf(p2.dataa, "18.04.1996");
	sprintf(p2.place, "Белгород");
	sprintf(p2.amplua, "брошюра");
	p2.games = ((float)rand() / RAND_MAX) * (49 - 0) + 1;
	p2.ycard = ((float)rand() / RAND_MAX) * (5 - 0);

	sprintf(p3.sname, "Фролов");
	sprintf(p3.dataa, "21.12.2003");
	sprintf(p3.place, "Алмата");
	sprintf(p3.amplua, "крекер");
	p3.games = ((float)rand() / RAND_MAX) * (49 - 0) + 1;
	p3.ycard = ((float)rand() / RAND_MAX) * (5 - 0);

	sprintf(p4.sname, "Пырков");
	sprintf(p4.dataa, "30.07.1994");
	sprintf(p4.place, "Мурманск");
	sprintf(p4.amplua, "крен");
	p4.games = ((float)rand() / RAND_MAX) * (49 - 0) + 1;
	p4.ycard = ((float)rand() / RAND_MAX) * (5 - 0);

	sprintf(p5.sname, "Свинотов");
	sprintf(p5.dataa, "01.04.2004");
	sprintf(p5.place, "Липецск");
	sprintf(p5.amplua, "рефрактор");
	p5.games = ((float)rand() / RAND_MAX) * (49 - 0) + 1;
	p5.ycard = ((float)rand() / RAND_MAX) * (5 - 0);
	if ((p1.dataa[8] == 0 && (int)p1.dataa >= 2) || (((float)p1.ycard / (float)p1.games) >= 0.1)) {
		printf("1 неподходит");
	}
	else printf("Фамилия > %s\nДата рождения > %s\nМесто рождения > %s\nАмплуа > %s\nИгр > %d\nЖелтых карточек > %d\n", p1.sname, p1.dataa, p1.place, p1.amplua, p1.games, p1.ycard);
	printf("\n");
	printf("\n");
	if ((p2.dataa[8] == 0 && (int)p2.dataa >= 2) || (((float)p2.ycard / (float)p2.games) >= 0.1)) {
		printf("2 неподходит");
	}
	else printf("Фамилия > %s\nДата рождения > %s\nМесто рождения > %s\nАмплуа > %s\nИгр > %d\nЖелтых карточек > %d\n", p2.sname, p2.dataa, p2.place, p2.amplua, p2.games, p2.ycard);
	printf("\n");
	printf("\n");
	if ((p3.dataa[8] == 0 && (int)p3.dataa >= 2) || (((float)p3.ycard / (float)p3.games) >= 0.1)) {
		printf("3 неподходит");
	}
	else printf("Фамилия > %s\nДата рождения > %s\nМесто рождения > %s\nАмплуа > %s\nИгр > %d\nЖелтых карточек > %d\n", p3.sname, p3.dataa, p3.place, p3.amplua, p3.games, p3.ycard);
	printf("\n");
	printf("\n");
	if ((p4.dataa[8] == 0 && (int)p4.dataa >= 2) || (((float)p4.ycard / (float)p4.games) >= 0.1)) {
		printf("4 неподходит");
	}
	else printf("Фамилия > %s\nДата рождения > %s\nМесто рождения > %s\nАмплуа > %s\nИгр > %d\nЖелтых карточек > %d\n", p4.sname, p4.dataa, p4.place, p4.amplua, p4.games, p4.ycard);
	printf("\n");
	printf("\n");
	if (((int)p5.dataa[8] == 48 && (int)p5.dataa[9] >= 50) || (((float)p5.ycard / (float)p5.games) > 0.1)) {
		printf("5 неподходит");
	}
	else {
		printf("Фамилия > %s\nДата рождения > %s\nМесто рождения > %s\nАмплуа > %s\nИгр > %d\nЖелтых карточек > %d\n", p5.sname, p5.dataa, p5.place, p5.amplua, p5.games, p5.ycard);
		printf("\n");
		printf("\n");
	}
}

void main() {
	setlocale(LC_ALL, "ru_RU");
	task1();
}