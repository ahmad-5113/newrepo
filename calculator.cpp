#include <iostream>

using namespace std; // Using the standard namespace globally

class Calculator {
public:
    double add(double a, double b) { return a + b; }
    double subtract(double a, double b) { return a - b; }
    double multiply(double a, double b) { return a * b; }
    
    // Returns false if division by zero is attempted
    bool divide(double a, double b, double &result) {
        if (b == 0) return false;
        result = a / b;
        return true;
    }
};

int main() {
    Calculator calc;
    double num1, num2, result;
    char op;

    cout << "====================================\n";
    cout << "          C++ Calculator            \n";
    cout << "====================================\n";

    while (true) {
        cout << "Enter operator (+, -, *, /) or 'q' to quit: ";
        cin >> op;

        if (op == 'q' || op == 'Q') {
            break;
        }

        // Validate operator input
        if (op != '+' && op != '-' && op != '*' && op != '/') {
            cout << "Invalid operator! Please try again.\n\n";
            continue;
        }

        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;

        cout << "\n> ";
        switch (op) {
            case '+':
                cout << num1 << " + " << num2 << " = " << calc.add(num1, num2);
                break;
            case '-':
                cout << num1 << " - " << num2 << " = " << calc.subtract(num1, num2);
                break;
            case '*':
                cout << num1 << " * " << num2 << " = " << calc.multiply(num1, num2);
                break;
            case '/':
                if (calc.divide(num1, num2, result)) {
                    cout << num1 << " / " << num2 << " = " << result;
                } else {
                    cout << "Error: Division by zero is undefined.";
                }
                break;
        }
        cout << "\n------------------------------------\n\n";
    }

    cout << "Exiting program. Goodbye!\n";
    return 0;
}