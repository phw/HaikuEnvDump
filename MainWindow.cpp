#include "MainWindow.h"

#include <Application.h>
#include <StringView.h>

MainWindow::MainWindow(void)
	:	BWindow(BRect(100,100,500,400),"HaikuEnvDump",B_TITLED_WINDOW, B_ASYNCHRONOUS_CONTROLS)
{
    int offset = 10;
    BRect frame(10, 10, 10, 10);
    for (char **current = environ; *current; current++) {
        frame.Set(10, offset, 10, 10);
        BStringView *label = new BStringView(frame, "label", *current);
        label->ResizeToPreferred();
        this->AddChild(label);
        offset += 20;
    }
}


void
MainWindow::MessageReceived(BMessage *msg)
{
	switch (msg->what)
	{
		default:
		{
			BWindow::MessageReceived(msg);
			break;
		}
	}
}


bool
MainWindow::QuitRequested(void)
{
	be_app->PostMessage(B_QUIT_REQUESTED);
	return true;
}
