// main.cpp
// 중간고사, 기말고사, 그리고 과제 점수 몇개를 받고
// 마지막 평균 결과 점수를 계산하기.
#include <algorithm>
#include <ios>
#include <fstream> //file stream 파일을 사용하기위해 
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "grade.h"
#include "median.h"
#include "Student_info.h"




int main() {
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0; //초기상태
    ifstream student_file("grades.txt"); //파일스트림 만들고 "txt" 파일을 읽기 
    //학생 이름과 모든 점수를 읽어 저장하고
    //가장 긴 이름을 찾음.
 
    while (read(student_file, record)) {//cin을 사용하면 사용자 입력만 받을 수 있다. ifstream이여서 파일 입력 받을수
        maxlen = max(maxlen, record.name.size());

        students.push_back(record);
    }
   
    


    //학생 정보를 알파벳 순으로 정렬
    sort(students.begin(), students.end(), compare);


    for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
        //이름과 오른쪽 공백을 포함하여 maxlen + 1 개의 문자를 출력
        cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');
        

        // 종합 점수를 계산해 생성
        try {
            double final_grade = grade(students[i]);
            // 결과를 출력
            streamsize prec = cout.precision(); // 지금 cout precision
            cout << "Final grade: " << setprecision(3)
                << final_grade << setprecision(prec) << endl;
        }
        catch (domain_error e) {
            cout << e.what();

        }
    }

    return 0;
} // main 끝
