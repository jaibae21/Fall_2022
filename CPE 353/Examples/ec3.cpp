

void f(int a);
bool g(int& b);

int main(int argc, char* argv[])
{
    char a[10];

    // Array bounds error
    a[10] = 0;

    // Array bounds error via loop
    for(int k = 0; k <= 10; k++)
    {
        a[k] = k;
    }

    // Array bounds error via loop
    int m = 0;
    while (true)
    {
        a[m] = m;
        m++;
    }

    // Pointer variable p uninitialized
    int* p;
    *p = 5;

    // Null pointer dereference
    int* x = 0;
    *x = 1;

    // Trigger path in function g that does not return Boolean
    int c = -1;
    if ( g(c) )
        c = 2;
    else
        c = 3;

    // Memory leak
    int* q = new int;

    // Memory leak
    int* r = new int[4];
    delete r;

    return 0;
}

// Unused function f
void f(int a)
{
    a = a + 1;    // No side effect outside function
}

// Function g has one path that does not return a Boolean value
bool g(int& b)
{
    if (b > 0)
        return false;

    b = 0;
    // Exit without returning a Boolean
}


