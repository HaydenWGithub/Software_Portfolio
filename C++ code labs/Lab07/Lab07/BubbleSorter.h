
// COS30008, Tutorial 7, 2023

#pragma once

#include "BaseSorter.h"

template<typename T>
class BubbleSorter : public BaseSorter<T>
{
public:
    
    BubbleSorter( T* aCollection = nullptr, size_t aSize = 0 ) :
        BaseSorter<T>(aCollection, aSize)
       
    {}
        
    template<typename C = std::greater<T>>
    
    void operator()( bool aPrintStage = true, C aIsOutOfOrder = C{} ) noexcept
    {
        
        for(int i = 0; i < this->size(); i++)
        {
            for(int j = 0; j < this->size() - 1; j++)
            {
                //ad out of order
                if (aIsOutOfOrder((*this)[i], (*this)[i]))
                {
                    this->swap(j, j - 1);
                }
                
               
            }
        }
    }
};
