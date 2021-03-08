#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void Menu();
void Save();
void View();
void Search();
void Delete();
char info[50];
class user{
	public :
		char name [20];
		char phone [20];
}
user;
FILE *contacts;
FILE *change;
void Menu(){
	printf("\n\n\t ----------------------------------------\n");
	printf("\t -	1	: View Contacts		-\n\n");
	printf("\t -	2	: Creat a New Contact	-\n\n");
	printf("\t -	3	: Search In Contacts  	-\n\n");
	printf("\t -	4	: Delete a Contact	-\n\n");
	printf("\t -	5	: Exit			-\n");
	printf("\t ----------------------------------------\n");
}
int main(){
	int choice=0;
	system("cls");
	system("color 90");
	Menu();
	printf("\n Choose a Number : ");
	fflush(stdin);
	scanf("%i",&choice);
	switch (choice){
		case 1:{
			system("cls");
			View();
			break;
		}
		case 2:{
			system("cls");
			Save();
			break;
		}
		case 3:{	
			system("cls");
			Search();
			break;
		}
		case 4:{
			system("cls");
			Delete();
			break;
		}
		case 5:{
			system("cls");
			break;
		}
		default:{
			system("color c0");
			printf("\n Enter a Correct Number\n"); 
			system("pause");
			main();
		}
	}
return 0;
}
void View(){
	if((contacts=fopen("contacts.txt","r"))==NULL){
		system("color c0");
		printf("\n NO Contacts Imported Yet !\n\n");
		fclose(contacts);
	}
	else {
		while(true){
			fgets(info,70,contacts);
			if (feof(contacts)) {
				break;
			}
			printf("\n %s\n",info);
		}
	}
	fclose(contacts);
	system("pause");
	main();
}
void Save(){
	char choice2; 
    while (true){
		system("color 90");
		contacts = fopen("contacts.txt","a+");
		printf("\n Enter Name (Without Space) :\n");
		fflush(stdin);
		scanf("%s",user.name);
		printf("\n Enter Phone Number :\n");
		fflush(stdin);
		scanf("%s",user.phone);
		fprintf(contacts,"%s %s \n",user.name,user.phone);
		fclose(contacts);
		system("color 20");
		printf("\n Saved Successfully !");
		printf("\n Would You Like To Continue? Y/N ");
		fflush(stdin);
		scanf("%c",&choice2);
		if (choice2=='n'||choice2=='N'){
			break;
		}
		else if (choice2=='y'||choice2=='Y'){
			continue;
		}
	}
	main();
}
void Search(){
    char input[20];
	int Found = 0;
	if((contacts=fopen("contacts.txt","r"))==NULL){
		system("color c0");
		printf("\n NO Contacts Imported Yet !\n\n");
		fclose(contacts);
	}
	else{
		printf("\n Enter Name To Search : \n");
		fflush(stdin);
		scanf(" %s",input);
		while(!feof(contacts)&& Found==0){
			fscanf(contacts,"%s %s",user.name,user.phone);
			if(strcmp(input,user.name)==0){
				Found = 1;
				break;
			}
		}
		if (Found){
			system("color 20");
			printf("\n Name: %s \n",user.name);
			printf("\n Phone Number: %s \n",user.phone);
		}
		else {
			system("color c0");
			printf("\n Contact Not Found !\n\n");
		}
	}
	fclose(contacts);
	system("pause");
	main();
}
void Delete(){
	if((contacts=fopen("contacts.txt","r"))==NULL){
		system("color c0");
		printf("\n NO Contacts Imported Yet\n\n");
		fclose(contacts);
	}
	else {
		int Found = 0 ;
		char input[70];
		change=fopen("change.txt","w");
		printf("\n Enter Name To Delete : ");
		fflush(stdin);
		gets(input);
		while(true){
			fscanf(contacts,"%s %s",user.name,user.phone);
			if (feof(contacts)){
				break;
			}
			if(strcmp(input,user.name)!=0){
				fprintf(change,"%s %s\n",user.name,user.phone);
			}
			else {
				Found = 1;
			}
		}
		fclose(contacts);
		fclose(change);
		if (!Found){
			system("del change.txt");
			system("color c0");
			printf("\n Contact Not Found !\n");
		}
		else {
			system("del contacts.txt");
			system("rename change.txt contacts.txt");
			system("color 20");
			printf("\n Contact Deleted Successfully !\n");
		}
	}
	system("pause");
	main();
}