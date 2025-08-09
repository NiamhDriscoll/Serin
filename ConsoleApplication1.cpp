#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <filesystem>
#include <string>


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
        
        if (Type == "int") {
			int value = std::stoi(Data);
            std::cout << "Integer value: " << value << std::endl;
        } else if (Type == "float") {
            float value = std::stoi(Data);
            std::cout << "Float value: " << value << std::endl;
        } else if (Type == "string") {
            std::cout << "String value: " << Data << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(5));
        } else {
            std::cerr << "Unknown type." << std::endl;
            return 1;
		}
		

	}

};
int main() {

    input hello;
    hello.add("hello");








}