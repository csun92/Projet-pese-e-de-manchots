#include <Windows.h>
#include "mainForm.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThread]
int __stdcall WinMain(HINSTANCE hInstance,
            HINSTANCE hPrevInstance,
            LPSTR lpCmdLine,
            int nCmdShow)
{
	pes�e::mainForm^ mainform=gcnew pes�e::mainForm;
	mainform->ShowDialog();

	return 0;
}