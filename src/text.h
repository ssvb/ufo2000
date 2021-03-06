/*
This file is part of UFO2000 (http://ufo2000.sourceforge.net)

Copyright (C) 2000-2001  Alexander Ivanov aka Sanami
Copyright (C) 2002-2003  ufo2000 development team

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/

#ifndef TEXT_H
#define TEXT_H

/**
 * Ufo2000: Text for messages and help-system
 */

//! Starting pages for the help-chapters
#define HELP_U2K_INDEX    0
 // "HELP_INDEX" already used in /MinGW/include/winuser.h
#define HELP_INTRO       10
#define HELP_BATTLESCAPE 20
#define HELP_MAPVIEW     40
#define HELP_MINDPROBE   50
#define HELP_SCANNER     60
#define HELP_MEDIKIT     70
#define HELP_PSI_AMP     80
#define HELP_BLASTER     90
#define HELP_INVENTORY  100
#define HELP_STATS      120
#define HELP_ENDGAME    140
#define HELP_NET        150

// First page of scenario-help follows directly
// after last page of help for mission-planner:
#define HELP_PLANNER    170
#define HELP_SCENARIO   HELP_PLANNER + 11

//! Return string with current date+time
const char *datetime();

//! Write message into init-scripts.log
void lua_message( const std::string &str1 );

//! Write message into battlereport.txt
void battle_report( const char *format, ... );

#undef map
//! Interface to LUA-gettext()
#ifdef __GNUC__
__attribute__((format_arg(1)))
#endif
const char *ufo2k_gettext(const char *str);
extern std::map<const char *, const char *> translation_cache;
#define map g_map

//! Translations for placenames
void Init_place_names();

//! Tooltips for the control-panel
const char *icontext( const int icon_nr );

//! Show tip-of-the-day
void showtip();

//! Simple help, using alert3().
void help( const int helppage );

//! Show a large dialog with formatted text.
void show_help(const char *text);

//! A C++ variant of lua 'string.format' (a safe sprintf replacement)
#if defined(__GNUC__)
__attribute__((__format__(__printf__,1,2)))
#endif
std::string string_format(const char *fmt, ...);
std::string string_vformat(const char *fmt, va_list arglist);

#endif

