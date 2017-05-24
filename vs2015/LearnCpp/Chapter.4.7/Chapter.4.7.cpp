// Chapter.4.7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

struct Advertising
{
    int numberOfAdsShown;
    int numberOfAdsClicked;
    int averageEarnedOnClickedAds;
};

int getInteger()
{
    int value = 0;
    std::cin >> value;
    std::cin.ignore(32767, '\n');

    return value;
}

Advertising getAdvertising()
{
    std::cout << "Number of ads shown: ";
    int shown = getInteger();

    std::cout << "Number of ads clicked: ";
    int clicked = getInteger();

    std::cout << "Average earned on clicked ads: ";
    int average = getInteger();

    Advertising advertising{ shown, clicked, average };

    return advertising;
}

void displayAdvertising(Advertising advertising)
{
    std::cout << "Number of ads shown : " << advertising.numberOfAdsShown << "\n";
    std::cout << "Number of ads clicked: " << advertising.numberOfAdsClicked << "\n";
    std::cout << "Average earned on clicked ads: " << advertising.averageEarnedOnClickedAds << "\n";
}

int madeForThatDay(Advertising advertising)
{
    return advertising.numberOfAdsShown * advertising.numberOfAdsClicked * advertising.averageEarnedOnClickedAds;
}

void FractionTest();

int main()
{
    /*
    Advertising advertising = getAdvertising();
    
    displayAdvertising(advertising);

    int made = madeForThatDay(advertising);

    std::cout << "Total Earnings: $" << made << "\n";
    */

    FractionTest();

    return 0;
}

