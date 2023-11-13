#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
using namespace std;

bool round_1(int A, int B, int answer, int key){
	//generate sign
	srand(time(0));
	int signcode;
	signcode = 1 + rand() % (2-1+1);
	
	//print questions, answers, key
	if (signcode == 1){
		key = A + B;
		cout << A << " + " << B << " = ";
		cin>>answer;
	} else if (signcode == 2){
		key = A - B;
		cout << A << " - " << B << " = ";
		cin>>answer;
	}
	//correcting
	if (answer == key){
		return true;
	} else if (answer != key){
		return false;
	}
}

bool round_2(int A, int B, int C, int answer, int key){
	//generate sign
	srand(time(0));
	int signcode1, signcode2;
	signcode1 = 1 + rand() % (2-1+1);
	signcode2 = 1 + rand() % (2-1+1);
	
	//print questions, input answers, key
	if (signcode1 == 1 && signcode2 == 1){
		key = A + B + C;
		cout << A << " + " << B << " + " << C << " = ";
		cin>>answer;
	} else if (signcode1 == 1 && signcode2 == 2){
		key = A + B - C;
		cout << A << " + " << B << " - " << C << " = ";
		cin>>answer;
	} else if (signcode1 == 2 && signcode2 == 1){
		key = A - B + C;
		cout << A << " - " << B << " + " << C << " = ";
		cin>>answer;
	} else {
		key = A - B - C;
		cout << A << " - " << B << " - " << C << " = ";
		cin>>answer;
	}
	//correcting
	if (answer == key){
		return true;
	} else if (answer != key){
		return false;
	}
}

bool round_3(int A, int B, int C, int answer, int key){
	//generate sign
	srand(time(0));
	int signcode;
	signcode = 1 + rand() % (2-1+1);
	
	//print questions, answers, key
	if (signcode == 1){
		key = A * B + C;
		cout << A << " x " << B << " + " << C<< " = ";
		cin>>answer;
	} else if (signcode == 2){
		key = A * B - C;
		cout << A << " x " << B << " - " << C << " = ";
		cin>>answer;
	}
	//correcting
	if (answer == key){
		return true;
	} else if (answer != key){
		return false;
	}
}

void border(){
	cout<<"\n====================\n";
}

int data_calculation(float total_correct, int total_incorrect, float round_correct[]){
	//display score per round
	float round_score[3];
	for (int i = 0; i<3; i++){
		round_score[i] = (round_correct[i]/15)*100;
		cout<<"round "<<i+1<<" score : "<<round_score[i]<<endl;
	}
	//display total correct and incorrect
	cout<<"Total correct : "<<total_correct<<endl;
	cout<<"Total incorrect : "<<total_incorrect<<endl;
	//total score
	float score = (total_correct/45)*100;
	cout<<"Total score : "<<score<<endl;
}

void main_menu(){
	cout<<"MATH TEST";
	border();
	cout<<"There will be 3 segments with different difficulty. Do your best and enjoyy :D\n";
}

int main(){
	//declarations
	char start;
	char next;
	float total_correct = 0;
	int total_incorrect = 0;
	int correct, incorrect;
	int A, B, C, answer, key;
	float round_correct[3];
	
	//main menu
	main_menu();
	cout << "\nstart test? (y/n)\n";
	cin>>start;
	
	//round 1
	system("cls");
	cout<<"round 1\n";
		correct = 0;
		incorrect = 0;
		for (int i = 1; i<=15; i++){
			cout<<i<<". ";
			A = 1 + rand() % 100;
			B = 1 + rand() % 100;
			if (round_1(A, B, answer, key) == true){
				correct++;
			} else {
				incorrect++;
			}
		}
	border();
	cout<<"round 1 report\n";	
	cout<<"correct : "<<correct<<endl;
	cout<<"incorrect : "<<incorrect<<endl;
	round_correct[0] = correct;
	total_correct += correct;
	total_incorrect += incorrect;
	cout<<"press any key to continue";
	cin>>next;
	system("cls");
	
	//round 2
	cout<<"start round 2? ";
	cin>>start;
	system("cls");
	cout<<"round 2\n";
		correct = 0;
		incorrect = 0;
		for (int i = 1; i<=15; i++){
			cout<<i<<". ";
			A = 1 + rand() % 100;
			B = 1 + rand() % 100;
			C = 1 + rand() % 100;
			if (round_2(A, B, C, answer, key) == true){
				correct++;
			} else {
				incorrect++;
			}
		}
		border();
		cout<<"round 2 report\n";
		cout<<"correct : "<<correct<<endl;
		cout<<"incorrect : "<<incorrect<<endl;
	round_correct[1] = correct;
	total_correct += correct;
	total_incorrect += incorrect;
	cout<<"press any key to continue";
	cin>>next;
	system("cls");
	
	//round 3
	cout<<"start round 3?";
	cin>>start;
	system("cls");
	cout<<"round 3\n";
		correct = 0;
		incorrect = 0;
		for (int i = 1; i<=15; i++){
			cout<<i<<". ";
			A = 1 + rand() % 20;
			B = 1 + rand() % 10;
			C = 1 + rand() % 100;
			if (round_3(A, B, C, answer, key) == true){
				correct++;
			} else {
				incorrect++;
			}
		}
		border();
		cout<<"round 3 report\n";
		cout<<"correct : "<<correct<<endl;
		cout<<"incorrect : "<<incorrect<<endl;
		cout<<"press any key to continue";
		cin>>next;
		system("cls");
	total_correct += correct;
	total_incorrect += incorrect;
	round_correct[2] = correct;
	
	//final report
	cout<<"Test Report"; border();
	data_calculation(total_correct, total_incorrect, round_correct);
}
