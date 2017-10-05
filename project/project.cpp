#include <iostream>
#include <fstream>
#include<ctype.h>
#include<string>
#include<ctime>
#include<cstdlib>
using namespace std;
//function to read data from user
void data();
//function to write data on file
void write(string,string,int);
//function to read data of question,answer,help and choise
void read(string);
//function to show ask and choise
void show(string[],string[],int);
int main()
{
	system("color 0a");
	system("color 4a");
	

	
	data();//calling function data

    system("pause");
    return 0;
}
void data()
{
	/*some question to enter your name and your
	        country and your age*/
	string name,coun;
	int age;
	
	cout<<"\n\n\t\t\t      WELCOME TO QUESTION \n\n\n";
	cout<<"Enter Your Name : ";
	getline(cin,name);
	cout<<"\nEnter Your Country : ";
	getline(cin,coun);	
	cout<<"\nEnter Your Age : ";
	cin>>age;
	
		//calling for functin to write data in file
	    write(name,coun,age);
		
	
	
}
void write(string name,string coun,int age)
{
	ofstream out;
	
	out.open("data.txt",ios::app);
	
	//when the file not open
	if(!out)
	{
		cout<<"error\n";
	}
	//write some data on data file
	out<<"NAME    : "<<name<<endl;
	out<<"COUNTRY : "<<coun<<endl;
	out<<"AGE     : "<<age<<endl;
	out<<"__________________\n";
	

   
	//to clear the screen
	system("cls");
	cout<<"\n\n\t\t\t\t Hellow  "<<name;
	char ch;
	do
	{
	read(name);//calling function read
	cout<<"If You Need To Play Again Press Y or y: ";
	cin>>ch;
	system("cls");

	}while(ch=='Y'||ch=='y');
	out.close();
}
void read(string name)
{
	char ch,ch2;
	ofstream score; 
    ifstream input,input1,input2,choise,input3,input4,input5;
	string question[15],answer[15],help[15],cho[15],ans,help2[15];
	// t is true answer, h1 &h2 if acounter for number of help
    int i=0,f=0,k=0,p=0,h1=0,h2=0,z=0,l=0,c=0,o=0,scor;
	long t=0;
	input .open("ask.txt");
	choise.open("choise.txt");
    input2 .open ("answer.txt");
    input3 .open("help1.txt");
	input4 .open("help2.txt");
	input5 .open("ifwin.txt");

	score .open("score.txt",ios::app);
	cout<<"\n\n\t\t\t\t\t\t\t\t score : "<<t*1000;
	
	 while (!input.eof() && !input2.eof())
    {
		//to read question,choise,answer in array
        for(int j=0;j<15;j++)
        {
            getline(input,question[j]);
			getline(choise,cho[j]);
            getline(input2,answer[j]);

        }
	 }
	 
	 //to change random numb
     srand(time(0));
     //array of rondom nums
     int r[15];
	 //to save some random numb in array
     for(int b=0;b<15;b++)
     {
		r[b]=rand()%15;
     }
	 //to change random numb of are same numb
        for(int j=0;j<14;j++)
        {
			for(int n=(j+1);n<15;n++)
			{           
b:
				if(r[j]==r[n])
                {                
					r[n]=rand()%15;                
					goto b;
               }
            }
		}
			for(int j=0;j<10;j++)
            {      

				k=r[j];
		
				//calling to function show
				show(question,cho,k);
                

               
               // function of help

               //the switch for only help
				//___________________________________________________________________________
				if (h1==0||h2==0||c==0||o==0)
				{     cout<<"\t\t\t\t\t\t\t  ^^Help  Menu^^\n\n";
					if(h1==0)
					{
						
                        cout<<"\t\t\t\t\t\t   To delet one answer press <D> \n";
						
			        }

                    if(h2==0)
			        {
                        cout<<"\t\t\t\t\t\t   To replace questino press <R> \n";
				        
			        }
					if(o==0)
					{
						cout<<"\t\t\t\t\t\t   To people opinion press <P> \n";
					}
					if(c==0)
					{
						cout<<"\n\t\t\t\t\t\t   To quit press <Q> \n";
					}
c:					cout<<"Enter Your Answer: ";
                    cin>>ch2;
		
					switch(ch2)
                    {  
						
                        case 'D':
							{
								if(h1>0)
						
								{
									cout<<"\n\n\t\t\tYOU CAN,T USE THIS METHOD ): \n";
									goto c;
								}
								while (!input3.eof())
                               {
								   for (int i=0; i<15; i++)
                                   {
									   getline(input3,help[i]);

                                   }
                                
                                   cout<<"\n\n\n \t\t\t"<<help[k]<<endl;
                                   h1++;
                                   goto c;
								
                               }
								break;
                            }
						
						case 'R':
            
							{
								if(h2>0)
						
								{
									cout<<"\n\n\t\t\t YOU CAN,T USE THIS METHOD ): \n";
									goto c;
								}
                                j++;
                                h2++; 
                                goto m;
                                break;
                            }
						case 'P':
							{
								if(o>0)
						
								{
									cout<<"\n\n\t\t\tYOU CAN,T USE THIS METHOD ): \n";
									goto c;
								}
								while (!input4.eof())
                               {
								   for (int i=0; i<15; i++)
                                   {
									   getline(input4,help2[i]);

                                   }
                                
                                   cout<<"\n\n\n \t\t"<<help2[k]<<endl;
                                   o++;
                                   goto c;

                               }
								break;
							}
						case'Q':
							{
								system("cls");
								cout<<"\n\n\t\t\t\tYou Are Quit  ):  ";
								goto v;
								
							}
                        
                        default : 
							{
                                goto u;
                            }
					}

				}
m:

				
				
				
					k=r[j];
					cout<<"\n\n\n\t"<<question[k]<<endl;
			        cout<<"\n\n\n\t  "<<cho[k]<<"\n\n\n";
				    z++;
					h2++;
					goto c;
				
				//____________________________________________________________________________________

                
u:              
				system("cls");
				ans=ch2;
				if (ans== answer[k])
                { 
					 t++;
					cout<<"\n\n\t\t  <<**  :) Your Answer Is True :)  **>>"<<"\t\t score:"<<t*100000<<"\n\n";
					p++;
					
                }
                else
                {
                   cout<<"\n\n\t\t   <<**  :(Your Answer Is False :(  **>>\n\n";
				   cout<<"\n\n\t\t\t The True Answe Is             --> "<<answer[k];
		           goto v;
                 
                }
			if (p==10)
		    { 
			   goto v;
			  
		    }	
	}
			
		
		//____________________________________________________________________________
v:
		//to show us the score ,true answer and good luck statment
		
		
		cout<<"\n\n\t\t\t The Numb OF True Answer Is :) --> "<<t;
		scor=t*100000;
        cout<<"\n\n\t\t\t Your Score Is :)              --> "<<scor<<endl;
        cout<<"\n\n\t\t\t       ___Good luck ___ \n\n\n";
		if(scor==1000000)
					{ system("cls");
						cout<<"\n\n\n\n\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n " ;
						cout<<"\n\n\n\t\t\tCongratulation You Win The Million\n";
					      cout<<"\n\n\n\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * " ;
					}
		
		

	    
		input.close();    
        choise.close();
        input2.close();
		input4.close();
}	
void show(string question[],string cho[],int k)
{
	cout<<"\n\n\n\t"<<question[k]<<endl;
    cout<<"\n\n\n\t  "<<cho[k]<<"\n\n\n";
}









