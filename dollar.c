#include <stdio.h>

int main() {
    double inr, usd, eur, gbp, jpy,sgd;
    const double usdRate = 0.012; // Example conversion rate
    const double eurRate = 0.011; // Example conversion rate
    const double gbpRate = 0.009; // Example conversion rate
    const double jpyRate = 1.54;  // Example conversion rate
    char continueConversion;

    do {
        printf("Enter amount in INR: ");
        scanf("%lf", &inr);

        usd = inr * usdRate;
        eur = inr * eurRate;
        gbp = inr * gbpRate;
        jpy = inr * jpyRate;

        printf("%.3f INR is %.3f USD\n", inr, usd);
        printf("%.3f INR is %.3f EUR\n", inr, eur);
        printf("%.3f INR is %.3f GBP\n", inr, gbp);
        printf("%.3f INR is %.2f JPY\n", inr, jpy);

        printf("Do you want to convert another amount? (y/n): ");
        scanf(" %c", &continueConversion);

    } while (continueConversion == 'y' || continueConversion == 'Y');

    printf("Exiting the program.\n");

    return 0;
}
	