#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <filesystem>
#include <string>
#include <variant>


class input {
	
public : int add(std::string name) {
        std::string Type;
        std::ifstream typeFile("type.txt");
        if (!typeFile.is_open()) {
            std::cerr << "Error opening type file." << std::endl;
            return 1;
        }

        std::getline(typeFile, Type);
        typeFile.close();

   
        std::string Data;
        std::ifstream dataFile("data.txt");
        if (!dataFile.is_open()) {
            std::cerr << "Error opening data file." << std::endl;
            return 1;
        }
        std::getline(dataFile, Data);
        dataFile.close();
		std::variant <int, float, std::string> inputValue;
		inputValue = Data;
        if (Type == "int") {
            value = std::get<int>(inputValue);
        }
        else if (Type == "float") {
            value = std::get<float>(inputValue);
        }
        else if (Type == "string") {
            value = std::get<std::string>(inputValue);
        }
        else {
            std::cerr << "Unsupported type." << std::endl;
            return 1;
        }
        return 0;
    }
	   std::variant <int, float, std::string> value;

	}

};
int main() {

    input hello;
    hello.add("hello");
    std::cout << hello.value;







}