#include<iostream>
#include<vector>
using namespace std;
class Student{
    private:
    int rollno;
    string name;
    int semester;
    float CGPA;
    public:
    Student(){
        rollno=0;
        name="\0";
        semester=0;
        CGPA=0;
    }
    Student(int r,string n,int s,float cg){
        rollno=r;
        name=n;
        semester=s;
        CGPA=cg;
    }
    void input(){
        cout<<"Enter roll no: ";
        cin>>rollno;
        cin.ignore();
        cout<<"Enter name: ";
        getline(cin,name);
        cout<<"Enter semester: ";
        cin>>semester;
        cout<<"Enter CGPA: ";
        cin>>CGPA;
    }
    void output(){
        cout<<"\n-----------------------------\n";
        cout<<"Roll no is: "<<rollno<<endl;
        cout<<"Name is: "<<name<<endl;
        cout<<"Semester is: "<<semester<<endl;
        cout<<"CGPA is: "<<CGPA<<endl;
        cout<<"-----------------------------\n";
    }
    int getrollno(){
        return rollno;
    }
    void update(){
        cin.ignore();
        cout<<"Enter new name: ";
        getline(cin,name);
        cout<<"Enter new semester: ";
        cin>>semester;
        cout<<"Enter new CGPA: ";
        cin>>CGPA;
    }

};
int main(){
    vector<Student>students;
    int choice;

    do{
        cout<<"\n-----------------------\n";
        cout<<"Student Management System";
        cout<<"\n-----------------------\n";
        cout<<"1.Add Student\n";
        cout<<"2.Display Students\n";
        cout<<"3.Search Student\n";
        cout<<"4.Update Student\n";
        cout<<"5.Delete Student\n";
        cout<<"6.Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
            {
            Student s;
            s.input();
            students.push_back(s);
            cout<<"Student added successfully...\n";
            break;
            }
            case 2:
            {
            if(students.empty()){
                cout<<"No Students found...\n";
            }
            else{
                for(int i=0; i<students.size(); i++){
                    students[i].output();
                }
            }
            break;
            }
            case 3:
            {
                int roll;
                bool found=false;
                cout<<"Enter RollNumber: ";
                cin>>roll;
                for(int i=0; i<students.size(); i++){
                    if(students[i].getrollno()==roll){
                        students[i].output();
                        found=true;
                    }
                }
                if(!found){
                    cout<<"Student Not Found...\n";
                }
                break;
            }
            case 4:
            {
                int roll;
                bool found=false;
                cout<<"Enter RollNumber: ";
                cin>>roll;
                for(int i=0; i<students.size(); i++){
                    if(students[i].getrollno()==roll){
                        students[i].update();
                        cout<<"Record Updated Successfully...";
                        found=true;
                    }

                }
                if(!found){
                    cout<<"Student not found...\n";
                }
                break;
            }
            case 5:
            {
                int roll;
                bool found=false;
                cout<<"Enter rollno: ";
                cin>>roll;
                for(int i=0; i<students.size(); i++){
                    if(students[i].getrollno()==roll){
                        students.erase(students.begin()+i);
                        cout<<"Student deleted successfully...\n";
                        found = true;
                    }
                }
                if (!found){
                    cout<<"Student not found...";
                }
                break;
            }
            case 6:
            {
            cout<<"\n...Thankyou...\n";
            break;
            }
            default:
            cout<<"Invalid Choice...";
        }
    }while(choice !=6);
    return 0;
}