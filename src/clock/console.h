#pragma once
#include <string>
#include <memory>

class Console final {
public:
    Console();
    ~Console();
    void Write(std::string) const;
    void SetOutStream(std::ostream&);
    void HideCursor() const;
    void ShowCursor() const;
    void Clear() const;
private:
    void SetCursorVisibility(bool) const;

    std::ostream* _out;

    class PlatformDependent;
    std::unique_ptr<PlatformDependent> _platform;
};
