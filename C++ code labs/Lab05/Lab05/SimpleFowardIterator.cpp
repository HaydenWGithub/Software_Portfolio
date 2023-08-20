//
//  SimpleFowardIterator.cpp
//  Lab05
//
//  Created by Hayden Flynn Whiteford on 29/3/2023.
//
#include "SimpleForwardIterator.h"
#include "DataWrapper.h"

SimpleForwardIterator::SimpleForwardIterator(const DataWrapper* aCollection) noexcept :
    fCollection(aCollection),
    fIndex(0)
{}

const DataMap& SimpleForwardIterator::operator*() noexcept
{
    return (*fCollection)[fIndex];
}

SimpleForwardIterator& SimpleForwardIterator::operator++() noexcept // prefix
{
    fIndex++;

    return (*this);
}

SimpleForwardIterator SimpleForwardIterator::operator++(int) noexcept // posfix
{
    SimpleForwardIterator lPrevIterator = *this;

    ++(*this);
    return lPrevIterator;

}

bool SimpleForwardIterator::operator==(const SimpleForwardIterator& aOther) const noexcept
{
    return aOther.fCollection == fCollection && aOther.fIndex == fIndex;
}

bool SimpleForwardIterator::operator!=(const SimpleForwardIterator& aOther) const noexcept
{
    return !(*this == aOther);
}

SimpleForwardIterator SimpleForwardIterator::begin() const noexcept
{
    SimpleForwardIterator lCopy = *this;
    lCopy.fIndex = 0;
    return lCopy;
}

SimpleForwardIterator SimpleForwardIterator::end() const noexcept
{
    SimpleForwardIterator lCopy = *this;
    lCopy.fIndex = (*fCollection).size();
    return lCopy;
}
