#define FILENAME  "SubGUIClass.h"
#define CLASSNAME  SubGUIClass

#include "wxWidgetsApp.h"
#include FILENAME

IMPLEMENT_APP(wxWidgetsApp)

wxWidgetsApp::wxWidgetsApp()  {
}

wxWidgetsApp::~wxWidgetsApp() {
}

bool wxWidgetsApp::OnInit() {
    CLASSNAME* frame = new CLASSNAME( (wxWindow*)NULL );
    frame ->Show();
    SetTopWindow( frame );
    return true;
}
