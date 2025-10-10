// game_of_life.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream> 


void CreerEtAfficherGrille(int taille1 , int taille2) 
{
    
    int* grille = new int[taille1 * taille2];

    // Initialisation de la grille avec des 0
    for (int i = 0; i < taille1; i++) 
    {
        for (int j = 0; j < taille2; j++) 
        {
            grille[i * taille2 + j] = 0;
        }
    }

    // Affichage de la grille
    
    for (int a = 0; a < taille1 * 2 + 2; a++)
    {

        std::cout << "-";
    }
    std::cout << "\n";

    for (int i = 0; i < taille1; i++) 
    {
        std::cout << "|";
        for (int j = 0; j < taille2; j++) 
        {
            std::cout << (grille[i * taille2 + j] == 1 ? "0" : ".") << " ";
        }
        std::cout << "|";
        std::cout << "\n";
    }

    for (int b = 0; b < taille1 * 2 + 2; b++)
    {
        std::cout << "-";
    }


    // Libération de la mémoire
    delete[] grille;
    grille = nullptr;
}

void CreerEtModifierGrille(int taille1, int taille2, int* coor, int nbr_modif)
{

    int* grille = new int[taille1 * taille2];

    for (int i = 0; i < taille1; i++) 
    {
        for (int j = 0; j < taille2; j++) 
        {
            grille[i * taille2 + j] = 0;
        }
    }

    for (int i = 0; i < nbr_modif; i++) 
    {
        int index = coor[i];
        
        grille[index] = 1;
        
    }
    
    // Affichage de la grille
    for (int a = 0; a < taille1 * 2 + 2; a++)
    {

        std::cout << "-";
    }
    std::cout << "\n";

    for (int i = 0; i < taille1; i++)
    {
        std::cout << "|";
        for (int j = 0; j < taille2; j++)
        {
            std::cout << (grille[i * taille2 + j] == 1 ? "0" : ".") << " ";
        }
        std::cout << "|";
        std::cout << "\n";
    }

    for (int b = 0; b < taille1 * 2 + 2; b++)
    {
        std::cout << "-";
    }
    delete[] grille;
    grille = nullptr;
}


int main()
{
    int Y = 0;
    int X = 0;
    int difficulte = 0;
    std::cout << "Entrez la taille souhaitee pour votre grille (minimum 10) : \n";
    std::cin >> Y >> X;

    CreerEtAfficherGrille(Y, X);
    
    std::cout << "\n";
    std::cout << "Choisissez la difficulte : \n 1 pour quatre cellules, \n 2 pour six cellules,\n et 3 pour huit cellules.\n";
    std::cin >> difficulte;

    std::cout << "Les coordonnees sont alors egales a " << Y << " a la verticale, et "<< X << " a l'horizontale. \n";
    std::cout << "Sachant cela, veuillez entrer les coordonnees des cellules vivantes que vous voulez placer :\n";
    std::cout << "exemple : 1 puis 2 (1 = horizontale, 2 = verticale)\n";
    
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

    int A = 0;
    int B = 0;
    int* tab = new int[nombreCellules];

    for (int i = 0; i < nombreCellules; i++) 
    {
        std::cout << "Entrez les coordonnees numero " << i + 1 << " : \n";
        std::cin >> A >> B;
        tab[i] = B * X + A; // Attention : B est la ligne (verticale), A la colonne (horizontale)
    }

    CreerEtModifierGrille(Y, X, tab, nombreCellules);

    delete[] tab;

    return 0;
}
