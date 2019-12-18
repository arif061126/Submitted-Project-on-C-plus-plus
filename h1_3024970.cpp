/*
Task: H1
Family Name: AHMED
Given Name: Arif
Matriculation number: 3024970
Uni-Email: arif.ahmed@stud.uni-due.de
Course of Studies: ISE CE
*/

#include<iostream>
#include<string>
using namespace std;

int n,c, i=0, j=0, k=0;

//task-1
struct Team{
    string teamName;
    int points;
    int matches;
};

//task-2
void initialArray(struct Team teams[], int teamNumber){
    for( i=0; i<teamNumber; i++){
        cout<<"team "<<i+1<<":";
        cin >> teams[i].teamName;
        teams[i].points = 0;
        teams[i].matches = 0;
    }
}

//task-3
void outputgameTable(struct Team teams[], int teamNumber){
    for (i = 0; i<teamNumber; i++){
        cout<<"   "<<teams[i].points <<"\t     "<< teams[i].matches<<"\t\t"<<teams[i].teamName<<"\n"<<endl;
            cout<<"----------------------------------"<<"\n"<<endl;
    }
}

//task-4
int choosingTeam(struct Team teams[], int teamNumber){
    for( i=0; i<teamNumber;i++){
        cout<<i+1<<"\t"<<teams[i].teamName<<endl;
        }
    cout<<"\n"<<"choose team by number: ";
    cin>>c;
    return c-1;
}

//task-5
void storeGamePoints(struct Team teams[], int teamNumber, int index[], int numberPoints[]){
    int temp;

    teams[index[0]].matches+=1;
    teams[index[1]].matches+=1;
    teams[index[0]].points+=numberPoints[0];
    teams[index[1]].points+=numberPoints[1];

    for(i=0;i<teamNumber-1;i++){
            for(j=i+1;j<teamNumber;j++){
                if(teams[i].points<teams[j].points){
                    Team temp=teams[i];
                    teams[i]=teams[j];
                    teams[j]=temp;
                }
            }
    }
    for (i=0; i<teamNumber; i++){
        cout<<"   "<<teams[i].points <<"\t     "<< teams[i].matches<<"\t\t"<<teams[i].teamName<<"\n"<<endl;
            cout<<"----------------------------------"<<"\n"<<endl;
    }
}

//task-6:

void resetGameTable(struct Team teams[], int teamNumber){
    cout<<"\n"<<"Initial Ranking:"<<endl;
    cout<<"================"<<endl;
    cout<<"points"<<"\t"<<"done matches"<<"\t"<<"Team Name"<<endl;
    cout<<"----------------------------------"<<endl;

    for (i = 0; i<teamNumber; i++){
            teams[i].points = 0;
            teams[i].matches = 0;
            cout<<"   "<<teams[i].points <<"\t     "<< teams[i].matches<<"\t\t"<<teams[i].teamName<<"\n"<<endl;
            cout<<"----------------------------------"<<"\n"<<endl;
    }
}

//task-7:

int main(){
    int no, ch, p[2], choice;
    int in[2];

    cout<<"number of teams: ";
    cin >> no;
    cout<<"\n";
    cout<<"input of teams"<<endl;
    cout<<"============"<<endl;
    struct Team t[no];
    initialArray(t,no);
    cout<<"\n"<<"Initial Ranking"<<endl;
    cout<<"==============="<<endl;
    cout<<"points"<<"\t"<<"done matches"<<"\t"<<"Team Name"<<endl;
    cout<<"----------------------------------"<<endl;
    outputgameTable(t,no);
    do{
            cout<<"0 end"<<endl;
            cout<<"1 add result of a match"<<endl;
            cout<<"2 show ranking"<<endl;
            cout<<"9 reset points"<<endl;
            cout<<"\n"<<"Your choice: ";
            cin>>ch;

            switch (ch){
                case 0: break;
                case 1:
                    for(j=0;j<2;j++){
                        cout<<"\n"<<"Please choose team " <<j+1<<"?"<<endl;
                        cout<<"\n"<<"teams"<<endl;
                        cout<<"====="<<endl;
                        in[j]=choosingTeam(t,no);
                    }
                    if(in[0]==in[1]){
                        cout<<"\n"<<"*** sorry teams need to be different ***"<<"\n\n"<<endl;
                    }
                    else{
                        cout<<"\n"<<"input as [points of "<<t[in[0]].teamName<<"] : [points of "<<t[in[1]].teamName<<"]? ";
                        cin>>p[0];
                        cout<<" : ";
                        cin>>p[1];
                        cout<<"\n"<<endl;
                    }
                    break;
                case 2:
                    cout<<"\n"<<"Rankings:"<<endl;
                    cout<<"=========="<<endl;
                    cout<<"points"<<"\t"<<"done matches"<<"\t"<<"Team Name"<<endl;
                    cout<<"----------------------------------"<<endl;
                    storeGamePoints(t, no, in, p);
                    break;
            case 9: resetGameTable(t,no); break;
            default: cout<<"\n"<<"Please enter the right number!!!!!!"<<"\n\n"<<endl;
        }
    }while(ch!=0);

    return 0;
}
