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
	pesée::mainForm^ mainform=gcnew pesée::mainForm;
	mainform->ShowDialog();

	return 0;
}