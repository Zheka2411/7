template <typename T>
class Queue {
private:
    Array<T> array;
    int frontIndex = 0;
    int backIndex = 0;

public:
    void push(T value) {
        array.push_back(value);
        backIndex++;
    }

    T pop() {
        if (frontIndex == backIndex) {
            throw std::out_of_range("Queue is empty");
        }
        return array[frontIndex++];
    }

    T top() const {
        if (frontIndex == backIndex) {
            throw std::out_of_range("Queue is empty");
        }
        return array[frontIndex];
    }

    void clear() {
        frontIndex = backIndex = 0;
    }

    bool is_empty() const {
        return frontIndex == backIndex;
    }

    bool is_matching_pair(char open, char close) {
        return (open == '(' && close == ')') || (open == '{' && close == '}') || (open == '[' && close == ']');
    }

    bool check_parentheses(const string& str) {
        Stack<char> stack;
        for (char ch : str) {
            if (ch == '(' || ch == '{' || ch == '[') {
                stack.push(ch);
            }
            else if (ch == ')' || ch == '}' || ch == ']') {
                if (stack.is_empty() || !is_matching_pair(stack.pop(), ch)) {
                    return false;
                }
            }
            if (ch == ';') break; // кінець рядка
        }

        return stack.is_empty();
    }

    int main() {
        string input;
        cout << "Enter the string with parentheses: ";
        getline(cin, input);

        if (check_parentheses(input)) {
            cout << "The parentheses are correctly placed.\n";
        }
        else {
            cout << "There is an error in the parentheses placement.\n";
        }

        return 0;
    }

};
