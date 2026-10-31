#include <iostream>
using namespace std;

int main(){
    int NUM_STUDENTS = 5;

    string studentsNames[NUM_STUDENTS] = {
        "Ali", "Hiba", "Asma", "Zain", "Faisal"
    };

    int courseCounts[NUM_STUDENTS] = {
        5, 4, 3, 3, 5
    };

    double** grades = new double*[NUM_STUDENTS];
    for(int i = 0; i < NUM_STUDENTS; i++){
        grades[i] = new double[courseCounts[i]];
    }

    // Populating the grades for each student

    // Ali (5 subjects)
    grades[0][0] = 3.66; grades[0][1] = 3.33; grades[0][2] = 4.0; grades[0][3] = 3.0; grades[0][4] = 2.66;
    // Hiba (4 subjects)
    grades[1][0] = 3.33; grades[1][1] = 3.0;  grades[1][2] = 3.66; grades[1][3] = 3.0;
    // Asma (3 subjects)
    grades[2][0] = 4.0;  grades[2][1] = 3.66; grades[2][2] = 2.66;
    // Zain (3 subjects)
    grades[3][0] = 2.66; grades[3][1] = 2.33; grades[3][2] = 4.0;
    // Faisal (5 subjects)
    grades[4][0] = 3.33; grades[4][1] = 3.66; grades[4][2] = 4.0; grades[4][3] = 3.0; grades[4][4] = 3.33;  

    // Calculate and display the GPA for each student
    
    cout << "================================" << endl;
    cout << "GPA of Students" << endl;
    cout << "================================" << endl;
    cout << "Student Name\tGPA" << endl;
    cout << "================================" << endl;
    
    for(int i = 0; i < NUM_STUDENTS; i++){
        double sum = 0.0;
        for(int j = 0; j < courseCounts[i]; j++){
            sum += grades[i][j];
        }
        double gpa = sum / courseCounts[i];
        cout << "GPA of " << studentsNames[i] << ": \t" << gpa << endl;
    }

    return 0;
}
