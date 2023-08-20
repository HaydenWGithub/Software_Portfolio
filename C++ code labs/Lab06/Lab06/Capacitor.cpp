//
//  Capacitor.cpp
//  Lab06
//
//  Created by Hayden Flynn Whiteford on 5/4/2023.
//
#include <cmath>
#include <stdio.h>
#include "Capacitor.h"

Capacitor::Capacitor( double aBaseValue) noexcept
{}

bool Capacitor::mustScale( double aValue ) const noexcept
{
    return aValue < 1.0;
}
// 1000.0
const double Capacitor::getMultiplier() const noexcept
{
    return 1000.0;
}
// "F"
const std::string Capacitor::getMajorUnit() const noexcept
{
    return "F";
}
// minor units: "Fmunp", the first letter means "no major unit"
const std::string Capacitor::getMinorUnits() const noexcept
{
    return "Fmunp";
}

// returns (frequency-dependent) passive resistance value
double Capacitor::getReactance( double aFrequency ) const noexcept
{
    return( 1.0 / atan(1.0) * 8.0 * aFrequency * getBaseValue() );
    
}
