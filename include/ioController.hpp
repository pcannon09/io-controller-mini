#pragma once

#include "ioController.hpp"
#include <string>
#include <iostream>
#include <stdio.h>
#include <sys/ioctl.h>

extern "C"
{
#include "../vendor/conio-master/conio.h"
}

#include "../include/structs.hpp"

extern std::string NONE;

extern std::string ioc_key_pressed;
extern std::string ioc_last_key_pressed;
extern std::string ioc_last_textColor;
extern std::string ioc_last_bgColor;
extern std::string exception;
extern std::string platform;

extern bool ioc_key_is_pressed;

#define IOC_getch                               c_getch
#define IOC_getche                              c_getche
#define IOC_kbhit                               c_kbhit

/// @brief Checks if any key is pressed
#define IOC_IS_KEY_PRESSED\
    if (IOC_kbhit())

/// @brief Must be a char
#define IOC_KB_KEY_PRESSED(x)\
    if (ioc_key_pressed == (x))

/// @brief Must be a char
#define IOC_KB_NOT_PRESSED(x)\
    if (ioc_key_pressed != (x) && ioc_key_is_pressed == true)

namespace ioc
{
    void start();

    template <typename T>

    void print(T message)
    {
        std::cout<<message<<"\n";
    }

    template <typename T, typename... Args>

    void print(T text, Args... args)
    {
        std::cout<<text<<" ";

        print(args...);
    }

    template <typename T>

    void println(T message)
    {
        std::cout<<message<<"\n";
    }

    template <typename T, typename... Args>

    void println(T text, Args... args)
    {
        std::cout<<text<<"\n";

        print(args...);
    }
    
    template <typename T>

    void echo(T message)
    {
        std::cout<<message<<"";
    }

    template <typename T, typename... Args>

    void echo(T text, Args... args)
    {
        std::cout<<text<<"";
        
        echo(args...);
    }

    std::string input(std::string text, std::string var);

    int terminalW();
    int terminalH();

    namespace compare
    {
        bool key(std::string key1, std::string key2);
        bool asciiKey(int key1, int key2);
    }

    namespace kb
    {
        int getAscii();
        void emulateKey(std::string whatKey, bool isKeyPressed);
        void anyKey();
        void update();
        void clear();

        template <typename T>

        void updateAddAscii(T addedNum)
        {
            ioc_key_pressed = "";
            ioc_key_is_pressed = false;

            if (IOC_kbhit())
            {
                if (IOC_getche() && addedNum)
                {
                    ioc_key_pressed = addedNum;
                    ioc_key_is_pressed = false;
                }
            }
        }

        template <typename T>

        void updateAddChar(T addedChar)
        {
            ioc_key_pressed = "";
            ioc_key_is_pressed = false;

            if (IOC_kbhit())
            {
                if (IOC_getche() && addedChar)
                {
                    ioc_key_pressed = addedChar;
                    ioc_key_is_pressed = false;
                }
            }
        }
    }

    namespace cursor
    {
        void gotoxy(int x, int y);
        void printWhereX();
        void printWhereY();
        void printWhereXY();
        int whereX(void);
        int whereY(void);
        
    }

    namespace color
    {
        [[deprecated("`ioc::color::help()` function is deprecated")]]
        void help();
        void set(std::string color);
        void setBackground(std::string color);

        [[deprecated("`ioc::color::reset()` function is deprecated, use `ioc::color::set(\"reset\")` or / and `ioc::color::setBackground(\"reset\")`")]]
        void reset();
    }

    namespace rule
    {
        [[deprecated("`ioc::rule::colorReset(...)` is deprecated")]]
        void colorReset(bool val);

        [[deprecated("`ioc::rule::reset()` is deprecated")]]
        void reset();
    }

    void end(int status);
    
    std::string input(std::string text, std::string inputAnswer);
    
    template <typename T>

    /// @brief Do an error without ending program
    /// @param text (T)
    void errorNoEnd(T message)
    {
        ioc::color::set("red");
        ioc::color::setBackground("reset");

        std::cout<<"Error: "<<message<<"\n";

        ioc::color::setBackground(ioc_last_bgColor);
    }
    
    template <typename T, typename... Args>

    // @brief Do an error without ending program
    /// @param text (T)
    /// @param message (Args...)
    void errorNoEnd(T text, Args... args)
    {
        ioc::color::set("red");
        ioc::color::setBackground("reset");

        std::cout<<"Error: "<<text<<" ";

        ioc::print(args...);

        ioc::color::set(ioc_last_textColor);
        ioc::color::setBackground(ioc_last_bgColor);
    }

    template <typename T>

    /// @brief Sets an error
    /// @param message (T)
    [[deprecated("Use `ioc::errorNoEnd(...)` instead")]]
    void error(T message) { }
    
    template <typename T, typename... Args>

    /// @brief Sets an error
    /// @param text (T)
    /// @param message (Args...)
    [[deprecated("Use `ioc::errorNoEnd(...)` instead")]]
    void error(T text, Args... args) { }

    template <typename T>

    /// @brief Sets a warning
    /// @param message (Args...)
    void warn(T message)
    {
        ioc::color::set("yellow");
        ioc::color::setBackground("reset");

        std::cout<<"Warn: "<<message<<"\n";

        ioc::color::setBackground(ioc_last_bgColor);
        ioc::color::set(ioc_last_textColor);
    }
    
    template <typename T, typename... Args>

    /// @brief Sets a warning
    /// @param text (T)
    /// @param message (Args...)
    void warn(T text, Args... args)
    {
        ioc::color::set("yellow");
        ioc::color::setBackground("reset");

        std::cout<<"Warn: "<<text<<"\n";

        ioc::print(args...);

        ioc::color::setBackground(ioc_last_bgColor);
        ioc::color::set(ioc_last_textColor);
    }

    namespace lower
    {
        [[deprecated("Use `ioc::lower()` function instead")]]
        char charType(char ch);

        [[deprecated("Use `ioc::lower()` function instead")]]
        std::string stringType(const std::string& str);
    }

    std::string LOWER(const std::string& str);

    namespace upper
    {
        [[deprecated("Use `ioc::upper()` function instead")]]
        char charType(char ch);

        [[deprecated("Use `ioc::upper()` function instead")]]
        std::string stringType(const std::string& str); 
    }

    std::string UPPER(const std::string& str);
}
