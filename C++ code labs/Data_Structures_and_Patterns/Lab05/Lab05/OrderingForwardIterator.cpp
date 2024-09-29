//
//  OrderingForwardIterator.cpp
//  Lab05
//
//  Created by Hayden Flynn Whiteford on 29/3/2023.
//

#include <stdio.h>
#include "OrderingForwardIterator.h"

void OrderingForwardIterator::setMapPosition()
{
    for (size_t i = 0; i < fCollection->size(); i++)
    {
        if ( (*fCollection)[i].key() == fIndex)
        {
            fMapPosition = i;
            
            break;
        }
    }
}
    
OrderingForwardIterator::OrderingForwardIterator( const DataWrapper* aCollection ) noexcept :
    fCollection(aCollection),
    fIndex(0),
    fMapPosition(0)
{
    setMapPosition();
}
    
const DataMap& OrderingForwardIterator::operator*() noexcept
{
    //return *fCollection->operatior[](fIndex);
    return (*fCollection)[fMapPosition];
}
    
OrderingForwardIterator& OrderingForwardIterator::operator++() noexcept
{
    fIndex++;
    
    setMapPosition();
    
    return *this;
}// prefix

OrderingForwardIterator OrderingForwardIterator::operator++(int) noexcept
{
    OrderingForwardIterator old = *this;
    
    ++(*this);
    
    return old;
}// postfix

bool OrderingForwardIterator::operator==( const OrderingForwardIterator& aOther ) const noexcept
{
    return fCollection == aOther.fCollection && fIndex == aOther.fIndex;
}

bool OrderingForwardIterator::operator!=( const OrderingForwardIterator& aOther ) const noexcept
{
    //return fCollection != aOther.fCollection || fIndex != aOther.fIndex;
    return !(*this == aOther);
}
    
OrderingForwardIterator OrderingForwardIterator::begin() const noexcept
{
    OrderingForwardIterator copy = *this;
    
    copy.fIndex = 0;
    copy.fMapPosition = 0;
    copy.setMapPosition();
    
    return copy;
}

OrderingForwardIterator OrderingForwardIterator::end() const noexcept
{
    OrderingForwardIterator copy = *this;
    
    copy.fIndex = fCollection->size();
    
    return copy;
}

