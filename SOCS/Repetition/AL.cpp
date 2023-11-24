#include <stdio.h>

int main()
{
  long long int jmlPdg, jmlNga;

  scanf("%lld %lld", &jmlPdg, &jmlNga);

  long long int pdg[jmlPdg];

  for (long long int i = 0; i < jmlPdg; i++)
  {
    scanf("%lld", &pdg[i]);
  }

  long long int nga[jmlNga];

  for (long long int i = 0; i < jmlNga; i++)
  {
    scanf("%lld", &nga[i]);
  }

  long long int mostPdg = 0;
  for (long long int i = 0; i < jmlPdg; i++)
  {
    if (pdg[i] > mostPdg)
    {
      mostPdg = pdg[i];
    }
  }

  long long int mostNga = 0;
  for (long long int i = 0; i < jmlNga; i++)
  {
    if (nga[i] > mostNga)
    {
      mostNga = nga[i];
    }
  }

  if (mostPdg > mostNga)
  {
    printf("The dark secret was true\n");
  }
  else
  {
    printf("Secret debunked\n");
  }

  return 0;
}