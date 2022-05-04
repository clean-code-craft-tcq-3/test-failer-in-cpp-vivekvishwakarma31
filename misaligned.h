#ifndef MISALIGNED_H
#define MISALIGNED_H

#include <iostream>
#include <assert.h>

enum MajorColor { WHITE, RED, BLACK, YELLOW, VIOLET };
enum MinorColor { BLUE, ORANGE, GREEN, BROWN, SLATE };

extern const char* MajorColorNames[];
extern const char* MinorColorNames[];
extern int numberOfMajorColors;
    extern int numberOfMinorColors;

    class ColorPair
    {
    private:
        MajorColor m_majorColor;
        MinorColor m_minorColor;
    public:
        ColorPair(MajorColor major, MinorColor minor);      
        MajorColor getMajor();
        MinorColor getMinor();
        std::string ToString();
    };
    ColorPair ConvertPairNumberstoColor(int pairNumber);
    void printColorCodeMap();

#endif
