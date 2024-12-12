// #include <iostream>
// #include <fstream>
// #include <string>
// using namespace std;

// int countFGrades(const string& filename) {
//     ifstream file(filename);
//     if (!file.is_open()) {
//         cerr << "Unable to open file: " << filename << endl;
//         return -1;
//     }

//     string line;
//     int fGradeCount = 0;

//     while (getline(file, line)) {
//         // Split the line by spaces to extract the grade
//         size_t lastSpace = line.find_last_of(' ');
//         if (lastSpace != string::npos) {
//             char grade = line[lastSpace + 1];
//             if (grade == 'F') {
//                 fGradeCount++;
//             }
//         }
//     }

//     file.close();
//     return fGradeCount;
// }

// int main() {
//     string filename = "g:/SADIA/Data Structure Assignment (3)/Data Structure Assignment/studentData.txt";
//     int totalFGrades = countFGrades(filename);

//     if (totalFGrades != -1) {
//         cout << "Total number of students who got F grades: " << totalFGrades << endl;
//     }

//     return 0;
// }


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int countFGrades(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Unable to open file: " << filename << endl;
        return -1;
    }

    int fGradeCount = 0;
    string line;
    while (getline(file, line)) {
        if (!line.empty() && line.back() == 'F') {
            fGradeCount++;
        }
    }

    return fGradeCount;
}

int main() {
    string filename = "g:/SADIA/Data Structure Assignment (3)/Data Structure Assignment/studentData.txt";
    int totalFGrades = countFGrades(filename);

    if (totalFGrades != -1) {
        cout << "Total number of students who got F grades: " << totalFGrades << endl;
    }

    return 0;
}
