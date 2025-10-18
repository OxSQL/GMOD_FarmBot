#include <iostream>
#include <format>
#include <windows.h>

#include "Keyboard.h"

#define W_KEY 0x57
#define S_KEY 0x53

int main() {
    setlocale(LC_ALL, "Russian");
    std::cout << "* Garry's Mod BOT Controller" << "\n\n";
    system("title Garry's Mod BOT Controller");


    int MOUSE_PRESS_DELAY    = 7500; // M.S
    int KEYBOARD_PRESS_DELAY = 3000;               // M.S

    HWND GameHandle = FindWindow(NULL, "Garry's Mod (x64)");
    std::cout << "\n" << "> Game handle: " << std::format("{:#x}", int(GameHandle)) << "\n";
    std::cout << "> MOUSE_PRESS_DELAY: " << MOUSE_PRESS_DELAY << " ms" << "\n";
    std::cout << "> KEYBOARD_PRESS_DELAY: " << KEYBOARD_PRESS_DELAY << " ms" << "\n\n";

    std::cout << "> Убидитесь что клавиатура переключена на английскую раскладу." << "\n" << "> ";
    system("pause");

    std::cout << "\n\n" << "> Запускается цикл действий..." << "\n\n";

    while (true) {
        if (GetForegroundWindow() != GameHandle) {
            std::cout << "> Окно игры свернуто." << "\n";

            SendKey(GameHandle, 0x4A, KEYBOARD_PRESS_DELAY);
            Sleep(1700);

            std::cout << "> Нажата левая кнопка мыши." << "\n";
            PostMessage(GameHandle, WM_LBUTTONDOWN, WM_LBUTTONDOWN, NULL);
            Sleep(MOUSE_PRESS_DELAY);
            PostMessage(GameHandle, WM_LBUTTONUP, WM_LBUTTONUP, NULL);


            std::cout << "> Нажата кнопка на клавиатуре - W." << "\n";
            SendKey(GameHandle, 0x57, KEYBOARD_PRESS_DELAY);

               
            std::cout << "> Нажата левая кнопка мыши." << "\n";
            PostMessage(GameHandle, WM_LBUTTONDOWN, WM_LBUTTONDOWN, NULL);
            Sleep(MOUSE_PRESS_DELAY);
            PostMessage(GameHandle, WM_LBUTTONUP, WM_LBUTTONUP, NULL);

            
            std::cout << "> Нажата кнопка на клавиатуре - S." << "\n";
            SendKey(GameHandle, 0x53, KEYBOARD_PRESS_DELAY);
        }

        else {
            std::cout << "> Окно игры открыто, цикл действий приостановлен до его сворачивания.";
        }

        std::cout << "\n\n";
        Sleep(500);
    }
}
