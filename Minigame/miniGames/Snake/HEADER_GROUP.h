#pragma once
#pragma region ��� �� ��ó��

#define MAX_STAGE_ 2

#include<iostream>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <windows.h>
#include <time.h>
//#include <fmod.h>
#include"Point_Class.h"
#include "stdafx.h"

//*********************************
//��� ����
//*********************************
#define EXT_KEY			0xffffffe0	//Ȯ��Ű �νİ� 
#define KEY_LEFT		0x4b
#define KEY_RIGHT		0x4d
#define KEY_UP			0x48
#define KEY_DOWN		0x50
enum {
	BLACK,      /*  0 : ��� */
	DARK_BLUE,    /*  1 : ��ο� �Ķ� */
	DARK_GREEN,    /*  2 : ��ο� �ʷ� */
	DARK_SKY_BLUE,  /*  3 : ��ο� �ϴ� */
	DARK_RED,    /*  4 : ��ο� ���� */
	DARK_VOILET,  /*  5 : ��ο� ���� */
	DARK_YELLOW,  /*  6 : ��ο� ��� */
	GRAY,      /*  7 : ȸ�� */
	DARK_GRAY,    /*  8 : ��ο� ȸ�� */
	BLUE,      /*  9 : �Ķ� */
	GREEN,      /* 10 : �ʷ� */
	SKY_BLUE,    /* 11 : �ϴ� */
	RED,      /* 12 : ���� */
	VOILET,      /* 13 : ���� */
	YELLOW,      /* 14 : ��� */
	WHITE,      /* 15 : �Ͼ� */
};

enum state {
	STATE_DEFAULT,		// ���� �ʱ�
	STATE_INIT,			// �ʱ�ȭ��
	STATE_TITLE,		// Ÿ��Ʋ
	STATE_PLAY,			// ������
	STATE_GAMEOVER,		// ���� ����
	STATE_GAME_OFF		// ���� ����
};

#pragma endregion
