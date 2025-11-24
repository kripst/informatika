#include <iostream>
#include <math.h>

int main() {
    double x, y;
    std::cout << "x: ";
    std::cin >> x;

    std::cout << "y: ";
    std::cin >> y;

    double under_sqrt = x * x - 4 * x * y;
    if (under_sqrt < 0) {
        std::cout << "Ошибка: подкоренное выражение отрицательное.\n";
        return 1;
    }

    double R = (-x + sqrt(under_sqrt)) / (2 * x);
    double S = pow(4.0, -3.0 * x) * sin(y);

    std::cout << "R = " << R << "\n";
    std::cout << "S = " << S << "\n";

    double C = (R > S) ? R : S;
    std::cout << "C = " << C << "\n";

    return 0;
}
