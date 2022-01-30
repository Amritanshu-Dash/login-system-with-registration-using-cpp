//
//  main.cpp
//  Login_System_with_Registration_and_Filestoring_Filesystem_using_C++
//
//  Created by Amritanshu Dash on 21/01/22.
//

#include <bits/stdc++.h>
using namespace std;

class login_sys{
    
    string user_name;
    
    bool validation(string given_id, string given_passcode){
        
        string read_id, read_passcode;
        
        ifstream read("data\\" + user_name + ".txt");
        
        getline(read, read_id);
        getline(read, read_passcode);
        
        if(read_id == given_id && read_passcode == given_passcode){
            return true;
        }
        
        else{
            return false;
        }
    }
    
    public:
    
    void start(int &option){
        
        if(option == 1){
            
            string user_id, passcode;
            
            cout<<"Enter a username: ";
            cin>>user_id;
            
            cout<<"Enter a password: ";
            cin>>passcode;
            
            cout<<endl;
            
            ofstream input;
            input.open("data\\" + user_name + ".txt");
            
            input << user_id << endl << passcode;
            
            input.close();
        }
        
        if(option == 2){
            
            string input_id, input_passcode;
            
            cout<<"Enter the user id to log in: ";
            cin>>input_id;
            
            cout<<"Enter the password to log in: ";
            cin>>input_passcode;
            
            bool validator_var = validation(input_id, input_passcode);
            
            if(validator_var){
                cout<<endl<<"Succesfully logged in !!"<<endl<<endl;
            }
            
            else if(validator_var == false){
                cout<<endl<<"Error!!"<<endl<<endl;
            }
        }
    }
};

int main() {
    // insert code here...
    
    int option;
    
    cout<<"1 : for registraion \n2 : for log in \nEnter your option: ";
    cin>>option;
    cout<<endl;
    
    login_sys ls;
    
    ls.start(option);
    main();
    
    return 0;
}
