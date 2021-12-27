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
    int k {-1};
    int contains(const std::string &stud,int g = 0){
        if(g != 0){
            for (int i = 0; i < stu.size(); ++i) {
                if (stu[i].name == stud && stu[i].grades == ""){
                    return -1;
                }
            }
        }else{
            for (int i = 0; i < stu.size(); ++i) {
                if (stu[i].name == stud){
                    k = i;
                }
            }
        }
        return k;
    }
};
struct courses{
    std::vector<assignments> assign;
    std::vector<std::string> enrolled;
    int kiin {-1};
    int contains(const std::string &stud){
        for (int i = 0; i < enrolled.size(); ++i) {
            if (enrolled[i] == stud){
                kiin = i;
            }
        }
        return kiin;
    }
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
//bool isthere(std::string enstu, std::vector<student> enrolled);
void tmenu(const std::string &User);
void smenu(const std::string &User);
void sgreport(const std::string &User);
void sregister(const std::string &User);
void slistcourses(const std::string &User);
void sselcourses(const std::string &User);
void tlistcourses(const std::string &User);
void tcreatecourses(const std::string &User);
void tselcourses(const std::string &User);
void tviewcourses(const std::string &User,int &j,std::vector<int> &indexes);
void sviewcourses(const std::string &User,int &b,std::vector<int> &sindexes);
void sucourses(const std::string &User,int &b,std::vector<int> &sindexes);
void sviewassign(const std::string &User,int &b,std::vector<int> &sindexes);
void sselassign(const std::string &User,int &b,std::vector<int> &sindexes);
void scourseinfo(const std::string &User,int &b,std::vector<int> &sindexes);
void ssubmitassign(const std::string &User,int &b,int &sl,std::vector<int> &sindexes,int dkin = -1);
void tlists(const std::string &User,int &j,std::vector<int> &indexes);
void tlistassign(const std::string &User,int &j,std::vector<int> &indexes);
void tcreateassign(const std::string &User,int &j,std::vector<int> &indexes);
void tselassign(const std::string &User,int &j,std::vector<int> &indexes);
void tviewassign(const std::string &User,int &j,int &l,std::vector<int> &indexes);
void tgreport(const std::string &User,int &j,int &l,std::vector<int> &indexes);
void tselsol(const std::string &User,int &j,int &l,std::vector<int> &indexes);
void tviewsol(const std::string &User,int &j,int &l,int &s,std::vector<int> &indexes);
#endif //EDUCATION_FUNC_H
