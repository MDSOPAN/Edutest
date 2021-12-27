#include "Func.h"
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <zconf.h>

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
        else return "";
    }
    return User;
}

void mainmenu(const std::string &User){
    if (TS.find(User) != TS.end()){
        tmenu(User);
    }else{
        smenu(User);
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
    else if (k == 3) tcreatecourses(User);
    else start();
}

void start(){
    std::string User = logmenu();
    if (User == "") return;
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
              << "4.List Students\n"
              << "5.Back\n";
    std::cin >> k;
    if (k == 1) tlistassign(User,j,indexes);
    else if (k == 2) tselassign(User,j,indexes);
    else if (k == 3) tcreateassign(User,j,indexes);
    else if (k == 4) tlists(User,j,indexes);
    else tmenu(User);
}

void tviewassign(const std::string &User,int &j,int &l,std::vector<int> &indexes){
    int k {0};
    std::cout << "1.Grades Report\n"
              << "2.View Solutions\n"
              << "3.Back\n";
    std::cin >> k;
    if (k == 1) tgreport(User,j,l,indexes);
    else if(k==2) tselsol(User,j,l,indexes);
    else tviewcourses(User,j,indexes);
}
void tselassign(const std::string &User,int &j,std::vector<int> &indexes){
    if (cor[indexes[j-1]].assign.empty()){
        std::cout << "No assignments to view " << std::endl;
        tviewcourses(User,j,indexes);
    }
    std::cout << "Choose Assignment:" << std::endl;
    for (int i = 0; i < cor[indexes[j-1]].assign.size(); ++i) {
        std::cout << "Asignment " << i+1 << "." << cor[indexes[j-1]].assign[i].prob << std::endl;
    }
    int l;
    std::cin >> l;
    if (l > cor[indexes[j-1]].assign.size()){
        std::cout << "Invalid Input" << std::endl;
        tviewcourses(User,j,indexes);
    }else{
        tviewassign(User,j,l,indexes);
    }
};


void tselsol(const std::string &User,int &j,int &l,std::vector<int> &indexes){
    int s;
    for (int i = 0; i < cor[indexes[j-1]].assign[l-1].stu.size(); ++i) {
        std::cout << "Solution " << i+1 << ". " << cor[indexes[j-1]].assign[l-1].stu[i].subsol << " By " <<
        cor[indexes[j-1]].assign[l-1].stu[i].name << std::endl;
    }
    if (cor[indexes[j-1]].assign[l-1].stu.empty()){
        std:: cout << "No solutions Provided Yet by students" << std::endl;
        tviewassign(User,j,l,indexes);
    }
    std::cin >> s;
    if (s > cor[indexes[j-1]].assign[l-1].stu.size()){
        std::cout << "Invalid Input" << std::endl;
        tselsol(User,j,l,indexes);
    }
    else{
        tviewsol(User,j,l,s,indexes);
    }
}

void tviewsol(const std::string &User,int &j,int &l,int &s,std::vector<int> &indexes){
    int m {0};
    std::cout << "1.Set Grade\n"
              << "2.Give comment\n"
              << "3.Back\n";
    std::cin >> m;
    if(m==1){
        std::cout << "Enter Grade" << std::endl;
        std::string So;
        std::cin >> So;
        if (So != "A+" && So != "A" && So != "A-" && So != "B" && So != "C" && So != "D"
        && So != "F"){
            std::cout << "Invalid Input" << std::endl;
            tviewsol(User,j,l,s,indexes);
        }else{
            cor[indexes[j-1]].assign[l-1].stu[s-1].grades = So;
            tviewsol(User,j,l,s,indexes);
        }
    }else if(m == 2){
        std::cout << "Enter Comment: ";
        std::string Co;
        std::cin.ignore();
        getline(std::cin,Co);
        std::cout << std::endl;
        cor[indexes[j-1]].assign[l-1].stu[s-1].Comment = Co;
        tviewsol(User,j,l,s,indexes);
    }else{
        tviewassign(User,j,l,indexes);
    }
}

/*bool isthere(std::string enstu, std::vector<student> enrolled){
    for (int i = 0; i < enrolled.size(); ++i) {
        if (enrolled[i].name == enstu){
            return true;
        }
    }
    return false;
}*/

void tgreport(const std::string &User,int &j,int &l,std::vector<int> &indexes){
    for (int i = 0; i < cor[indexes[j-1]].assign[l-1].stu.size(); ++i) {
        if (cor[indexes[j-1]].assign[l-1].stu[i].grades == ""){
            std::cout << "Student: " << cor[indexes[j-1]].assign[l-1].stu[i].name
            << "'s Solution Not Evaluated Yet";
        }else{
            std::cout << "Student: " << cor[indexes[j-1]].assign[l-1].stu[i].name << " Got an " <<
            cor[indexes[j-1]].assign[l-1].stu[i].grades << std::endl;
        }
    }
    tviewassign(User,l,j,indexes);
}


void tcreateassign(const std::string &User,int &j,std::vector<int> &indexes){
    assignments ne;
    std::string question;
    std::cout << "Enter assignment Question: ";
    std::cin.ignore();
    getline(std::cin,question);
    ne.prob = question;
    cor[indexes[j-1]].assign.push_back(ne);
    tviewcourses(User,j,indexes);
}

void tcreatecourses(const std::string &User){
    courses ne;
    std::string n;
    std::cout << "Enter Course Name: " ;
    std::cin.ignore();
    getline(std::cin,n);
    ne.name = n;
    ne.teach = User;
    cor.push_back(ne);
    tmenu(User);
}

void tlists(const std::string &User,int &j,std::vector<int> &indexes){
    for (int i = 0; i < cor[indexes[j-1]].enrolled.size(); ++i) {
        std::cout << cor[indexes[j-1]].enrolled[i] << std::endl;
    }
    tviewcourses(User,j,indexes);
}

void smenu(const std::string &User){
    int si {0};
    std::cout << "1.Register in a Course\n"
              << "2.List My Courses\n"
              << "3.View Course\n"
              << "4.Grades Report\n"
              << "5.Back\n";
    std::cin >> si;
    if (si == 1) sregister(User);
    else if (si == 2) slistcourses(User);
    else if (si == 3) sselcourses(User);
    else if (si == 4) sgreport(User);
    else start();
}

void sregister(const std::string &User){
    std::cout << "Choose a course to register" << std::endl;
    int sin;
    for (int i = 0; i < cor.size(); ++i) {
        std::cout << i+1 << "." << cor[i].name << std::endl;
    }
    std::cin >> sin;
    sin = sin - 1;
    if (std::count(cor[sin].enrolled.begin(),cor[sin].enrolled.end(),User)){
        std::cout << "You are already registered in this course" << std::endl;
        smenu(User);
    } else{
        cor[sin].enrolled.push_back(User);
        smenu(User);
    }
}

void slistcourses(const std::string &User){
    std::cout << "My Courses:" << std:: endl;
    for (int i = 0; i < cor.size(); ++i) {
        if (std::count(cor[i].enrolled.begin(),cor[i].enrolled.end(),User)){
            std::cout << cor[i].name << " taught by " << cor[i].teach << std::endl;
            sleep(1);
        }
    }
    smenu(User);
}

void sselcourses(const std::string &User){
    int b {0};
    std::vector<int> sindexes;
    std::cout << "Choose course" << std::endl;
    for (int i = 0;i < cor.size();i++){
        if (std::count(cor[i].enrolled.begin(),cor[i].enrolled.end(),User)){
            sindexes.push_back(i);
        }
    }
    for (int l = 0; l < sindexes.size(); ++l) {
        std::cout << l+1 << ". " <<
                  cor[sindexes[l]].name << std::endl;
    }
    std::cin >> b;
    b = b-1;
    if (b > sindexes.size()){
        std::cout << "Invalid Input" << std::endl;
        smenu(User);
    }else{
        sviewcourses(User,b,sindexes);
    }
}

void sviewcourses(const std::string &User,int &b,std::vector<int> &sindexes){
    int sin {0};
    std::cout << "1.Course Info\n"
              << "2.View Assignments\n"
              << "3.Submit Assignments\n"
              << "4.Unregister from course\n"
              << "5.Back\n";
    std::cin >> sin;
    if (sin == 1) scourseinfo(User,b,sindexes);
    else if (sin == 2) sviewassign(User,b,sindexes);
    else if (sin == 3) sselassign(User,b,sindexes);
    else if (sin == 4) sucourses(User,b,sindexes);
    else smenu(User);
}

void scourseinfo(const std::string &User,int &b,std::vector<int> &sindexes){
    std::cout << "Name: " << cor[sindexes[b]].name << std::endl;
    std::cout << "Teacher: " << cor[sindexes[b]].teach << std::endl;
    sviewcourses(User,b,sindexes);
}

void sviewassign(const std::string &User,int &b,std::vector<int> &sindexes){
    for (int i = 0; i < cor[sindexes[b]].assign.size(); ++i) {
        std::cout << "Asssignment " << i+1 << ":" << cor[sindexes[b]].assign[i].prob << std::endl;
        int ki = cor[sindexes[b]].assign[i].contains(User);
        if (ki >= 0){
            std::cout << "Submitted Answer: " << cor[sindexes[b]].assign[i].stu[ki].subsol << std:: endl;
            sleep(1);
        } else{
            std::cout << "Assignment not submitted yet\n";
            sleep(1);
        }
    }
    sviewcourses(User,b,sindexes);
}

void sselassign(const std::string &User,int &b,std::vector<int> &sindexes){
    if (cor[sindexes[b]].assign.empty()){
        std::cout << "No assignments to view " << std::endl;
        sviewcourses(User,b,sindexes);
    }
    std::cout << "Choose Assignment to Submit:" << std::endl;
    for (int i = 0; i < cor[sindexes[b]].assign.size(); ++i) {
        std::cout << "Asignment " << i+1 << "." << cor[sindexes[b]].assign[i].prob << std::endl;
    }
    int sl;
    std::cin >> sl;
    sl = sl - 1;
    int kinn = cor[sindexes[b]].assign[sl].contains(User);
    if (kinn != -1){
        std::cout<< "This Will udate your current answer.\nAre you sure?\n"
                 << "1.Yes\n"
                 << "2.No\n";
        int sin;
        std::cin >> sin;
        if (sin == 2){
            sviewcourses(User,b,sindexes);
            return;
        }else{
            ssubmitassign(User,b,sl,sindexes,kinn);
            return;
        }
    }
    if (sl > cor[sindexes[b]].assign.size()){
        std::cout << "Invalid Input" << std::endl;
        sviewcourses(User,b,sindexes);
    }else{
        ssubmitassign(User,b,sl,sindexes);
    }
}

void ssubmitassign(const std::string &User,int &b,int &sl,std::vector<int> &sindexes,int dkin){
    std::string answer;
    std::cout << "Enter Assignment Answer: ";
    std::cin.ignore();
    getline(std::cin,answer);
    std::cout << std::endl;
    if (dkin == -1){
        student ne;
        ne.name = User;
        ne.subsol = answer;
        cor[sindexes[b]].assign[sl].stu.push_back(ne);
    }else{
        cor[sindexes[b]].assign[sl].stu[dkin].subsol = answer;
    }
    sviewcourses(User,b,sindexes);
}


void sucourses(const std::string &User,int &b,std::vector<int> &sindexes){
    std::cout<< "Are you sure?\n"
             << "1.Yes\n"
             << "2.No\n";
    int ssin;
    std::cin >> ssin;
    if (ssin == 1){
        int kiin = cor[sindexes[b]].contains(User);
        cor[sindexes[b]].enrolled.erase(cor[sindexes[b]].enrolled.begin()+kiin);
        for (int i = 0; i < cor[sindexes[b]].assign.size(); ++i) {
            int kki = cor[sindexes[b]].assign[i].contains(User);
            if (kki != -1){
                cor[sindexes[b]].assign[i].stu.erase(cor[sindexes[b]].assign[i].stu.begin()+kki);
            }
        }
        smenu(User);
    }else{
        sviewcourses(User,b,sindexes);
        return;
    }
}

void sgreport(const std::string &User){
    for (int i = 0; i < cor.size(); ++i) {
        if (cor[i].contains(User) != -1) {
            std::cout << cor[i].name << "-";
            int subm{0};
            for (int j = 0; j < cor[i].assign.size(); ++j) {
                int k = cor[i].assign[j].contains(User);
                if (k != -1) {
                    subm++;
                }
            }
            std::cout << "Total Submitted " << subm << " out of " << cor[i].assign.size() << "-";
            for (int l = 0; l < cor[i].assign.size(); ++l) {
                int ki = cor[i].assign[l].contains(User);
                int kj = cor[i].assign[l].contains(User, 2);
                if (ki != -1 && l != cor[i].assign.size() - 1 && kj != -1) {
                    std::cout << cor[i].assign[l].stu[ki].grades << ",";
                } else if (l != cor[i].assign.size() - 1 && kj == -1) {
                    std::cout << "Not Given Yet,";
                } else if (ki != -1 && l == cor[i].assign.size() - 1 && kj != -1) {
                    std::cout << cor[i].assign[l].stu[ki].grades;
                } else {
                    std::cout << "Not Given Yet";
                }
            }
            std::cout << std::endl;
        }else{
            continue;
        }
    }
    smenu(User);
}