#include <Windows.h>
#include <iostream>

#include "extensions2.h"

extern "C" void MH_CALL button_callback(MegaHackExt::Button *obj);
extern "C" void MH_CALL color_callback(MegaHackExt::ColourPicker *obj, MegaHackExt::Colour col);
extern "C" void MH_CALL on_startup();

DWORD MainThread(LPVOID lpParam)
{
    using namespace MegaHackExt;

    AllocConsole();

    on_startup();

    Window *window = Window::Create("Window");

    Button *button = Button::Create("Button");
    CheckBox *checkbox = CheckBox::Create("Checkbox");
    Label *label = Label::Create("Label");
    ComboBox *combo = ComboBox::Create("Select: ", nullptr);
    ColourPicker *picker = ColourPicker::Create({ 238, 119, 98 });

    button->setCallback(button_callback);
    checkbox->setCallback([](CheckBox *obj, bool b) { std::cout << b << '\n'; });
    combo->setCallback([](ComboBox *obj, int index, const char *str) { std::cout << "index " << index << " selected: " << str << '\n'; });
    picker->setCallback(color_callback);

    const char *strs[] = { "One", "Two", "Three", nullptr };
    combo->setValues(strs);

    window->add(button);
    window->add(checkbox);
    window->add(combo);
    window->add(picker);

    Client::commit(window);

    return S_OK;
}

DWORD DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
    switch (dwReason)
    {
        case DLL_PROCESS_ATTACH:
            CreateThread(NULL, 0x1000, reinterpret_cast<LPTHREAD_START_ROUTINE>(&MainThread), NULL, 0, NULL);
            break;

        default:
            break;
    }

    return TRUE;
}