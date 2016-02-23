#include <windows.h>
#include "Console.h"

class Console::PlatformDependent {
public:	
	PlatformDependent() {
		_hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	}

	HANDLE GetConsoleOutHandle() {
		return _hConsoleOut;
	}
private:
	HANDLE _hConsoleOut;
};

Console::Console() {
	_out = &std::cout;
	_platform = std::make_unique<PlatformDependent>();
}

Console::~Console() {
	delete _out;
}

void Console::Write(std::string out) {
	*_out << out;
}

void Console::SetOutStream(std::ostream& output) {
	_out = &output;
}

void Console::HideCursor() {
	SetCursorVisibility(false);
}

void Console::ShowCursor() {
	SetCursorVisibility(true);
}

void Console::Clear() {
	HANDLE hConsoleOut = _platform->GetConsoleOutHandle();

	COORD coordScreen = { 0, 0 };
	DWORD cCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo;
	DWORD dwConSize;

	if (!GetConsoleScreenBufferInfo(hConsoleOut, &screenBufferInfo))
	{
		return;
	}

	dwConSize = screenBufferInfo.dwSize.X * screenBufferInfo.dwSize.Y;

	if (!FillConsoleOutputCharacter(hConsoleOut, (TCHAR) ' ', dwConSize, coordScreen, &cCharsWritten))
	{
		return;
	}

	if (!GetConsoleScreenBufferInfo(hConsoleOut, &screenBufferInfo))
	{
		return;
	}

	if (!FillConsoleOutputAttribute(hConsoleOut, screenBufferInfo.wAttributes, dwConSize, coordScreen, &cCharsWritten))
	{
		return;
	}

	SetConsoleCursorPosition(hConsoleOut, coordScreen);
}

void Console::SetCursorVisibility(bool isVisible) {
	HANDLE hConsoleOut = _platform->GetConsoleOutHandle();

	CONSOLE_CURSOR_INFO cursorInfo;

	GetConsoleCursorInfo(hConsoleOut, &cursorInfo);
	cursorInfo.bVisible = isVisible;
	SetConsoleCursorInfo(hConsoleOut, &cursorInfo);
}


