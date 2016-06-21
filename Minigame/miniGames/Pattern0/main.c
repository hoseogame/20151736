#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include "Screen.h"

void gotoxy( int x, int y )
{
	COORD CursorPosition = { x, y };
	SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE), CursorPosition );
}

typedef enum _DIRECT { UP, UP_RIGHT, RIGHT, DOWN_RIGHT, DOWN, DOWN_LEFT, LEFT, UP_LEFT } DIRECT;


typedef struct _PAT
{
	DIRECT nDirect;
	int nStep;
	clock_t MoveTime;
	int nDist;
} PAT;

typedef struct _PAT_INFO
{
	int nCount;
	int nX0, nY0;
	PAT *pPat;
} PAT_INFO;

PAT_INFO g_PatInfo;

int Menu()
{
	int nMenu;

	gotoxy( 20, 2 );  printf( " 패턴 뷰어 프로그램" );
	gotoxy( 10, 8 );  printf( "1. 파일 열기" );
	gotoxy( 10, 10);  printf( "2. 패턴 보기" );
	gotoxy( 10, 12 ); printf( "3. 종료" );
	gotoxy( 10, 17 ); printf( "메뉴 선택 [    ]" );
	gotoxy( 22, 17 ); scanf( "%d", &nMenu );

	return nMenu;
}

void InputBox()
{
	gotoxy( 10, 5 ); printf( "┌──────────────────────┐" );
	gotoxy( 10, 6 ); printf( "│                                            │" );
	gotoxy( 10, 7 ); printf( "│ 파일명 :                                   │" );
	gotoxy( 10, 8 ); printf( "│                                            │" );
	gotoxy( 10, 9 ); printf( "└──────────────────────┘" );
}

int main(void)
{
	int i, nX, nY, nSignX, nSignY, nMenu, nKey, nLoop1, nLoop2 = 1;
	clock_t CurTime;
	int nIndex, nStep;
	char string[100];
	FILE *fp;
	clock_t PatOldTime;

	while( 1 )
	{
		system( "cls" );
		nMenu = Menu();
		if( nMenu == 3 )
			break;

		switch( nMenu )
		{
		case 1 :
				system( "cls" );

				InputBox();
				gotoxy( 22, 7 );
				scanf( "%s", string );

				fp = fopen( string, "r" );

				fscanf( fp, "%d\n", &g_PatInfo.nCount );
				fscanf( fp, "%d %d\n", &g_PatInfo.nX0, &g_PatInfo.nY0 );

				if( g_PatInfo.pPat != NULL )
					free( g_PatInfo.pPat );

				g_PatInfo.pPat = (PAT*)malloc( sizeof( PAT ) * g_PatInfo.nCount );

				for( i = 0 ; i < g_PatInfo.nCount ; i++ )
					 fscanf( fp, "%d %d %d %d\n", &g_PatInfo.pPat[i].nDirect, &g_PatInfo.pPat[i].nStep, &g_PatInfo.pPat[i].MoveTime, &g_PatInfo.pPat[i].nDist );
				
				fclose( fp );	
				break;
		case 2 :
				nLoop1 = 1;
				while( nLoop1 )
				{
					system( "cls" );
					gotoxy( g_PatInfo.nX0, g_PatInfo.nY0 ); 
					printf( "@:[0] (%d, %d)", g_PatInfo.nX0, g_PatInfo.nY0 );

					nX = g_PatInfo.nX0;
					nY = g_PatInfo.nY0;

					for( i = 0 ; i < g_PatInfo.nCount ; i++ )
					{
						switch( g_PatInfo.pPat[i].nDirect )
						{
						case UP: 
								nSignX = 0;
								nSignY = -1;
								break;

						case UP_RIGHT:
								nSignX = 1;
								nSignY = -1;
								break;

						case RIGHT:
								nSignX = 1;
								nSignY = 0;
								break;

						case DOWN_RIGHT:
								nSignX = 1;
								nSignY = 1;
								break;

						case DOWN:
								nSignX = 0;
								nSignY = 1;
								break;

						case DOWN_LEFT:
								nSignX = -1;
								nSignY = 1;
								break;

						case LEFT:
								nSignX = -1;
								nSignY = 0;
								break;

						case UP_LEFT:
								nSignX = -1;
								nSignY = -1;
								break;
						}

						nX = nX + nSignX*g_PatInfo.pPat[i].nDist*g_PatInfo.pPat[i].nStep;
						nY = nY + nSignY*g_PatInfo.pPat[i].nDist*g_PatInfo.pPat[i].nStep;

						gotoxy( nX, nY );
						printf( "@:[%d] (%d, %d)", i+1, nX, nY );
					}

					gotoxy( 0, 23 );
					printf( "실행: s 메뉴로: q  [     ]" );
					gotoxy( 22, 23 );

					nLoop2 = 1;
					while( nLoop2 )
					{
						nKey = _getch();
						if( nKey == 'q' )
						{
							nLoop1 = 0;
							break;
						}else if( nKey == 's' ){
							
							// 게임 화면 전환
							ScreenInit();
						
							nIndex = 0;
							nX = g_PatInfo.nX0;
							nY = g_PatInfo.nY0;
							nStep = -1;
							PatOldTime = clock();

							while( 1 )
							{								
								// Note: Update()
								CurTime = clock();
								
								if( CurTime - PatOldTime > g_PatInfo.pPat[nIndex].MoveTime ) 
								{
									PatOldTime = CurTime;
									nStep++;

									if( nStep == g_PatInfo.pPat[nIndex].nStep )
									{
										nIndex++;

										if( nIndex == g_PatInfo.nCount ) // 종료 조건
										{
											nLoop2 = 0;
 											break;
										}else{
											nStep = 0;
										}
									}

									switch( g_PatInfo.pPat[nIndex].nDirect )
									{
									case UP: 
											nSignX = 0;
											nSignY = -1;
											break;
									case UP_RIGHT:
											nSignX = 1;
											nSignY = -1;
											break;
									case RIGHT:
											nSignX = 1;
											nSignY = 0;
											break;
									case DOWN_RIGHT:
											nSignX = 1;
											nSignY = 1;
											break;
									case DOWN:
											nSignX = 0;
											nSignY = 1;
											break;
									case DOWN_LEFT:
											nSignX = -1;
											nSignY = 1;
											break;
									case LEFT:
											nSignX = -1;
											nSignY = 0;
											break;
									case UP_LEFT:
											nSignX = -1;
											nSignY = -1;
											break;
									}

									nX = nX + nSignX*g_PatInfo.pPat[nIndex].nDist;
									nY = nY + nSignY*g_PatInfo.pPat[nIndex].nDist;
									
								}

								// Note: Render()

								ScreenClear();
								ScreenPrint( nX, nY, "@" );
								ScreenFlipping();								
							}							
							ScreenRelease();
						}
					}
				}				
				break;
		}
	}

	return 0;
}