 


#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <string>
#include <iomanip>
#include <sstream>
//#include <libcurl4-openssl-dev> // For SHA-256 hash

struct Commit {
    std::string id;
    std::string message;
    std::string author;
    std::string timestamp;
    // Add other commit information as needed
};

void writeCommitToFile(const Commit& commit, const std::string& filePath) {
    std::ofstream outputFile(filePath, std::ios::app); // Append mode

    if (outputFile.is_open()) {
        outputFile << "Commit Details:" << std::endl;
        //outputFile << "ID: " << commit.id << std::endl;
        outputFile << "Author: " << commit.author << std::endl;
        outputFile << "Timestamp: " << commit.timestamp << std::endl;
        outputFile << "Message: " << commit.message << std::endl;
        // Write other commit information as needed
        outputFile << "--------------------------------------------" << std::endl;
        outputFile.close();
    } else {
        std::cerr << "Error: Could not open the file for writing." << std::endl;
    }
}

// std::string calculateSHA256Hash(const std::string& input) {
//     unsigned char hash[SHA256_DIGEST_LENGTH];
//     SHA256_CTX sha256;
//     SHA256_Init(&sha256);
//     SHA256_Update(&sha256, input.c_str(), input.size());
//     SHA256_Final(hash, &sha256);

//     std::stringstream ss;
//     for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
//         ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
//     }

//     return ss.str();
// }


Commit createCommit(const std::string& author, const std::string& message) {
    Commit commit;
    commit.author = author;
    commit.message = message;

    // Generate a timestamp for the commit
    std::time_t currentTime = std::time(nullptr);
    commit.timestamp = std::ctime(&currentTime);

    // Calculate the commit ID based on author, message, and timestamp
    std::string commitData = author + message + commit.timestamp;
    //commit.id = calculateSHA256Hash(commitData);

    return commit;
}

int commitment() {
    std::string filePath = "C:\\Users\\mridu\\Downloads\\Test_Folder\\Repo\\commit.txt"; // Specify the desired file path
    std::string author, message;
    char choice;

    std::cout << "Version Control System" << std::endl;

    // Initialize the commit log file or clear its contents if it already exists
   // std::ofstream initFile(filePath);
    //initFile.close();


                std::cin.ignore(); // Consume newline character
                std::cout << "Enter author's name: ";
                std::getline(std::cin, author);
              
                std::cout << "Enter commit message: ";
                std::getline(std::cin, message);

                Commit newCommit = createCommit(author, message);
                writeCommitToFile(newCommit, filePath);

                std::cout << "Commit created and saved." << std::endl;
                
            
            
        return 0;
        }
    
    
    
