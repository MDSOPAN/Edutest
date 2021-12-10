#include <iostream>
#include "Func.h"


int main() {
    US["Sopan"] = "1234";
    TS["Zarif"] = "1234";
    US["Shakil"] = "1234";
    TS["Sanad"] = "1234";
    courses CS1;
    CS1.enrolled.push_back("Sopan");
    student sopan;
    sopan.name = "Sopan";
    sopan.subsol = "6";
    CS1.teach = "Zarif";
    CS1.name = "Programming";
    assignments Fri;
    Fri.prob = "What is 3+3";
    Fri.solution = "6";
    CS1.assign.push_back(Fri);
    CS1.assign[0].stu.push_back(sopan);
    cor.push_back(CS1);
    courses CS2;
    CS2.teach = "Sanad";
    CS2.name = "Graph";
    CS2.enrolled.push_back("Shakil");
    assignments Sat;
    Sat.prob = "What is 5+3";
    Sat.solution = "8";
    CS2.assign.push_back(Sat);
    cor.push_back(CS2);
    courses CS3;
    CS3.teach = "Zarif";
    CS3.name = "Prog2";
    assignments fat;
    fat.prob = "New";
    fat.solution = "ton";
    CS3.assign.push_back(fat);
    CS3.enrolled.push_back("Sopan");
    cor.push_back(CS3);
    start();
    return 0;
}
