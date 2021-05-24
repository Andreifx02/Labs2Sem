#include <windows.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
LOGFONT lf;
HFONT hFont;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wc{ sizeof(WNDCLASSEX) };

	wc.style = CS_VREDRAW | CS_HREDRAW;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
	wc.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = L"WindowClass";

	lf.lfCharSet = DEFAULT_CHARSET;
	lf.lfPitchAndFamily = DEFAULT_PITCH;
	wcscpy_s(lf.lfFaceName, L"Harlow Solid Italic");
	lf.lfHeight = 30;
	lf.lfWeight = 10;
	lf.lfWidth = 20;
	lf.lfEscapement = 0;
	hFont = CreateFontIndirect(&lf);


	wc.lpfnWndProc = [](HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)->LRESULT {
		HDC  hdc;
		static PAINTSTRUCT ps;
		static RECT rect;
		static int Width, Height;
		static double x, y, r, phi, i, x_, y_;

		switch (uMsg)
		{
		case WM_SIZE:
			Width = LOWORD(lParam);
			Height = HIWORD(lParam);
			x = Width / 2;
			//x_ = Width / 2;
			y = Height / 2;
			//y_ = Height / 2;
			break;
		case WM_TIMER:
			if (wParam == 2) {
				HDC hdc = GetDC(hWnd);
				HBRUSH Brush = CreateSolidBrush(RGB(0, 255, 0));
				HBRUSH BrushW = CreateSolidBrush(RGB(255, 255, 255));
				HPEN PenW = CreatePen(PS_SOLID, 3, RGB(255, 255, 255));
				HPEN Pen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
				HPEN Pen1 = CreatePen(PS_DASH, 3, RGB(0, 0, 0));
				HPEN Pen2 = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
				HPEN Pen3 = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
				wstring str = L"x = " + std::to_wstring(cos(phi));
				wstring str1 = L"y = " + std::to_wstring(sin(phi));
				SelectObject(hdc, hFont);
				TextOut(hdc, 100, 100, str.c_str(), str.size());
				TextOut(hdc, 100, 130, str1.c_str(), str1.size());
				SelectObject(hdc, BrushW);
				SelectObject(hdc, PenW);
				Ellipse(hdc, x - 18, y - 18, x + 18, y + 18);


				SelectObject(hdc, Pen1);
				MoveToEx(hdc, 0, Height / 2, nullptr);
				LineTo(hdc, Width, Height / 2);
				MoveToEx(hdc, Width / 2, Height, nullptr);
				LineTo(hdc, Width / 2, 0);

				SelectObject(hdc, Pen);
				MoveToEx(hdc, Width, Height / 2, nullptr);
				LineTo(hdc, Width - 15, Height / 2 - 15);
				MoveToEx(hdc, Width, Height / 2, nullptr);
				LineTo(hdc, Width - 15, Height / 2 + 15);
				MoveToEx(hdc, Width / 2, 0, nullptr);
				LineTo(hdc, Width / 2 - 15, 15);
				MoveToEx(hdc, Width / 2, 0, nullptr);
				LineTo(hdc, Width / 2 + 15, 15);
				DeleteObject(Pen);
				DeleteObject(Pen1);

				{
					int Width_ = 30;
					while (Width / 2 + Width_ <= Width - 30) {
						MoveToEx(hdc, Width / 2 + Width_, Height / 2 + 8, nullptr);
						LineTo(hdc, Width / 2 + Width_, Height / 2 - 8);
						MoveToEx(hdc, Width / 2 - Width_, Height / 2 + 8, nullptr);
						LineTo(hdc, Width / 2 - Width_, Height / 2 - 8);
						Width_ += 30;
					}
				}

				{
					int Height_ = 30;
					while (Height / 2 - Height_ >= 0 + 30) {
						MoveToEx(hdc, Width / 2 - 8, Height / 2 - Height_, nullptr);
						LineTo(hdc, Width / 2 + 8, Height / 2 - Height_);
						MoveToEx(hdc, Width / 2 - 8, Height / 2 + Height_, nullptr);
						LineTo(hdc, Width / 2 + 8, Height / 2 + Height_);
						Height_ += 30;
					}
				}
				SelectObject(hdc, Brush);
				SelectObject(hdc, Pen3);
				Ellipse(hdc, x - 15, y - 15, x + 15, y + 15);
				double i1 = 0;
				SelectObject(hdc, Pen2);
				MoveToEx(hdc, Width / 2, Height / 2, nullptr);
				phi = i;
				r = sin(3 * phi / 7);
				x = Width / 2 + r * cos(phi) * 200;
				y = Height / 2 - r * sin(phi) * 200;
				while (i1 < i) {
					phi = i1;
					r = sin(3 * phi / 7);
					x_ = Width / 2 + r * cos(phi) * 200;
					y_ = Height / 2 - r * sin(phi) * 200;
					LineTo(hdc, x_, y_);
					i1 += 0.01;
				}
				i1 = 0;

				i += 0.01;
				if (i >= 2 * 3.14159265358979323846) {
					KillTimer(hWnd, 2);
				}
				DeleteObject(Pen2);
			}
			break;
		case WM_PAINT: {
			HDC hdc = BeginPaint(hWnd, &ps);
			HBRUSH Brush = CreateSolidBrush(RGB(0, 255, 0));
			SelectObject(hdc, Brush);
			Ellipse(hdc, x - 15, y - 15, x + 15, y + 15);
			SetTimer(hWnd, 2, 15, nullptr);
			i = 0;



			EndPaint(hWnd, &ps);
		}
					 break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		}
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	};

	if (!RegisterClassEx(&wc)) {
		MessageBox(nullptr, L"Ошибка создания класса", L"Ошибка", MB_OK | MB_ICONSTOP);
		return NULL;
	}

	HWND hwnd = CreateWindow(
		wc.lpszClassName, L"My first lab",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, 1500, 900,
		nullptr, nullptr, hInstance, nullptr
	);

	if (hwnd == INVALID_HANDLE_VALUE) {
		MessageBox(nullptr, L"Ошибка создания окна", L"Ошибка", MB_OK | MB_ICONSTOP);
		return NULL;
	}

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	MSG msg{};
	while (GetMessage(&msg, nullptr, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessageW(&msg);
	}

	return msg.wParam;
}