//
//  ResistorBase.cpp
//  Lab06
//
//  Created by Hayden Flynn Whiteford on 5/4/2023.
//

#include <stdio.h>
#include "ResistorBase.h"


#include "ResistorBase.h"

ResistorBase::ResistorBase( double aBaseValue) noexcept :
    fBaseValue(aBaseValue)
{}

void ResistorBase::setBaseValue( double aBaseValue ) noexcept
{
    fBaseValue = aBaseValue;
}

double ResistorBase::getBaseValue() const noexcept
{
    return fBaseValue;
}

// returns (frequency-dependent) voltage drop
double ResistorBase::getPotentialAt( double aCurrent, double aFrequency) const noexcept
{
    return aCurrent * getReactance(aFrequency);
}

// returns (frequency-dependent) current flowing through a resistor
double ResistorBase::getCurrentAt( double aVoltage, double aFrequency) const noexcept
{
    return aVoltage / getReactance(aFrequency);
}

// resistor I/O
std::istream& operator>>( std::istream& aIStream, ResistorBase& aObject )
{
    double lValue;
    std::string lUnit;

    aIStream >> lValue >> lUnit;

    aObject.convertUnitValueToBaseValue(lValue, lUnit);

    return aIStream;
}

std::ostream& operator<<( std::ostream& aOStream, const ResistorBase& aObject )
{
    double lValue;
    std::string lUnit;
    aObject.convertBaseValueToUnitValue(lValue, lUnit);

    return aOStream << lValue << lUnit << std::endl;
}
