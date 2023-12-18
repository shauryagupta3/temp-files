#include <iostream>
#include <stdexcept>
using namespace std;

class StackEmpty : public runtime_error
{
public:
    StackEmpty(const string &err) : runtime_error(err) {}
};

class StackFull : public runtime_error
{
public:
    StackFull(const string &err) : runtime_error(err) {}
};

template <typename T>
class Arrstack
{
    enum
    {
        DEF_CAPACITY = 100
    };

public:
    Arrstack(int cap = DEF_CAPACITY);
    int size() const;
    bool empty() const;
    const T &top() const ;
    void push(const T &e);
    T pop();
    void display();
    void clear();

    T *s;
    int capacity;
    int t;
};

template <typename T>
Arrstack<T>::Arrstack(int cap) : s(new T[cap]), capacity(cap), t(-1){};

template <typename T>
int Arrstack<T>::size() const
{
    return t + 1;
}

template <typename T>
bool Arrstack<T>::empty() const
{
    return (t < 0);
}

template <typename T>
const T &Arrstack<T>::top() const
{
    if (empty())
    {
        throw StackEmpty("TOP OF THE EMTPY STACK");
    }
    else
    {
        return s[t];
    }
}
template <typename T>
void Arrstack<T>::push(const T &e)
{
    if (size() == capacity)
    {
        throw StackFull("push to full stack");
    }
    else
    {
        s[++t] = e;
    }
}
template <typename T>
T Arrstack<T>::pop()
{
    if (empty())
    {
        throw StackEmpty("pop from empty stack");
    }
    else
    {
        return s[t--];
    }
}

template <typename T>
void Arrstack<T>::display()
{
    int a = 0;
    while (a <= t)
    {
        cout << s[a++] << " ";
    }
}

template <typename T>
void Arrstack<T>::clear()
{
    while (t > -1)
    {
        pop();
    }
}

int main()
{
    Arrstack<char> s;
    string express;
    cout << "Enter your expression ";
    getline(cin, express);
    int b = express.size();
    char *exp = &express[0];
    bool c = false;
    for (int i = 0; i < b; i++)
    {
        if (exp[i] == '[' || exp[i] == '(' || exp[i] == '{'|| exp[i] == '<')
        {
            s.push(exp[i]);
        }
        else if (exp[i] == ']' || exp[i] == ')' || exp[i] == ')' || exp[i] == '>')
        {
            if (s.empty())
            {
                c = false;
                break;
            }
            if (!((s.top() == '(' && exp[i] == ')') || (s.top() == '[' && exp[i] == ']') || (s.top() == '{' && exp[i] == '}')|| (s.top() == '<' && exp[i] == '>')))
            {
                
                c = false;
                break;
            }
            s.pop();
        }
    }
    if (s.empty())
    {
        c = true;
    }
    if (c)
    {
        cout<<"The expression is correctly written";
    }
    else{
        cout<<"Wrong expression";
    }
    
    return 0;
}