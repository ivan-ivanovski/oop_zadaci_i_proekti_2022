#include<iostream> //basic input/ouput stream, using cin, cout etc
#include<cstring> // using function like strcmp to compare input dynamic char array with other string
#include<windows.h>//to set timer in miliseconds, then clear cmd window and display new 

using namespace std; // to escape std error
class User{
	
	char *userName;
	char *userPassword;
	public:
    //2in1 constructor
		User(char *userName="", char *userPassword=""){
			this->userName = new char[strlen(userName)+1];
			strcpy(this->userName, userName);
			this->userPassword = new char[strlen(userPassword)+1];
			strcpy(this->userPassword, userPassword);
		}
  //copy constructor
		User(const User& u){
			this->userName = new char[strlen(u.userName)+1];
			strcpy(this->userName, u.userName);
			this->userPassword = new char[strlen(u.userPassword)+1];
			strcpy(this->userPassword, u.userPassword);
		}
  //operator overloading =
		User &operator=(const User&u){
			if(this!=&u){
				delete[] userName;
				delete[] userPassword;
				this->userName = new char[strlen(u.userName)+1];
				strcpy(this->userName, u.userName);
				this->userPassword = new char[strlen(u.userPassword)+1];
				strcpy(this->userPassword, u.userPassword);
			}
			return *this;
		}
		///operator <<
		friend ostream& operator<<(ostream &o, const User&u){
			o<<u.userName<<endl;
			o<<u.userPassword<<endl;
			return o;
		}
		///operator >>
		friend istream& operator>>(istream &i, User &u){
			i>>u.userName>>u.userPassword;
			return i;
		}
    //get and set methodes
    void setUserName(char *userName = ""){
			this->userName = new char[strlen(userName)+1];
			strcpy(this->userName, userName);
		}
		const char *getUserName(){
			return userName;
		}	
		void setUserPass(char *userPassword = ""){
			this->userPassword = new char[strlen(userPassword)+1];
			strcpy(this->userPassword, userPassword);
		}
		const char *getPassword(){
			return userPassword;
		}	
};
int main(){
	User u; // define basic instance of object named u( user) of class User
	cout<<"Enter login information: "<<endl; 
	cin>>u;//input user, we wiil get error if we dont do overload of >>
	if(strcmp(u.getUserName(),"admin")!=0){
    //first comparing if input name of user is same as user admin name, in this case admin
		cout<<"Error\n";//get errror if not else continue 
	}
	else
	{
		if(strcmp(u.getPassword(), "addmin123@")!=0){ 
      //comparing password of user and admin password
      //get error if is not true else continue
			cout<<"Erorr\n";
		}
		else{
     ///if everythink is ok we get approve to new screen, but we need to wait 3s or 3ms
			cout<<"Approved\n";
			Sleep(3000);
			system("cls");///system cmd clear
			cout<<"Welcome\n";//display new message
		}
	}
	cout<<u.getUserName();//get user name in new cmd 
	return 0;
}
