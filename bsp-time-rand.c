/*
bsp-time-rand.c
Kleines Beispiel fuer:  rand(), srand(), time() etc.
fhdwbap 09.04.2008, 16.11.2017

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MODVALUE 10000  // Bereich der Zufallszahlen 0..MODVALUE-1


int main(int argc, char *argv[])
{
  unsigned long i, anzahl, summe = 0L, wert, min, max;
  double average;
  time_t sec;
  
  if (argc!=2)
  {
      fprintf(stderr,"Aufruf: zufall <anzahl> \n");
      return EXIT_FAILURE;
  }
  
  anzahl = atoi(argv[1]);
  printf("Anzahl: %lu\n",anzahl);
  
  if (anzahl <= 0)
  {
      fprintf(stderr,"Fehler: \"anzahl\" muss groesser 0 sein!\n");
      return EXIT_FAILURE;
  }
  
  /* Initialisieren des Zufallszahlengenerators */
  time(&sec);
  printf("Datum und Uhrzeit (GMT): %s %u\n", asctime(gmtime(&sec)),(unsigned int)sec);  
  srand(sec);
  
  summe = 0L;
  for (i=0; i<anzahl; i++)
  {
      wert = rand() % MODVALUE;
      if (i==0)
      {
         min = max = wert;
      }
      printf("Zufallswert Nr. %5ld: %6lu\n",i+1,wert);
      
      summe += wert;
      if (max < wert) 
      {
         max = wert;
      }
      if (min > wert)
      {
         min = wert;
      }
      
  }
  average = (double)summe / (double)anzahl;
  
  printf("\nStatistik:\n");
  printf("Summe:       %13lu\n",summe);
  printf("Mittelwert:  %16.2lf\n",average);
  printf("Minimum:     %13lu\n",min);
  printf("Maximum:     %13lu\n",max);

  return EXIT_SUCCESS;
}
