Of course. Here are the requirements from your README.md file, formatted for clarity.

### Assignment: C++ Module 07 - ex02

**Files to turn in:**
*   `Makefile`
*   `main.cpp`
*   `Array.{h, hpp}`
*   (Optional) `Array.tpp`

**Forbidden functions:** None

---

Develop a class template `Array` that contains elements of type `T` and implements the following behavior:

*   **Construction with no parameter:**
    *   Creates an empty array.

*   **Construction with an `unsigned int n` as a parameter:**
    *   Creates an array of `n` elements, initialized by default.
    *   *Tip: Try to compile `int * a = new int();` then display `*a` to see what default initialization does.*

*   **Copy Constructor and Assignment Operator:**
    *   Modifying the original array or its copy must not affect the other.

*   **Memory Allocation:**
    *   You **MUST** use the `new[]` operator to allocate memory.
    *   Preventive allocation (allocating more memory than requested) is forbidden.
    *   Your program must never access non-allocated memory.

*   **Element Access:**
    *   Elements must be accessible through the subscript operator (`[]`).
    *   If an index is out of bounds, the `[]` operator must throw an `std::exception`.

*   **`size()` Member Function:**
    *   Must return the number of elements in the array.
    *   Must take no parameters.
    *   Must not modify the current instance (i.e., it should be a `const` member function).

As usual, ensure everything works as expected and provide a `main.cpp` file that contains your tests.
