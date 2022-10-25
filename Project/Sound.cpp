#include "Sound.h"
#include <iostream>
#include <windows.h>
#include <conio.h>


bool Config_OnOff_Music(bool isplay, string songname) {
    wstring temp = wstring(songname.begin(), songname.end());
    LPCWSTR wideString = temp.c_str();
    char key;
    cout << "Music: On" << endl;
    cout << " Nhan enter de bat/tat hoac esc de thoat" << endl;
    do {
        key = _getch();
        if (key == 13) {
            if (isplay == true) {
                cout << "Music: Off" << endl;
                isplay = PlaySound(NULL, NULL, SND_ASYNC);
                isplay = false;
            }
            else {
                cout << "Music: On" << endl;
                isplay = PlaySound(wideString, NULL, SND_ASYNC);
                isplay = true;
            }
        }
    } while (key != 27);

    return isplay;
}
