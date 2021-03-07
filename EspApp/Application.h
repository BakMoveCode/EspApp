//===============
// Application.h
//===============

#pragma once


//=======
// Using
//=======

#include "Devices/Displays/Oled128x64.h"
#include "Core/Controls/Grid.h"
#include "Network/WiFi/WiFiConnection.h"
#include "Web/WebPage.h"


//===========
// Namespace
//===========

namespace EspApp {


//=============
// Application
//=============

class Application: public Runtime::Application
{
private:
	// Using
	using Grid=Core::Controls::Grid;
	using OledDisplay=Devices::Displays::Oled128x64;

public:
	// Con-/Destructors
	Application();

	// Common
	Handle<OledDisplay> Display;
	Handle<Network::WiFi::WiFiConnection> WiFiConnection;
	Handle<Web::WebPage> WebPage;

private:
	// Common
	VOID CreateDisplay();
	VOID CreateWebPage();
	Handle<Grid> hGrid;
};

}