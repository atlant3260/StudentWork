#include <iostream> // библиотека вводы вывода
#include <string> // библиотека для работы со строками
#include <sstream> // для преобразования строк в числа
#include <iomanip> // для форматированяи вывода


    int a = 0;
    int b = 0;
    int result = 0;

    //функция для ввода 16ти ричного число, принимает число подсказку возвращает число в десячичном виде
    int inputHex(std::string promt) {
        std::string input;
        int number;
        std::cout << promt;
        getline(std::cin, input);
        std::stringstream ss;// создаем поток для преобразования строки в число
        ss << std::hex << input; // записываем строку в поток hex означает что число в 16ти ричной системе
        ss >> number;
        return number;
    }
    //функция сложения на ассемблере
    int addAsm(int x, int y) {
        int result_asm = 0;
        __asm {
            mov eax, x; //загружаем 1 число
            mov ebx, y; //загружаем 2 число
            mov ebx,ebx //складываем в eax
            mov result_asm,eax //сохраняем результат из eax в переменную
        }
        return result_asm;
    }
    int main()
    {
        setlocale(LC_ALL, "Rus");
        std::cout << "=========================" << std::endl;
        std::cout << "введите число в HEX(например: 1F,A3,100" << std::endl;
        a = inputHex("введите первое число в HEX: ");
        b = inputHex("введите второе число в HEX: ");
        result = addAsm(a, b);
        std::cout << "результат" << result;
        return 0;
    }


