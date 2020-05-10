#include <iostream>
#include <iomanip>
#include <cstring>

class char_stack
{
private:
    struct node
    {
        char data;
        node* next;
    };

private:
    typedef node node_t;
    typedef node_t* node_ptr_t;

private:
    node_ptr_t top_node;

public:
    char_stack()
        : top_node(NULL)
    {

    }

    ~char_stack()
    {
        while (!empty())
            pop();
    }

    void push(char data)
    {
        node_ptr_t new_node = new node_t;
        new_node->data = data;
        new_node->next = top_node;
        top_node = new_node;
    }

    void pop()
    {
        node_ptr_t tmp = top_node->next;
        delete top_node;
        top_node = tmp;
    }

    char top() const
    {
        return top_node->data;
    }

    bool empty() const
    {
        return !top_node;
    }
};

// -----------------------
bool check_func(const char* s)
{
    const char* left = "([{";
    const char* right = ")]}";

    char_stack stack;

    for (size_t i = 0; s[i] != '\0'; ++i)
    {
        if (strchr(left, s[i]))
        {
            stack.push(s[i]);
        }

        else
        {
            if (strchr(right, s[i]))
            {
                if (stack.empty())
                    return false;

                switch (stack.top())
                {
                case '(':
                    if (s[i] != ')')
                        return false;
                    break;

                case '[':
                    if (s[i] != ']')
                        return false;
                    break;

                case '{':
                    if (s[i] != '}')
                        return false;
                    break;
                }

                stack.pop();
            }
        }
    }

    return stack.empty();
}

int main()
{
    char s[256];
    std::cout << "INPUT STRING:" << std::endl;
    std::cin.getline(s, sizeof(s));

    if (!std::cin) return 1;

    std::cout << std::boolalpha << check_func(s) << std::endl;
}