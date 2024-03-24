#include <iostream>
#include <cstdint>
#include <bitset>

template<typename T>
class BinaryArithmetic {
private:
    T value;

public:
    BinaryArithmetic(T val) : value(val) {}

    std::string toBinary() const {
        return std::bitset<sizeof(T) * 8>(value).to_string();
    }

    int toInteger() const {
        return static_cast<int>(value);
    }

    BinaryArithmetic operator+(const BinaryArithmetic& other) const {
        return BinaryArithmetic(value + other.value);
    }

    BinaryArithmetic operator-(const BinaryArithmetic& other) const {
        return BinaryArithmetic(value - other.value);
    }

    BinaryArithmetic operator*(const BinaryArithmetic& other) const {
        return BinaryArithmetic(value * other.value);
    }

    BinaryArithmetic operator/(const BinaryArithmetic& other) const {
        return BinaryArithmetic(value / other.value);
    }

    BinaryArithmetic operator^(const int& exponent) const {
        T result = 1;
        for (int i = 0; i < exponent; ++i) {
            result *= value;
        }
        return BinaryArithmetic(result);
    }

    friend std::ostream& operator<<(std::ostream& os, const BinaryArithmetic& bin) {
        os << bin.toBinary() << " (" << bin.toInteger() << ")";
        return os;
    }
};

int main() {

    setlocale(LC_ALL, "RU");

    int num1, num2; 
    std::cout << "Введите первое целое число: ";
    std::cin >> num1;
    std::cout << "Введите второе целое число (степень): ";
    std::cin >> num2;

    BinaryArithmetic<int> binaryNumObj1(num1);
    BinaryArithmetic<int> binaryNumObj2(num2);

    std::cout << "Сумма: " << binaryNumObj1 + binaryNumObj2 << std::endl;
    std::cout << "Разность: " << binaryNumObj1 - binaryNumObj2 << std::endl;
    std::cout << "Произведение: " << binaryNumObj1 * binaryNumObj2 << std::endl;
    std::cout << "Частное: " << binaryNumObj1 / binaryNumObj2 << std::endl;
    std::cout << "Возведение в степень: " << (binaryNumObj1 ^ num2) << std::endl;

    return 0;
}
