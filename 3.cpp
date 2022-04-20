/**03. Students details using encapsulation.**/
#include<bits/stdc++.h>
using namespace std;

struct Student
{
string name;
char finalLetterGrade;
};

class StudentRecord
{
private:
    Student someStudent;

    double quiz[2], midterm, finalExam;
    double finalGrade;
    char finalLetterGrade;

public:
    void inputQuizzes();
    void inputMidtermGrade();
    void inputFinalGrade();

    double *getQuizzes();
    double getMidterm();
    double getFinalExam();

    double calcPercent(double grade, double outOfTotalPts, double
percentOfTotal);
double setFinalNumericGrade(double newFinalGrade);
char setFinalLetterGrade(char newFinalLetterGrade);
char calcFinalLetterGrade(double finalGrade);
};
double *StudentRecord::getQuizzes()
{
    double *quizPtr;
    quizPtr = quiz;

    return quizPtr;
}
double StudentRecord::getMidterm() { return midterm; }
double StudentRecord::getFinalExam() { return finalExam; }
double StudentRecord::calcPercent(double grade, double outOfTotalPts, double
percentOfTotal)
{
    double totalPercent = (grade / outOfTotalPts) * percentOfTotal;
    return totalPercent;
}

double StudentRecord::setFinalNumericGrade(double newFinalGrade) { return
finalGrade = newFinalGrade; }
char StudentRecord::calcFinalLetterGrade(double finalGrade)
{


    if (finalGrade >= 90)
        return 'A+';
    else if (finalGrade >= 85 && finalGrade < 90)
        return 'A';
    else if (finalGrade >= 80 && finalGrade < 85)
        return 'B+';
    else if (finalGrade >= 75 && finalGrade < 80)
        return 'B';
    else if (finalGrade >= 70 && finalGrade < 75)
        return 'C';
    else if (finalGrade >= 60 && finalGrade < 70)
        return 'D+';
    else if (finalGrade >= 50 && finalGrade < 60)
        return 'D';


    else
        return 'F';
}

char StudentRecord::setFinalLetterGrade(char newFinalLetterGrade) { return
finalLetterGrade = newFinalLetterGrade; }


void StudentRecord::inputQuizzes()
{
    cout << "Enter two quiz grades : ";
    for (int i = 0; i < 2; i++)
    {
        cin >> quiz[i];
    }
}

void StudentRecord::inputMidtermGrade()
{
    cout << "Enter midterm grade : ";
    cin >> midterm;
}

void StudentRecord::inputFinalGrade()
{
    cout << "Enter final grade : ";
    cin >> finalExam;
}

int main()
{
    Student someStudent;

    cout << "Enter name : ";
    cin >> someStudent.name;

    StudentRecord student;

    student.inputQuizzes();
    student.inputMidtermGrade();
    student.inputFinalGrade();

    double *ptr;

    ptr = student.getQuizzes();
    for (int i = 0; i < 2; i++)
        cout << "Quiz "<< i+1 <<": "<< ptr[i] << endl;


    cout << "Midterm : " << student.getMidterm() << endl;

    cout << "Final Exam : " << student.getFinalExam() << endl;

    // calculations //

    double quizSum = 0;
    for (int i = 0; i < 2; i++)
        quizSum += ptr[i];

    double quizPercent = student.calcPercent(quizSum, 20, 25);
    double midtermPercent = student.calcPercent(student.getMidterm(), 100,
25);
    double finalPercent = student.calcPercent(student.getFinalExam(), 100,
50);

    double finalNumGrade = quizPercent + midtermPercent + finalPercent;

    student.setFinalNumericGrade(finalNumGrade);

    char letterGrade = student.calcFinalLetterGrade(finalNumGrade);

    student.setFinalLetterGrade(letterGrade);

    someStudent.finalLetterGrade = letterGrade;

    cout << "Name : " << someStudent.name << endl;
    cout << "Final Grade : " << someStudent.finalLetterGrade << endl;

}
