#include <iostream>
#include <string>

int n1, n2, result, var;

int calculate(int n1, int n2, int result, int var);
using namespace std;


int main() {
    string comment;

    result = calculate(n1, n2, result, var);

    cout << "Result for yout operation: " << result << endl;
    cout << "If you are like please write comment" << endl;

    cin.ignore();
    getline(cin, comment);

    (comment.length()) ? cout << "Thanks" << endl : cout << "Yanks go home" << endl;

    return 0;
}

int calculate(int n1, int n2, int result, int var) {
    cout << "What you want which i am calculating\n1 +\n2 - \n3 *\n4 /" << endl;
    cin >> var;
    cout << "Please enter your numbers" << endl;
    cin >> n1 >> n2;
    switch (var) {
        case 1:
            result = n1 + n2;
            break;
        case 2:
            result = n1 - n2;
            break;
        case 3:
            result = n1 * n2;
            break;
        case 4:
            try {
                if (!n2) throw 1;
                result = n1 / n2;
            } catch (int e) {
                cout << e + "- divide by 0, try again" << endl;
                return calculate(n1, n2, result, var);
            }
            break;
        default:
            cout << "You choose variant if i don't know\nDo you want recalculate your operation? Please write your answer(+ or -)" << endl;
            bool answer = false;
            cin >> answer;
            if (answer)  return calculate(n1, n2, result, var); else return -1;
    }
    return result;
}