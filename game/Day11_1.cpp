//#include "stc.h"
//#include "font.h"
//#include <iostream>
//
//#define RED 0xff0000
//#define BLUE 0x0000ff
//#define GREEN 0x00ff00
//#define BLACK 0x000000
//#define WHITE 0xffffff
//#define YELLOW 0xfff000
//
//char s[100];
//int score;
//int life;
//bool gameStart = false;
//
//// Position of ball;
//int ballX;
//int ballY;
//
//// Speed of ball;
//int speed;
//bool speedUp;
//
//// Direction of ball : {upLeft : 1, upRight : 2, downRight : 3, downLeft : 4}
//int direction;
//
//// Start x index of slide bar;
//int start;
//int length;
//int currentTime;
//
//
//struct Brick {
//	int startPosX;
//	int startPosY;
//	unsigned int color;
//	int step;
//	bool right = true;
//	void draw() {
//		for (int i = startPosX;i < startPosX + 40;i++) {
//			for (int j = startPosY; j < startPosY + 10; j++) {
//				SetPixel(i, j, color);
//			}
//		}
//	}
//
//	void move() {
//		if (right) {
//			if (startPosX == 280 || GetPixel(startPosX + 40, startPosY) != BLACK) {
//				right = false;
//				return;
//			}
//			startPosX = startPosX + 1;
//			for (int j = startPosY; j < startPosY + 10;j++) {
//				SetPixel(startPosX + 39, j, color);
//			}
//
//			for (int j = startPosY; j < startPosY + 10;j++) {
//				SetPixel(startPosX - 1, j, BLACK);
//			}
//		}
//		else {
//
//			if (startPosX == 0 || GetPixel(startPosX - 1, startPosY) != BLACK) {
//				right = true;
//				return;
//			}
//			startPosX = startPosX - 1;
//
//			for (int j = startPosY; j < startPosY + 10;j++) {
//				SetPixel(startPosX, j, color);
//			}
//
//
//			for (int j = startPosY; j < startPosY + 10;j++) {
//				SetPixel(startPosX + 40, j, BLACK);
//			}
//
//		}
//	}
//
//};
//
//Brick b1;
//Brick b2;
//Brick list_brick[5][8];
//void draw_char(char c, int x, int y, unsigned int color) {
//	int posY = 0;
//
//	while (posY < 8)
//	{
//		int posX = 0;
//
//		while (posX < 8)
//		{
//			if (font[c][posY][posX] == 1) SetPixel(posX + x, posY + y, color);
//			else SetPixel(posX + x, posY + y, BLACK);
//			posX++;
//		}
//		posY++;
//	}
//}
//
//void draw_text() {
//	draw_char('S', 0, 0, YELLOW);
//	draw_char('C', 8, 0, YELLOW);
//	draw_char('O', 16, 0, YELLOW);
//	draw_char('R', 24, 0, YELLOW);
//	draw_char('E', 32, 0, YELLOW);
//}
//
//
//void swap(char& a, char& b) {
//	char c = a;
//	a = b;
//	b = c;
//}
//
//char* toString(int x) {
//	int size = 0;
//	if (x == 0) {
//		s[0] = '0';
//		s[1] = '\0';
//		return s;
//	}
//	while (x > 0) {
//		s[size++] = x % 10 + '0';
//		x /= 10;
//	}
//	s[size] = '\0';
//	for (int i = 0; i < size / 2; i++) {
//		swap(s[i], s[size - i - 1]);
//	}
//	return s;
//}
//
//void updateScore(int x) {
//
//	for (int i = 56; i < 90;i++) {
//		for (int j = 0; j < 8;j++) {
//			SetPixel(i, j, BLACK);
//		}
//	}
//
//	char* t = toString(x);
//	for (int i = 0;t[i] != '\0';i++) {
//		draw_char(t[i], 56 + i * 8, 0, YELLOW);
//	}
//}
//
//void updateLife(int x) {
//
//	for (int i = x;i < 3;i++) {
//		draw_char(3, 96 + i * 8, 0, BLACK);
//	}
//
//	for (int i = 0;i < x;i++) {
//		draw_char(3, 96 + i * 8, 0, RED);
//	}
//}
//
//void draw_brick() {
//	for (int i = 0;i < 5;i++) {
//		for (int j = 0;j < 8;j++) {
//			if ((i + j) % 2 == 0) {
//				if (j == 0 || j == 4) {
//					list_brick[i][j].startPosX = j * 40;
//					list_brick[i][j].startPosY = i * 10 + 20;
//					list_brick[i][j].color = RED;
//					list_brick[i][j].draw();
//				}
//				if (j == 2 || j == 6) {
//					list_brick[i][j].startPosX = j * 40;
//					list_brick[i][j].startPosY = i * 10 + 20;
//					list_brick[i][j].color = BLUE;
//					list_brick[i][j].draw();
//				}
//				if (j == 1 || j == 5) {
//					list_brick[i][j].startPosX = j * 40;
//					list_brick[i][j].startPosY = i * 10 + 20;
//					list_brick[i][j].color = GREEN;
//					list_brick[i][j].draw();
//				}
//				if (j == 3 || j == 7) {
//					list_brick[i][j].startPosX = j * 40;
//					list_brick[i][j].startPosY = i * 10 + 20;
//					list_brick[i][j].color = YELLOW;
//					list_brick[i][j].draw();
//				}
//			}
//		}
//	}
//}
//
//void move_all_brick() {
//	for (int i = 0;i < 5;i++) {
//		for (int j = 0;j < 8;j++) {
//			if ((i + j) % 2 == 0) {
//				list_brick[i][j].move();
//			}
//		}
//	}
//}
////void draw_brick() {
////
////	Draw brick line 1,3,5
////	for (int i = 0;i < 8;i++) {
////		for (int j = i * 40; j < (i + 1) * 40; j++) {
////			for (int k = 20;k < 30;k++) {
////				if (i == 0 || i == 3 || i == 6) {
////					SetPixel(j, k, RED);
////				}
////				else if (i == 1 || i == 4 || i == 7) {
////					SetPixel(j, k, BLUE);
////				}
////				else {
////					SetPixel(j, k, GREEN);
////				}
////			}
////
////			for (int k = 40;k < 50;k++) {
////				if (i == 0 || i == 3 || i == 6) {
////					SetPixel(j, k, RED);
////				}
////				else if (i == 1 || i == 4 || i == 7) {
////					SetPixel(j, k, BLUE);
////				}
////				else {
////					SetPixel(j, k, GREEN);
////				}
////			}
////
////			for (int k = 60;k < 70;k++) {
////				if (i == 0 || i == 3 || i == 6) {
////					SetPixel(j, k, RED);
////				}
////				else if (i == 1 || i == 4 || i == 7) {
////					SetPixel(j, k, BLUE);
////				}
////				else {
////					SetPixel(j, k, GREEN);
////				}
////			}
////
////		}
////	}
////
////	Draw brick line 2,4
////	for (int i = 0;i < 8;i++) {
////		for (int j = i * 40; j < (i + 1) * 40; j++) {
////			for (int k = 30;k < 40;k++) {
////				if (i == 0 || i == 3 || i == 6) {
////					SetPixel(j, k, BLUE);
////				}
////				else if (i == 1 || i == 4 || i == 7) {
////					SetPixel(j, k, GREEN);
////				}
////				else {
////					SetPixel(j, k, RED);
////				}
////			}
////
////			for (int k = 50;k < 60;k++) {
////				if (i == 0 || i == 3 || i == 6) {
////					SetPixel(j, k, BLUE);
////				}
////				else if (i == 1 || i == 4 || i == 7) {
////					SetPixel(j, k, GREEN);
////				}
////				else {
////					SetPixel(j, k, RED);
////				}
////			}
////		}
////	}
////
////}
//
//void draw_ball(int x, int y, unsigned int color) {
//	SetPixel(x, y, color);
//	SetPixel(x + 1, y, color);
//	SetPixel(x, y + 1, color);
//	SetPixel(x + 1, y + 1, color);
//}
//
//void draw_slide_bar(int start, int length) {
//	for (int i = start; i < start + length; i++)
//	{
//		for (int j = 190; j < 200; j++)
//		{
//			SetPixel(i, j, WHITE);
//		}
//	}
//}
//
//int move_slide_bar(int start, bool left, int length) {
//	int step = 5;
//
//	// Move to left
//	if (left) {
//		// If bar touches the left edge of window 
//		if (start == 0) return start;
//
//		// Draw 5 white block in left
//		for (int i = start - step; i < start; i++) {
//			for (int j = 190; j < 200;j++) {
//				SetPixel(i, j, WHITE);
//			}
//		}
//
//		// Change 5 white block to black in right;
//		for (int i = start + length - step; i < start + length;i++) {
//			for (int j = 190; j < 200;j++) {
//				SetPixel(i, j, BLACK);
//			}
//		}
//		return start - step;
//	}
//	else {
//
//		// If bar touches the right edge of window 
//		if (start == 280) return start;
//
//		// Draw 5 white block in right
//		for (int i = start + length; i < start + length + step; i++) {
//			for (int j = 190; j < 200;j++) {
//				SetPixel(i, j, WHITE);
//			}
//		}
//
//		// Change 5 white block to black in left;
//		for (int i = start - step; i < start + step;i++) {
//			for (int j = 190; j < 200;j++) {
//				SetPixel(i, j, BLACK);
//			}
//		}
//		return start + step;
//	}
//}
//
//void clear_slide_bar(int start, int length) {
//	for (int i = start; i < start + length;i++) {
//		for (int j = 190;j < 200;j++) {
//			SetPixel(i, j, BLACK);
//		}
//	}
//}
//
//void speed_up_ball() {
//	speed = 10;
//	speed = true;
//	length = 20;
//	speed = 10;
//	speedUp = true;
//	clear_slide_bar(start, 40);
//	draw_slide_bar(start, length);
//}
//
//void delete_brick(int r, int c) {
//	for (int i = 20 + r * 10; i < 20 + (r + 1) * 10; i++)
//	{
//		for (int j = c * 40; j < (c + 1) * 40; j++)
//		{
//			SetPixel(j, i, BLACK);
//		}
//	}
//}
//
//void upLeft() {
//
//	// Delete previous ball position
//	draw_ball(ballX, ballY, BLACK);
//	ballX = ballX - 1;
//	ballY = ballY - 1;
//
//	// Update ball position
//	draw_ball(ballX, ballY, WHITE);
//
//
//	// Touch left edge of window or right short edge of brick
//	if (ballX == 0 || GetPixel(ballX - 1, ballY) != BLACK || GetPixel(ballX - 1, ballY + 1) != BLACK) {
//		direction = 2;
//		return;
//	}
//
//	// Touch the top bar
//	if (ballY == 8) {
//		if (!speedUp) {
//			speed_up_ball();
//		}
//		direction = 4;
//		return;
//	}
//
//	// Touch the long edge of brick
//	if (GetPixel(ballX, ballY - 1) != BLACK || GetPixel(ballX + 1, ballY - 1) != BLACK) {
//		int r = (ballY - 1 - 20) / 10;
//		int c = ballX / 40;
//		delete_brick(r, c);
//		score += 10;
//		updateScore(score);
//		direction = 4;
//		return;
//	}
//}
//
//
//void upRight() {
//
//	// Delete previous ball position
//	draw_ball(ballX, ballY, BLACK);
//	ballX = ballX + 1;
//	ballY = ballY - 1;
//
//	// Update ball position
//	draw_ball(ballX, ballY, WHITE);
//
//
//	// Touch right edge of window or left short edge of brick
//	if (ballX == 318 || GetPixel(ballX + 2, ballY) != BLACK || GetPixel(ballX + 2, ballY + 1) != BLACK) {
//		direction = 1;
//		return;
//	}
//
//	// Touch the top bar
//	if (ballY == 8) {
//		if (!speedUp) {
//			speed_up_ball();
//		}
//		direction = 3;
//		return;
//	}
//
//	// Touch the long edge of brick
//	if (GetPixel(ballX, ballY - 1) != BLACK || GetPixel(ballX + 1, ballY - 1) != BLACK) {
//		int r = (ballY - 1 - 20) / 10;
//		int c = ballX / 40;
//		delete_brick(r, c);
//		score += 10;
//		updateScore(score);
//		direction = 3;
//		return;
//	}
//}
//
//void downRight() {
//
//	// Delete previous ball position
//	draw_ball(ballX, ballY, BLACK);
//	ballX = ballX + 1;
//	ballY = ballY + 1;
//
//	// Update ball position
//	draw_ball(ballX, ballY, WHITE);
//
//
//	// Touch right edge of window or left short edge of brick
//	if (ballX == 318 || GetPixel(ballX + 2, ballY) != BLACK || GetPixel(ballX + 2, ballY + 1) != BLACK) {
//		direction = 4;
//		return;
//	}
//
//	// Touch the bottom bar
//	if (ballY == 198) {
//		draw_ball(ballX, ballY, BLACK);
//		life--;
//		gameStart = false;
//		updateLife(life);
//		clear_slide_bar(start, length);
//		ballX = 159;
//		ballY = 188;
//		start = 140;
//		direction = 2;
//		draw_ball(ballX, ballY, WHITE);
//		draw_slide_bar(start, length);
//		return;
//	}
//
//	// Touch the long edge of brick  or long edge of slide bar
//	if (GetPixel(ballX, ballY + 2) != BLACK || GetPixel(ballX + 1, ballY + 2) != BLACK) {
//		if (GetPixel(ballX, ballY + 2) != WHITE || GetPixel(ballX + 1, ballY + 2) != WHITE) {
//			int r = (ballY + 2 - 20) / 10;
//			int c = ballX / 40;
//			delete_brick(r, c);
//			score += 10;
//			updateScore(score);
//		}
//
//		direction = 2;
//		return;
//	}
//}
//
//void downLeft() {
//
//	// Delete previous ball position
//	draw_ball(ballX, ballY, BLACK);
//	ballX = ballX - 1;
//	ballY = ballY + 1;
//
//	// Update ball position
//	draw_ball(ballX, ballY, WHITE);
//
//
//	// Touch left edge of window or right short edge of brick
//	if (ballX == 0 || GetPixel(ballX - 1, ballY) != BLACK || GetPixel(ballX - 1, ballY + 1) != BLACK) {
//		cout << direction << endl;
//
//		direction = 3;
//		cout << direction << endl;
//		return;
//	}
//
//	// Touch the bottom bar
//	if (ballY == 198) {
//		draw_ball(ballX, ballY, BLACK);
//		life--;
//		gameStart = false;
//		updateLife(life);
//		clear_slide_bar(start, length);
//		ballX = 159;
//		ballY = 188;
//		start = 140;
//		direction = 2;
//		draw_ball(ballX, ballY, WHITE);
//		draw_slide_bar(start, length);
//		return;
//	}
//
//	// Touch the long edge of brick  or long edge of slide bar
//	if (GetPixel(ballX, ballY + 2) != BLACK || GetPixel(ballX + 1, ballY + 2) != BLACK) {
//		if (GetPixel(ballX, ballY + 2) != WHITE || GetPixel(ballX + 1, ballY + 2) != WHITE) {
//			int r = (ballY + 2 - 20) / 10;
//			int c = ballX / 40;
//			delete_brick(r, c);
//			score += 10;
//			updateScore(score);
//		}
//
//		direction = 1;
//		return;
//	}
//}
//
//void init() {
//	score = 0;
//	life = 3;
//	ballX = 159;
//	ballY = 188;
//	speed = 15;
//	length = 40;
//	start = 140;
//	direction = 2;
//	currentTime = GetMilisec();
//	speedUp = false;
//
//
//	draw_text();
//	updateScore(score);
//	updateLife(life);
//	draw_brick();
//
//
//	draw_slide_bar(140, 40);
//	draw_ball(ballX, ballY, WHITE);
//}
//
//void play() {
//	while (true) {
//		if (life == 0 || score == 400) init();
//		int keyPressed = GetInput(false);
//		//Spacebar
//		if (keyPressed == 32) {
//			gameStart = true;
//			cout << keyPressed << endl;
//		}
//
//		// Left
//		if (keyPressed == 144) {
//			start = move_slide_bar(start, true, length);
//			cout << keyPressed << endl;
//
//		}
//
//		//Right
//		if (keyPressed == 146) {
//			start = move_slide_bar(start, false, length);
//			cout << keyPressed << endl;
//
//		}
//
//		if (gameStart) {
//			if (GetMilisec() >= (currentTime + speed)) {
//				BeginUpdate();
//				move_all_brick();
//				if (direction == 1) {
//					currentTime = GetMilisec();
//					upLeft();
//					//start = move_slide_bar(start, true, length);
//
//				}
//				else if (direction == 2) {
//					currentTime = GetMilisec();
//					upRight();
//					//start = move_slide_bar(start, false, length);
//
//				}
//				else if (direction == 3) {
//					currentTime = GetMilisec();
//					downRight();
//					//start = move_slide_bar(start, false, length);
//
//
//				}
//				else {
//					currentTime = GetMilisec();
//					downLeft();
//					//start = move_slide_bar(start, true, length);
//
//				}
//				EndUpdate();
//			}
//
//		}
//	}
//}
//
//int main() {
//	init();
//	play();
//	return 0;
//}