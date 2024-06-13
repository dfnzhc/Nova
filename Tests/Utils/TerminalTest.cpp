/**
 * @File TerminalTest.cpp
 * @Author dfnzhc (https://github.com/dfnzhc)
 * @Date 2024/5/18
 * @Brief 
 */

#include <gtest/gtest.h>

#include <fstream>
#include <string>

#include <Nova/Base/Defines.hpp>
#include <Nova/Utils/Terminal.hpp>

using namespace nova;
using namespace std;

#include <consoleapi.h>

namespace {

void OutputTest(std::ostream& os)
{
    os << tc::reset << "===== start ===== \n";

    os << "Styles: ";
    os << tc::bold << "Bold " << tc::reset;
    os << tc::dark << "Dark " << tc::reset;
    os << tc::italic << "Italic " << tc::reset;
    os << tc::underline << "Underline " << tc::reset;
    os << tc::blink << "Blink " << tc::reset;
    os << tc::reverse << "Reverse " << tc::reset;
    os << tc::concealed << "Concealed " << tc::reset;
    os << tc::crossed << "Crossed \n" << tc::reset;
    
    os << "Colors1: ";
    os << tc::color<1> << "1 " << tc::reset;
    os << tc::color<2> << "2 " << tc::reset;
    os << tc::color<3> << "3 " << tc::reset;
    os << tc::color<4> << "4 " << tc::reset;
    os << tc::color<5> << "5 " << tc::reset;
    os << tc::color<6> << "6 " << tc::reset;
    os << tc::color<7> << "7 " << tc::reset;
    os << tc::color<8> << "8 " << tc::reset;
    os << tc::color<9> << "9 " << tc::reset;
    os << tc::color<10> << "10 " << tc::reset;
    os << tc::color<11> << "11 " << tc::reset;
    os << tc::color<12> << "12 " << tc::reset;
    os << tc::color<13> << "13 " << tc::reset;
    os << tc::color<14> << "14 " << tc::reset;
    os << tc::color<15> << "15 " << tc::reset;
    os << tc::color<16> << "16 " << tc::reset;
    
    os << "\nColors2: ";
    os << tc::bg_color<1> << "1 " << tc::reset;
    os << tc::bg_color<2> << "2 " << tc::reset;
    os << tc::bg_color<3> << "3 " << tc::reset;
    os << tc::bg_color<4> << "4 " << tc::reset;
    os << tc::bg_color<5> << "5 " << tc::reset;
    os << tc::bg_color<6> << "6 " << tc::reset;
    os << tc::bg_color<7> << "7 " << tc::reset;
    os << tc::bg_color<8> << "8 " << tc::reset;
    os << tc::bg_color<9> << "9 " << tc::reset;
    os << tc::bg_color<10> << "10 " << tc::reset;
    os << tc::bg_color<11> << "11 " << tc::reset;
    os << tc::bg_color<12> << "12 " << tc::reset;
    os << tc::bg_color<13> << "13 " << tc::reset;
    os << tc::bg_color<14> << "14 " << tc::reset;
    os << tc::bg_color<15> << "15 " << tc::reset;
    os << tc::bg_color<16> << "16 " << tc::reset;
    
    os << "\nColors3: ";
    os << tc::color<0, 0, 0> << "(0, 0, 0) " << tc::reset;
    os << tc::color<255, 0, 0> << "(255, 0, 0) " << tc::reset;
    os << tc::color<0, 255, 0> << "(0, 255, 0) " << tc::reset;
    os << tc::color<0, 0, 255> << "(0, 0, 255) " << tc::reset;
    os << tc::color<255, 255, 255> << "(255, 255, 255) " << tc::reset;
    
    os << "\nColors4: ";
    os << tc::bg_color<0, 0, 0> << "(0, 0, 0) " << tc::reset;
    os << tc::bg_color<255, 0, 0> << "(255, 0, 0) " << tc::reset;
    os << tc::bg_color<0, 255, 0> << "(0, 255, 0) " << tc::reset;
    os << tc::bg_color<0, 0, 255> << "(0, 0, 255) " << tc::reset;
    os << tc::bg_color<255, 255, 255> << "(255, 255, 255) " << tc::reset;
    
    os << "\nColor: \n";
    os << tc::grey << "grey " << tc::reset;
    os << tc::red << "red " << tc::reset;
    os << tc::green << "green " << tc::reset;
    os << tc::yellow << "yellow " << tc::reset;
    os << tc::blue << "blue " << tc::reset;
    os << tc::magenta << "magenta " << tc::reset;
    os << tc::cyan << "cyan " << tc::reset;
    os << tc::white << "white " << tc::reset;
    
    os << "\nBright Color: \n";
    os << tc::bright_grey << "grey " << tc::reset;
    os << tc::bright_red << "red " << tc::reset;
    os << tc::bright_green << "green " << tc::reset;
    os << tc::bright_yellow << "yellow " << tc::reset;
    os << tc::bright_blue << "blue " << tc::reset;
    os << tc::bright_magenta << "magenta " << tc::reset;
    os << tc::bright_cyan << "cyan " << tc::reset;
    os << tc::bright_white << "white " << tc::reset;
    
    os << "\nBackground Color: \n";
    os << tc::bg_grey << "grey " << tc::reset;
    os << tc::bg_red << "red " << tc::reset;
    os << tc::bg_green << "green " << tc::reset;
    os << tc::bg_yellow << "yellow " << tc::reset;
    os << tc::bg_blue << "blue " << tc::reset;
    os << tc::bg_magenta << "magenta " << tc::reset;
    os << tc::bg_cyan << "cyan " << tc::reset;
    os << tc::bg_white << "white " << tc::reset;
    
    os << "\nBackground Bright Color: \n";
    os << tc::bg_bright_grey << "grey " << tc::reset;
    os << tc::bg_bright_red << "red " << tc::reset;
    os << tc::bg_bright_green << "green " << tc::reset;
    os << tc::bg_bright_yellow << "yellow " << tc::reset;
    os << tc::bg_bright_blue << "blue " << tc::reset;
    os << tc::bg_bright_magenta << "magenta " << tc::reset;
    os << tc::bg_bright_cyan << "cyan " << tc::reset;
    os << tc::bg_bright_white << "white " << tc::reset;
    
    
    os << tc::reset << "\n===== end ===== \n";
}

} // namespace

TEST(Terminal, Colors)
{
    cout << "cout:\n";
    OutputTest(cout);

    cout << "\n\ncerr:\n";
    OutputTest(cerr);

    cout << "\n\nclog:\n";
    OutputTest(clog);
}