#include"FOOTBALL_GAME_CLASS.h"

void FOOTBALL_GAME_CLASS::Update()
{
	if (_kbhit())
	{
		if (this->m_state == STATE_GAMEOVER)
			break;

		nKey = _getch();

		switch (nKey)
		{
		case 'j':
			if (g_sPlayer.get_x() > 2) // ���� �浹 ��� ��ǥ üũ
			{
				g_sPlayer.plus_x(-1);
				nRemain = g_Opt.g_nLength - g_sPlayer.nCenterX + 1; // ��ü ���� - ( �߽� ��ǥ + 1 )�� ���� ����
																	// Note: 2�÷��� �̵��ϱ� ���� �κ� ( ���� ��ģ ��� ) 
				if (g_sPlayer.get_x() - g_sPlayer.nCenterX < 2 || g_sPlayer.get_x() + nRemain > 43)
					g_sPlayer.plus_x(-1);

				g_sPlayer.nX = g_sPlayer.get_x() - g_sPlayer.nCenterX;
			}
			break;
		case 'l':
			if (g_sPlayer.get_x() + 1 < 43) // ������ �浹 ��� ��ǥ üũ
			{
				g_sPlayer.plus_x(1);
				nRemain = g_Opt.g_nLength - g_sPlayer.nCenterX + 1; // ��ü ���� - ( �߽� ��ǥ + 1 )�� ���� ����
																	// Note: 2�÷��� �̵��ϱ� ���� �κ� ( ���� ��ģ ��� )
				if (g_sPlayer.get_x() + nRemain > 43 || (g_sPlayer.get_x() - g_sPlayer.nCenterX < 2))
					g_sPlayer.plus_x(1);

				g_sPlayer.nX = g_sPlayer.get_x() - g_sPlayer.nCenterX;
			}
			break;
		case 'k':
			if (g_sBall.nIsReady && this->m_state == STATE_PLAY)
			{
				g_sBall.set_x(g_sPlayer.get_x());
				g_sBall.set_y(g_sPlayer.get_y() - 1);
				g_sBall.OldTime = clock();
				g_sBall.nIsReady = 0;

				//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_Sound[5], 0, &g_Channel[5]); // �� ���� �Ҹ� ���
			}
			break;

		case 'y':
		case 'Y':
			if (this->m_state == STATE_GAMEOVER)
			{
				Init();
				this->m_state = STATE_TITLE;
				//FMOD_Channel_Stop( g_Channel[2] );  // �̼� ���� ���� ��� ���� 
				//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_Sound[3], 0, &g_Channel[3]);
			}
			break;
		case 'n':
		case 'N':
			if (this->m_state == STATE_GAMEOVER)
			{
				this->m_state = STATE_GAMEOVER;
				//FMOD_Channel_Stop( g_Channel[2] );  // �̼� ���� ���� ��� ����							
			}
			break;

		case ' ':
			if (this->m_state == STATE_INIT && g_Opt.g_nStage == 0)
			{
				this->m_state = STATE_TITLE;
				//FMOD_Channel_Stop( g_Channel[0] ); // ����� ����
				//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_Sound[3], 0, &g_Channel[3]); // ready ����
				g_Opt.g_UpdateOldTime = clock();  // ready�� �����ð� ������ �ֱ� ���� 							
			}
			break;
		}
	}
}