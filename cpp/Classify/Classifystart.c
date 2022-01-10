
#include "GEClassify.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int Evolved[FitnessCases];

double main() {

  FILE *file;

  double Dim[FitnessCases][Variables + 1];

  if (!(file = fopen("SampleData.txt", "r"))) {
    printf("Error opening file");
    exit(0);
  }

  for (int i = 0; i < FitnessCases; i++) {
    for (int j = 0; j < Variables + 1; j++) {
      fscanf(file, "%lf", &Dim[i][j]);
    }
  }

  fclose(file);
  int i;
  double temp;
  for (i = 0; i < FitnessCases; i++) {

    temp =
