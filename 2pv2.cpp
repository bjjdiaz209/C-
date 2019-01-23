//Implement a f_stack<T> (LIFO) class.

// Implement a RPN evaluator class. (1 2 +) will push 1 and 2 in a stack, and the operator + will remove  them and push into them the result of adding them up. It will support the 4 basic operations.

// You can use everything seen at class, but no other stuff.

// Not compiling code will render your exam useless.

// Having memory leaks will subtract 10 points to your last score.

// Do not use inheritance, polymorphism or any virtual thing.
#include <iostream>
#include <string>
#include <exception>
#include <cstring>

using namespace std;
template <typename T>
class my_exception : public exception
{
    T value;
public:
    my_exception(const T &value)
    :value{value}
    {}
    ~my_exception()
    {}
    const char* what() const noexcept override
    {
        return value.c_str();
    }
};
template <typename T>
struct Node
{
    string name;
    T value;
};


template <typename T>
class f_stack
{
private:
    size_t size;
    T *items;
    size_t count;
public:
    f_stack()
    :size{13}, items{new T[size]}, count{0}
    {}

    f_stack(size_t size)
    :size{size}, items{new T[size]}, count{0}
    {
    }

    ~f_stack()
    {
        delete [] items;
    }
    void set_size(const size_t &size)
    {
        this->size=size;
    }

    void set_count(const size_t &count)
    {
        this->count=count;
    }

    size_t get_size() const
    {
        return size;
    }

    size_t get_count() const
    {
        return count;
    }
    void push(T node)
    {
        //resize();
        items[count] = node;
        count++;
    }

    T& pop()
    {
        if (count == 0)
        {
            throw my_exception<string>{"Attempt to pop value from empty stack"s};
        }
        count--;
        return items[count];
    }

    template <typename PROC>
    void iterate(PROC p) const
    {
        for (int i = count-1; i>=0 ; i=i-1)
        {
            p(items[i]);
        }
    }

    T* get_items() const
    {
        return items;
    }
    
    T& get(const size_t &position) const
    {
        if (position>count)
        {
            throw my_exception<string>{"No such element in the stack"s};
        }
        return items[position];
    }
   bool is_empty()const
    {
        if (count == 0)
        {
            return true;
        }
        return false;
    }
};

void split_string(const char &delimiter,const char *src, auto p)
{
    size_t len = strlen(src);
    char * textChar = new char[len+1];
    memcpy(textChar,src,len+1);

    char *delimiterChar = new char[2];
    delimiterChar[0] = delimiter;
    delimiterChar[1] = '\0';

    char *textCopy = strtok (textChar,delimiterChar);
    while (textCopy != nullptr)
    {
        string aux = string(textCopy);
        p(aux);
        textCopy = strtok (nullptr,delimiterChar);
    }
    delete [] delimiterChar;
    delete [] textChar;
    delete [] textCopy;
}

typedef int (*FUNCION)(int&,int&);
struct NodePair
{
    string name;
    FUNCION operation;
};

class evaluator
{
    f_stack<int> stack;
    f_stack<NodePair> operatorStack;
public:
    evaluator()
    :stack{},operatorStack{}
    {
        add_operator("*", [](auto& x, auto& y)
        {
            return x * y;
        });
        add_operator("+", [](auto& x, auto& y)
        {
            return x + y;
        });
        add_operator("-", [](auto& x, auto& y)
        {
            return x - y;
        });
        add_operator("/", [](auto& x, auto& y)
        {
            return x / y;
        });
    }
    ~evaluator()
    {
    }
    int evaluate(const char *src)
    {
        int result = 0;
        size_t len = strlen(src);
        char * textChar = new char[len+1];
        memcpy(textChar,src,len+1);

        char * pch = strtok (textChar," ");
        while (pch != NULL)
        {
            string s{pch};
            try
            {
                int aux = stoi(s);
                stack.push(aux);
            }
            catch(...)
            {
                result = real_evaluate(s);
                stack.push(result);
            }
            pch = strtok (NULL, " ");
        }
        delete [] textChar;
        delete [] pch;
        return result;
    }
    int real_evaluate(const string &src)
    {
        try
        {
            int elem1 = stack.pop(),elem2=stack.pop();
            int result=0;
            for (size_t i = 0U; i < operatorStack.get_count(); ++i)
            {
                if (src == operatorStack.get(i).name)
                {
                    result = operatorStack.get(i).operation(elem1,elem2);
                }
            }
            return result;
        }
        catch(...)
        {
            throw my_exception<string>{"Operand not found"s};
        }
    }

    void add_operator(const string& name, FUNCION p)
    {
        operatorStack.push(NodePair{name,p});
    }
};



bool test0()
{
    f_stack<int> st;
    auto r1 = st.is_empty();
    st.push(10);
    auto r2 = st.is_empty();

    return r1 && !r2;
}

bool test1()
{
    f_stack<int> st;
    st.push(50);
    st.push(40);
    st.push(25);

    return st.pop() == 25 && st.pop() == 40;
}


bool test2()
{
    f_stack<string> s;
    s.push("easy");
    s.push("was");
    s.push("exam");
    s.push("second");
    auto s4 = s.pop();
    auto s3 = s.pop();
    auto s2 = s.pop();
    auto s1 = s.pop();

    return s4 == "second" && s3 == "exam" && s2 == "was" && s1 == "easy" && s.is_empty();
}

bool test3()
{
    f_stack<string> sd;
    sd.push("devices");
    sd.push("own");
    sd.push("my");
    sd.push("to");
    sd.push("left");
    string accum;
    sd.iterate([&accum](auto& x)
    {
        accum += x + " ";
    });
    string accum2;
    sd.iterate([&accum2](auto& x)
    {
        accum2 += x + " ";
    });
    return accum == accum2 && accum == "left to my own devices ";
}

bool test4()
{
    try
    {
        f_stack<string> x;
        x.push("hello");
        x.push("world");
        x.pop();
        x.pop();
        x.pop();

        return false;
    }
    catch (const std::exception& ex)
    {
        return "Attempt to pop value from empty stack"s == ex.what();
    }
}

bool test5()
{
    string result;
    split_string(' ', "abc def ghi jkl", [&result](auto& s)
    {
        result += s + "; ";
    });

    return result == "abc; def; ghi; jkl; ";
}
bool test6()
{
    evaluator m;

    return m.evaluate("10 30 +") == 40;
}

bool test7()
{
    evaluator x;
    return x.evaluate("10 20 50 + *") == 700;
}
bool test8()
{
    try
    {
        evaluator x;
        x.evaluate("10 20 + +");

        return false;
    }
    catch (const exception& x)
    {
        return "Operand not found"s == x.what();
    }
}
bool test9()
{
    evaluator x;
    x.add_operator("min", [](auto& x, auto& y)
    {
        return x < y ? x : y;
    });
    return x.evaluate("5 3 * 10 20 - min") == 10;
}

using test = bool(*)();

auto main() -> int
{
    test tests[] = { test0,
                     test1,
                     test2,
                     test3,
                     test4,
                     test5,
                     test6,
                     test7,
                     test8,
                     test9
    };
    size_t score = 0;
    for (auto& t : tests)
    {
        score += t() * 10;
    }
    cout << "Score: " << score << " / 100\n";
    getchar();
    return 0;
}
