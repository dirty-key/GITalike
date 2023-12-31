#include <iostream>
#include <fstream>
#include <string>

std::string filetostring() {
    // Specify the file path to test.txt in the C:\Downloads folder
    std::string filePath = "C:\\Users\\mridu\\Downloads\\Test_folder\\test.txt";

    // Open the file for reading
    std::ifstream inputFile(filePath);

    if (!inputFile.is_open()) {
        std::cerr << "Failed to open the file: " << filePath << std::endl;
        return "";
    }

    // Read the file content into a string
    std::string fileContent;
    std::string line;

    while (std::getline(inputFile, line)) {
        fileContent += line + "\\n"; // Add \n escape sequence to separate lines
    }

    // Remove the trailing \n from the last line
    if (!fileContent.empty()) {
        fileContent.pop_back();
    }

    // Close the file
    inputFile.close();

    // Print or use the file content as needed
    //std::cout << "File Content with Escape Sequences:\n" << fileContent << std::endl;

    return fileContent;
}
