#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iomanip.h>

#define max 10
#define size 10

char t[size];
int amt = 0;
double Medicine[10] = {2.00,3.00,1.00,4.00,1.00,5.00,7.00,4.00,3.00,5.00};
char *medicineName[] = {"Probiotics","Vitamin C(500mg)","Acid Free C(500mg)","Women'S Multivate","Marino Tablet","Maxi Cal Tablet",
	"Amino Zinc Tablet","Burnex","Fabuloss 5","Royal Propollen"};;

struct node
{
	int reciept_number;
	char customerName[20];
	char date[20];
	int quantity[10];
	int x, menu2[10];
    	double amount[10];
    	int medicineName[10];
	double total;

	node *prev;
	node *next;
	node *link; 

}*q, *temp; 


node *start_ptr = NULL;
node *head = NULL;
node *last = NULL;

class order
{
	public:
	
    	void take_order()
    	{
	getch();
	int i;
 	int choice, quantity, price,None;

	cout <<"\nAdd Order Details\n";
	cout <<"_____________________________________ \n\n";
	node *temp;
	temp=new node;

	cout <<"***********************************************************\n";
	cout<<"DRUGS ID"<<"\t\tDRUGS NAME"<<"           DRUGS PRICE(RS)"<<endl;
	cout <<"***********************************************************\n";
    	cout<<"0001"<<"\t\t"<<"    Probiotics"<<"			RS 2.00"<<endl;
     	cout<<"0002"<<"\t\t"<<"    Vitamin C(500mg)"<<"		RS 3.00"<<endl;
      	cout<<"0003"<<"\t\t"<<"    Acid Free C(500mg)"<<"		RS 1.00"<<endl;
	cout<<"0004"<<"\t\t"<<"    Paracetamol"<<"			RS 4.00"<<endl;
       	cout<<"0005"<<"\t\t"<<"    Marino Tablet"<<"	 	RS 1.00"<<endl;
       	cout<<"0006"<<"\t\t"<<"    Cal Tablet"<<" 			RS 5.00"<<endl;
       	cout<<"0007"<<"\t\t"<<"    Amino Zinc Tablet"<<"		RS 7.00"<<endl;
       	cout<<"0008"<<"\t\t"<<"    Burnex"<<"			RS 4.00"<<endl;
       	cout<<"0009"<<"\t\t"<<"    Fabuloss 5"<<"			RS 3.00"<<endl;
       	cout<<"0010"<<"\t\t"<<"    Royal Propollen"<<"		RS 5.00"<<endl;
       	cout<<" "<<endl;
    
	temp = new node;
	cout << "Type Order no: ";
   	cin >> temp->reciept_number;
	cout<< "Enter Customer Name: ";
	cin>> temp->customerName;
	cout<<"Enter Date(DD/MM/YYYY): ";
	cin>>temp->date;
	cout << "How many Medicine would you like to order:"<< endl;
	cout<<"( Maximum is 10 order for each transaction ) \n";
	cout << "  " ;
	cin >> temp->x;
	if (temp->x >10)
	{
		cout << "The Medicine you order is exceed the maximum amount of order !";
		getch();
	}
	else
	{
	for (i=0; i<temp->x; i++)
	{
		
		cout << "Please enter your selection : "<<endl;
		cin>> temp->menu2[i];
		int j;
		j=temp->menu2[i];
        		cout<< "Medicine Name: " <<medicineName[j-1]<<endl;
       	 	cout << "How many medicine do you want: ";
        		cin >> temp->quantity[i];
        		temp->amount[amt] = temp->quantity[i] * Medicine[temp->menu2[i]-1];
        		cout << "The amount You need to pay is: " << temp->amount[amt]<<" RS"<<endl;
                      
	}
	cout<<"==========================================================================="<<endl;
    	cout << "Order Taken Successfully"<<endl;
    	cout<<"==========================================================================="<<endl;
    	cout << "Go to Reciept Menu to Pay The Bill"<<endl;
    	cout<<"==========================================================================="<<endl;
	cout<<"Press Enter To Continue.."<<endl;
	
    	temp->next=NULL;
	if(start_ptr!=NULL)
	{
		temp->next=start_ptr;
	}
	start_ptr=temp;
	getch();
	system("cls");
	}
	}
    	
 	void delete_order()
    	{
	system("cls");
	int i, num, count;
    	cout<<"Enter the data you want to delete \n";
    	cin>>num;
    	node *q;
	node *temp;
	int found=0;

	if(start_ptr == NULL)
		cerr<<"Can not delete from an empty list.\n";
	else
	{
		if(start_ptr->reciept_number == num)
		{
			q = start_ptr;
			start_ptr = start_ptr->next;
			count--;
			if(start_ptr == NULL)
			last = NULL;
			delete q;
			cout<<"The Reciept is Deleted Successfully"<<endl;
		}
		else
		{
			found = 0;
			temp = start_ptr;
			q = start_ptr->next;
	
		while((!found) && (q != NULL))
		{
  			if(q->reciept_number != num) 
			{
			temp = q;
			q = q-> next;
			}
			else
			found = 1;
		}

			if(found==1)
			{
			temp->next = q->next;
			count--;
			if(last == q) 
			last = temp;
			delete q;
			cout<<"The Reciept is Deleted Successfully"<<endl;
			}
			else
			cout<<"Item to be deleted is not in the list."<<endl;
			}
		} 
	}
	
	order()
	{
		//empty constructor
	}
	~order()
	{
		cout<<"----Destructor Call----";
	}
};

class modification : public order
{
	public:
	void modify()
	{
 	getch();
 	int i, ch, sid, found= 0;
 	temp = start_ptr;
 	cout<<"Enter Receipt Number To Modify: ";
 	cin>>sid;
 	if (temp==NULL && sid==0)
 	{
    	cout<<"NO RECORD TO MODIFY..!"<<endl;
 	}
 	else
 	{
 	while(temp !=NULL && !found)
	{
		if (temp->reciept_number==sid)
		{
		found = 1;
		}
		else
		{
		temp = temp -> next;
		}
   	 if (found==1)
    	{
	cout << "Change  Order Number: ";
    	cin >> temp->reciept_number;
	cout<< "Change Customer Name: ";
	cin>> temp->customerName;
	cout<<"Change Date : ";
	cin>>temp->date;
	cout << "How many New Medicine would you like to Change:"<< endl;
	cout<<"( Maximum is 10 order for each transaction ) \n";
	cout << "  " ;
	cin >> temp->x;
	if (temp->x >10)
	{
		cout << "The Medicine you order is exceed the maximum amount of order !";
		getch();
	}
	else
	{
	for (i=0; i<temp->x; i++)
	{
		
	cout << "Please enter your selection to Change: "<<endl;
	cin>> temp->menu2[i];
	int j;
	j=temp->menu2[i];
        	cout<< "Change Medicine Name: " <<medicineName[j-1]<<endl;
        	cout << "How many New medicine do you want: ";
        	cin >> temp->quantity[i];
        	amt=i;
        	temp->amount[amt] = temp->quantity[i] * Medicine[i];
        	cout << "The amount You need to pay After Modify  is: " << temp->amount[amt]<<" RS"<<endl;
        	getch();
	}
	temp = temp->next;
	getch();
	}
 	cout<<"RECORD MODIFIED....!"<<endl;
 	}
 	else 
 	{
 	if(temp != NULL && temp->reciept_number != sid)
 	{
	cout<<"Invalid Reciept Number...!"<<endl;
    	}
 	}
	}
	}
	}	
};

class details : public order, public modification
{
	public:
	void order_list()
	{
	int i, num, num2,found=0;			
	getch();
	node *temp;
	temp=start_ptr;
	cout<<" Enter the Reciept Number To Print The Reciept\n";
	cin>>num2;
	cout<<"\n";
	cout<<"==========================================================================="<<endl;
	cout <<"\t\tHere is the Order list\n"; 
	cout<<"==========================================================================="<<endl;

	if(temp == NULL)
	{
		cout << "\tThere is no Order to show\n\t\t\tSo The List is Empty\n\n\n";
	}
	while(temp !=NULL && !found)
	{
		if (temp->reciept_number==num2)
		{
			found = 1;
		}
		else
		{
			temp = temp -> next;
		}
        		if (found==1)
        		{
		cout<<"Reciept Number : "<<temp->reciept_number;
		cout<<"\n";
		cout<<"Customer Name: "<<temp->customerName<<endl;
				
		cout<<"Order Date : "<<temp->date<<endl;		
		cout<<"_____________________________________________________________________________"<<endl;	
		cout<<"=========================================================" << endl;
		cout<<"|Medicine Name    |  	Quantity     |    Total Price |" << endl;
		cout<<"=========================================================" << endl;
		for (i=0;i<temp->x;i++)
		{
		int j;
		j=temp->menu2[i];
		cout<<medicineName[j-1]<<"\t\t  ";
		cout<<temp->quantity[i] <<"\t\t";
		cout<< temp->amount[i]<<" RS"<<endl;
		cout<<"_________________________________________________________________________________"<<endl;
		}
		for(i=0;i<=amt;i++)
		{	
		temp->total= 0 + temp->amount[i];
		}
		cout<<"Total Bill is : "<<temp->total;
		cout<<"\n";
		cout<<"Type the exact amount You need to pay: ";
		cin >> num;
		cout<<"\n";
		cout<<"\n";
		cout<<"Payment Done\nThank You\n";
		cout<<"\n_____________________________________________________________________________\n";
		}
	}
	}
	
	void daily_summary()
	{
	int i,num;
	system("cls");
	node *temp ;
	temp=start_ptr;
	if(temp == NULL)
		{
		cout << "\t\t\tThere is no Order to show\n\t\t\tSo The List is Empty\n\n\n";
		}
	else
		{
		cout<<"\n";
		cout<<"==========================================================================="<<endl;
		cout <<" \t\tHere is the Daily Summary of All Orders \n"; //print all receipt
		cout<<"==========================================================================="<<endl;
		while(temp!=NULL)
		{
		cout <<"Reciept Number : "<<temp->reciept_number;
		cout <<"\n";
		cout<<"Customer Name: "<<temp->customerName<<endl;
		cout<<"Order Date : "<<temp->date<<endl;
		cout<<"____________________________________________________________________________"<<endl;
		cout<<"=========================================================" << endl;
		cout<<"|Medicine Name    |  	Quantity     |    Total Price |" << endl;
		cout<<"=========================================================" << endl;
		amt=0;
		for (i=0;i<temp->x;i++)
		{
		int j;
		j=temp->menu2[i];
		cout<<medicineName[j-1]<<"\t\t";
		cout<<temp->quantity[i] <<"\t\t";
		cout<< temp->amount[amt]<<" RS"<<endl;
		cout<<"_____________________________________________________________________________"<<endl;
		}
		for(i=0;i<=amt;i++)
		{
		temp->total=0+temp->amount[i];
		}
		cout<<"Total Bill is : "<<temp->total;
		cout <<"\n";
		cout <<"\n";
		cout <<"\n_______________________________________________________________________________\n";	
		temp=temp->next;
		}
	}
	}	
};
class exitt
{
	public:
	void exit()
	{
	cout<<"\nYou choose to exit.\n"<<endl;
	}
};

int main()
{
	order medicine;
	details det;
	exitt ex;
	int menu;
	do
	{
		system("cls");
		cout<<"\t\t\t    Pharmacy Management System \n";
		cout<<"\t\t==================================================\n\n";
		cout<<"\t\t--------------------------------------------------\n";
		cout<<"\t\t||\t1. Take new Medicine order \t\t ||\n";
		cout<<"\t\t||\t2. Print the Reciept and Make Payment \t ||\n";
		cout<<"\t\t||\t3. Modify Order List \t\t\t ||\n";
		cout<<"\t\t||\t4. Delete latest Medicine order\t\t ||\n";
		cout<<"\t\t||\t5. Daily Summary of total Sale \t\t ||\n";
		cout<<"\t\t||\t6. Exit\t\t\t\t\t ||\n";
		cout<<"\t\t--------------------------------------------------\n";
		cout<<"Enter choice: ";
		cin>>menu;
		switch (menu)
		{
		case 1:
			{
			medicine.take_order();
			break;
			}
		
		
		case 4:
			{
			medicine.delete_order();
			getch();
			break;
			}
			
		case 3:
			{
			modification mod;
			mod.modify();
			getch();
			break;
			}

		case 2:
			{
			det.order_list();
			getch();
			break;
			}
		case 5:
			{
			det.daily_summary();
			getch();
			break;
			}
       		 case 6:
			{
			ex.exit();	
			cout<<"Thank You"<<endl;
			break;
			}

		default:
			{
			cout<<"You enter invalid input\nRe-enter the input\n"<<endl;
			break;
			}
		}
	}while(menu!=6);
	return 0;
}