#include <iostream>
#include <variant>
#include <string>

int main() {
    // 创建一个可以存储int或std::string的variant
    std::variant<int, std::string> myVariant;

    // 给variant赋值
    myVariant = 10;
    std::cout << "Integer: " << std::get<int>(myVariant) << std::endl;

    // 改变variant存储的类型
    myVariant = "Hello, World!";
    std::cout << "String: " << std::get<std::string>(myVariant) << std::endl;

    // 使用visit来访问variant
    std::visit([](auto&& arg) {
        std::cout << arg << std::endl;
    }, myVariant);

    return 0;
}
