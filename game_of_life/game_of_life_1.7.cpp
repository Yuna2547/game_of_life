// game_of_life_1.3.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <chrono>
#include <conio.h>
#include <fstream>
#include <sstream>

void AfficheGrille(int* grille, int X, int Y) { //fonction servant a creer une grille a partir des donnees et coordonnées entrées en parametre
    for (int a = 0; a < X * 2 + 2; a++) { //purement esthetique, rajoute des "-" pour delimiter la grille

        std::cout << "-";
    }
    std::cout << "\n";

    for (int i = 0; i < Y; i++) {
        std::cout << "|";
        for (int j = 0; j < X; j++) {
            std::cout << (grille[i * X + j] == 1 ? "0" : ".") << " "; //parcourt la grille, affichant les 0 en "." et les 1 en 0
        }
        std::cout << "|"; // delimitation esthetique de la grille 
        std::cout << "\n";
    }

    for (int b = 0; b < X * 2 + 2; b++) {  //purement esthetique, rajoute des "-" pour delimiter la grille
        std::cout << "-";
    }
    std::cout << "\n";

}

int CalcVoisins(int* grille, int X, int Y, int x, int y) { //fonction qui recherche les voisins d'une coordonnee
    int CellIndex = x * X + y;
    int nbVoisins = 0;

    for (int VoisinX = x - 1; VoisinX <= x + 1; VoisinX++) {
        for (int VoisinY = y - 1; VoisinY <= y + 1; VoisinY++) {
            if (VoisinX >= 0 && VoisinX < X && VoisinY >= 0 && VoisinY < Y) { //verifie si voisins dans grille
                int IndexVoisin = VoisinX * Y + VoisinY;
                if (IndexVoisin != CellIndex && grille[IndexVoisin] == 1) {//verifie que pas cellule meme
                    nbVoisins++;
                }
            }
        }
    }
    return nbVoisins;
}

int main() {
    int choice = 0;
    while (choice != 1) { //condition pour eviter au joueur d'entrer une donnee incorrecte
        int Y = 0;
        int X = 0;
        int difficulte = 0;
        while (X < 10 || Y < 10) { //condition pour eviter au joueur d'entrer une donnee incorrecte
            std::cout << "Entrez la taille souhaitee pour votre grille, horizontale puis verticale (minimum 10 et maximum 100) : \n";
            std::cin >> X >> Y;
            if (X < 10 && Y <= 10 || X <= 10 && Y < 10) { //empeche le joueur d'entrer une donnee trop petite
                std::cout << "Veuillez entrer une taille valide, superieure a 10 \n";
            }
            else if (X > 100 && Y > 100) //empeche le joueur d'entrer une donnee trop grande
            {
                std::cout << "Ca fait beaucoup la non?";
            }
        }

        int* grille = new int[Y * X];

        // Initialisation de la grille avec des 0
        for (int i = 0; i < Y; i++) {
            for (int j = 0; j < X; j++) {
                grille[i * X + j] = 0;
            }
        }

        // Affichage de la grille
        AfficheGrille(grille, X, Y);

        int textOrByHand = 0;

        while (textOrByHand != 1 && textOrByHand != 2) //condition pour eviter au joueur d'entrer une donnee incorrecte
        {
            std::cout << "Voulez vous ecrire les coordonnees ou lire un fichier texte? \n\n";
            std::cout << " - 1 pour fichier texte \n(les coordonnees sont deja pretes dans un fichier texte)\n\n - 2 pour ecriture main \n(vous devez entrer les coordonness vous - meme) \n\n";
            std::cin >> textOrByHand;

            if (textOrByHand == 2) { //ce choix permet au joueur d'entrer les coordonnees lui meme
                int nombreCellules = 0;
                while (difficulte != 1 && difficulte != 2 && difficulte != 3) { //condition pour eviter au joueur d'entrer une donnee incorrecte
                    std::cout << "\n";
                    std::cout << "Choisissez la difficulte :\n\n - 1 pour 10 cellules vivantes,\n - 2 pour 15 cellules vivantes,\n - 3 pour 20 cellules vivantes.\n\n";
                    std::cin >> difficulte;

                    //choix du nombre de cellule a placer
                    if (difficulte == 1) {
                        nombreCellules = 10;
                    }
                    else if (difficulte == 2) {
                        nombreCellules = 15;
                    }
                    else if (difficulte == 3) {
                        nombreCellules = 20;
                    }
                    else {
                        std::cout << "Difficulte invalide.\n";
                    }
                }

                system("cls");
                std::cout << "Les coordonnees vont de 0 a " << Y - 1 << " a la verticale, et de 0 a " << X - 1 << " a l'horizontale. \n";
                std::cout << "Sachant cela, veuillez entrer les coordonnees des cellules vivantes que vous voulez placer :\n";
                std::cout << "exemple : 1 puis 2 (1 = horizontale, 2 = verticale)\n";

                int A = 0;
                int B = 0;
                int* tab = new int[nombreCellules];
                int nbr_modif = nombreCellules;

                for (int i = 0; i < nombreCellules; i++) { // boucle pour entrer toutes les coordonnées, le joueur doit en rentrer (nombreCellules)
                    int test = 0;
                    while (test != 1) {
                        std::cout << "Entrez les coordonnees numero " << i + 1 << " : \n";
                        std::cin >> A >> B;

                        bool IsValid = true;
                        int index = A * X + B;
                        for (int k = 0; k < i; k++) { //verifie si la coordonnee n'est pas deja existante
                            if (tab[k] == index) {
                                IsValid = false;
                                
                            }
                        }
                        if (IsValid) {
                            if (A >= 0 && A < X && B >= 0 && B < Y) { //la coordonnee est valide si elle rentre dans les limites de la grille
                                tab[i] = A * X + B;
                                test = 1;

                                for (int i = 0; i < Y; i++) {   //initie les coordonnees vides en 0
                                    for (int j = 0; j < X; j++) {
                                        grille[i * X + j] = 0;
                                    }
                                }

                                for (int i = 0; i < nbr_modif; i++) { //initie les coordonnees occupees (cellules vivantes) en 1
                                    int index = tab[i];

                                    if (index >= 0 && index < Y * X) {
                                        grille[index] = 1;
                                    }
                                }

                                system("cls");
                                AfficheGrille(grille, X, Y);

                            }
                            else {
                                IsValid = false; //non valide si elle depasse les limites de la grille
                                std::cout << "Coordonnees invalides \n";
                            }

                        }
                        else { //les coordonnees sont deja prises
                            std::cout << "Coordonnees deja utilisees.\n";

                        }
                        /*
                        int nbr_modif = nombreCellules;

                        for (int i = 0; i < Y; i++) { //initie les coordonnees vides en 0
                            for (int j = 0; j < X; j++) {
                                grille[i * X + j] = 0;
                            }
                        }

                        for (int i = 0; i < nbr_modif; i++) { //initie les coordonnees occupees (cellules vivantes) en 1
                            int index = tab[i];

                            if (index >= 0 && index < Y * X) {
                                grille[index] = 1;
                            }
                        }
                        //clear la console pour afficher la grille a chaque coordonnee affichee*/
                    }
                }

            }

            else if (textOrByHand == 1) { // Lecture depuis fichier texte

                std::ifstream fichier("coordonnees.txt"); // ouverture du fichier
                if (!fichier.is_open()) {
                    std::cout << "Erreur d'ouverture du fichier.";
                    delete[] grille; //delete la grille car le remplissage est impossible
                    grille = nullptr;
                    return 1;
                }

                int A;
                int B;

                while (fichier >> A >> B) {
                    while (!(A >= 0 && A < X && B >= 0 && B < Y)) { //la coordonnee est valide si elle rentre dans les limites de la grille
                        std::cout << "Coordonnees invalides dans le fichier : " << A << " " << B << "\n";
                        std::cout << "Veuillez entrer des coordonnees valides : \n"; //remplace les coordonnees invalides par de nouvelles coordonnees
                        std::cin >> A >> B;
                    }

                    int index = A * X + B;
                    if (grille[index] == 1) {
                        std::cout << "Coordonnees deja utilisees : " << A << " " << B << "\n";
                        std::cout << "Veuillez entrer des coordonnees non dupliquees : \n"; //remplace les coordonnees fausses car deja utilisees
                        std::cin >> A >> B;
                        index = A * X + B;
                    }

                    grille[index] = 1;
                }
            }

            else
            {
                std::cout << "Veuillez entrer un choix valide \n";
            }
            system("cls");
            AfficheGrille(grille, X, Y);
        }



        int* grille_modif = new int[Y * X];
        int nbr_boucle = 0;
        int nbr = 0;
        float vitesse = 0.0f;
        while (nbr <= 0) { // condition pour un choix valide
            //le joueur indique le nombre d'itteration 
            std::cout << "Indiquez le nombre de boucles souhaite : \n";
            std::cin >> nbr;
            if (nbr == 0) {
                std::cout << "0 boucle? Vraiment? Invalide \n";
            }
            else if (nbr < 0) {
                std::cout << "Nombre de boucles invalide \n";
            }
        }

        while (vitesse <= 0.0) { // condition pour un choix valide
            //le joueur indique la vitesse de tic
            std::cout << "Indiquez la vitesse (la vitesse a indiquer est en seconde) : \n";
            std::cin >> vitesse;
            if (vitesse < 0) {
                std::cout << "Vitesse invalide \n";
            }
        }

        auto TimePoint = std::chrono::steady_clock::now(); //ajuste le timer au temps actuel

        std::cout << "Appuie sur la barre d'espace pour stopper la simulation\n";
        while (nbr_boucle < nbr) {//créé la boucle tant que le nombre choisi par le joueur n'est pas atteint

            auto TimePoint2 = std::chrono::steady_clock::now();
            std::chrono::duration<float> Duration = TimePoint2 - TimePoint;
            if (Duration.count() >= vitesse) { //rapidité d'apparition
                TimePoint = std::chrono::steady_clock::now();
                for (int x = 0; x < X; x++) {
                    for (int y = 0; y < Y; y++) {
                        int index = x * Y + y;
                        int nbVoisin = CalcVoisins(grille, X, Y, x, y);
                        if (grille[index] == 1) {//verifie si la cellule est vivante
                            if (nbVoisin == 3 || nbVoisin == 2) {
                                grille_modif[index] = 1;
                            }
                            else {
                                grille_modif[index] = 0;
                            }
                        }

                        if (grille[index] == 0)
                            //verifie si la cellule est morte
                        {
                            if (nbVoisin == 3) {
                                grille_modif[index] = 1;
                            }
                            else {
                                grille_modif[index] = 0;
                            }
                        }
                    }
                }

                //affiche sur la console la grille modifiée pendant le nombre d'iteration choisi
                for (int x = 0; x < X; x++) {
                    for (int y = 0; y < Y; y++) {
                        int index = x * Y + y;
                        grille[index] = grille_modif[index];
                    }
                }
                system("cls");
                AfficheGrille(grille, X, Y);
                nbr_boucle++;

            }
            if (_kbhit()) { //determine la touche qui va mettre en pause le programme
                int Character = _getch();
                if (Character == 32) { //32 correspond a la barre d'espace
                    system("pause");
                }
            }
        }

        int ch = -1;
        while (ch != 0 && ch != 1) { //propose au joueur de continuer (recommencer) ou arreter le programme
            std::cout << "Voulez-vous continuer ? 0 pour oui || 1 pour non\n";
            std::cin >> ch;
            if (ch == 0) {
                std::cout << "C'est reparti \n";
            }
            else if (ch == 1) {
                std::cout << "Okay bye bye!\n";
            }
            else
            {
                std::cout << "Il faut ecrire un chiffre valide ..";
            }
            choice = ch;
        }
        delete grille_modif;
        delete grille;
        grille_modif = nullptr;
        grille = nullptr;
    }
}


