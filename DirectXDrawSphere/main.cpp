

//������ ���α� : https://mingyu0403.tistory.com/218
//�ܼ�â�� ����ֵ��� ����
#ifdef UNICODE
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
#else
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif

#include "Engine.h"

#ifdef UNICODE
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
#else
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int nCmdShow)
#endif
{
	// ��ü.
	Engine engine = Engine(hInstance, 1280, 800, L"�׷��Ƚ� ����");

	// �ʱ�ȭ.
	if (engine.Initialize() == false)
	{
		MessageBox(nullptr, L"���� �ʱ�ȭ ����", L"����", 0);
		exit(-1);
	}
	
	//  ����.
	engine.Run();
}