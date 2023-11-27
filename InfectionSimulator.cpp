#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <windows.h>


using namespace std;
//                         Struct for Person
struct Person 
{
    int id;
    int x;
    int y;
    bool infected;
};
void Make_Person(Person Str_Person[], int Arr_size);
void Infected_Sim(Person Str_Person[], int Arr_size, int day);

int main() 
{
	//                        Some Varibales used
	int Total_Person=100;
	Person P_100[Total_Person];
	int Num_Day=0;
	
	while (true) 
	{
		//                        Display Menu
        cout << "\nWelcome" << endl;
        cout << "-----------" << endl;
        cout << "Menu:" << endl;
        cout << "1. Run simulation" << endl;
        cout << "2. Exit program" << endl;
		//                        Enter an
        int an;
        cout << "Please enter your choice (1-2): ";
        cin >> an;
        
        if (an < 1 || an > 2 ){
				cout << "Not a Valid Option. TRY AGAIN"<<endl;
				
				return 1;}
				
				
        	while(cin.fail() ){
			cin.clear();
			string not_an_int;
			cin >> not_an_int;
			cout << "Please enter your choice (1-2): ";
			cin >> an;
		}
		//                        Menu Selection
		if(an==1)
        {
        	Make_Person(P_100, Total_Person);
        	cout<<"Please enter the number of Days to run Simulation:";
            cin>>Num_Day;
            
            	while(cin.fail() ){
			cin.clear();
			string not_an_int;
			cin >> not_an_int;
			cout << "Please enter the number of Days to run Simulation:";
			cin >> Num_Day;
		}
			if (Num_Day < 0){
				cout << "Number of days cannot be in negative. TRY AGAIN"<<endl;
				
				return 1;
			}
			
            Infected_Sim(P_100, Total_Person, Num_Day);
		}
		else
		{
			cout << "Exit...Thank You" << endl;
            exit(0);
		}
                
    }
    system("PAUSE");
	return 0;
}

//                        This functions creates a random number between 0, 1 and -1
int getRandomNumber() 
{
    int randomValue = rand() % 3; //                                                                         Generate a random value between 0 and 2
    return randomValue - 1;
}

void Make_Person(Person Str_Person[], int Arr_size)
//                        This function is to create 100 persons and assign them random possitions and at most 10% will be affected 
{
	int temp_count=0;
	for (int i = 0; i < Arr_size; ++i) 
	{
        int x = rand() % 201 - 100; //                                                 Random x-coordinate [-100, 100]
        int y = rand() % 201 - 100; //                         Random y-coordinate [-100, 100]
        bool isInfected = (temp_count < 10) && (rand() % 10 == 0); //                         10% chance of being infected
        isInfected = (temp_count < 10) && (rand() % 10 == 0);
        isInfected = (temp_count < 10) && (rand() % 10 == 0);
        isInfected = (temp_count < 10) && (rand() % 10 == 0);
        //                        Setting attributes
        Str_Person[i].id = i + 1;
        Str_Person[i].x = x;
        Str_Person[i].y = y;
        Str_Person[i].infected = isInfected;
        if (isInfected) 
		{
            temp_count++; //                         Increment the infected temp_count if we assign an infection
        }
    }
    cout<<"Total Infected: "<<temp_count<<endl;//                        Display total affected
}
void Infected_Sim(Person Str_Person[], int Arr_size, int day)
{
	//                        Declare Variables
	int temp_count;
	float root= sqrt(2);
	float distance=0;
	//                        Loop to simulate the days entered by user
	for(int i=0; i<day; i++)
	{
		temp_count=0; 
		//                        Loop to visit each Person and check distance and see if they will be infected or not
		for(int j=0;j<Arr_size;j++)
		{
			int move=getRandomNumber();
			Str_Person[j].x=Str_Person[j].x+move;
			move=getRandomNumber();
			Str_Person[j].y=Str_Person[j].y+move;
			for(int k=0;k<Arr_size;k++)
			{
				if(Str_Person[j].id==Str_Person[k].id)
				{
					
				}
				else
				{
					if(Str_Person[j].infected||Str_Person[k].infected)
					{
						int dx = Str_Person[k].x - Str_Person[j].x;
					    int dy = Str_Person[k].y - Str_Person[j].y;
					    distance =sqrt((dx * dx) + (dy * dy));
						if(distance<=root)
						{
							bool isInfected = (rand() % 10) < 9;
							if(isInfected&&Str_Person[j].infected==false)
							{
								//                        Infects at a probability of 90% if one person is infected and in close range
								Str_Person[j].infected=true;
							}
						}
					}
				}
			}
			//                        Keeping count of new infected people
			if(Str_Person[j].infected)
			{
				temp_count++;
			}
		}	
		cout<<"On Day Number: "<<i+1<<endl;
		cout<<temp_count<<"/100 people infected"<<endl;
			//                        Nested loop to print the graph with automatic simulation
			for(int k=-101;k<=100;k++)
			{
				cout<<" ";
				for(int l=-100;l<=100;l++)
				{
					
					bool space=false;
					//                        Check to print x for infected o for non infected and space if person not at coordinates
					for(int j=0;j<Arr_size;j++)
					{
						if(Str_Person[j].x==k&&Str_Person[j].y==l)
						{
							if(Str_Person[j].infected)
							{
								cout<<"x";
							}
							else
							{
								cout<<"o";
							}
						}
						else
						{
							space=true;
						}
					}
					if(space)
					{
						cout<<" ";
					}
				}
				cout<<endl;
			}
			 
			Sleep(2500); // makes the program delay for 2 seconds before clearing the console
			system("cls");//                        To clear the console
	}
	cout<<"On Day Number: "<<day<<endl;
	cout<<temp_count<<"/100 people infected"<<endl;
}

