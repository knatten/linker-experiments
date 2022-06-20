#pragma once

#if defined(ZIVID_CORE_EXPORTS)
#ifdef _WIN32
        #define ZIVID_CORE_EXPORT __declspec(dllexport)
    #else
        #define ZIVID_CORE_EXPORT __attribute__ ((visibility ("default")))
    #endif
#else
#ifdef _WIN32
#define ZIVID_CORE_EXPORT __declspec(dllimport)
#else
#define ZIVID_CORE_EXPORT
#endif
#endif

#ifndef _WIN32
#define ZIVID_CORE_EXPORT_NON_WIN32 ZIVID_CORE_EXPORT
#else
#define ZIVID_CORE_EXPORT_NON_WIN32
#endif
