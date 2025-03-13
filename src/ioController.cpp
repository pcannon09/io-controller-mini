#include <string>
#include <iostream>
#include <sys/ioctl.h>
#include <cctype>

extern "C"
{
#include "../vendor/conio-master/conio.h"
}

#include "../include/ioController.hpp"

std::string NONE = "{NONE}";

std::string ioc_key_pressed = NONE;
std::string ioc_last_key_pressed = NONE;
std::string ioc_last_textColor = "reset";
std::string ioc_last_bgColor = "reset";
std::string exception;
std::string platform;

bool ioc_key_is_pressed = false;

#define IOC_getch                               c_getch
#define IOC_getche                              c_getche
#define IOC_kbhit                               c_kbhit

namespace ioc
{
    namespace compare
    {
        /// @brief Checks if key1 is same as key2, returns 'true' / '1' if key1 is = key2, else, returns 'false' / '0'
        /// @param key1 (std::string)
        /// @param key2 (std::string)
        /// @return bool
        bool key(std::string key1, std::string key2)
        {
            if (key1 == key2)
            {
                return true;
            }

            else
            {
                return false;
            }
        }

        /// @brief Checks if key1 is same as key2, returns 'true' / '1' if key1 is = key2, else, returns 'false' / '0', but it checks it as an ascii value
        /// @param key1 (int)
        /// @param key2 (int)
        /// @return bool
        bool asciiKey(int key1, int key2)
        {
            if (key1 == key2)
            {
                return true;
            }
            
            else
            {
                return false;
            }
        }
    }

    namespace kb
    {
        /// @brief Returns the ascii key pressed
        /// @return int
        int getAscii()
        {
            return IOC_getche();
        }

        /// @brief Detects if any key is pressed
        void anyKey()
        {
            ioc_key_pressed = "";
            ioc_key_is_pressed = false;

            if (IOC_kbhit())
            {
                ioc_key_is_pressed = true;
                ioc_key_pressed = "<unknown>";
            }
        }

        /// @brief Updates key press
        void update()
        {
            ioc_key_pressed = "";
            ioc_key_is_pressed = false;

            if (IOC_kbhit())
            {
                switch (IOC_getche())
                {
                case 000:
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "NULL";
                     
                    break;

                case '\n':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "return";
                     
                    break;

                case 127 /*Backspace button*/:
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "backspace";
                    
                    break;

                case '|':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "|";

                    break;

                case '"':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "\"";

                    break;
                    
                case '!':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "!";

                    break;

                case '@':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "@";

                    break;

                case '$':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "$";

                    break;

                case '%':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "%";

                    break;

                case '^':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "^";

                    break;

                
                case '&':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "&";

                    break;

                case '*':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "*";

                    break;

                case '(':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "(";

                    break;

                case ')':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = ")";

                    break;

                case '_':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "_";

                    break;

                case '+':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "+";

                    break;    

                case '{':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "{";

                    break;

                case '}':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "}";

                    break;

                case ':':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = ":";

                    break;

                case ' ':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "space";

                    break;


                case ';':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = ";";

                    break;

                case '[':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "[";

                    break;

                case ']':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "]";

                    break;

                case '/':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "/";

                    break;

                case '=':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "=";

                    break;

                case '-':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "-";

                    break;

                case '?':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "?";

                    break;                    

                case '\'':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "\\";

                    break;

                case '\\':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "\\";

                    break;

                case ',':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = ",";

                    break;

                case '.':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = ".";

                    break;

                case '`':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "`";

                    break;

                case '~':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "~";

                    break;

                // Numbers

                case '1':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "1";

                    break;

                case '2':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "2";

                    break;

                case '3':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "3";

                    break;

                case '4':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "4";

                    break;

                case '5':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "5";

                    break;
                
                case '6':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "6";

                    break;

                case '7':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "7";

                    break;

                case '8':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "8";

                    break;

                case '9':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "9";

                    break;

                case '0':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "0";

                    break;

                // Letters

                case 'q':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "q";

                    break;

                case 'w':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "w";

                    break;

                case 'e':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "e";

                    break;

                case 'r':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "r";

                    break;
                
                case 't':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "t";

                    break;

                case 'y':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "y";

                    break;

                case 'u':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "u";

                    break;

                case 'i':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "i";

                    break;

                case 'o':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "o";

                    break;

                case 'p':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "p";

                    break;

                case 'a':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "a";

                    break;

                case 's':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "s";

                    break;
                
                case 'd':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "d";

                    break;

                case 'f':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "f";

                    break;

                case 'g':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "g";

                    break;

                case 'h':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "h";

                    break;

                case 'j':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "j";

                    break;

                case 'k':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "k";

                    break;

                case 'l':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "l";

                    break;
                
                case 'z':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "z";

                    break;

                case 'x':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "x";

                    break;
                
                case 'c':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "c";

                    break;

                case 'v':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "v";

                    break;

                case 'b':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "b";

                    break;

                case 'n':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "n";

                    break;

                case 'm':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "m";

                    break;

                case 'Q':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "Q";

                    break;

                case 'W':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "W";

                    break;

                case 'E':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "E";

                    break;

                case 'R':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "R";

                    break;
                
                case 'T':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "T";

                    break;

                case 'Y':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "Y";

                    break;

                case 'U':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "U";

                    break;

                case 'I':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "I";

                    break;

                case 'O':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "O";

                    break;

                case 'P':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "P";

                    break;

                case 'A':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "A";


                    break;

                case 'S':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "S";

                    break;

                case 'D':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "D";

                    break;

                case 'F':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "F";

                    break;

                case 'G':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "G";

                    break;

                case 'H':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "H";

                    break;

                case 'J':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "J";

                    break;

                case 'K':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "K";

                    break;

                case 'L':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "L";

                    break;
                
                case 'Z':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "Z";

                    break;

                case 'X':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "X";

                    break;
                
                case 'C':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "C";

                    break;

                case 'V':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "V";

                    break;

                case 'B':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "B";

                    break;

                case 'N':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "N";

                    break;

                case 'M':
                    ioc_key_is_pressed = true;
                    ioc_key_pressed = "M";

                    break;

                default:
                    ioc_key_pressed = "";
                    ioc_key_is_pressed = false;

                    break;
                }
            
                ioc_last_key_pressed = ioc_key_pressed;
            }
        }

        /// @brief Resets the ioc_key_pressed and ioc_key_is_pressed to the original value
        void clear()
        {
            ioc_key_pressed = "";
            ioc_key_is_pressed = false;
        }

    }

    int terminalH()
    {
        struct winsize w;
        ioctl(0, TIOCGWINSZ, &w);

        return w.ws_row;
    }

    int terminalW()
    {
        struct winsize w;
        ioctl(0, TIOCGWINSZ, &w);

        return w.ws_col;
    }
    
    namespace cursor
    {
        /// @brief Set terminal cursor to the given x and y position
        /// @param x (int)
        /// @param y (int)
        void gotoxy(int x, int y)
        {
            c_gotoxy(x, y);
        }

        /// @brief Returns a variable to cursor x in terminal
        /// @return int
        int whereX(void)
        {
            return c_wherex();
        }
        
        /// @brief Returns a variable to cursor y in terminal
        /// @return int
        int whereY(void)
        {
            return c_wherey();
        }
    }

    /// @brief Gets the text info
    /// @param r
    void getTextInfo(struct text_info *r)
    {
        c_gettextinfo(r);
    }

    /// @brief Sets console text attribute
    /// @param newattr
    void textattr(int newattr)
    {
        c_textattr(newattr);
    }

    namespace color
    {
        /// @brief Sets the color of text in terminal
        /// @param color (std::string)
        void set(std::string color)
        {
            if (color == "black" || color == "0")
            {
                c_textcolor(BLACK);
            }

            else if (color == "blue" || color == "1")
            {
                c_textcolor(BLUE);
            }

            else if (color == "green" || color == "2")
            {
                c_textcolor(GREEN);
            }

            else if (color == "cyan" || color == "3")
            {
                c_textcolor(CYAN);
            }
            
            else if (color == "red" || color == "4")
            {
                c_textcolor(RED);
            }

            else if (color == "magenta" || color == "5")
            {
                c_textcolor(MAGENTA);
            }

            else if (color == "brown" || color == "6")
            {
                c_textcolor(BROWN);
            }

            else if (color == "light gray" || color == "light grey" || color == "7")
            {
                c_textcolor(LIGHTGRAY);
            }

            else if (color == "dark gray" || color == "light grey" || color == "8")
            {
                c_textcolor(DARKGRAY);
            }

            else if (color == "light blue" || color == "9")
            {
                c_textcolor(LIGHTBLUE);
            }

            else if (color == "light green" || color == "10")
            {
                c_textcolor(LIGHTGREEN);
            }

            else if (color == "light cyan" || color == "11")
            {
                c_textcolor(LIGHTCYAN);
            }

            else if (color == "light red" || color == "12")
            {
                c_textcolor(LIGHTRED);
            }

            else if (color == "light magenta" || color == "13")
            {
                c_textcolor(LIGHTMAGENTA);
            }

            else if (color == "yellow" || color == "14")
            {
                c_textcolor(YELLOW);
            }

            else if (color == "white" || color == "15")
            {
                c_textcolor(WHITE);
            }

            else if (color == "blink" || color == "none" || color == "reset" || color == "128")
            {
                c_textcolor(BLINK);
            }

            else if (color == "reset" || color == "r")
            {
                if (platform == "win32")
                {
                    c_textcolor(7);
                }

                else if (platform == "linux apple")
                {
                    std::cout << "\033[0m";
                }
            }

            else
            {
                ioc::color::set("red");
                std::cout << "No color named " << color.c_str() << "\n";
                ioc::color::set("white");
                std::exit(1);
            }

            ioc_last_textColor = color;
        }

        /// @brief Sets text background
        /// @param color 
        void setBackground(std::string color)
        {
            if (color == "black" || color == "0")
            {
                c_textbackground(BLACK);
            }

            else if (color == "blue" || color == "1")
            {
                c_textbackground(BLUE);
            }

            else if (color == "green" || color == "2")
            {
                c_textbackground(GREEN);
            }

            else if (color == "cyan" || color == "3")
            {
                c_textbackground(CYAN);
            }
            
            else if (color == "red" || color == "4")
            {
                c_textbackground(RED);
            }

            else if (color == "magenta" || color == "5")
            {
                c_textbackground(MAGENTA);
            }

            else if (color == "brown" || color == "6")
            {
                c_textbackground(BROWN);
            }

            else if (color == "light gray" || color == "light grey" || color == "7")
            {
                c_textbackground(LIGHTGRAY);
            }

            else if (color == "dark gray" || color == "light grey" || color == "8")
            {
                c_textbackground(DARKGRAY);
            }

            else if (color == "light blue" || color == "9")
            {
                c_textbackground(LIGHTBLUE);
            }

            else if (color == "light green" || color == "10")
            {
                c_textbackground(LIGHTGREEN);
            }

            else if (color == "light cyan" || color == "11")
            {
                c_textbackground(LIGHTCYAN);
            }

            else if (color == "light red" || color == "12")
            {
                c_textbackground(LIGHTRED);
            }

            else if (color == "light magenta" || color == "13")
            {
                c_textbackground(LIGHTMAGENTA);
            }

            else if (color == "yellow" || color == "14")
            {
                c_textbackground(YELLOW);
            }

            else if (color == "white" || color == "15")
            {
                c_textbackground(WHITE);
            }

            else if (color == "blink" || color == "none" || color == "reset" || color == "128")
            {
                c_textbackground(BLINK);
            }

            else if (color == "reset" || color == "r")
            {
                if (platform == "win32")
                {
                    c_textcolor(7);
                }

                else if (platform == "linux apple")
                {
                    std::cout << "\033[0m";
                }
            }

            else
            {
                ioc::color::set("red");
                std::cout << "No color named " << color.c_str() << "\n";
                ioc::color::set("white");
                std::exit(1);
            }
        
            ioc_last_bgColor = color;
        }
    }
    
    /// @param status (int)
    /// THINKING: param 2 might be a function call and end it with the program with the function
    void end(int status)
    {
        ioc::color::set("reset");
        std::exit(status);
    }

    /// @brief Does std::getline(std::cin, var) 
    /// @param text 
    /// @param inputAnswer 
    /// @return std::string 
    std::string input(std::string text, std::string inputAnswer)
    {
        ioc::kb::clear();
        ioc::print(ioc_key_pressed);
        ioc::print(ioc_key_is_pressed);

        std::getline(std::cin.ignore(), inputAnswer);

        return inputAnswer;
    }

    std::string LOWER(const std::string& str)
    {
        std::string result = str;
        
        for (char& c : result)
        {
            c = (char)std::tolower(static_cast<unsigned char>(c));
        }
        
        return result;
    }

    char charType(char ch)
    {
        if (std::isupper(ch))
        {
            return (char)std::tolower(ch);
        }
        
        return ch;
    }

    std::string stringType(const std::string& str)
    {
        std::string result = str;
        
        for (char& c : result)
        {
            c = (char)std::toupper(static_cast<unsigned char>(c));
        }
        
        return result;
    }

    std::string UPPER(const std::string& str) 
    {
        std::string result = str;
        
        for (char& c : result)
        {
            c = (char)std::toupper(static_cast<unsigned char>(c));
        }
        
        return result;
    };
}

