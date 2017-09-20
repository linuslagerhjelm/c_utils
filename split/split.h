
/*
*   Author:             Linus Lagerhjelm
*   Date:                2017-09-20 
*   File:                  split.h
*   Description:        Works in much the same way as strtok() used to work
*                       but leaves the input string intact
*
*    Copyright (C) <2015>  <Linus Lagerhjelm>
*
*    This program is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.
*
*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
* Returns an array containing a copy of each part of the input string.
* Example: "/path/to/file" -> ["path", "to", "file"]
* 
* Parameter:  (const char*) the string to split
*             (char) the delimiter to split the string at
*             (int*) optional out-pointer that, if provided, will
*                    be set to the length of the returned array
* Return:     (char**) array containing the string segments
* Note:       This function allocates memory for the returned array
*             which will have to be free'd
*/
char** split(const char* str, char delim, int* size);
