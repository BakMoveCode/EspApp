//=================
// Application.cpp
//=================

#include "pch.h"


//=======
// Using
//=======

#include "Core/Controls/Label.h"
#include "Core/Controls/TextBlock.h"
#include "Graphics/Emulation/Fonts/SmallFont.h"
#include "Web/Templates/NetworkParagraph.h"
#include "Web/Templates/SystemParagraph.h"
#include "Application.h"

using namespace Graphics;
using namespace Graphics::Emulation::Fonts;
using namespace Web::Templates;


//=============
// Entry-Point
//=============

VOID Initialize()
{
new EspApp::Application();
}


//===========
// Namespace
//===========

namespace EspApp {


//==================
// Con-/Destructors
//==================

Application::Application():
Runtime::Application("EspApp")
{
DebugPrint("%s\n", Name->Begin());
DebugPrint("http://localhost\n");
Log->Write("Anwendung gestartet");
CreateDisplay();
WiFiConnection=new Network::WiFi::WiFiConnection();
WiFiConnection->HostName="espapp";
WiFiConnection->StationNetwork="SSID";
WiFiConnection->StationPassword="Password";
CreateWebPage();
AppData->Add("index.html", WebPage);
}


//================
// Common Private
//================

VOID Application::CreateDisplay()
{
using TextBlock=Core::Controls::TextBlock;
Core::Controls::Control::DefaultColor=Colors::White;
hGrid=new Grid();
hGrid->Font=new SmallFont();
hGrid->Padding={ 2, 2, 2, 2 };
Handle<TextBlock> htext=new TextBlock("EspApp");
htext=new TextBlock("v1.0");
htext->Line=1;
Display=new OledDisplay();
Display->Content=hGrid;
}

VOID Application::CreateWebPage()
{
WebPage=new Web::WebPage(Name);
new NetworkParagraph();
new SystemParagraph();
}

}