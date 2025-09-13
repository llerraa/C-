#include <iostream> // для ввода-вывода
#include <cmath> // для дополнительных математических функций
#include <locale> // для SetConsoleCP и SetConsoleOutputCP (русский язык)
#include <iomanip>  // для вывода в консоль с точностью до 2 знаков после запятой
#include <limits> // для проверки ввода (очистка)
#include <string> // для работы со строками

using namespace std;

float calculation(float prev_rez = NAN) {
        float x=0, y=0, R=0, n=0;
        char a1 = ' ';
        cout << "==========================" << endl;
        cout << "Доступные операции:" << endl;
        cout << "+ : Сложение" << endl;
        cout << "- : Вычитание" << endl;
        cout << "* : Умножение" << endl;
        cout << "/ : Деление" << endl;
        cout << "% : Остаток от деления" << endl;
        cout << "^ : Возведение в степень" << endl;
        cout << "s : Корень (sqrt)" << endl;
        cout << "c : Косинус (cos)" << endl;
        cout << "i : Синус (sin)" << endl;
        cout << "t : Тангенс (tan)" << endl;
        cout << "l : Натуральный логарифм (ln)" << endl;
        cout << "==========================" << endl;

        if (isnan(prev_rez)){
            cout << "Введите первое число: ";
            cin >> x;
        }
        else {
            cout << "Первое число взято из прошлого вычисления: " << prev_rez << endl;
            x = prev_rez;
        }
        cout << "Введите операцию: ";
        cin >> a1;
        switch(a1){
            case '+':
                cout << "Введите второе число: ";
                cin >> y;
                R = x+y;
                cout << "Результат: " << R << endl;
                break;
            case '-':
                cout << "Введите второе число: ";
                cin >> y;
                R = x-y;
                cout << "Результат: " << R << endl;
                break;
            case '*':
                cout << "Введите второе число, на которое умножаем: ";
                cin >> y;
                R = x*y;
                cout << "Результат: " << R << endl;
                break;
            case '/':
                cout << "Введите второе число, на которое делим: ";
                cin >> y;
                if(y==0){
                    cout << "Деление на 0 невозможно";
                    break;}
                else{
                    R = x/y;
                    cout << "Результат: " << R << endl;
                    break;}
            case '%': 
                cout << "Введите второе число для вычисления остатка от деления первого на второе: ";
                cin >> y;
                if(y==0){
                    cout << "Деление на 0 невозможно";
                    break;}
                else{
                    int rx = round(x);
                    int ry = round(y);
                    if ((ry - y) != 0){
                    cout << "Остаток от деления можно вычислить только для целых чисел \n";
                    cout << "Поэтому нам пришлось округлить: x = " << rx << " y = " << ry << endl;
                    cout << "Вычисляем остаток от деления " << rx << " на "<< ry << endl;
                    R = rx%ry;
                    }
                    else {
                    R = rx%ry;
                    }
                cout << "Результат: " << R << endl;
                break;
                }
            case '^': 
                cout << "В какую степень возводим первое число? \n";
                cin >> y;
                if(y==0){
                    cout << "Степень 0 невозможна";
                    break;}
                else{
                    int rx = round(x);
                    int ry = round(y);
                    if ((ry - y) != 0){
                        cout << "Степень можно вычислить только для целых чисел \n";
                        cout << "Поэтому нам пришлось округлить: x = " << rx << " y = " << ry << endl;
                        cout << "Вычисляем степень " << ry << " по основанию "<< x << endl;
                        R = pow(rx, ry);
                    }
                    else{
                        cout << "Вычисляем степень " << y << " по основанию "<< x << endl;
                        R = pow(rx, ry);
                    }
                cout << "Результат: " << R << endl;
                break;
                }
            case 's':
                cout << "Вы в операции корня. Корень какой степени хотите вычислить? \n";
                cin >> y;
                    if(x==0){
                        cout << "Корень из 0 невозможен";
                        break;}
                    else{
                        int ry = round(y);
                        if ((ry - y) != 0){
                        cout << "Можно вычислить только корень целой степени \n";
                        cout << "Поэтому нам пришлось округлить: y = " << ry << endl;
                        cout << "Вычисляем корень " << ry << "-й степени из "<< x << endl;
                        R = pow(x, 1.0/ry);
                        }
                        else {
                            cout << "Вычисляем корень " << y << "-й степени из "<< x << endl;
                            R = pow(x, 1.0/y);
                        }
                    cout << "Результат: " << R << endl;
                    break;
                    }
            case 'c':
                R = cos(x);
                cout << "Результат: " << R << endl;
                break;
            case 'i':
                R = sin(x);
                cout << "Результат: " << R << endl;
                break;
            case 't':
                R = tan(x);
                cout << "Результат: " << R << endl;
                break;
            case 'l':
                R = log(x); 
                cout << "Результат: " << R << endl;
                break;
        break;
        }
    return R;  
};

int main() {
    float arr[10]; // Массив для хранения результатов вычислений
    arr[0] = NAN; // Первый элемент массива, но мне он неудобен из-за индекса ноль, так что пусть будет NAN

    // Изначально заполним массив NaN-значениями
    for (int k = 1; k < 10; k++) {
        arr[k] = NAN;  //Not-a-Number
    }

    for (int i = 1; i < 10; i++) {
        if (isnan(arr[1])) {
            cout << "Добро пожаловать в калькулятор! \n";
            arr[i] = calculation();
        }
        else {
                cout << "Что делаем дальше? \n 1. Продолжить операции с полученным результатом \n 2. Считать новые числа \n 3. Выйти \n";
                int otv;
                cin >> otv;
                if (otv == 1) {
                cout << "Продолжаем вычисления с результатом: " << arr[i-1] << endl;
                arr[i] = calculation(arr[i-1]);    
                }
                else if (otv == 2) {
                cout << "Считаем новые числа!" << endl;
                arr[i] = calculation();
                }
                else {
                cout << "История ваших результатов: \n" << endl;
                for (int j = 1; j < 10; j++) {
                    cout << arr[j] << "; " << endl;
                }
                cout << "До свидания!" << endl;
                break;
                }
        }
};
};