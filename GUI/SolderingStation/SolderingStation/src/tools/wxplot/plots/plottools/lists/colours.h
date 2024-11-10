#pragma once

#include <wx/wx.h>
#include <vector>

enum {
	// Grundl�ggande f�rger
	PLOT_COLOUR_RED,
	PLOT_COLOUR_GREEN,
	PLOT_COLOUR_BLUE,
	PLOT_COLOUR_YELLOW,
	PLOT_COLOUR_CYAN,
	PLOT_COLOUR_MAGENTA,
	PLOT_COLOUR_BLACK,
	PLOT_COLOUR_WHITE,

	// Pastellf�rger
	PLOT_COLOUR_LIGHT_PINK,
	PLOT_COLOUR_LIGHT_BLUE,
	PLOT_COLOUR_LIGHT_GREEN,
	PLOT_COLOUR_LIGHT_YELLOW,

	// Jordn�ra f�rger
	PLOT_COLOUR_BROWN,
	PLOT_COLOUR_SIENNA,
	PLOT_COLOUR_PERU,
	PLOT_COLOUR_SADDLE_BROWN,

	// Moderna f�rger
	PLOT_COLOUR_TOMATO,
	PLOT_COLOUR_LIME,
	PLOT_COLOUR_VIOLET,
	PLOT_COLOUR_HOT_PINK,

	// Neutrala toner
	PLOT_COLOUR_DARK_GRAY,
	PLOT_COLOUR_LIGHT_GRAY,
	PLOT_COLOUR_GRAY,

	// D�mpade f�rger
	PLOT_COLOUR_DARK_SLATE_GRAY,
	PLOT_COLOUR_DARK_SLATE_BLUE,
	PLOT_COLOUR_TEAL,
	PLOT_COLOUR_DARK_GREEN,
	PLOT_COLOUR_DARK_ORANGE
};

static std::vector<wxColour> plotColours = {
	// Grundl�ggande f�rger
	wxColour(255, 0, 0),     // R�d
	wxColour(0, 255, 0),     // Gr�n
	wxColour(0, 0, 255),     // Bl�
	wxColour(255, 255, 0),   // Gul
	wxColour(0, 255, 255),   // Cyan
	wxColour(255, 0, 255),   // Magenta
	wxColour(0, 0, 0),       // Svart
	wxColour(255, 255, 255), // Vit

	// F�rger med pastelltoner
	wxColour(255, 182, 193), // Ljusrosa
	wxColour(173, 216, 230), // Ljusbl�
	wxColour(144, 238, 144), // Ljusgr�n
	wxColour(255, 228, 181), // Ljusgul

	// Jordn�ra f�rger
	wxColour(139, 69, 19),  // Brun
	wxColour(160, 82, 45),   // Sienna
	wxColour(205, 133, 63),  // Peru
	wxColour(160, 82, 45),   // Saddle Brown

	// F�rger f�r trendiga och moderna nyanser
	wxColour(255, 99, 71),   // Tomatr�d
	wxColour(50, 205, 50),   // Limegr�n
	wxColour(238, 130, 238), // Lila
	wxColour(255, 105, 180), // Hot pink

	// Ljus och m�rka neutrala f�rger
	wxColour(169, 169, 169), // M�rkgr�
	wxColour(211, 211, 211), // Ljusgr�
	wxColour(128, 128, 128), // Gr�

	// Mer d�mpade f�rger
	wxColour(47, 79, 79),    // Dark Slate Gray
	wxColour(72, 61, 139),   // Dark Slate Blue
	wxColour(0, 128, 128),   // Teal
	wxColour(0, 100, 0),     // Dark Green
	wxColour(255, 140, 0),   // Dark Orange
};