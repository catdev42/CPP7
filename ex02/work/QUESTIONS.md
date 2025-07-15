Questions:

Construction with no parameter: Creates an empty array.

### Should this array be of size 1? How do i make an empty array? Just init it to 0?

#### What does this do: arr(new T[0]()), _size(0)

That line is part of a **member initializer list** for your `Array`'s default constructor. It initializes the class's member variables *before* the constructor's body `{}` is executed.

Let's break it down into its two parts:

1.  **`_size(0)`**
    *   This is the simple part. It initializes the `_size` member variable to `0`. This makes sense, as a default-constructed array should be empty.

2.  **`arr(new T[0]())`**
    *   This is the more interesting part. It initializes the `arr` pointer.
    *   `new T[0]` tells the compiler to allocate a **zero-sized array** on the heap.
    *   The `()` at the end ensures **value-initialization**, though it has no practical effect on a zero-sized array.

#### What does `new T[0]` do exactly?

This is a special case in C++. The C++ standard guarantees that `new T[0]` is a valid operation. It does the following:

*   It returns a **unique, non-null pointer**.
*   This pointer **cannot be dereferenced**. You cannot access `arr[0]` because no memory was allocated for any elements.
*   Crucially, this pointer **can be safely passed to `delete[]`**.

**Why is this useful?**

It simplifies your destructor. By ensuring `arr` is always a valid, deletable pointer (never `NULL` after construction), your destructor can simply be:


In summary, the line `arr(new T[0]()), _size(0)` creates a valid, empty `Array` object where `_size` is `0` and `arr` holds a valid, non-null pointer that can be safely deleted, even though it points to no actual elements.



### Should the function in a template class be defined directly in the hpp file?  
They could be or they could be defined in the TPP file which is included at the very end of the hpp file (if its at the beginning, the compiler won't link cause it wont know the declarations necessary for the tpp file)

### If there is a tpp file, should i include that in the hpp file? 

### Do I need the () here : arr = new T[_size]?  
No, but that meant it will be default initialized for fundamental types and will contain garbage values  
If () are included then it is value initialized which means it is initialized to 0.  

### the operator[] function - what does it reutnr?
It must return a reference to T (T&) because that allows it to be editable... actually maybe in cnst case it should no be editable?

#### Is there no way the user can overwrite the constness of tht return and edit the array?
They can with const_cast... but shoudl still return const T reference n- its a contract fnot a fortress
