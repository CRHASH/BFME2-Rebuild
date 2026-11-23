// AptOptions.h: the options screen ("Options.apt").
//
// Target facts (retail game.dat, RVAs; table addresses are VAs):
//  - Constructor 0x0051A78E (one argument for _bfme_AptGameWindow's constructor 0x0051268C), deleting destructor 0x00518AE9, tables VA
//    0x00866698 (primary) and 0x00866694 (AptCallbackHost secondary). SIZE 0x324 (screen factory 0x002D205F). The screen instance is
//    the map's g_Va00A04908.
//  - Members: +0x27C an int, +0x280..+0x284 five flag bytes (zeroed by the constructor; OpenScreen 0x005185D8 stores its four bool
//    arguments into +0x280/+0x282 (the second), +0x283 (the first), +0x281 (the third) and +0x284 (the fourth)), +0x288 a 0x14-byte
//    container (constructor 0x0043FE13), +0x29C sixteen zeroed bytes, +0x2AC..+0x30F ints, +0x310 the selected detail level (-1 when
//    none; EnterAdvancedSettings 0x0051889D builds an OptionPreferences when it is set), +0x314 an AsciiString (the settings text).
#pragma once
#ifndef BFME2_APTOPTIONS_H
#define BFME2_APTOPTIONS_H

#include "GameClient/BfmeAptGameWindow.h"
#include "Common/AsciiString.h"

class AptOptions : public _bfme_AptGameWindow
{
public:
	AptOptions(void *);								// 0x0051A78E
	virtual ~AptOptions();							// 0x00518AE9

	void ExternsLODTemplate(int, char *, bool);		// The LOD template Apt query: gets or sets the settings text, or formats a static level's settings
	void AdvancedOptionNum(int, char *, bool);		// Formats the enum row's count into the text unless quiet
	static void OpenScreen(bool, bool, bool, bool);
	void EnterAdvancedSettings(const char *);		// Shows the advanced settings with the values of the chosen detail level
	void updateHealthBarsBox();						// 0x005183FA: the health bars box follows the preferences while the detail level is custom
	void rva0051890E(int message);					// Applies the pending detail level, advanced settings text and entry once the message is 1
	void setGraphicsWarning();						// 0x005189CF: shows the "cannot change graphics" text with the name of the master detail level in front
	void rva00518359();								// Reselects the detail combo box entry of the stored detail level

	void rva00518FEA(int level, int kind);					// Warns when a high graphics level is chosen
	void rva00518B05(const AsciiString &, int);
	void Externs(int query, char *result, bool set);		// The options Apt queries (0 count, 1 detail level, 2 top level, 3..6 flags)
	bool rva005183A0();								// Whether the stored detail level is a usable choice (custom, 5, asks the preferences)
	void rva0051847B(int);
	void rva0051A669();								// Shows the "cannot change resolution" text with the stored resolution in front
	int rva00518557(int message, unsigned char key, int state);	// The Escape key closes the advanced settings or the screen

	int m_x27C;										// +0x27C
	bool m_flag280;									// +0x280
	bool m_flag281;									// +0x281
	bool m_flag282;									// +0x282
	bool m_flag283;									// +0x283
	bool m_flag284;									// +0x284
	unsigned char m_pad285[3];
	unsigned char m_x288[0x14];						// +0x288: a container
	unsigned char m_x29C[0x10];						// +0x29C
	GameWindow *m_detailCombo2;						// +0x2AC (rva0051890E 0x0051890E reselects its entry)
	GameWindow *m_detailCombo;						// +0x2B0 (the detail level combo box; rva00518359 clears it while it reselects the entry)
	unsigned char m_x2B4[8];						// +0x2B4..+0x2BB
	GameWindow *m_healthBarsBox;					// +0x2BC (the "show all health bars" check box)
	unsigned char m_x2C0[0x38];						// +0x2C0..+0x2F7
	bool m_flag2F8;									// +0x2F8
	unsigned char m_x2F9[0xF];						// +0x2F9..+0x307
	AsciiString m_lodTemplateName;					// +0x308 (ExternsLODTemplate 0x00518C0D compares the entered text against it)
	int m_x30C;										// +0x30C
	int m_detailLevel;								// +0x310
	AsciiString m_settingsText;						// +0x314
	int m_pendingX318;								// +0x318 (the value rva0051890E 0x0051890E applies to +0x30C)
	int m_pendingDetailLevel;						// +0x31C
	AsciiString m_pendingSettings;					// +0x320
};
typedef char AptOptionsSizeCheck[sizeof(AptOptions)==0x324 ? 1 : -1];

#endif
