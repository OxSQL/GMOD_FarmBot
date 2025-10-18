#pragma once


struct extraKeyInfo
{
    unsigned short repeatCount;
    unsigned char scanCode;
    bool extendedKey, prevKeyState, transitionState;

    operator unsigned int()
    {
        return repeatCount | (scanCode << 16) | (extendedKey << 24) |
            (prevKeyState << 30) | (transitionState << 31);
    }
};

void SendKey(HWND wnd, char ch, DWORD del) {
    short vkCode = LOBYTE(VkKeyScan(ch));
    extraKeyInfo lParam = {};
    lParam.scanCode = MapVirtualKey(vkCode, MAPVK_VK_TO_VSC);
    PostMessage(wnd, WM_KEYDOWN, vkCode, lParam);
    lParam.repeatCount = 1;
    lParam.prevKeyState = true;
    lParam.transitionState = true;
    Sleep(del);
    PostMessage(wnd, WM_KEYUP, vkCode, lParam);
}