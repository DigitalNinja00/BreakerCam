#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<cstring>

using namespace std;

class Decores{
private:
	int var;
public:
	int print_banner(){
		system("cat banner.txt");
		return 0;
	}
	int lista(){
		string varca[] = {
			"{1} GoogleMeet",
			"{2} Microsoft Teams",
			"{3} Webex",
			"{4} Zoom",
			"{0} Exit"
		};
		size_t local = sizeof(varca)/sizeof(string);
		for(int x=0;x<local;x++){
			cout<<varca[x]<<endl;
		}
		return 0;
	}
};

void google_meet_web_server(){
	system("nohup php -S localhost:8080 -t web/gmeet/ > /dev/null 2>&1 &");
}
void microsoft_teams_server(){
	system("nohup php -S localhost:8080 -t web/mteams > /dev/null 2>&1 &");
}
void webex_server(){
	system("nohup php -S localhost:8080 -t web/webex > /dev/null 2>&1 &");
}
void zoom_server(){
	system("nohup php -S localhost:8080 -t web/webex > /dev/null 2>&1 &");
}
void default_(){
	cout<<"Server \\/"<<endl;
	cout<<"http://localhost:8080"<<endl;
}

int main(){
	Decores var; Decores* rar = &var;
	rar->print_banner();
	Decores ll; Decores* lol = &ll;
	lol->lista();
	int rio;
	int control = 1;
	while(control <= 10){
		cout<<"OPTION> ";cin>>rio;
		if(rio==0){
			return 0;
		}else{
			if(rio==1){
				google_meet_web_server();
				default_();
			}else{
				if(rio==2){
					microsoft_teams_server();
					default_();
				}else{
					if(rio==3){
						webex_server();
						default_();
					}else{
						if(rio==4){
							zoom_server();
							default_();
						}else{
							cout<<"Error!";
							return 0;
						}
					}
				}
			}
		}
	}
	system("pkill php");
	return 0;
}