#pragma once
#include <iostream>
#include <string>
#include <memory>

class Console {
public:
	Console();
	~Console();
	void Write(std::string);
	void SetOutStream(std::ostream&);
	void HideCursor();
	void ShowCursor();
	void Clear();
private:
	void SetCursorVisibility(bool);

	std::ostream* _out;

	class PlatformDependent;
	std::unique_ptr<PlatformDependent> _platform;
};