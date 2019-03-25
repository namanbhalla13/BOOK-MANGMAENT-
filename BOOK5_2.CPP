#include<iostream.h>
#include<conio.h>
#include<string.h>
int books=0;
class book
{
	char title[20];
	char pub[20];
	char aut[20];
	int price;
	int stock;
	int number;
	public:
		book();
		book(char t[],char p[],char a[]);
		 void display();
		 int compare(book &);
		 int comparee(book&);
		void sto();
		void bill()
		{
			cout<<"book title:" <<title<<endl;
			cout<<"book author:"<<aut<<endl;
			cout<<"book publisher:"<<pub<<endl;
			cout<<"book price"<<price<<endl;
		}

};
book::book()
{
	cout<<"enter the title"<<endl;
	cin>>title;
	cout<<"enter the author name"<<endl;
	cin>>aut;
	cout<<"enter the publisher name"<<endl;
	cin>>pub;
	cout<<"enter the price and stock"<<endl;
	cin>>price>>stock;
}
void book::display()
{
	cout<<"author name is:"<<aut<<endl;
	cout<<"book name is:"<<title<<endl;
	cout<<"publisher name is:"<<pub<<endl;
	cout<<"stock:"<<stock<<endl;
	cout<<"price:"<<price<<endl;
}
/*book::book(char title,char pub,char aut)
{
	title=title;
	pub=pub;
	aut=aut;
} */
int book::comparee(book& b4)
{
	int flag;
	int x=strcmp(b4.title,title);
	int y=strcmp(b4.pub,pub);
	int z=strcmp(b4.aut,aut);
	if(x==0&&y==0&&z==0)
	{
		int out;
		display();
		cout<<"you you want to buy this book or not?"<<endl<<"press 1 for buy otherwise press anynumber"<<endl;
		cin>>out;
		if(out==1)
		{
			sto();
		}

		flag=1;

	}
	else
	{
		//cout<<"search in ather one"<<endl;
		flag=0;
	}
	return (flag);

}

int book::compare(book& b4)
{
	int flag;
	int x=strcmp(b4.title,title);
	int y=strcmp(b4.pub,pub);
	int z=strcmp(b4.aut,aut);
	if(x==0&&y==0&&z==0)
	{
		//display();
		sto();
		//cout<<"new update******************************"<<endl;
		//display();
		flag=1;

	}
	else
	{

		flag=0;
	}
	return (flag);

}
void book::sto()
{
	int p;
	cout<<"enter the no. of books you wnat"<<endl;
	cin>>p;
	if(stock>p)
	{
		stock=stock-p;
		cout<<"your bill***********************************"<<endl;
		//display();
		bill();
		cout<<"number of books:"<<p<<endl;
		cout<<"your total is:"<<(p*price)<<endl<<"thank you"<<endl;
	}
	else
	{
		cout<<"not in stock"<<endl ;

	}
}
int main()
{   int operation;
	int z=0;
	int q;
	char m_name[20];
	char c_name[20];
	cout<<"enter your name mr.Manager"<<endl;
	cin>>m_name;
	cout<<"mr.Manager:"<<m_name<<endl<<"please enter the basic 2 books entires which would you like to add in the book store"<<endl;
	//cin>>::books;
	//cout<<::books;
	book b[2];
	cout<<"enter the customer name which you would like to save in database"<<endl;
	cin>>c_name;
	clrscr();

	cout<<m_name<<endl;
	cout<<"hello"<<endl;
	do
	{
	cout<<"your menu is"<<endl<<"press 1 for display books"<<endl<<"press 2 for seraching"<<endl<<"press 3 for buying"<<endl;
	cin>>q;

	switch(q)
	{
	case 1:
	{
		for(int i=0;i<2;i++)
		{
			b[i].display();
			cout<<"*******************************************"<<endl;
		}
	break;
	}

	case 3:
	{
		cout<<"enter the book details which you wnat to searach"<<endl;
		book b1;
		int  i=0;
		do
		{
			z=b[i].compare(b1);
			i++;

		}while(z==0&&i<2);
		if(z==0){cout<<"no found"<<endl;}
		break;
	}
	case 2:

	{
		cout<<"enter the book details which you wnat to search"<<endl;
		book b1;
		 int i=0;
		do
		{
			z=b[i].comparee(b1);
			i++;

		}while(z==0&&i<2);
		if(z==0){cout<<"no found"<<endl;}
		break;
	}

	default:
	cout<<"use proper number"    <<endl;
	}
	cout<<"you wnat more operation press 1 otherwise 2"<<endl;
	cin>>operation;
	clrscr();
	}while(operation==1);
	getch();
	return 0;
}