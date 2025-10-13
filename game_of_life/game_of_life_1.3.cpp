// game_of_life_1.3.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>



int main()
{
    int Y = 0;
    int X = 0;
    int difficulte = 0;
    std::cout << "Entrez la taille souhaitee pour votre grille (minimum 10) : \n";
    std::cin >> Y >> X;

    int* grille = new int[Y * X];

    // Initialisation de la grille avec des 0
    for (int i = 0; i < Y; i++)
    {
        for (int j = 0; j < X; j++)
        {
            grille[i * X + j] = 0;
        }
    }

    // Affichage de la grille

    for (int a = 0; a < Y * 2 + 2; a++)
    {

        std::cout << "-";
    }
    std::cout << "\n";

    for (int i = 0; i < Y; i++)
    {
        std::cout << "|";
        for (int j = 0; j < X; j++)
        {
            std::cout << (grille[i * X + j] == 1 ? "0" : ".") << " ";
        }
        std::cout << "|";
        std::cout << "\n";
    }

    for (int b = 0; b < Y * 2 + 2; b++)
    {
        std::cout << "-";
    }

    std::cout << "\n";
    std::cout << "Choisissez la difficulte : \n 1 pour 10 cellules, \n 2 pour 15 cellules,\n et 3 pour 20 cellules.\n";
    std::cin >> difficulte;

    int nombreCellules = 0;

    if (difficulte == 1)
    {
        nombreCellules = 10;
    }
    else if (difficulte == 2)
    {
        nombreCellules = 15;
    }
    else if (difficulte == 3)
    {
        nombreCellules = 20;
    }
    else
    {
        std::cout << "Difficulte invalide.\n";
        return 1;
    }

    std::cout << "Les coordonnees sont alors egales a " << Y << " a la verticale, et " << X << " a l'horizontale. \n";
    std::cout << "Sachant cela, veuillez entrer les coordonnees des cellules vivantes que vous voulez placer :\n";
    std::cout << "exemple : 1 puis 2 (1 = horizontale, 2 = verticale)\n";

    int A = 0;
    int B = 0;
    int* tab = new int[nombreCellules];

    for (int i = 0; i < nombreCellules; i++)
    {
        std::cout << "Entrez les coordonnees numero " << i + 1 << " : \n";
        std::cin >> A >> B;
        if (A < 0 || A >= X || B < 0 || B >= Y)
        {
            std::cout << "Coordonnees invalides \n ";
            return 1;
        }
        tab[i] = B * X + A;
    }

    int nbr_modif = nombreCellules;

    for (int i = 0; i < Y; i++)
    {
        for (int j = 0; j < X; j++)
        {
            grille[i * X + j] = 0;
        }
    }

    for (int i = 0; i < nbr_modif; i++)
    {
        int index = tab[i];

        if (index >= 0 && index < Y * X) {
            grille[index] = 1;
        }
    }

    // Affichage de la grille
    for (int a = 0; a < Y * 2 + 2; a++)
    {

        std::cout << "-";
    }
    std::cout << "\n";

    for (int i = 0; i < Y; i++)
    {
        std::cout << "|";
        for (int j = 0; j < X; j++)
        {
            std::cout << (grille[i * X + j] == 1 ? "0" : ".") << " ";
        }
        std::cout << "|";
        std::cout << "\n";
    }

    for (int b = 0; b < Y * 2 + 2; b++)
    {
        std::cout << "-";
    }
    std::cout << "\n";

    for (int z = 0; z < Y * X; z++)
    {
        int x = z % X;
        int y = z / X;
        int voisins_zero = 0;

        for (int Xvoisin = -1; Xvoisin <= 1; Xvoisin++)
        {
            for (int Yvoisin = -1; Yvoisin <= 1; Yvoisin++)
            {
                if (Xvoisin == 0 && Yvoisin == 0) continue; // ignorer la cellule elle-même

                int IndexX = x + Xvoisin;
                int IndexY = y + Yvoisin;

                if (IndexX >= 0 && IndexX < X && IndexY >= 0 && IndexY < Y)
                {
                    int index_voisin = IndexY * X + IndexX;
                    if (grille[index_voisin] == 0)
                        voisins_zero++;

                    for (int a = 0; a < Y * 2 + 2; a++)
                    {

                        std::cout << "-";
                    }
                    std::cout << "\n";

                    for (int i = 0; i < Y; i++)
                    {
                        std::cout << "|";
                        for (int j = 0; j < X; j++)
                        {
                            std::cout << (grille[i * X + j] == 1 ? "0" : ".") << " ";
                        }
                        std::cout << "|";
                        std::cout << "\n";
                    }

                    for (int b = 0; b < Y * 2 + 2; b++)
                    {
                        std::cout << "-";
                    }

                    std::cout << "\n";
                }
            }
        }

        if (grille[z] == 0 && voisins_zero < 3)
            grille[z] = 1;
        else if (grille[z] == 1 && voisins_zero > 3)
            grille[z] = 0;
        else
            grille[z] = grille[z]; 
    }

    return 0;
}