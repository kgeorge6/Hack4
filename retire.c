/*
	Declare variables for rates, initial ballance, monthly contribution, 
	and years before retirement
	
	Gather input from the user
	
	Convert RoI and RoR to monthly rates
	
	Calculate and display the interest and new balance for each month
	
	Display total interest earned and final account total
*/

/*
	Retirement - Hack 4
	Kyle George
	1-15-2020
*/

#include <stdio.h>

int main(void) {
	//Variable Definitions
	double balance; 			//Current balance of the account
	double interest = 0;	//Interest at given month
	double monthlyContribution;	//Amount added each month
	double RoR;					//Rate of Return
	double RoI;					//Rate of Inflation
	int time;					//Years unitl retirement
	double inflationAdjustedRoR;
	
	//Gather input from user
	printf("Starting Balance: ");
	scanf("%lf", &balance);
	printf("Monthly Contribution: ");
	scanf("%lf", &monthlyContribution);
	printf("Annual Rate of Return: ");
	scanf("%lf", &RoR);
	printf("Annual Rate of Inflation: ");
	scanf("%lf", &RoI);	
	printf("Years Until Retirement: ");
	scanf("%d", &time);
	
	printf("\n%.2f, %.2f, %.2f, %.2f, %d\n", balance, monthlyContribution, RoR, RoI, time);
	printf("\n");
	
	//Calculate inflation adjusted rate
	inflationAdjustedRoR = (1 + RoR)/(1 + RoI) - 1;
	
	//Convert inputs into monthly values
	inflationAdjustedRoR /= 12;
	time *= 12;
	
	printf("Inflation Adjusted Rate of Return: %.5f\n\n", inflationAdjustedRoR);
	
	double prevBalance;
	double monthlyInterest;
	//Loop through each month
	printf("Month\t   Interest\tBalance\n");
	for(int i = 0; i < time; i++) {
		monthlyInterest = inflationAdjustedRoR * balance;
		balance += monthlyInterest;
		balance += monthlyContribution;
		interest += monthlyInterest;
		printf("   %d\t   $%.2f\t$%.2f\n",i+1, monthlyInterest, balance);
	}
	printf("Net Balance: $%.2f\n", balance);
	printf("Total Interest Earned: $%.2f\n", interest);
}

/*
	Tested Data Sets
	Inputs: (Initial Balance = 1000, Monthly Contribution = 100, RoR = 0.050, RoI = 0.01, Years = 3)
	Expected Outputs: (Net Balance = 4941.85, Total Interest = 341.85)
	Outputs: (Net Balance = 4941.85, Total Interest = 341.85)
	
	Inputs: (Initial Balance = 1400, Monthly Contribution = 50, RoR = 0.100, RoI = 0.050, Years = 4)
	Expected Outputs: (Net Balance = 4331.17, Total Interest = 531.17)
	Outputs: (Net Balance = 4331.17, Total Interest = 531.17)
	
	Inputs: (Initial Balance = 10000, Monthly Contribution = 50, RoR = 0.09, RoI = 0.012, Years = 10)
	Expected Outputs: (Net Balance = 111556.15, Total Interest = 41556.15)
	Outputs: (Net Balance = 111556.15, Total Interest = 41556.15)
*/