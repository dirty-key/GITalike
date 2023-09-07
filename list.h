#include <iostream>
#include <fstream>
#include <string>
#include "diffandinverseanditworks.h"
#include "filetostring.h"


class Node {
public:
    std::string diffData;
    int commitId;
    Node* prev;
    Node* next;

    Node(const std::string& data, int id) {
        diffData = data;
        commitId = id;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    int nextCommitId;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
        nextCommitId = 1;
    }

    void addDiffDataAndCommitId(const std::string& data, int commitId) {
        Node* newNode = new Node(data, commitId);
        if (tail == nullptr) {
            // The list is empty.
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    /*void displayCommitHistory() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << "Commit ID: " << current->commitId << "\nDiff Data: " << current->diffData << "\n\n";
            current = current->next;
        }
    }
*/
   /* void saveToFile(const std::string& filename) {
        std::ofstream outFile(filename);
        if (!outFile.is_open()) {
            std::cerr << "Unable to open file: " << filename << std::endl;
            return;
        }

        Node* current = head;
        while (current != nullptr) {
            outFile << "Commit ID: " << current->commitId << "\nDiff Data: " << current->diffData << "\n\n";
            current = current->next;
        }

        outFile.close();
        std::cout << "Commit history saved to " << filename << std::endl;
    }
*/
    ~DoublyLinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};


void printLinkedList()
    {DoublyLinkedList commitHistory;
    bool firstCommit = true;
    std::string oldData;
    std::hash<std::string> hash_obj;


    // Call f1 and f2 to get diff data and commit ID and add them to the list.
        // std::string data = firstCommit?"":oldData;
        // firstCommit = false;
        // std::string diffData = generateDiffData(data,filetostring());
        // oldData = filetostring();
        // int commitId = f2();
        // commitHistory.addDiffDataAndCommitId(diffData, commitId);
        std::cout<<hash_obj("hrelooo");

    //std::cout << "Commit History:\n";
    //commitHistory.displayCommitHistory();

    //commitHistory.saveToFile("commit_history.txt");

}
