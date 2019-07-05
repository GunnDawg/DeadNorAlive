#pragma once

//Targeting Windows 7 or later
#define WINVER 0x0601
#define _WIN32_WINNT 0x0601
#define NTDDI_VERSION 0x0601
#include <sdkddkver.h>

#define WIN32_LEAN_AND_MEAN

//(NOTE): We need these, hence why they're not defined.
//#define NOGDICAPMASKS
//#define NOWINSTYLES
//#define NOSHOWWINDOW
//#define NOUSER
//#define NOVIRTUALKEYCODES
//#define NOMSG

#define NOSYSMETRICS
#define NOMENUS
#define NOICONS
#define NOKEYSTATES
#define NOSYSCOMMANDS
#define NORASTEROPS
#define OEMRESOURCE
#define NOATOM
#define NOCLIPBOARD
#define NOCOLOR
#define NOCTLMGR
#define NODRAWTEXT
#define NOKERNEL
#define NONLS
#define NOMEMMGR
#define NOMETAFILE
#define NOMINMAX
#define NOOPENFILE
#define NOSCROLL
#define NOSERVICE
#define NOSOUND
#define NOTEXTMETRIC
#define NOWH
#define NOMB
#define NOCOMM
#define NOKANJI
#define NOHELP
#define NOPROFILER
#define NODEFERWINDOWPOS
#define NOMCX
#define NORPC
#define NOPROXYSTUB
#define NOIMAGE
#define NOTAPE
#define STRICT

//C Integer Types
#include <stdint.h>

typedef char int8;
typedef int16_t int16;
typedef int32_t int32;
typedef int64_t int64;
typedef int32 bool32;

typedef unsigned char uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;

//Windows API Files
#include <Windows.h>

//C++ Standard Library Files
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <memory>
#include <vector>

//OpenGL and GLEW Files (OpenGL Functions)
#include <glew.h>

//My Files
#include "Win32Platform.h"
#include "Renderer.h"