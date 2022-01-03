#include <iostream>

using namespace std;

class preparationStyle
{
	public:
	preparationStyle()
	{
		cout<<"preparationStyle Constructor called"<<endl;
	}
	
	~preparationStyle()
	{
		cout<<"preparationStyle Destructor called"<<endl;
	}
	
	virtual void cook()
	{
		cout<<"Cook function called"<<endl;
	}
};

class jain: public preparationStyle
{
	public:
	jain()
	{
		cout <<"Jain Preparation Style Selected - Constructor called"<<endl;
	}
	
	~jain()
	{
		cout<<"Jain Preparation style - Destructor called"<<endl;
	}
	
	void cook()
	{
		cout<<"Cook food in Jain style"<<endl;
	}
};

class nonJainVeg: public preparationStyle
{
	public:
	nonJainVeg()
	{
		cout <<"nonJainVeg Preparation Style Selected - Constructor called"<<endl;
	}
	
	~nonJainVeg()
	{
		cout<<"nonJainVeg Preparation style - Destructor called"<<endl;
	}
	
	void cook()
	{
		cout<<"Cook food in Non Jain Veg style"<<endl;
	}
};

class lunch
{
	protected:
	preparationStyle* style = nullptr;
	
	public:
	lunch()
	{
		cout<<"lunch Constructr called"<<endl;
	}
	
	virtual ~lunch()
	{
		cout<<"lunch destructor called"<<endl;
	}
	
	void prepareLunch()
	{
		style->cook();
	}
};

class dal: public lunch
{
	public:
	dal( string style)
	{
		cout<<"dal constructor called"<<endl;
		if (style == "jain")
			this->style = new jain;
		else
			this->style = new nonJainVeg;
	}
	
	private:
	dal()
	{
	}
};

class sabji: public lunch
{
	public:
	sabji( string style)
	{
		cout<<"sabji constructor called"<<endl;
		if (style == "jain")
			this->style = new jain;
		else
			this->style = new nonJainVeg;
	}
	
	private:
	sabji()
	{
	}
};

class roti: public lunch
{
	public:
	roti()
	{
		cout<<"roti constructor called"<<endl;
		style = new preparationStyle;
	}
};

int main()
{
	lunch* lunch[3];
	lunch[0] = new dal("jain");
	lunch[1] = new sabji("nonJain");
	lunch[2] = new roti;
	
	for ( auto index: lunch)
		index->prepareLunch();
	
	return 0;
}