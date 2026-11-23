// The in-game messenger screen and its chat lists.
#pragma once

#include <utility>
#include <vector>
#include "GameClient/BfmeAptGameWindow.h"

class Coord2D;
class UnicodeString;

class ChatWindowsInGame {
public:
  void rva005B000C(); // 0x005B000C: the list's send button
  void rva005AFC21(class GameWindow *window); // 0x005AFC21: binds the chat window (the map holds it on the placeholder class Rva005AFC21Class)
  void rva005AFC4C(class GameWindow *window); // 0x005AFC4C: binds the player list (the map holds it on the placeholder class Rva005AFC4CClass)
  void rva005AFD43(class GameWindow *entry, const class UnicodeString &text); // 0x005AFD43: shows the text in the list's entry window
  int rva005AFEF7(void *ids, void *names); // 0x005AFEF7: collects the selected players (a vector of ids and a vector of names)
};
class AptMessenger : public _bfme_AptGameWindow
{
public:
	AptMessenger(void *creationData);
	virtual ~AptMessenger();

	virtual WindowMsgHandledType input(unsigned int message, unsigned int key, unsigned int state);
	virtual WindowMsgHandledType system(unsigned int message, unsigned int data1, unsigned int data2);
	virtual int tooltip(WinInstanceData *instance, unsigned int message);
	virtual int invokeCallback();
	virtual GameWindowFactory getWindowFactory();

	virtual bool vslot11();
	virtual void createChatWindows();
	virtual void destroyChatWindows();
	virtual void vslot14();
	virtual bool vslot15() const;
	virtual ChatWindowsInGame *CreateChatWindow(int tab) = 0;

	static void OnMessengerBttn(const char *);
	static void OpenScreen();
	static void IsOpen(int, char *, bool);
	void rva005AE886();
	void rva005AE990();
	void OnBttn_0(const char *);
	void OnInitialized(const char *);
	void GameWindowSize(const Coord2D *position, const Coord2D *size, void *, void *);
	void OnButtonSend(const char *);
	void InitGadgets(const char *name, void *, GameWindow *window);	// 0x005119FF
	void GetSelectedPlayers(int listIndex, int ids, int names);

	enum State
	{
		UNINITIALIZED,
		INITIALIZED,
		CLOSE_REQUESTED
	};
	State m_state;
	std::vector<ChatWindowsInGame *> m_lists;
	std::vector<std::pair<const AsciiString, char> > m_tabLabels;
	GameWindow *m_textEntry;
	bool m_refresh;
	bool m_tabFlag;
};

typedef char AptMessengerSizeCheck[sizeof(AptMessenger) == 0x2A0 ? 1 : -1];

extern int g_Va00E046BC;
extern AptMessenger *g_aptMessenger;
