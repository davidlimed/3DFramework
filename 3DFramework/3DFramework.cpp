// 3DFramework.cpp: 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "3DFramework.h"
#include "Main.h"

HWND g_hWnd = nullptr;

LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(NULL));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = L"Client";
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(NULL));

	RegisterClassExW(&wcex);

	RECT		rc = { 100, 100, 900, 700 };

	AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);

	g_hWnd = CreateWindowW(L"Client", L"Client", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, rc.right - rc.left, rc.bottom - rc.top, nullptr, nullptr, hInstance, nullptr);

	ShowWindow(g_hWnd, nCmdShow);
	UpdateWindow(g_hWnd);

    MSG msg;
	ZeroMemory(&msg, sizeof(MSG));

	C_Main * pMain = new C_Main;

	pMain->Awake();
	pMain->Init();

    // 기본 메시지 루프입니다.
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		else
		{
			pMain->Update();
			pMain->LastUpdate();
			pMain->Render();
			pMain->LastRender();
		}
    }

	pMain->Release();

    return (int) msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
	case WM_KEYDOWN:
		if (GetAsyncKeyState(VK_ESCAPE))
			DestroyWindow(g_hWnd);
		break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}
