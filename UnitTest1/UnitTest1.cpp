#include "pch.h"
#include "CppUnitTest.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include "../lab_11.1/11.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:
        // Тест для CreateTXT
        TEST_METHOD(TestCreateTXT)
        {
            const char* filename = "test_file.txt";

            // Створення текстового файлу
            CreateTXT(filename);

            // Перевіряємо, чи файл існує після створення
            std::ifstream fin(filename);
            Assert::IsTrue(fin.is_open());  // Файл повинен бути відкритий

            // Перевіряємо, чи можемо прочитати вміст файлу
            std::string content;
            std::getline(fin, content);
            Assert::IsFalse(content.empty());  // Вміст файлу не повинен бути порожнім

            fin.close();
        }

        // Тест для PrintTXT
        TEST_METHOD(TestPrintTXT)
        {
            const char* filename = "test_print_file.txt";

            // Створимо тестовий файл
            std::ofstream fout(filename);
            fout << "Line 1" << std::endl;
            fout << "Line 2" << std::endl;
            fout.close();

            // Захоплюємо виведення
            std::streambuf* originalBuf = std::cout.rdbuf();
            std::ostringstream outputStream;
            std::cout.rdbuf(outputStream.rdbuf());

            // Виводимо вміст файлу
            PrintTXT(filename);

            // Перевіряємо, чи виведено правильний вміст
            std::string output = outputStream.str();
            Assert::IsTrue(output.find("Line 1") != std::string::npos);
            Assert::IsTrue(output.find("Line 2") != std::string::npos);

            std::cout.rdbuf(originalBuf);  // Відновлюємо стандартний вивід
        }
    };
}