#include <cstdio>
#include <iostream>
#include <streambuf>
#include "windows.h"
#include "shellapi.h"

class outbuf : public std::streambuf {
public:
    outbuf() {
        setp(0, 0);
    }

    virtual int_type overflow(int_type c = traits_type::eof()) {
        return fputc(c, stdout) == EOF ? traits_type::eof() : c;
    }
};

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow) {
    // create the console
    if(AllocConsole()) {
        freopen("CONOUT$", "w", stdout);
        SetConsoleTitle("Debug Console");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);  
    }

    // set std::cout to use my custom streambuf
    outbuf ob;
    std::streambuf *sb = std::cout.rdbuf(&ob);

    // do some work here
    std::clog << "hmm\n";
	OutputDebugString("Asdf");

    // make sure to restore the original so we don't get a crash on close!
    std::cout.rdbuf(sb);
	ShellExecute(NULL,"open","http://localhost:889",NULL,NULL,SW_SHOWNORMAL);
	OutputDebugString("finished");
    return 0;

}

/*
int main()
{
    std::clog << "hmm\n";
	ShellExecute(NULL,L"open",L"http://localhost:889",NULL,NULL,SW_SHOWNORMAL);
    return 0;
}*/