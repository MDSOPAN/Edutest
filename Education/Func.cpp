#include "Func.h"
#include <unordered_map>
#include <iostream>

std::unordered_map<std::string,std::string> US;
std::unordered_map<std::string,std::string> TS;
std::vector<courses> cor;

void loginsys::signup(){
    std::cout << "Enter Username(No Spaces): ";
    std::string k;
    std::cin >> k;
    //std::cout << std::endl;
    std::cout << "Enter Pass: ";
    std::string p;
    std::cin >> p;
    //std::cout << std::endl;
    US[k] = p;
}


std::string loginsys::loginst() {
    std::cout << "Enter Username(No Spaces):";
    std::string ki;
    std::cin >> ki;
    std::cout << std::endl;
    if (US.find(ki) != US.end()){
        std::cout << "Enter Pass:";
        std::string p;
        std::cin >> p;
        std::cout << std::endl;
        if (US[ki] != p){
            std::cout << "Wrong Pass" << std::endl;
        }else{
            return ki;
        }
    } else{
        std::cout << "No User by that name is available\n";
        return "";
    }
}
std::string loginsys::logint(){
    std::cout << "Enter Username(No Spaces):";
    std::string ki;
    std::cin >> ki;
    std::cout << std::endl;
    if (TS.find(ki) != TS.end()){
        std::cout << "Enter Pass:";
        std::string p;
        std::cin >> p;
        std::cout << std::endl;
        if (TS[ki] != p){
            std::cout << "Wrong Pass" << std::endl;
        }else{
            return ki;
        }
    } else{
        std::cout << "No Teacher by that name is available\n";
        return "";
    }
}

std::string logmenu(){
    std::string User;
    loginsys sys;
    while (User == ""){
        int k = 0;
        std::cout << "1.Log In as Student\n"
                  << "2.Sign Up\n"
                  << "3.Log In as Teacher\n";
        std::cin >> k;
        if (k == 1) {
            User = sys.loginst();
        }else if (k == 2) sys.signup();
        else if (k == 3) User = sys.logint();
    }
    return User;
}

void mainmenu(const std::string &User){
    if (TS.find(User) != TS.end()){
        tmenu(User);
    }
}
void tlistcourses(const std::string &User){
    std::cout << "Courses By You:" << std::endl;
    for (int i = 0;i < cor.size();i++){
        if (cor[i].teach == User){
            std::cout << "Code:" << i+1 << "      Name: " <<
                      cor[i].name << std::endl;
        }
    }
    tmenu(User);
}

void tselcourses(const std::string &User){
    int j {0};
    std::vector<int> indexes;
    std::cout << "Enter course code" << std::endl;
    for (int i = 0;i < cor.size();i++){
        if (cor[i].teach == User){
            indexes.push_back(i);
        }
    }
    for (int l = 0; l < indexes.size(); ++l) {
        std::cout << l+1 << ". " <<
                  cor[indexes[l]].name << std::endl;
    }
    std::cin >> j;
    if (j > indexes.size()){
        std::cout << "Invalid Input" << std::endl;
        tmenu(User);
    }else{
        tviewcourses(User,j,indexes);
    }
}

void tmenu(const std::string &User){
    int k {0};
    std::cout << "1.List Courses\n"
              << "2.View Courses\n"
              << "3.Create Courses\n"
              << "4.Log Out\n";
    std::cin >> k;
    if (k == 1) tlistcourses(User);
    else if (k == 2) tselcourses(User);
    else if (k == 4) start();
}

void start(){
    std::string User = logmenu();
    std::cout << "Welcome " << User << std::endl << std::endl;
    mainmenu(User);
}

void tlistassign(const std::string &User,int &j,std::vector<int> &indexes){
    for (int i = 0; i < cor[indexes[j-1]].assign.size(); ++i) {
        std::cout << "Asignment " << i+1 << "." << cor[indexes[j-1]].assign[i].prob << std::endl;
    }
    tviewcourses(User,j,indexes);
};
void tviewcourses(const std::string &User,int &j,std::vector<int> &indexes){
    int k {0};
    std::cout << "1.List Assignments\n"
              << "2.View Assignments\n"
              << "3.Create Assignments\n"
              << "4.Back\n";
    std::cin >> k;
    if (k == 1) tlistassign(User,j,indexes);
    else if (k == 2) tselassign(User,j,indexes);
    //else if (k == 3) tviewcourses(User);
    else if (k == 4) tmenu(User);
}

void tviewassign(const std::string &User,int &j,int &l,std::vector<int> &indexes){
    int k {0};
    std::cout << "1.Grades Report\n"
              << "2.View Solutions\n"
              << "3.Back\n";
    std::cin >> k;
    if (k == 1) ;
    else if(k==2) tselsol(User,j,l,indexes);
}
void tselassign(const std::string &User,int &j,std::vector<int> &indexes){
    std::cout << "Choose Assignment:" << std::endl;
    for (int i = 0; i < cor[indexes[j-1]].assign.size(); ++i) {
        std::cout << "Asignment " << i+1 << "." << cor[indexes[j-1]].assign[i].prob << std::endl;
    }
    int l;
    std::cin >> l;
    if (l > cor[indexes[j-1]].assign.size()){
        std::cout << "Invalid Input" << std::endl;
    }else{
        tviewassign(User,j,l,indexes);
    }
};


void tselsol(const std::string &User,int &j,int &l,std::vector<int> &indexes){
    int s;
    for (int i = 0; i < cor[indexes[j-1]].assign[l-1].stu.size(); ++i) {
        if (cor[indexes[j-1]].assign[l-1].stu[i].name == ""){
            std::cout << "Solution Not Provided By "<< cor[indexes[j-1]].assign[l-1].stu[i].name  << std::endl;
        }
        std::cout << "Solution " << i+1 << "." << cor[indexes[j-1]].assign[l-1].stu[i].subsol << "By " <<
        cor[indexes[j-1]].assign[l-1].stu[i].name << std::endl;
    }
    std::cin >> s;
    if (s > cor[indexes[j-1]].assign[l-1].stu.size()){
        std::cout << "nvalid Input" << std::endl;
    }
    else{
        tviewsol(User,j,l,indexes);
    }
}

void tviewsol(const std::string &User,int &j,int &l,std::vector<int> &indexes){

}