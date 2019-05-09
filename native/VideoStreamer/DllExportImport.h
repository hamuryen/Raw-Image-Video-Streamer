/*
* File:   DllExportImport.h
* Author: Burak Hamuryen
*
* Created on 07.05.2019
*/

#ifndef DLL_EXPORT_IMPORT_H
#define DLL_EXPORT_IMPORT_H

#ifdef WIN32
#ifndef DLL_EXPORT
#define DLL_EXPORT __declspec(dllexport)
#endif // !DLL_EXPORT

#ifndef DLL_IMPORT
#define DLL_IMPORT __declspec(dllimport)
#endif // !DLL_IMPORT
#endif // !WIN32

#ifndef WIN32
#ifndef DLL_EXPORT
#define DLL_EXPORT
#endif // !DLL_EXPORT

#ifndef DLL_IMPORT
#define DLL_IMPORT
#endif // !DLL_IMPORT
#endif // !WIN32

#endif // !DLL_EXPORT_IMPORT_H