template <class T>
class SmartPointer
{
public:
    SmartPointer(T* ptr)
    {
        ref = ptr;
        ref_count = (unsigned*)malloc(sizeof(unsigned));
        *ref_count = 1;
    }        

    SmartPointer(SmartPointer<T>& sptr)
    {
        ref = sptr.ref;
        ref_count = sptr.ref_count;
        
        ++(*ref_count);
    }

    /* 覆写=运算符，这样才能将一个旧的智能指针赋值给另一指针，
     * 旧的引用计数减一，新的智能指针的引用计数则加一。
     */
    SmartPointer<T>& operator=(SmartPointer<T>& sptr)
    {
        if(this == &sptr)
        {
            return *this;
        }

        // 若已赋值为某个对象，则移除引用
        if(*ref_count > 0)
        {
            remove();
        }

        ref = sptr.ref;
        ref_count = sptr.ref_count;
        ++(*ref_count);
        return *this;
    }
    
    ~SmartPointer()
    {
        remove(); // 移除一个对象引用
    }    

    T getValue()
    {
        return *ref;
    }

protected:
    void remove()
    {
        --(*ref_count);
        if(*ref_count == 0)
        {
            delete ref;
            free(ref_count);
            ref = NULL;
            ref_count = NULL;
        }
    }
    
    T* ref;
    unsigned* ref_count;  

};


