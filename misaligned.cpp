#include <iostream>
#include <assert.h>
#include "misaligned.h"

const char* MajorColorNames[] = { "White", "Red", "Black", "Yellow", "Violet" };
int numberOfMajorColors = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);

const char* MinorColorNames[] = { "Blue", "Orange", "Green", "Brown", "Slate" };
int numberOfMinorColors = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

ColorPair::ColorPair(MajorColor major, MinorColor minor) : m_majorColor(major), m_minorColor(minor) {

}

std::string ColorPair::ToString() {
    std::string colorPairStr = MajorColorNames[m_majorColor];
    colorPairStr += " ";
    colorPairStr += MinorColorNames[m_minorColor];
    return colorPairStr;
}

ColorPair ConvertPairNumberstoColor(int pairNumber) {
    int zeroBasedPairNumber = pairNumber - 1;
    MajorColor majorColor = (MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
    MinorColor minorColor = (MinorColor)(zeroBasedPairNumber % numberOfMinorColors);

    return ColorPair(majorColor, minorColor);
}
void printColorCodeMap() {
    std::cout << "----------------------------- " << std::endl;
    std::cout << " Color Code MAP " << std::endl;
    std::cout << "----------------------------- " << std::endl;
    std::cout << "PairNumber | MajorColor | MinorColor " << std::endl;

    int maxPairCount = TelCoColorCoder::numberOfMajorColors * TelCoColorCoder::numberOfMinorColors;

    for (int pairNumber = 1; pairNumber <= maxPairCount; ++pairNumber)
    {
        TelCoColorCoder::ColorPair colorPair = TelCoColorCoder::GetColorFromPairNumber(pairNumber);
        std::cout << std::setw(6) << pairNumber << " \t   | \t " << colorPair.ToString().c_str() << std::endl;
    }
}

void testNumberToPair(int pairNumber,
    MajorColor expectedMajor,
    MinorColor expectedMinor)
{
    ColorPair colorPair = GetColorFromPairNumber(pairNumber);
    std::cout << "Got pair " << colorPair.ToString().c_str() << std::endl;
    assert(colorPair.getMajor() == expectedMajor);
    assert(colorPair.getMinor() == expectedMinor);
}

int main() {
    printColorCodeMap();
    testNumberToPair(1, WHITE, BLUE);
    testNumberToPair(4, WHITE, BROWN);
    testNumberToPair(5, WHITE, SLATE);
    std::cout << "All is well (maybe!)\n";
    return 0;
}
