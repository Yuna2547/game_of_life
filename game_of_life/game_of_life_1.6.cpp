// game_of_life_1.3.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <chrono>
#include <conio.h>

void AfficheGrille(int* grille, int X, int Y)
{
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

}

int CalcVoisins(int* grille, int X, int Y, int x, int y)
{
    int CellIndex = x * X + y;
    int nbVoisins = 0;

    for (int VoisinX = x - 1; VoisinX <= x + 1; VoisinX++)
    {
        for (int VoisinY = y - 1; VoisinY <= y + 1; VoisinY++)
        {
            if (VoisinX >= 0 && VoisinX < X && VoisinY >= 0 && VoisinY < Y)

                //verifie si voisins dans grille
            {
                int IndexVoisin = VoisinX * Y + VoisinY;
                if (IndexVoisin != CellIndex && grille[IndexVoisin] == 1)
                    //verifie que pas cellule meme
                {
                    nbVoisins++;
                }
            }
        }
    }
    return nbVoisins;
}

int main()
{
    int choice = 0;
    while (choice != 1)
    {
        int Y = 0;
        int X = 0;
        int difficulte = 0;
        while (X < 10 || Y < 10)
        {
            std::cout << "Entrez la taille souhaitee pour votre grille, horizontale puis verticale (minimum 10) : \n";
            std::cin >> X >> Y;
            if (X < 10 && Y < 10)
            {
                std::cout << "Veuillez entrer une taille valide, superieure a 10 \n";
            }

        }

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
        AfficheGrille(grille, X, Y);

        int nombreCellules = 0;
        while (difficulte != 1 && difficulte != 2 && difficulte != 3)
        {
            std::cout << "\n";
            std::cout << "Choisissez la difficulte :\n1 pour 10 cellules vivantes,\n2 pour 15 cellules vivantes,\net 3 pour 20 cellules vivantes.\n";
            std::cin >> difficulte;



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
            }
        }
        std::cout << "Les coordonnees sont alors egales a " << Y << " a la verticale, et " << X << " a l'horizontale. \n";
        std::cout << "Sachant cela, veuillez entrer les coordonnees des cellules vivantes que vous voulez placer :\n";
        std::cout << "exemple : 1 puis 2 (1 = horizontale, 2 = verticale)\n";

        int A = 0;
        int B = 0;
        int* tab = new int[nombreCellules];
       
       
        for (int i = 0; i < nombreCellules; i++)
        { 
            int test = 0;
            while (test != 1)
            {
                std::cout << "Entrez les coordonnees numero " << i + 1 << " : \n";
                std::cin >> A >> B;
                bool IsValid = true;
                int index = A * X + B;
                for (int k = 0; k < i; k++)
                {
                    if (tab[k] == index)
                    {
                        IsValid = false;
                    }
                }
                if (IsValid)
                {
                    if (A >= 0 && A < X && B >= 0 && B < Y){
                        tab[i] = A * X + B;
                        test = 1;
                    }
                    else {
                        IsValid = false;
                        std::cout << "Coordonnees invalides \n";
                    }

                }
                else
                {
                    std::cout << "Coordonnees deja utilisees.\n";
                    
                }
               
               
            }
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
        AfficheGrille(grille, X, Y);

        int* grille_modif = new int[Y * X];
        int nbr_boucle = 0;
        int nbr = 0;
        float vitesse = 0.0f;
        while (nbr <= 0)
        {
            std::cout << "Indiquez le nombre de boucles souhaite : \n";
            std::cin >> nbr;
            if (nbr == 0)
            {
                std::cout << "0 boucle? Vraiment? Invalide \n";
            }
            else if (nbr < 0)
            {
                std::cout << "Nombre de boucles invalide \n";
            }
        }

        while (vitesse <= 0.0)
        {
            std::cout << "Indiquez la vitesse : \n";
            std::cin >> vitesse;
            if (vitesse < 0)
            {
                std::cout << "Vitesse invalide \n";
            }
        }
        
        auto TimePoint = std::chrono::steady_clock::now();

        std::cout << "Appuie sur la barre d'espace pour stopper la simulation\n";
        while (nbr_boucle < nbr)
            //créé la boucle tant que le nombre choisi par le joueur n'est pas atteint
        {
            auto TimePoint2 = std::chrono::steady_clock::now();
            std::chrono::duration<float> Duration = TimePoint2 - TimePoint;
            if (Duration.count() >= vitesse) //rapidité d'apparition
            {
                TimePoint = std::chrono::steady_clock::now();
                for (int x = 0; x < X; x++)
                {
                    for (int y = 0; y < Y; y++)
                    {
                        int index = x * Y + y;
                        int nbVoisin = CalcVoisins(grille, X, Y, x, y);
                        if (grille[index] == 1)
                            //verifie si la cellule est vivante
                        {
                            if (nbVoisin == 3 || nbVoisin == 2)
                            {
                                grille_modif[index] = 1;
                            }
                            else
                            {
                                grille_modif[index] = 0;
                            }
                        }

                        if (grille[index] == 0)
                            //verifie si la cellule est morte
                        {
                            if (nbVoisin == 3)
                            {
                                grille_modif[index] = 1;
                            }
                            else
                            {
                                grille_modif[index] = 0;
                            }
                        }
                    }
                }

                for (int x = 0; x < X; x++)
                {
                    for (int y = 0; y < Y; y++)
                    {
                        int index = x * Y + y;
                        grille[index] = grille_modif[index];
                    }
                }
                system("cls");
                AfficheGrille(grille, X, Y);
                nbr_boucle++;

            }
            if (_kbhit())
            {
                int Character = _getch();
                if (Character == 32)
                {
                    system("pause");
                }
            }
        }

        int ch = -1;
        while (ch != 0 && ch != 1)
        {
            
            std::cout << "Voulez-vous continuer ? 0 pour oui || 1 pour non\n";
            std::cin >> ch;
            if (ch == 0)
            {
                std::cout << "C'est reparti \n";
            }
            else if (ch == 1)
            {
                std::cout << "Okay bye bye!\n";
            }
            choice = ch;
            
        }
        
        delete grille_modif;
        delete grille;
        grille_modif = nullptr;
        grille = nullptr;

    }
}
