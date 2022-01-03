#include <iostream>
#include <string> 

using namespace std;

class BronzeCard;
class SilverCard;
class GoldCard;
class PlatinumCard;

class OffersVisitor
{
public:
	virtual void visitBronzeCard(BronzeCard* cc) = 0;
	virtual void visitSilverCard(SilverCard* cc) = 0;
	virtual void visitGoldCard(GoldCard* cc) = 0;
	virtual void visitPlatinumCard(PlatinumCard* cc) = 0;
};

//--------------------------------------------------------------------------------

class CreditCard
{
public:
	virtual string& getName(void) = 0;
	virtual void accept(OffersVisitor* offersPtr) = 0;
private:
	//OffersVisitor* offers;
};

class BronzeCard : public CreditCard
{
public:
	BronzeCard()
	{
		cardName = "Bronze Card";
	}

	string& getName(void)
	{
		return cardName;
	}
	void accept(OffersVisitor* offersPtr)
	{
		offersPtr->visitBronzeCard(this);
	}

private:
	string cardName;
};

class SilverCard : public CreditCard
{
public:
	SilverCard()
	{
		cardName = "Silver Card";
	}

	string& getName(void)
	{
		return cardName;
	}

	void accept(OffersVisitor* offersPtr)
	{
		offersPtr->visitSilverCard(this);
	}

private:
	string cardName;
};

class GoldCard : public CreditCard
{
public:
	GoldCard()
	{
		cardName = "Gold Card";
	}

	string& getName(void)
	{
		return cardName;
	}
	void accept(OffersVisitor* offersPtr)
	{
		offersPtr->visitGoldCard(this);
	}

private:
	string cardName;
};

class PlatinumCard : public CreditCard
{
public:
	PlatinumCard()
	{
		cardName = "Platinum Card";
	}

	string& getName(void)
	{
		return cardName;
	}
	void accept(OffersVisitor* offersPtr)
	{
		offersPtr->visitPlatinumCard(this);
	}

private:
	string cardName;
};

//-----------------------------------------------------------------

class FuelOffer : public OffersVisitor
{
public:
	void visitBronzeCard(BronzeCard* cc)
	{
		cout << "Computing Cashback for " << cc->getName().c_str() << " for Fuel" << endl;
	}
	void visitSilverCard(SilverCard* cc)
	{
		cout << "Computing Cashback for " << cc->getName().c_str() << " for Fuel" << endl;
	}
	void visitGoldCard(GoldCard* cc)
	{
		cout << "Computing Cashback for " << cc->getName().c_str() << " for Fuel" << endl;
	}
	void visitPlatinumCard(PlatinumCard* cc)
	{
		cout << "Computing Cashback for " << cc->getName().c_str() << " for Fuel" << endl;
	}
};

class HotelOffer : public OffersVisitor
{
public:
	void visitBronzeCard(BronzeCard* cc)
	{
		cout << "Computing Cashback for " << cc->getName().c_str() << " for Hotel" << endl;
	}
	void visitSilverCard(SilverCard* cc)
	{
		cout << "Computing Cashback for " << cc->getName().c_str() << " for Hotel" << endl;
	}
	void visitGoldCard(GoldCard* cc)
	{
		cout << "Computing Cashback for " << cc->getName().c_str() << " for Hotel" << endl;
	}
	void visitPlatinumCard(PlatinumCard* cc)
	{
		cout << "Computing Cashback for " << cc->getName().c_str() << " for Hotel" << endl;
	}
};

class MovieOffer : public OffersVisitor
{
public:
	void visitBronzeCard(BronzeCard* cc)
	{
		cout << "Computing Cashback for " << cc->getName().c_str() << " for Movie" << endl;
	}
	void visitSilverCard(SilverCard* cc)
	{
		cout << "Computing Cashback for " << cc->getName().c_str() << " for Movie" << endl;
	}
	void visitGoldCard(GoldCard* cc)
	{
		cout << "Computing Cashback for " << cc->getName().c_str() << " for Movie" << endl;
	}
	void visitPlatinumCard(PlatinumCard* cc)
	{
		cout << "Computing Cashback for " << cc->getName().c_str() << " for Movie" << endl;
	}
};

//---------------------------------------------------------------

int main()
{
	CreditCard* bc = new BronzeCard;
	CreditCard* sc = new SilverCard;
	CreditCard* gc = new GoldCard;
	CreditCard* pc = new PlatinumCard;
	
	OffersVisitor* visitor1 = new FuelOffer;
	OffersVisitor* visitor2 = new MovieOffer;
	OffersVisitor* visitor3 = new HotelOffer;
	
	bc->accept(visitor1);
	bc->accept(visitor2);

	sc->accept(visitor1);
}