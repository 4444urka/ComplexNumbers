#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H
#include <ostream>


class RationalNumber {

private:

    int m; // Числитель

    unsigned int n; // Знаменатель

public:

    // Конструктор
    RationalNumber(int m, unsigned int n);

    // Геттеры сеттеры
    [[nodiscard]] int getNumerator() const;

    [[nodiscard]] int getDenominator() const;

    void setNumerator(int m);

    void setDenominator(unsigned int n);

    // Неявные-явные преобразования
    explicit operator float() const;

    explicit operator double() const;

    explicit operator int() const;

    // Унарный минус
    RationalNumber operator-() const;

    // Оператор вывода в поток
    friend std::ostream & operator<<(std::ostream &os, const RationalNumber &obj);

    // Операторы сравнения
    friend bool operator==(const RationalNumber &lhs, const RationalNumber &rhs);

    friend bool operator!=(const RationalNumber &lhs, const RationalNumber &rhs);

    friend bool operator<(const RationalNumber &lhs, const RationalNumber &rhs);

    friend bool operator<=(const RationalNumber &lhs, const RationalNumber &rhs);

    friend bool operator>(const RationalNumber &lhs, const RationalNumber &rhs);

    friend bool operator>=(const RationalNumber &lhs, const RationalNumber &rhs);

    // Операторы арифметических действий
    friend RationalNumber operator+(const RationalNumber &lhs, const RationalNumber &rhs);

    friend RationalNumber operator-(const RationalNumber &lhs, const RationalNumber &rhs);

    friend RationalNumber operator*(const RationalNumber &lhs, const RationalNumber &rhs);

    friend RationalNumber operator/(const RationalNumber &lhs, const RationalNumber &rhs);

    friend RationalNumber operator+=(RationalNumber &lhs, const RationalNumber &rhs);

    friend RationalNumber operator-=(RationalNumber &lhs, const RationalNumber &rhs);

    friend RationalNumber operator*=(RationalNumber &lhs, const RationalNumber &rhs);

    friend RationalNumber operator/=(RationalNumber &lhs, const RationalNumber &rhs);

    friend RationalNumber pow(const RationalNumber &base, int exponent);

    friend RationalNumber abs(const RationalNumber &number);

    bool operator!=(int i) const;

    bool operator==(int i) const;

    bool operator>(int i) const;
};
#endif //RATIONALNUMBER_H
