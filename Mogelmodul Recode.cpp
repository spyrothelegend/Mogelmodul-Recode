/*#######################################################################
|Credits an frk für die XOR Klasse und Calb für's unter die Arme greifen|
########################################################################*/


#include "Includes.h"
#include <random>
#include "CUpdater.h"
#include "CMisc.h"
#include "CRadar.h"
#include "CGlow.h"
#include "CTrigger.h"
#include "CRCS.h"
#include "CAim.h"
#include "CMain.h"
#include "CScanner.h"



/* Variable für "Countdown" */
int a = 1;
std::string b = "Sekunde";
/*//*/


/* Random-String Funktion */

std::string random_string()
{
	std::string str("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");

	std::random_device rd;
	std::mt19937 generator(rd());

	std::shuffle(str.begin(), str.end(), generator);

	return str.substr(0, 32);
}

/*//*/


/* Main Funktion */




int main(int argc, char* argv[])
{
	

	/* Umbenennen des Konsolentitels und der Exe */

	SetConsoleTitleA(random_string().c_str() );
	std::string name = random_string().c_str();
	std::string name2 = (name + ".exe");
	rename(argv[0], (name2.c_str() ) );

	/*//*/

	


	g_pColor->printColor(XorStr(" [>] Der Hack benennt sich bei jedem Neustart um! "), CC_RED, CC_CYAN);

	g_pColor->printColor(XorStr(" [>] Es wird nach Updates gesucht. Einen Moment... "), CC_RED, CC_CYAN);
	

	/* Updater wird initialisiert */

	g_pUpdater->Act();

	/*//*/

	g_pColor->printColor(XorStr(" [>] Spyros External - V 0x2 "), CC_YELLOW, CC_RED);
	g_pColor->printColor(XorStr(" [>] Nach CSGO wird gesucht"), CC_YELLOW, CC_RED);


	/* Injection wird initialisiert*/
	while (!g_pMemory->Intialize()) {

		g_pMemory->idp();
		g_pColor->printColorwb((" [>] "), CC_YELLOW, CC_RED); std::cout << a << " " << b << std::endl; 
		a++;
		if (a == 1)
		{
			b = "Sekunde";
		}
		else { b = "Sekunden"; }
		Sleep(1000);
		if (a == 10 || a == 20 || a == 30 || a == 40 || a == 50)
		{

			system("cls");
			g_pColor->printColor(XorStr(" [>] Spyros External - V 0x2 "), CC_YELLOW, CC_RED);
			g_pColor->printColor(XorStr(" [>] Nach CSGO wird gesucht"), CC_YELLOW, CC_RED);
			Sleep(1000);


		}
		if (a == 60)
		{
			g_pColor->printColor(XorStr(" [>] CSGO konnte nicht gefunden werden. Die Anwendung wird beendet."), CC_RED, CC_WHITE);
			Sleep(2000);
			return 0;
		}
	}
	/*//*/

	/* Ausgabe von Prozess,Window, etc. */
	system("cls");
	g_pColor->printColor(XorStr(" [>] Spyros External - V 0x2 "), CC_RED, CC_GREEN);
	g_pColor->printColor(XorStr(" [>] CSGO wurde gefunden "), CC_RED, CC_GREEN);
	g_pColor->printColor(XorStr(" [>] Prozess: ") + std::to_string(g_pMemory->getProcessId()) , CC_RED, CC_WHITE);
	g_pColor->printColor(XorStr(" [>] Window: ") + std::to_string((DWORD)g_pMemory->getWindow()), CC_RED, CC_WHITE);
	g_pColor->printColor(XorStr(" [>] Handle: 0x") + std::to_string((DWORD)g_pMemory->getHandle()), CC_RED, CC_WHITE);
	g_pColor->printColor(XorStr(" [>] Client: 0x") + std::to_string(g_pMemory->getClientAddress()), CC_RED, CC_WHITE);
	g_pColor->printColor(XorStr(" [>] Engine: 0x") + std::to_string(g_pMemory->getEngineAddress()), CC_RED, CC_WHITE);
	Sleep(3500);
	system("cls");
	g_pColor->printColor(XorStr(" [>] Spyros External - V 0x2 "), CC_RED, CC_WHITE);
	g_pColor->printColor(XorStr(" [>] Mogelthreads werden geladen. Einen Moment"), CC_RED, CC_WHITE);
	g_pColor->printColor(XorStr(" [>] SpyrotheLegend @ high-minded.net"), CC_YELLOW, CC_RED);
	g_pColor->printColor(XorStr(" [>] Credits to frk f\x81r die XOR-Klasse und ganz besonders an Calb f\x81r seine anf\x84ngliche Hilfe und die ConsoleColors! "), CC_YELLOW, CC_RED);
	Sleep(1500);


	g_pChecker->ReadConfiguration();
	Sleep(3500);

	/* Threads werden initalisiert */
	CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)g_pChecker->Act, 0, 0, 0);
	CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)g_pMisc->Run, 0, 0, 0);
	CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)g_pRadar->Act, 0, 0, 0);
	CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)g_pGlow->Act, 0, 0, 0);
	CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)g_pTrigger->Act, 0, 0, 0);
	CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)g_pRCS->Act, 0, 0, 0);
	CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)g_pAim->Act, 0, 0, 0);
	


	

	std::cin.ignore();


    return 0;
}

/*//*/

