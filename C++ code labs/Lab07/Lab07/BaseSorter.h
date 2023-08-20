
// COS30008, Tutorial 7, 2023

#pragma once

#include <iostream>
#include <functional>
#include <cassert>
#include <algorithm>

template<typename T>
class BaseSorter
{
private:
    T* fCollection;
    size_t fSize;
	size_t fSwapCount;
 	
public:
    
    BaseSorter( T* aCollection = nullptr, size_t aSize = 0 ) :
        fCollection(new T[aSize]),
        fSize(aSize),
        fSwapCount(0)
    {
        for (size_t i = 0; i < fSize; i++)
        {
            fCollection[i] = aCollection[i];
        }
    }
    
    virtual ~BaseSorter()
    {
        delete[] fCollection;
    }
    
    size_t size() const noexcept
    {
        return fSize;
    }
    
    size_t getSwapCount() const noexcept
    {
        return fSwapCount;
    }

    const T& operator[]( size_t aIndex ) const
    {
        return fCollection[aIndex];
    }
    
    void swap( size_t aLeftIndex, size_t aRightIndex )
    {
        assert(aLeftIndex < fSize && aRightIndex < fSize);
        
        if (aLeftIndex != aRightIndex)
        {
            std::swap(fCollection[aLeftIndex], fCollection[aRightIndex]);
            fSwapCount++;
        }
        
    }
    
    template<typename C = std::greater<T>>
    
    void operator()( bool aPrintStage = true, C aIsOutOfOrder = C{} ) noexcept
    {
       /*
        
        size_t i = 1;

        while (i < fSize)
        {
            size_t j = i;

            while (j > 0 && aIsOutOfOrder(fCollection[j - 1], fCollection[j]))
            {
                swap(fCollection[j - 1], fCollection[j]);
                fSwapCount++;
                j--;
            }

            i++;
        }*/
        
    }
    
    void printStage( size_t aIndent = 0 ) const noexcept
    {
        while (aIndent--)
        {
            std::cout << ' ';
        }
        
        std::cout << '[';
        
        size_t i = 0;
        
        if (i < fSize)
        {
            while (true)
            {
                std::cout << fCollection[i++];
                
                if (i < fSize)
                {
                    std::cout << ',';
                }
                else
                {
                    break;
                }
                
            }
        }
        
        std::cout << ']';
        
        std::cout << std::endl;
        
        /*for (int i = 0; i < fSize; i++)
      //  {
       //     std::cout << fCollection[i] << ", ";
       // }
        std::cout << std::endl; */
    }
};
