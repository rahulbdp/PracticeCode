#include<iostream>

using namespace std;

class BankLoanApproval
{
public:
	virtual void handler() = 0;
	void setLoanAmount(size_t& loanAmtToBeSet)
	{
		loanAmt = loanAmtToBeSet;
	}
	void setNextHandler(BankLoanApproval* nextHandlerToBeSet)
	{
		if (!nextHandler)
			nextHandler = nextHandlerToBeSet;
	}

private:
	BankLoanApproval* nextHandler;

protected:
	void nextLevelApproval()
	{
		if (nextHandler)
			nextHandler->handler();
	}

	static size_t loanAmt;
};

class CreditOfficerApproval : public BankLoanApproval
{
public:
	virtual void handler()
	{
		if (loanAmt <= 10)
			cout << "Loan Approved by Credit Officer" << endl;
		else
		{
			cout << "Credit Officer is not authorized to approve the loan amount" << endl;
			nextLevelApproval();
		}
	}
};

class BranchManagerApproval : public BankLoanApproval
{
public:
	virtual void handler()
	{
		if (loanAmt <= 100)
			cout << "Loan Approved by Branch Manager" << endl;
		else
		{
			cout << "Branch Manager is not authorized to approve the loan amount" << endl;
			nextLevelApproval();
		}
	}
};

class DirectorApproval : public BankLoanApproval
{
public:
	virtual void handler()
	{
		if (loanAmt <= 1000)
			cout << "Loan Approved by Managing Director" << endl;
		else
			cout << "Loan amount to big for the Bank" << endl;
	}
};

size_t BankLoanApproval::loanAmt = 0;

int main3()
{
	size_t loanAmount;
	CreditOfficerApproval creditOfficer;
	BranchManagerApproval branchManager;
	DirectorApproval managingDirector;

	creditOfficer.setNextHandler(&branchManager);
	branchManager.setNextHandler(&managingDirector);

	cout << "Enter the Loan Amount" << endl;
	cin >> loanAmount;

	creditOfficer.setLoanAmount(loanAmount);
	creditOfficer.handler();

	return(0);
}