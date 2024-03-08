#include <stdio.h>

// ijuiFonction pour vérifier si un nombre est un palindrome
int estPalindrome(int nombre) {
    int original = nombre;
    int longueur = 0;

    // Calcul de la longueur du nombre
    while (nombre > 0) {
        nombre /= 10;
        longueur++;
    }

    int chiffres[longueur];
    nombre = original;

    // Stockage des chiffres dans un tableau
    for (int i = longueur - 1; i >= 0; i--) {
        chiffres[i] = nombre % 10;
        nombre /= 10;
    }

    // Comparaison des chiffres de gauche à droite et de droite à gauche
    for (int i = 0; i < longueur / 2; i++) {
        if (chiffres[i] != chiffres[longueur - 1 - i]) {
            return 0; // Ce n'est pas un palindrome
        }
    }

    return 1; // C'est un palindrome
}

int main() {
    int max_palindrome = 0;

    // Double boucle pour tester tous les produits i * j
    for (int i = 100; i < 1000; i++) {
        for (int j = 100; j < 1000; j++) {
            int produit = i * j;
            if (estPalindrome(produit) && produit > max_palindrome) {
                max_palindrome = produit;
                printf("%d X %d\n", i, j);
            }
        }
    }

    printf("Le plus grand palindrome produit de deux nombres à trois chiffres est : %d\n", max_palindrome);

    return 0;
}
