// GameProject.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <bangtal.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
SceneID scene, scene2;
ObjectID ball, ball2,ball3, startButton, back, endButton, restartButton;
TimerID timer1, timer2;
int p = 0;

void case1() {
	switch (rand() % 12) {
	case 0: locateObject(ball, scene, 240, 60); showObject(ball); break;
	case 1: locateObject(ball, scene, 240, 260); showObject(ball); break;
	case 2: locateObject(ball, scene, 240, 460); showObject(ball); break;
	case 3: locateObject(ball, scene, 440, 60); showObject(ball); break;
	case 4: locateObject(ball, scene, 440, 260); showObject(ball); break;
	case 5: locateObject(ball, scene, 440, 460); showObject(ball); break;
	case 6: locateObject(ball, scene, 640, 60); showObject(ball); break;
	case 7: locateObject(ball, scene, 640, 260); showObject(ball); break;
	case 8: locateObject(ball, scene, 640, 460); showObject(ball); break;
	case 9: locateObject(ball, scene, 840, 60); showObject(ball); break;
	case 10: locateObject(ball, scene, 840, 260); showObject(ball); break;
	case 11: locateObject(ball, scene, 840, 460); showObject(ball); break;

	}
}


void start() {
	setTimer(timer1, 0.35f);
	startTimer(timer1);
	setTimer(timer2, 20.0f);
	showTimer(timer2);
	startTimer(timer2);
	enterScene(scene);
}

void mouseCallback(ObjectID object, int x, int y, MouseAction action) {
	if (object == startButton){
		start();
	}
	if (object == ball) {
		p += 1;
		}
	if (object == endButton) {
		endGame();
	}
}


void timerCallback(TimerID timer)
{
	if (timer == timer1) {
		case1();
		setTimer(timer1, 0.35f);
		startTimer(timer1);
	}
	if (timer == timer2) {
		printf("score : %d click \n", p);
		setObjectImage(startButton, "restart.png");
		showObject(endButton);
		stopTimer(timer1);
		stopTimer(timer2);
		enterScene(scene2);
		}
	}


int main()
{
	setGameOption(GameOption::GAME_OPTION_ROOM_TITLE, false);
	setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
	setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);

	setTimerCallback(timerCallback);
	setMouseCallback(mouseCallback);

	scene2 = createScene("시작 배경", "kakao.jpg");
	scene = createScene("두더지 잡기", "back.png");
	ball = createObject("duck.png");
	startButton = createObject("start.png");
    endButton = createObject("end.png");

	timer1 = createTimer(0.35f);
	timer2 = createTimer(20.0f);
	
	locateObject(startButton, scene2, 580, 50);
	locateObject(endButton, scene2, 580, 10);
	
	back = createObject("f.png");
	locateObject(back, scene, 240, 60);
	showObject(back);

	showObject(startButton);

	SoundID sound = createSound("");
	playSound(sound);
	
	srand(time(NULL));
	startGame(scene2);
	return 0;
	
}
// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
