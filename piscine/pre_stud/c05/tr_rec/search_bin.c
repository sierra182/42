#include <stdio.h>
#include <unistd.h>

int rechercheBinaire(int arr[], int gauche, int droite, int x) {
  printf("in\n");
  if (droite >= gauche) {
    int milieu = gauche + (droite - gauche) / 2;
    printf(" int milieu: %d, arr-milieu: %d\n", milieu, arr[milieu]);
    // Si l'élément est présent au milieu
    if (arr[milieu] == x) return milieu;

    // Si l'élément est plus petit que le milieu, il ne peut être présent que dans la partie gauche
    if (arr[milieu] > x) {printf("milieu est plus grand\n"); return rechercheBinaire(arr, gauche, milieu - 1, x);}
    printf("milieu est plus petit\n");
    // Sinon, l'élément ne peut être présent que dans la partie droite
    return rechercheBinaire(arr, milieu + 1, droite, x);
  }
  // Si l'élément n'est pas présent dans le tableau
  printf("L'élément\n");
  return -1;
}

int main() {
  int arr[] = {2, 3, 4, 10, 40, 42, 46, 48, 57, 64, 70, 74, 75, 78, 80, 82, 86, 88, 90, 91, 93, 96, 99};
  int x = 92;
  int n = sizeof(arr) / sizeof(arr[0]);
  int resultat = rechercheBinaire(arr, 0, n - 1, x);
  (resultat == -1) ? printf("L'élément n'est pas présent dans le tableau")
                   : printf("L'élément est présent à l'index %d\n", resultat);
  return 0;
}
