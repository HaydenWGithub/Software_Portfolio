
// COS30008: Tutorial 9, 2023

#pragma once

#include <optional>
#include <cassert>

template<typename T>
class Stack
{
private:
    T* fElements;
    size_t fStackPointer;
    size_t fCurrentSize;

#ifdef P1
	    
    void resize( size_t aNewSize )
    {
        assert(fStackPointer <= aNewSize);
        
        T* newElements = new T[aNewSize];
        
        for (size_t i = 0; i < fStackPointer; i++)
        {
            newElements[i] = std::move(fElements[i]);
        }
        
        delete[] fElements;
        
        fElements = newElements;
        fCurrentSize = aNewSize;
    }
    
    void ensure_capacity()
    {
        if ( fStackPointer == fCurrentSize )
        {
            resize(fCurrentSize * 2);
        }
    }
    void adjust_capacity()
    {
        if (fStackPointer <= fCurrentSize / 4 )
        {
            resize(fCurrentSize / 2);
        }
    }

#endif
    
public:
    
#ifdef P1
	
    Stack();
    ~Stack();

#endif

#ifdef P3
	
    Stack( const Stack& aOther ); 
    
    Stack operator=( const Stack<T>& aOther );

#endif

#ifdef P4

    Stack( Stack<T>&& aOther ) noexcept;
    
    Stack operator=( Stack<T>&& aOther ) noexcept;

    void swap( Stack& aOther ) noexcept;

#endif
      
#ifdef P1
	  
    size_t size() const noexcept
    {
        return fStackPointer;
    }
    
    std::optional<T> top() noexcept
    {
        if (fStackPointer > 0)
        {
            return std::optional<T>(fElements[fStackPointer - 1]);
        }
        else
        {
            return std::optional<T>();
        }
    }

    void push( const T& aValue )
    {
        
    }

#endif
	
#ifdef P2
	
    template<typename... Args>
    void emplace(Args&&... args)
    {
        ensure_capacity();

        // free old entry
        fElements[fStackPointer].~T();
        
        //placement new (matching constructor)
        new ( &fElements[fStackPointer++]) T( std::forward<Args>(args)...);
    }

#endif

#ifdef P1
	
    void pop()
    {
        assert( fStackPointer > 0 );
        
    }
	
#endif
    
};
