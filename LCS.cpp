#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printTable(const vector<vector<int>>& table) {
    for (int i = 0; i < table.size(); ++i) {
        for (int j = 0; j < table[i].size(); ++j) {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
}

void findLongestCommonSubstrings(const string& str1, const string& str2) {
    int n = str1.length();

    vector<vector<int>> table(n + 1, vector<int>(n + 1, 0));
    int maxLength = 0;
    vector<string> substrings;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                table[i][j] = table[i - 1][j - 1] + 1;
                if (table[i][j] > maxLength) {
                    maxLength = table[i][j];
                    substrings.clear();  
                }
                if (table[i][j] == maxLength) {
                    substrings.push_back(str1.substr(i - maxLength, maxLength));  
                }
            }
        }
    }

    cout << "Table:\n";
    printTable(table);

    cout << "Longest common substrings:\n";
    for (const string& substring : substrings) {
        cout << substring << endl;
    }
}

int main() {
    string str1, str2;

    cout << "Enter the first string: ";
    cin >> str1;

    cout << "Enter the second string: ";
    cin >> str2;

    findLongestCommonSubstrings(str1, str2);

    return 0;
}
