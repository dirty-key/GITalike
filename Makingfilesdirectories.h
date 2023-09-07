#include <iostream>
#include <cstdlib>
#include <fstream>  // for system() function

int make_dir() {
    std::string RepoPath;  // Specify the directory path here
    RepoPath = "C:\\Users\\mridu\\Downloads\\GITalike\\Repo";

#ifdef _WIN32  // Check if the platform is Windows
    std::string command = "mkdir " + RepoPath;
#else  // Assume non-Windows platforms use 'mkdir' command
    std::string command = "mkdir -p " + RepoPath;  // Use '-p' to create parent directories if needed
#endif

    // Execute the system command to create the folder
    int result = system(command.c_str());

    if (result == 0) {
        std::cout << "Folder created successfully." << std::endl;
    } else {
        std::cerr << "Failed to create folder." << std::endl;
    }

    
    std::string filename = "diff.txt"; // Specify the desired file name

    // Construct the full file path
    std::string DiffPath = RepoPath + "\\" + filename;

    std::ofstream outputFile(DiffPath);

    if (outputFile.is_open()) {
        
        // Close the file
        outputFile.close();

        std::cout << "File '" << filename << "' created in '" << "'." << std::endl;
    } else {
        std::cerr << "Error: Could not create the file." << std::endl;
    }


   
   /*filename = "commits.txt"; // Specify the desired file name

    // Construct the full file path
    std::string CommitPath = RepoPath + "\\" + filename;

    //std::ofstream outputFile(CommitPath);
    outputFile(CommitPath);
    if (outputFile.is_open()) {
        
        // Close the file
        outputFile.close();

        std::cout << "File '" << filename << "' created in '" << "'." << std::endl;
    } else {
        std::cerr << "Error: Could not create the file." << std::endl;
    }*/

    return 0;
}


