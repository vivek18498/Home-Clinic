#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iomanip.h>
#include<iostream.h>
#include<ctype.h>
#include<dos.h>
#define clientfile"client4.txt"
#define recsize 100
#define max 15
fstream efile,sfile;
char buffer[80],c[20];
int count[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
class client
{
     public:
	      char user_id[5],user_name[15],gender[5],age[5];
	      char contact[12],weight[6],dtype[20];
	      void unpack();
	      void disp();
	      void initial();
	      void read();
	      int retrieve(int addr,char k[]);
	      void fever();
	      void diarrhea();
	      void flu();
	      void typhoid();
	      void asthama();
	      void diabetes();
	      void mumps();
	      void arthritis();
	      void measels();
	      void thyroid();
 };

void client::initial()
{
  int i,j,k;
  efile.open(clientfile,ios::in);
  if(!efile)
  {
     efile.open(clientfile,ios::out);
     if(!efile)
     {
      cout<<"unable to open the file";
      exit(1);
      }
    for(i=0;i<14;i++)
    {
     for(k=0;k<5;k++)
     {
	for(j=0;j<recsize-2;j++)
		efile<<"#";
	if(k!=4)
		efile<<"||";
     }
	efile<<endl;
   }
 cout<<"empty file created";
 }
 efile.close();
 return;
 }
void client::read()
{
label1: cout<<"Enter The user_ID:";     gets(user_id);

if(isdigit(user_id[0])&&isdigit(user_id[1])&&isdigit(user_id[2])&&strlen(user_id)==3)
 {
 cout<<"Enter user_Name:";           gets(user_name);
 cout<<"Enter gender:";      gets(gender);
 cout<<"Enter age:";      gets(age);
 cout<<"Enter Contact number:"; gets(contact);
 cout<<"Enter Weight:";  gets(weight);
 char m;
lab: cout<<"Select Whether you know:-\nA. Disease  \nB. Symptons\nEnter your choice\n"	;
 cin>>m;
 switch(m){

 case 'A'|'a':cout<<"\nEnter the Disease = ";
 cout<<"\n\t 1.Fever";
 cout<<"\n\t 2.Diarrhea";
 cout<<"\n\t 3.Flu";
 cout<<"\n\t 4.Typhoid";
 cout<<"\n\t 5.Asthama";
 cout<<"\n\t 6.Diabetes";
 cout<<"\n\t 7.Mumps";
 cout<<"\n\t 8.Measels";
 cout<<"\n\t 9.Arthritis";
 cout<<"\n\t 10.Thyroid";
   int ch;
   cout<<"\n\t Enter choice:\t ";
   cin>>ch;
   if(ch==1)
   {
	strcpy(dtype,"FEVER");
	fever();
   }
   else if(ch==2)
   {
	strcpy(dtype,"DIARRHEA");
	diarrhea();
   }
      else if(ch==3)
   {
	strcpy(dtype,"FLU");
	flu();
   }
      else if(ch==4)
   {
	strcpy(dtype,"TYPHOID");
	typhoid();
   }
   else if(ch==5)
   {
	strcpy(dtype,"ASTHAMA");
	asthama();
   }
      if(ch==6)
   {
	strcpy(dtype,"DIABETES");
	diabetes();
   }
   else if(ch==7)
   {
	strcpy(dtype,"MUMPS");
	mumps();
   }
      else if(ch==8)
   {
	strcpy(dtype,"MEASELS");
	measels();
   }
      else if(ch==9)
   {
	strcpy(dtype,"ARTHRITIS");
	arthritis();
   }
   else if(ch==10)
   {
	strcpy(dtype,"THYROID");
	thyroid();
   }
      else
   {
	cout<<"Disease Not in Database";
   }
   break;

 case 'B'|'b':  clrscr();
		 cout<<"\nSelect the symptons you are facing:-\n";
		int a[10];
		cout<<"Cough\tPress 1 for Yes or 0 for No\n";
		cin>>a[0];
		cout<<"Headache\tPress 1 for Yes or 0 for No\n";
		cin>>a[1];
		cout<<"BodyPain\tPress 1 for Yes or 0 for No\n";
		cin>>a[2];
		cout<<"Stomach Ache\tPress 1 for Yes or 0 for No\n";
		cin>>a[3];
		cout<<"Excess Body heat\tPress 1 for Yes or 0 for No\n";
		cin>>a[4];
		cout<<"Chest Pain\tPress 1 for Yes or 0 for No\n";
		cin>>a[5];
		cout<<"Sneezing\tPress 1 for Yes or 0 for No\n";
		cin>>a[6];
		cout<<"Swelling In Joints\tPress 1 for Yes or 0 for No\n";
		cin>>a[7];
		cout<<"Weakness & Dizzyness\tPress 1 for Yes or 0 for No\n";
		cin>>a[8];
		cout<<"White Spots on Skins\tPress 1 for Yes or 0 for No\n";
		cin>>a[9];
		if(a[0]==1 && a[2]==1 && a[4]==1) {
		strcpy(dtype,"FEVER");
		fever();
		}
		else if(a[3]==1 && a[8]==1){
		strcpy(dtype,"DIARRHEA");
		diarrhea();
		}
		else if(a[2]==1 && a[6]==1 && a[8]==1){
		strcpy(dtype,"FLU");
		flu();
		}
		else if(a[2]==1 && a[3]==1 && a[5]==1){
		strcpy(dtype,"TYPHOID");
		typhoid();
		}
		else if(a[0]==1 && a[5]==1 && a[6]==1){
		strcpy(dtype,"ASTHAMA");
		asthama();
		}
		else if(a[1]==1 && a[8]==1){
		strcpy(dtype,"DIABETES");
		diabetes();
		}
		else if(a[2]==1 && a[7]==1){
		strcpy(dtype,"MUMPS");
		mumps();
		}
		else if(a[4]==1 && a[9]==1){
		strcpy(dtype,"MEASELS");
		measels();
		}
		else if( a[2]==1 && a[7]==1) {
		strcpy(dtype,"ARTRITIS");
		arthritis();
		}
		else if( a[1]==1 && a[7]==1)  {
		strcpy(dtype,"THYROID");
		thyroid();
		}
	    break;


 default:   cout<<"\nInvalid selection.Please chosse either A or B";
    goto lab;

    }
 strcpy(buffer,user_id);             strcat(buffer,"|");
 strcat(buffer,user_name);           strcat(buffer,"|");
 strcat(buffer,gender);              strcat(buffer,"|");
 strcat(buffer,age);                 strcat(buffer,"|");
 strcat(buffer,contact);             strcat(buffer,"|");
 strcat(buffer,weight);              strcat(buffer,"|");
 strcat(buffer,dtype);               strcat(buffer,"|");
 return;
 }
 else
 {
    cout<<"INVALID user_ID \n";
    goto label1;

 }
}
int hash(char key[])
{
  int i=0,sum=0;
  while(key[i]!='\0')
  {
    sum=sum+(key[i]-48);
    i++;
    }
 return sum % max;
}
void store(int addr)
{
	char dummy[10];
	int flag=0,i,temp,temp1;
	efile.open(clientfile,ios::in|ios::out);
	if(count[addr]!=5)
	{
		efile.seekp(addr*recsize*5,ios::beg);
		count[addr]=count[addr]+1;
		efile.getline(dummy,5,'||');
		if(strcmp(dummy,"####")==0)
		{
			efile.seekp(addr*recsize*5,ios::beg);
			efile<<buffer;
			flag=1;
		}
		else
		{
			temp=(addr*recsize*5);
			temp=temp+100;
			while(temp<(addr*recsize*5)+500)
			{
				efile.seekp(temp,ios::beg);
				efile.getline(dummy,5,'||');
				if(strcmp(dummy,"####")==0)
				{
					efile.seekp(temp,ios::beg);
					efile<<buffer;
					flag=1;
					break;
				}
				temp=temp+100;
			}
		}

	}
	else
	{
		for(i=addr+1;i!=addr;i++)
		{
			if(i%max==0)
				i=0;
			if(count[i]!=5)
			{
				efile.seekp(i*recsize*5,ios::beg);
				count[i]=count[i]+1;
				cout<<count[i];
				efile.getline(dummy,5,'||');
				if(strcmp(dummy,"####")==0)
				{
					cout<<"\n collision has occured\n";
					cout<<"Home address is: "<<addr<<"Actual address is: "<<i<<"\n";
					efile.seekp(i*recsize*5,ios::beg);
					efile<<buffer;
					flag=1;
					break;
				}
				else
				{
					temp1=(i*recsize*5);
					temp1=temp1+100;
					while(temp1<(i*recsize*5)+500)
					{
						efile.seekp(temp1,ios::beg);
						efile.getline(dummy,5,'||');
						if(strcmp(dummy,"####")==0)
						{
							efile.seekp(temp1,ios::beg);
							efile<<buffer;
							flag=1;
							break;
						}
						temp1=temp1+100;
					}
				 }


			}
		 }
	}
	if((i==addr) && (!flag))
		cout<<"Hash file is full,record cannot be further inserted\n";
	efile.close();
	return;
}
void client::fever(){
	clrscr();
  lb: cout<<"What kind of treatment You Require For Fever\nSelect\nA - Home Remedy\nB - ALOPATHY\nC-HOMEOPATHY\nEnter Your Choice\n";
    char ch;
    cin>>ch;
    if(ch=='A'||ch=='a')
    {
     cout<<"Home Remedies for Fever:-\n";
    cout<<"* Drink plenty of fluids.\n* Take Rest.\n* Stay cool.\n\t\t\tTHANKS";
    }
    else if(ch=='B'||ch=='b')
    {  cout<<"Alopathic Medicine:-\n";
    cout<<"* Calpol 500 mg \n* Combiflam.\n Thanks";
    }
    else if(ch=='c'||ch=='C')
    {
	cout<<" Homeopathic Medicine:-\n";
	cout<< "* Belladonna \n*Gelsemium.\nThanks";
     }
    else
    {
    cout<<"Invalid Choice Select Again";
    goto lb;
    }
    getch();
}
void client::diarrhea(){
	clrscr();
       lb1: cout<<"What kind of treatment You Require For Diarrhea\nSelect\nA - Home Remedy\nB - ALOPATHY\nC-HOMEOPATHY\nEnter Your Choice\n";
    char ch;
    cin>>ch;
    if(ch=='A'||ch=='a')
    {
      cout<<"Home Remedies for Diarrhea:-\n";
    cout<<"* Drink Plenty of Fluids \n* Follow the BRAT(Banana,Rice,Apple,Toast) \n* Drink Chamomile Tea .\n Thanks";
    }
    else if(ch=='B'||ch=='b')
    {  cout<<"Alopathic Medicine:-\n";
    cout<<"* Loperamide \n* Imodium .\n Thanks";
    }
      else if(ch=='c'||ch=='C')
    {
	cout<<" Homeopathic Medicine:-\n";
	cout<<"* Bryonia \n* Arsenicum Album.\nThanks";
     }
    else
    {
    cout<<"Invalid Choice Select Again";
    goto lb1;
    }
    getch();
}
void client::flu(){
	clrscr();
      lb2: cout<<"What kind of treatment You Require For Flu\nSelect\nA - Home Remedy\nB - ALOPATHY\nC-HOMEOPATHY\nEnter Your Choice\n";
    char ch;
    cin>>ch;
    if(ch=='A'||ch=='a')
    {  cout<<"Home Remedies for Flu:-\n";
    cout<<"* Use Oregano Oil  \n* Use Olive Leaf Extract \n* Stay Hydrated .\n Thanks";
    }
    else if(ch=='B'||ch=='b')
    {
      cout<<"Alopathic Medicine:-\n";
    cout<<"* Decongestant \n* Analgesic .\n Thanks";
    }  else if(ch=='c'||ch=='C')
    {
	cout<<" Homeopathic Medicine:-\n";
	cout<<"*oscilloccinum\n*bryonia.\nThanks";
     }
    else
    {
    cout<<"Invalid Choice Select Again";
    goto lb2;
    }
    getch();
}
void client::typhoid(){
	clrscr();
      lb3: cout<<"What kind of treatment You Require For Typhoid\nSelect\nA - Home Remedy\nB - ALOPATHY\nC-HOMEOPATHY\nEnter Your Choice\n";
    char ch;
    cin>>ch;
    if(ch=='A'||ch=='a') {
    cout<<"Home Remedies for Typhoid:-\n";
    cout<<"* Maintain Hygiene .\n* Avoid contaminated water.\n* Choose Hot Food.\n\t\t\tTHANKS";
    }
    else if(ch=='B'||ch=='b'){
    cout<<"Alopathic Medicine:-\n";
    cout<<"* Antibiotics \n* Penicillin .\n Thanks";
    }
      else if(ch=='c'||ch=='C')
    {
	cout<<" Homeopathic Medicine:-\n";
	cout<<"Sbltyphoidinum\n*Typhoril.\nThanks";

     }
    else
    {
    cout<<"Invalid Choice Select Again";
    goto lb3;
    }
    getch();
}
void client::asthama(){
	clrscr();
     lb4: cout<<"What kind of treatment You Require For Asthama\nSelect\nA - Home Remedy\nB - ALOPATHY\nC-HOMEOPATHY\nEnter Your Choice\n";
    char ch;
    cin>>ch;
    if(ch=='A'||ch=='a')
    {  cout<<"Home Remedies for Asthama:-\n";
    cout<<"* Caffienated Tea or Coffee \n* Mustard oil\n* Eucalyptus.\n Thanks";
    }
    else if(ch=='B'||ch=='b')
    {
      cout<<"Alopathic Medicine:-\n";
    cout<<"* BronchoDilator \n* Anti Inflammatory .\n Thanks";
    }
      else if(ch=='c'||ch=='C')
    {
	cout<<" Homeopathic Medicine:-\n";
	cout<<"*PulsaTilla\n*Nunvomica.\nThanks";
     }
    else
    {
    cout<<"Invalid Choice Select Again";
    goto lb4;
    }
    getch();
}
void client::diabetes(){
	clrscr();
     lb5: cout<<"What kind of treatment You Require For diabetes\nSelect\nA - Home Remedy\nB - ALOPATHY\nC-HOMEOPATHY\nEnter Your Choice\n";
    char ch;
    cin>>ch;
    if(ch=='A'||ch=='a')
    {  cout<<"Home Remedies for Diabetes:-\n";
    cout<<"* Control Carb intake \n* Portion Control\n* Monitor Blood Sugar.\n Thanks";
    }
    else if(ch=='B'||ch=='b')
    {
      cout<<"Alopathic Medicine:-\n";
    cout<<"* Insulin \n*Metformin .\n Thanks";
    }
      else if(ch=='c'||ch=='C')
    {
	cout<<" Homeopathic Medicine:-\n";
	cout<<"*Sbl Diabonyl\n*R-40 DiaGlucon.\nThanks";
     }
    else
    {
    cout<<"Invalid Choice Select Again";
    goto lb5;
    }
    getch();
}
void client::mumps(){
	clrscr();
     lb6: cout<<"What kind of treatment You Require For mumps\nSelect\nA - Home Remedy\nB - ALOPATHY\nC-HOMEOPATHY\nEnter Your Choice\n";
    char ch;
    cin>>ch;
    if(ch=='A'||ch=='a')
    {  cout<<"Home Remedies for Mumps:-\n";
    cout<<"*  \n* Wardm or cold Compress\n* drink plenty of fluids.\n Thanks";
    }
    else if(ch=='B'||ch=='b')
    {
      cout<<"Alopathic Medicine:-\n";
    cout<<"* tylenol \n* IBUprofen .\n Thanks";
    }
      else if(ch=='c'||ch=='C')
    {
	cout<<" Homeopathic Medicine:-\n";
	cout<<"*R-186\n*Betonic.\nThanks";
     }
    else
    {
    cout<<"Invalid Choice Select Again";
    goto lb6;
    }
    getch();
}
void client::measels(){
	clrscr();
     lb7: cout<<"What kind of treatment You Require For Measels\nSelect\nA - Home Remedy\nB - ALOPATHY\nC-HOMEOPATHY\nEnter Your Choice\n";
    char ch;
    cin>>ch;
    if(ch=='A'||ch=='a')
    {  cout<<"Home Remedies for measels:-\n";
    cout<<"* Avoid Busy Activities \n* Seek respiratory Relief.\n Thanks";
    }
    else if(ch=='B'||ch=='b')
    {
      cout<<"Alopathic Medicine:-\n";
    cout<<"* M-vac \n* tresevac .\n Thanks";
    }
      else if(ch=='c'||ch=='C')
    {
	cout<<" Homeopathic Medicine:-\n";
	cout<<"* Reckeweg-r62\n* BC-14.\nThanks";
     }
    else
    {
    cout<<"Invalid Choice Select Again";
    goto lb7;
    }
    getch();
}
void client::arthritis()
{
	clrscr();
     lb8: cout<<"What kind of treatment You Require For Arthritis\nSelect\nA - Home Remedy\nB - ALOPATHY\nC-HOMEOPATHY\nEnter Your Choice\n";
    char ch;
    cin>>ch;
    if(ch=='A'||ch=='a')
    {  cout<<"Home Remedies for Arthritis:-\n";
    cout<<"* Use Turmeric\n* Consume More and More Fatty acid.\n Thanks";
    }
    else if(ch=='B'||ch=='b')
    {
      cout<<"Alopathic Medicine:-\n";
    cout<<"* Flexicart \n* Uri .\n Thanks";
    }
      else if(ch=='c'||ch=='C')
    {
	cout<<" Homeopathic Medicine:-\n";
	cout<<"* R-46\n* Apo-Rhun.\nThanks";
     }
    else
    {
    cout<<"Invalid Choice Select Again";
    goto lb8;
    }
    getch();
}
void client::thyroid()
{
	clrscr();
     lb9: cout<<"What kind of treatment You Require For Typhoid\nSelect\nA - Home Remedy\nB - ALOPATHY\nC-HOMEOPATHY\nEnter Your Choice\n";
    char ch;
    cin>>ch;
    if(ch=='A'||ch=='a')
    {  cout<<"Home Remedies for Thyroid:-\n";
    cout<<"* Take Vitamin B-12\n* Consume Dairy Products.\n Thanks";
    }
    else if(ch=='B'||ch=='b')
    {
      cout<<"Alopathic Medicine:-\n";
    cout<<"* Eltroxin\n* Thyraxin .\n Thanks";
    }
      else if(ch=='c'||ch=='C')
    {
	cout<<" Homeopathic Medicine:-\n";
	cout<<"*Whisel WL 38\n*Thyroidinum.\nThanks";
     }
    else
    {
    cout<<"Invalid Choice Select Again";
    goto lb9;
    }
    getch();
}
int client::retrieve(int addr,char k[])
{
 int found=0,i,temp;
 char dummy[10];
 i=addr;
 temp=i*recsize*5;
 efile.open(clientfile,ios::in|ios::out);
 do
 {
  while(temp<i*recsize*5+500)
  {
  efile.seekp(temp,ios::beg);
  efile.getline(dummy,5,'\n');
  if(strcmp(dummy,"####")==0)
  {
      temp=temp+100;

   }
   else
  {
  efile.seekp(temp,ios::beg);
  efile.getline(user_id,5,'|');
   if(strcmp(user_id,k)==0)
   {
	found=1;
	cout<<"\n RECORD FOUND\n"<<endl;

	efile.getline(user_name,15,'|');
	efile.getline(gender,5,'|');
	efile.getline(age,5,'|');
	efile.getline(contact,12,'|');
	efile.getline(weight,6,'|');
	cout<<"user_ID="<<user_id<<"\nuser_Name="<<user_name<<"\ngender="<<gender<<"\nage="<<age;
	cout<<"\ncontact="<<contact<<"\nweight="<<weight<<"\n";
	gets(c);
	return temp;

  }
   temp=temp+100;
 }
}

   i++;
   if(i%max==0)
      i=0;

}while(i!=addr);
if(found==0)
 cout<<"\n RECORD DOES NOT EXISTS\n";
 gets(c);
 return -1;
 }
 void client::unpack()
 {
	efile.getline(user_id,5,'|');
	efile.getline(user_name,15,'|');
	efile.getline(gender,5,'|');
	efile.getline(age,5,'|');
	efile.getline(contact,12,'|');
	efile.getline(weight,6,'|');
}
 void client::disp()
 {
    int i,j,temp;
    char dummy[10];
     efile.open(clientfile,ios::in);
     cout<<setiosflags(ios::left);
     cout<<setw(10)<<"user_ID "<<setw(15)<<"user_Name "<<setw(7)<<"Gender "<<setw(7)<<"age "<<setw(7)<<"Contact "<<setw(15)<<"weight "<<endl;
     for(i=0;i<14;i++)
     {
	 temp=(i*recsize*5);
	 for(j=1;j<=5;j++)
	 {
	     efile.seekp(temp,ios::beg);
	     efile.getline(dummy,5,'\n');
	     if(strcmp(dummy,"####")!=0)
		{
			efile.seekp(temp,ios::beg);
			unpack();
		    cout<<setiosflags(ios::left);
		    cout<<setw(10)<<user_id<<setw(15)<<user_name<<setw(7)<<gender<<setw(7)<<age<<setw(7)<<contact<<setw(15)<<weight;
		    cout<<endl;

		}
		temp=temp+100;
	 }

     }
     gets(c);
}
void main()
{
 int ch,addr,pos,i;

 char ekey[15];
 client c;
 clrscr();
 c.initial();

 la:for(;;)

 {
 clrscr();
   textcolor(14);
	    clrscr();
	    cout<<"\n*************************************************";
	    cout<<"\n*\t\t WELCOME\t\t\t*\n*\t\t1...READ\t\t\t* \n*\t\t2...DISPLAY\t\t\t*";
	    cout<<"\n*\t\t3...SEARCH\t\t\t*\n*\t\t4...DELETE\t\t\t*\n*\t\t5...MODIFY\t\t\t*\n*\t\t6...EXIT\t\t\t*\n";
	    cout<<"*************************************************";
	    cout<<"\n\nINPUT UR CHOICE: ";

  cin>>ch;
  switch(int(ch))
 {
  label1:
  case 1: clrscr();
	  cout<<endl<<"ENTER USER DETAILS:"<<endl;
	  c.read();
	  addr=hash(c.user_id);
	  store(addr);
	  break;
  case 2: clrscr();
	  cout<<"DETAILS ARE:"<<endl;
	  c.disp();
	  break;
  case 3: clrscr();
	  cout<<"ENTER  USER_ID :"<<endl;
	  cin>>ekey;
	  addr=hash(ekey);
	  c.retrieve(addr,ekey);
	  break;
  case 4: clrscr();
	  cout<<"DELETION BASED ON USER_ID\n" ;
	  cout<<"ENTER THE USER_ID\n";
	  cin>>ekey;
	  addr=hash(ekey);
	  cout<<"THE DELETED DETAILS ARE\n\n" ;
	  pos=c.retrieve(addr,ekey);
	  cout<<pos;
	  if(pos!=-1)
	  {
	    count[addr]=count[addr]-1;
	    efile.open(clientfile,ios::out);
	    efile.seekp(pos,ios::beg);
	    for(i=1;i<99;i++)
	    efile.put('#');
	    efile.close();
	 }
	 break;
  case 5:clrscr();
	 cout<<"MODIFICATION BASED ON THE USER_ID\n" ;
	 cout<<"ENTER THE USER_ID\n";
	 cin>>ekey;
	 addr=hash(ekey);
	 cout<<"RECORD TO BE MODIFIED IS:\n\n";
	 pos=c.retrieve(addr,ekey);
	 if(pos!=-1)
	 {
	   count[addr]=count[addr]-1;
	   efile.open(clientfile,ios::out);
	   efile.seekp(pos,ios::beg);
	   for(i=1;i<99;i++)
	   efile.put('#');
	   efile.close();
	   goto label1;


	 }

	 break;

 case 6:exit(0);
 default:goto la;


 }
efile.close();
}
}

