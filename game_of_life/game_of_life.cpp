// game_of_life.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream> 

int main()
{
    int taille = 0;
    int difficulte = 0;
    std::cout << "Entrez la taille souhaitee pour votre grille (minimum 10) : \n";
    std::cin >> taille;

    int** grille = new int* [taille];
    for (int i = 0; i < taille; i++) {
        grille[i] = new int[taille];
    }

    // Initialisation de la grille avec des 0 
    for (int i = 0; i < taille; i++) {
        for (int j = 0; j < taille; j++) {
            grille[i][j] = 0;
        }
    }

    // Affichage de la grille 
    for (int i = 0; i < taille; i++) {
        for (int j = 0; j < taille; j++) {
            std::cout << grille[i][j];
        }
        std::cout << "\n";
    }

    // Libération de la mémoire
    for (int i = 0; i < taille; i++) {
        delete[] grille[i];
    }
    delete[] grille;

    std::cout << "\n";
    std::cout << "Choisissez la difficulte : \n 1 pour quatre cellules, \n 2 pour six cellules,\n et 3 pour huit cellules.\n";
    std::cin >> difficulte;

    std::cout << "Les coordonnees sont alors egales a " << taille << " a l'horizontale, et a la verticale. \n";
    std::cout << "Sachant cela, veuillez entrer les coordonnees des cellules vivantes que vous voulez placer :\n";
    std::cout << "exemple : 1 puis 2 (1 = horizontale, 2 = verticale\n";
    
    int nombreCellules = 0;
   
    if (difficulte == 1) 
    {
        nombreCellules = 4;
    }
    else if (difficulte == 2)
    {
        nombreCellules = 6;
    }
    else if (difficulte == 3)
    {
        nombreCellules = 8;
    }
    else 
    {
        std::cout << "Difficulte invalide.\n";
        return 1;
    }

    int* tableau1 = new int[nombreCellules];
    int* tableau2 = new int[nombreCellules];

    for (int i = 0; i < nombreCellules; i++)
    {
        std::cout << "Entrez les coordonnees numero " << i + 1 << " : \n";
        std::cin >> tableau1[i];
        std::cin >> tableau2[i];
    }

    delete[] tableau1;
    delete[] tableau2;

    return 0;
}
