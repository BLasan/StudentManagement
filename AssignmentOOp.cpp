#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>
using namespace std;
const int MAXSUBJECTS=10;
const int MAXSTUDENT=100;
int open=0;         
struct node{
	int id;
	char grade;
	int mark;
	struct node *next;
};             
struct node *noder,*start,*prev,*traverse,*traverse1;             
class Record{
    ofstream text1;
	int k;
	string temp[300];                                    //sting array to store
	public:
		void DisplaySub(string s);
		void DisplayStu(long int num);
		void DisplaySubSum(string s);
		void SaveSum();
		void Exit(int);
		void viewFile();
		Record();
		~Record(){}
};

Record::Record(){
int size=0;
string str;
 ifstream text;
 string temp1;
 text.open("Assignment.txt",ios::in);                    //give the path of the text file
 
 if(text){                                                                  //if file open
 	while(!text.eof()){
 	getline(text,str);                                                       //get line by line to a string
    stringstream ss(str);
    while(getline(ss,temp1,' '))                                              //split from the space
    temp[size++]=temp1;                        //put into the string array
}
 text.close();
 this->k=size;
 }
 else
  cout<<"Error"<<endl;                          //if not opened
  if(k>2*(MAXSUBJECTS+MAXSTUDENT))                                    //if the text file exceeded the maximum terminate the process
  throw "Exceeded";
}

void Record::DisplayStu(long int num){
	int i,count=0,mark;
	char grade;
	string num1;
	stringstream ss;            
	ss<<num;                                        //convert int to string
	num1=ss.str();                                  //get the converted string to a string
	cout<<"Admission No:"<<num1<<endl;
	cout<<"Subject\t"<<"Marks\t"<<"Grade"<<endl;
	cout<<"---------------------"<<endl;
	for(i=0;i<k;i++){
		if(temp[i]=="SCS1201"||temp[i]=="SCS1202"||temp[i]=="SCS1203")
		count++;
		if(temp[i]==num1){                                                     //if the string equals to the student number
			stringstream g(temp[i+1]);                                       //get the next elemnt which is equal to the mark
			g>>mark;
			
			if(mark<30)                                             //find the grades
			grade='F';
			else if(mark>=30&&mark<40)
			grade='D';
			else if(mark>=40&&mark<55)
			grade='C';
			else if(mark>=55&&mark<70)
			grade='B';
			else if(mark>=70)
			grade='A';
			
			switch(count){                                                     //display the marks for subjects
				case 1:
					cout<<"SCS1201\t"<<mark<<"\t"<<grade<<endl;                    
					break;
				
				case 2:
					cout<<"SCS1202\t"<<mark<<"\t"<<grade<<endl;
					break;
					
				case 3:
					cout<<"SCS1203\t"<<mark<<"\t"<<grade<<endl;
					break;
			}
		}
      
     
	}
	if(count==0)
		cout<<"Invalid admission number"<<endl;	                             //if enters an invalid number
}

void Record::DisplaySub(string s){
	transform(s.begin(),s.end(),s.begin(),::toupper);                           //convert to uppercase
	int i,no,j,mark,flag=0,tempvar,temp_mark,temp_marks;
	start=NULL;
	char grade,tempchar;
	for(i=0;i<k;i++){
		
		if(temp[i]==s){                                                                 //when found the subject
			flag=1;
			cout<<"Student\t  \t"<<"   "<<"   "<<"Mark\t\t"<<""<<"Grade"<<endl;
			stringstream g(temp[i+1]);
			g>>no;                                                               //get number of students
			j=i+2;                                                               //points to the student
			while(no){
			i=i+2;
		    stringstream m(temp[j+1]);                                //get marks
			m>>mark;
			if(mark<30)
			grade='F';
			else if(mark>=30&&mark<40)
			grade='D';
			else if(mark>=40&&mark<55)
			grade='C';
			else if(mark>=55&&mark<70)
			grade='B';
			else if(mark>=70)
			grade='A';
			stringstream h(temp[i]);
			h>>temp_mark;        
			    noder=new struct node();         //create a link list of studentId and marks
			    noder->grade=grade;
			    noder->id=temp_mark;
			    noder->mark=mark;
			    if(start==NULL)
			    start=noder;
			    else{
			    	prev->next=noder;
				}
			    noder->next=NULL;
			    prev=noder;
				j=j+2;
				no--;
			}
			break;
		}
	}
	traverse=start;    
while(traverse!= NULL)                               //sorting
    {
        traverse1=traverse; 
        while (traverse1->next!=NULL)//travel till the second last element 
        {
           if(traverse1->id > traverse1->next->id)// compare the data of the nodes 
            {
              tempvar = traverse1->id;
              tempchar=traverse1->grade;
              temp_marks=traverse->mark;
              traverse1->id = traverse1->next->id;// swap the data
              traverse1->grade=traverse1->next->grade;
              traverse1->mark=traverse1->next->mark;
              traverse1->next->id = tempvar;
              traverse1->next->grade = tempchar;
              traverse1->next->mark= temp_marks;
              
            }
         traverse1= traverse1->next;    // move to the next element 
        }
        traverse=traverse->next;    // move to the next node
    }
	traverse=start;
	while(traverse!=NULL){
		cout<<traverse->id<<"\t \t"<<traverse->mark<<"\t \t"<<traverse->grade<<endl;
		traverse=traverse->next;
	}
	
	if(!flag)
	cout<<"Invalid subject code"<<endl;                                            //invalid code
	traverse=start;
	while (traverse)
    {
        struct node* old =traverse;
        traverse=traverse->next;
        delete old;
    }
}

void Record::DisplaySubSum(string s){
	 transform(s.begin(),s.end(),s.begin(),::toupper);              
	 int count1=0,count2=0,count3=0,count4=0,count5=0,sum=0,temp1,i,no,j,mark,flag,ty=0;
	 int *maks;
	 maks=new int[60];                    //store marks
	 char grade;
	 float avg=0.0,dev=0.0;
		for(i=0;i<k;i++){
		
		if(temp[i]==s){
	        flag=1;
			stringstream g(temp[i+1]);
			g>>no;
			j=i+2;
			temp1=no;                                    //get no of students
			while(no){
			stringstream m(temp[j+1]);                  //get marks
			m>>mark;
			maks[ty++]=mark;                       //store marks
			sum+=mark;
			if(mark<30){
				count1++;                             //count no of students for relevant grades
				grade='F';
			}
			
			else if(mark>=30&&mark<40){
				count2++;
				grade='D';
			}
		
			else if(mark>=40&&mark<55){
				count3++;
				grade='C';
			}
			
			else if(mark>=55&&mark<70){
				count4++;
				grade='B';
			}
			
			else if(mark>=70){
				count5++;
				grade='A';
			}
			
				j=j+2;
				no--;
			}
			
			avg=(float)sum/temp1;                                 //calculate average
			for(j=0;j<ty;j++){
				
			dev+=(float)(maks[j]-avg)*(maks[j]-avg);                      
			}
			cout<<dev<<endl;
			float dev1=(float)dev/temp1;                          
			dev1=pow(dev1,0.5);                                   //standard deviation
			stringstream dvv; 
			dvv<<dev1;
			string devv=dvv.str();
			devv="Standard deviation:"+devv;
			cout<<"Average:"<<avg<<endl;
			cout<<devv<<endl;
			cout<<"Grades"<<endl;
			cout<<"A-"<<count5<<endl;
			cout<<"B-"<<count4<<endl;
			cout<<"C-"<<count3<<endl;
			cout<<"D-"<<count2<<endl;
			cout<<"F-"<<count1<<endl;
			break;
		}
		
		else
		flag=0;
	}
	
	if(flag==0)
	cout<<"Invalid subject code"<<endl;	
	delete[] maks;                                   //remove dynamically allocated space
}

void Record::SaveSum(){
	    int j;
	    text1.open("Assignment2.txt",ios::out|ios::app|ios::in);         //open another file
	    int count1=0,count2=0,count3=0,count4=0,count5=0,i,no,temp1,mark,sum=0;
	    char grade;
	    float avg=0.0;
		for(i=0;i<k;i++){
		    count1=count2=count3=count4=count5=sum=0;
		if(temp[i]=="SCS1201"||temp[i]=="SCS1202"||temp[i]=="SCS1203"){                //calculate the given data and save into a file
			
		    string sub=temp[i];
			stringstream g(temp[i+1]);
			g>>no;
		
			j=i+2;
			temp1=no;
			while(no!=0){
			stringstream m(temp[j+1]);
			m>>mark;
			sum+=mark;
			if(mark<30){
				count1++;
				grade='F';
			}
			
			else if(mark>=30&&mark<40){
				count2++;
				grade='D';
			}
		
			else if(mark>=40&&mark<55){
				count3++;
				grade='C';
			}
			
			else if(mark>=55&&mark<70){
				count4++;
				grade='B';
			}
			
			else if(mark>=70){
				count5++;
				grade='A';
			}
			
				j=j+2;
				no--;
			}
			avg=(float)sum/temp1;
			stringstream ss;
			ss<<((float)count5/temp1)*100;
			string a=ss.str();
			a="A-"+a+"%";
			stringstream kk;
			kk<<((float)count4/temp1)*100;
			string b=kk.str();
			b="B-"+b+"%";
			stringstream mm;
			mm<<((float)count3/temp1)*100;
			string c=mm.str();
			c="C-"+c+"%";
			stringstream nn;
			nn<<((float)count2/temp1)*100;
			string d=nn.str();
			d="D-"+d+"%";
			stringstream oo;
			oo<<((float)count1/temp1)*100;
			string f=oo.str();
			f="F-"+f+"%";
			stringstream av;
			av<<avg;
			string p="Average:"+av.str()+" => ";
			string ori=sub+" "+p+" "+a+" "+b+" "+c+" "+d+" "+f+" ";
			text1<<ori<<endl;                                              //writes to the file
		
		}
	}	
	cout<<"Saved changes"<<endl;
	cout<<"Content"<<endl;
	cout<<"========================================================================"<<endl;
	viewFile();                                                                                  //view the file
	text1.close();
}

void Record::Exit(int open){
	if(open)                                                                                  //if the second file open
	if( remove( "Assignment2.txt" ) != 0 )                    //delete the file
    perror( "Error deleting file" );
    else
    puts( "File successfully deleted" );
    
    cout<<"Terminated"<<endl;
	exit(1);

  
}

void Record::viewFile(){
	string view;
	ifstream text;
	text.open("Assignment2.txt",ios::in);
	if(text){
		
		while(!text.eof()){                                     //iterate and print the file
			
			getline(text,view);
			cout<<view<<endl;
		}
	}
	
	text.close();
}
int main(){
 try{
 	Record r;
 int i=1;
 string s;
 long int no;
 cout<<"1.Display Subject"<<endl;
 cout<<"2.Display Student"<<endl;
 cout<<"3.Display Subject Summary"<<endl;
 cout<<"4.Save Summaries"<<endl;
 cout<<"5.Exit"<<endl;
 while(i){
 	cout<<"Enter the choice"<<endl;
    int choice;
    cin>>choice;
    if(cin.fail()){
    std::cin.clear();
    std::cin.ignore(numeric_limits<streamsize>::max(),'\n');
    std::cout << "Bad entry.Enter a NUMBER: "<<endl;
	}
 	switch(choice){
 		
 		case 1:
 		
 			cout<<"Enter subject code"<<endl;
 			cin>>s;
 			if(cin.fail()){
            std::cin.clear();
            std::cin.ignore(numeric_limits<streamsize>::max(),'\n');
            std::cout << "Invalid entry.Enter the subject code"<<endl;
	        }
 			else
 			r.DisplaySub(s);
 			break;
 			
 		case 2:
 			cout<<"Enter the student number"<<endl;
 			cin>>no;
 			if(cin.fail()){
            std::cin.clear();
            std::cin.ignore(numeric_limits<streamsize>::max(),'\n');
            std::cout << "Invalid entry.Enter the student code"<<endl;
            }
 			else
 			r.DisplayStu(no);
 			break;
 			
 		case 3:
 			cout<<"Enter the subject code"<<endl;
 			cin>>s;
 			if(cin.fail()){
            std::cin.clear();
            std::cin.ignore(numeric_limits<streamsize>::max(),'\n');
            std::cout << "Invalid entry.Enter the subject code"<<endl;
            }
 			else
 			r.DisplaySubSum(s);
 			break;
 			
 		case 4:
 			open=1;
 			cout<<"Summary"<<endl;
 			r.SaveSum();
 			break;
 			
 		case 5:
 			r.Exit(open);
 			i=0;
 			break;
	 }
}
}
catch(...){
	cout<<"Program terminated"<<endl;
	cout<<"Exceeded the maximum"<<endl;
}
}

 

