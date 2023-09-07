#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::string> findLongestCommonSubsequence(const std::vector<std::string>& originalLines, const std::vector<std::string>& modifiedLines) {
    int m = originalLines.size();
    int n = modifiedLines.size();

    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (originalLines[i - 1] == modifiedLines[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    std::vector<std::string> commonLines;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (originalLines[i - 1] == modifiedLines[j - 1]) {
            commonLines.insert(commonLines.begin(), originalLines[i - 1]);
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    return commonLines;
}

std::vector<std::string> applyPatch(const std::vector<std::string>& originalLines, const std::vector<std::string>& diffLines) {
    std::vector<std::string> modifiedLines;
    int originalIndex = 0;

    for (const std::string& line : diffLines) {
        if (line[0] == '-') {
            originalIndex++;
        } else if (line[0] == '+') {
            modifiedLines.push_back(line.substr(1));
        } else if (line[0] == ' ') {
            modifiedLines.push_back(originalLines[originalIndex]);
            originalIndex++;
        }
    }

    return modifiedLines;
}

std::string getContentFromOriginalNDiff(const std::string& originalContent, const std::string& diffData) {
    std::vector<std::string> originalLines;
    std::vector<std::string> diffLines;

    // Split originalContent and diffData into lines and store them in vectors
    size_t start = 0;
    size_t end = 0;
    while ((end = originalContent.find("\n", start)) != std::string::npos) {
        originalLines.push_back(originalContent.substr(start, end - start));
        start = end + 1;
    }
    originalLines.push_back(originalContent.substr(start));

    start = 0;
    end = 0;
    while ((end = diffData.find("\n", start)) != std::string::npos) {
        diffLines.push_back(diffData.substr(start, end - start));
        start = end + 1;
    }
    diffLines.push_back(diffData.substr(start));

    // Apply the patch and join modified lines into a single string
    std::vector<std::string> modifiedContentLines = applyPatch(originalLines, diffLines);
    std::string modifiedContent = "";
    for (const std::string& line : modifiedContentLines) {
        modifiedContent += line + "\n";
    }

    return modifiedContent;
}

std::string generateDiffData(const std::string& originalContent, const std::string& modifiedContent) {
    std::vector<std::string> originalLines;
    std::vector<std::string> modifiedLines;

    // Split originalContent and modifiedContent into lines and store them in vectors
    size_t start = 0;
    size_t end = 0;
    while ((end = originalContent.find("\n", start)) != std::string::npos) {
        originalLines.push_back(originalContent.substr(start, end - start));
        start = end + 1;
    }
    originalLines.push_back(originalContent.substr(start));

    start = 0;
    end = 0;
    while ((end = modifiedContent.find("\n", start)) != std::string::npos) {
        modifiedLines.push_back(modifiedContent.substr(start, end - start));
        start = end + 1;
    }
    modifiedLines.push_back(modifiedContent.substr(start));

    std::vector<std::string> diffLines;
    std::vector<std::string> commonLines = findLongestCommonSubsequence(originalLines, modifiedLines);

    int originalIndex = 0;
    int modifiedIndex = 0;

    for (const std::string& commonLine : commonLines) {
        while (originalLines[originalIndex] != commonLine) {
            diffLines.push_back("- " + originalLines[originalIndex]);
            originalIndex++;
        }

        while (modifiedLines[modifiedIndex] != commonLine) {
            diffLines.push_back("+ " + modifiedLines[modifiedIndex]);
            modifiedIndex++;
        }

        diffLines.push_back("  " + commonLine);
        originalIndex++;
        modifiedIndex++;
    }

    while (originalIndex < originalLines.size()) {
        diffLines.push_back("- " + originalLines[originalIndex]);
        originalIndex++;
    }

    while (modifiedIndex < modifiedLines.size()) {
        diffLines.push_back("+ " + modifiedLines[modifiedIndex]);
        modifiedIndex++;
    }

    // Join diff lines into a single string
    std::string diffData = "";
    for (const std::string& line : diffLines) {
        diffData += line + "\n";
    }

    return diffData;
}

std::string getOriginalContentFromModifiedAndDiff(const std::string& modifiedContent, const std::string& diffData) {
    // Reverse the process by applying the inverse of the diff data to the modified content
    std::vector<std::string> modifiedLines;
    std::vector<std::string> diffLines;

    // Split modifiedContent and diffData into lines and store them in vectors
    size_t start = 0;
    size_t end = 0;
    while ((end = modifiedContent.find("\n", start)) != std::string::npos) {
        modifiedLines.push_back(modifiedContent.substr(start, end - start));
        start = end + 1;
    }
    modifiedLines.push_back(modifiedContent.substr(start));

    start = 0;
    end = 0;
    while ((end = diffData.find("\n", start)) != std::string::npos) {
        diffLines.push_back(diffData.substr(start, end - start));
        start = end + 1;
    }
    diffLines.push_back(diffData.substr(start));

    std::vector<std::string> originalContentLines;
    int modifiedIndex = 0;

    for (const std::string& line : diffLines) {
        if (line[0] == '-') {
            modifiedIndex++;
        } else if (line[0] == '+') {
            originalContentLines.push_back(line.substr(1));
        } else if (line[0] == ' ') {
            originalContentLines.push_back(modifiedLines[modifiedIndex]);
            modifiedIndex++;
        }
    }

    // Join original content lines into a single string
    std::string originalContent = "";
    for (const std::string& line : originalContentLines) {
        originalContent += line + "\n";
    }

    return originalContent;
}

int main() {
    // Example usage:
    std::string originalContent = "This is the content.\n Blah blah blah";
    std::string modifiedContent = "This is the content.\n Blah blah";

    // Generate and print the diff data
    std::string diffData = generateDiffData(originalContent, modifiedContent);
    std::cout << "Diff Data:\n" << diffData << "\n";

    // Apply the diff data to the original content to get the modified content
    std::string resultContent = getContentFromOriginalNDiff(originalContent, diffData);
    std::cout << "Modified Content:\n" << resultContent << "\n";

    // Use the inverse function to get the original content from the modified content and diff data
    std::string originalFromModified = getOriginalContentFromModifiedAndDiff(modifiedContent, diffData);
    std::cout << "Original Content from Modified and Diff:\n" << originalFromModified << "\n";

    return 0;
}




