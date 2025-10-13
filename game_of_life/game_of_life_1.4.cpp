// game_of_life_1.3.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>



int main()
{
    int Y = 0;
    int X = 0;
    int difficulte = 0;
    std::cout << "Entrez la taille souhaitee pour votre grille (minimum 10) : \n";
    std::cin >> X >> Y;

    int* grille = new int[Y * X];

    // Initialisation de la grille avec des 0
    for (int i = 0; i < Y; i++)
    {
        for (int j = 0; j < X; j++)
        {
            grille[i * Y + j] = 0;
        }
    }

    // Affichage de la grille

    for (int a = 0; a < X * 2 + 2; a++)
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

    for (int b = 0; b < X * 2 + 2; b++)
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
        tab[i] = A * Y + B;
    }

    int nbr_modif = nombreCellules;

    for (int i = 0; i < Y; i++)
    {
        for (int j = 0; j < X; j++)
        {
            grille[i * Y + j] = 0;
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
    for (int a = 0; a < X * 2 + 2; a++)
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

    for (int b = 0; b < X * 2 + 2; b++)
    {
        std::cout << "-";
    }
    std::cout << "\n";

    int CellIndex = B * Y + A;
    int nbVoisins = 0;

    for (int x = 0; x < X; x++)
    {
        for (int y = 0; y < Y; y++)
        {
            for (int VoisinX = x - 1; VoisinX <= x + 1; VoisinX++)
            {
                for (int VoisinY = y - 1; VoisinY <= y + 1; VoisinY++)
                {
                    if (VoisinX >= 0 && VoisinX < x && VoisinY >= 0 && VoisinY < y)
                    {
                        int IndexVoisin = VoisinX * y + VoisinY;
                        if (IndexVoisin != CellIndex && grille[IndexVoisin] == 1)
                        {
                            nbVoisins++;
                        }
                    }
                }
            }
        }
    }
    return 0;
}