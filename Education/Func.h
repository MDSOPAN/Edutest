//
// Created by sopan on 12/5/21.
//

#ifndef EDUCATION_FUNC_H
#define EDUCATION_FUNC_H
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
void start();
extern std::unordered_map<std::string,std::string> TS;
extern std::unordered_map<std::string,std::string> US;
struct student{
    std::string grades;
    std::string Comment;
    std::string name;
    std::string subsol;
};
struct assignments{
    std::string prob;
    //std::string solution;
    std::vector<student> stu;
};
struct courses{
    std::vector<assignments> assign;
    std::vector<std::string> enrolled;
    std::string teach;
    std::string name;
};
extern std::vector<courses> cor;
struct loginsys{
    std::string loginst();
    std::string logint();
    void signup();
};

std::string logmenu();
void mainmenu(const std::string &User);
bool isthere(std::string enstu, std::vector<student> enrolled);

void tmenu(const std::string &User);
void tlistcourses(const std::string &User);
void tcreatecourses(const std::string &User);
void tselcourses(const std::string &User);
void tviewcourses(const std::string &User,int &j,std::vector<int> &indexes);
void tlistassign(const std::string &User,int &j,std::vector<int> &indexes);
void tcreateassign(const std::string &User,int &j,std::vector<int> &indexes);
void tselassign(const std::string &User,int &j,std::vector<int> &indexes);
void tviewassign(const std::string &User,int &j,int &l,std::vector<int> &indexes);
void tgreport(const std::string &User,int &j,int &l,std::vector<int> &indexes);
void tselsol(const std::string &User,int &j,int &l,std::vector<int> &indexes);
void tviewsol(const std::string &User,int &j,int &l,int &s,std::vector<int> &indexes);
#endif //EDUCATION_FUNC_H
