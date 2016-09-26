#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include "complexe.h"

int main()
{
    // Affiche la partie fixe du menu
    AffichageMenu();

    // Initialisation des variables
    int IterationMax;
    int potentiel;
    double Cx,Cy;
    double CxMin;
    double CxMax;
    double CyMin;
    double CyMax;
    double x,y;
    double zoom;
    int choice1,choice2,choice3;
    int Iteration;
    int c1,c2,c3,c4,c5,c6;


    //////////////////// PROFIl COULEUR ////////////////////

    printf("\n\n   Quel profil Couleur souhaitez-vous utiliser :\n");
    printf("\n     1) Fractale de base en noir et blanc\n");
    printf("\n     2) Fractale de base personalis%ce\n",130);
    printf("\n     3) Fractale %c ombre grise\n",133);
    printf("\n     4) Fractale %c d%cgrad%c discret orang%c\n",133,130,130,130);
    printf("\n     5) Fractale %c d%cgrad%c rouge utilisant les racines car%ces\n",133,130,130,130);
    printf("\n     6) Fractale %c d%cgrad%c de variation de rouge bas%ce ",133,130,130,130);
    printf("\n        sur le rapport IterationMax/Nombre d'Iteration\n");
    printf("\n     7) Fractale %c d%cgrad%c de bleu avec optimisation Bitswap\n",133,130,130);
    printf("\n     8) Fractale %c polyn%cme de Bernstein\n",133,147);
    printf("\n     9) Fractale %c d%ccomposition binaire LSM/M (Noir/Blanc)\n",133,130);
    printf("\n    10) Fractale %c coloriage continue (gr%cce au 'Normalized Iteration Count')\n",133,131);
    printf("\n    11) Fractale %c coloriage continue (gr%cce au 'Normalized Iteration Count')",133,131);
    printf("\n        l%cgerement modifi%c\n\n",130,130);

    do
    {
        printf("     Votre choix : ");
        fflush(stdin);
    }
    while(((scanf ("%d", &choice3))==0) || (choice3 < 1) || (choice3 > 11));
    system ("cls");
    AffichageMenu();

    if (choice3 == 2)
    {
        printf("\n\n   Pour l'int%crieur de la Mandelbrot :\n",130);
        printf("\n\n   Entrez le code couleur ROUGE d%csir%c :\n",130,130);
        do
        {
            printf("\n     - Code (compris entre 0 et 255 : ");
            fflush(stdin);
        }
        while(((scanf ("%d", &c1))==0) || (c1 < 0) || (c1 > 255));

        printf("\n\n   Entrez le code couleur VERT d%csir%c :\n",130,130);
        do
        {
            printf("\n     - Code (compris entre 0 et 255 : ");
            fflush(stdin);
        }
        while(((scanf ("%d", &c2))==0) || (c2 < 0) || (c2 > 255));

        printf("\n\n   Entrez le code couleur BLEU d%csir%c :\n",130,130);
        do
        {
            printf("\n     - Code (compris entre 0 et 255 : ");
            fflush(stdin);
        }
        while(((scanf ("%d", &c3))==0) || (c3 < 0) || (c3 > 255));

        printf("\n\n   Pour l'exterieur de la Mandelbrot :\n");
        printf("\n\n   Entrez le code couleur ROUGE d%csir%c :\n",130,130);
        do
        {
            printf("\n     - Code (compris entre 0 et 255 : ");
            fflush(stdin);
        }
        while(((scanf ("%d", &c4))==0) || (c4 < 0) || (c4 > 255));

        printf("\n\n   Entrez le code couleur VERT d%csir%c :\n",130,130);
        do
        {
            printf("\n     - Code (compris entre 0 et 255 : ");
            fflush(stdin);
        }
        while(((scanf ("%d", &c5))==0) || (c5 < 0) || (c5 > 255));

        printf("\n\n   Entrez le code couleur BLEU d%csir%c :\n",130,130);
        do
        {
            printf("\n     - Code (compris entre 0 et 255 : ");
            fflush(stdin);
        }
        while(((scanf ("%d", &c6))==0) || (c6 < 0) || (c6 > 255));
        system ("cls");
        AffichageMenu();
    }


    //////////////////// DIMENSION ////////////////////

    printf("\n\n   Quel dimension d'image souhaitez-vous :\n");
    printf("\n     1) Dimension optimale 3000x3000p (environ 20mo) == Encodage long\n");
    printf("\n     2) Dimension r%cduite 800x800p (environ 1,8mo) == Encodage rapide \n",130);
    printf("\n     3) Dimension %clev%ce 8000x8000p (environ 187mo) == Encodage tr%cs long\n",130,130,138);
    printf("\n     4) Dimension personalis%ce \n\n",130);
    // Saisie sécurisée
    do
    {
        printf("     Votre choix : ");
        fflush(stdin);
    }
    while(((scanf ("%d", &choice1))==0) || (choice1 < 1) || (choice1 > 4));

    system ("cls");
    AffichageMenu();

    // Coordonnées de l'écran // screen (integer) coordinate
    int iX,iY;
    int iXmax;
    int iYmax;

    if (choice1 == 1)
    {
        iXmax = 3000;
        iYmax = 3000;
    }
    else if (choice1 == 2)
    {
        iXmax = 800;
        iYmax = 800;
    }
    else if (choice1 == 3)
    {
        iXmax = 8000;
        iYmax = 8000;
    }
    else if (choice1 == 4)
    {
        printf("\n\n   Entrez la r%csolution d%csir%c :\n",130,130,130);
        do
        {
            printf("\n     - Dimension en largeur : ");
            fflush(stdin);
        }
        while(((scanf ("%d", &iXmax))==0) || (iXmax < 1));
        do
        {
            printf("\n     - Dimension en hauteur : ");
            fflush(stdin);
        }
        while(((scanf ("%d", &iYmax))==0) || (iYmax < 1));
        system ("cls");
        AffichageMenu();
    }

    //////////////////// ZOOM ////////////////////

    printf("\n\n   Quel Zoom voulez-vous :\n");
    printf("\n     1) Zoom Par d%cfaut\n",130);
    printf("\n     2) Zoom vers la vall%ce de l'Hippocampe\n",130);
    printf("\n     3) Zoom vers la vall%ce de l'%clephant\n",130,130);
    printf("\n     4) Zoom vers la vall%ce %c triple spirale\n",130,133);
    printf("\n     5) Zoom vers la mini Mandelbrot\n");
    printf("\n     6) Zoom vers la deuxi%cme mini Mandelbrot\n",138);
    printf("\n     7) Zoom vers la vall%ce des sceptres\n",130);
    printf("\n     8) Zoom Personalis%c\n\n",130);

    do
    {
        printf("     Votre choix : ");
        fflush(stdin);
    }
    while(((scanf ("%d", &choice2))==0) || (choice2 < 1) || (choice2 > 8));

    system ("cls");
    AffichageMenu();

    if (choice2 == 1)
    {
        // Ensemble de Mandelbrot toujours compris entre -2.1 et 0.6 sur axe des abscisse
        // et -1.2 et 1.2 sur axe des ordonnées
        CxMin = -2.1;
        CxMax = 0.6;
        CyMin = -1.2;
        CyMax = 1.2;
    }

    else if (choice2 == 2)
    {
        x = -0.75;
        y = -0.055;
        zoom = 0.05;
        CxMin = x - zoom;
        CxMax = x + zoom;
        CyMin = y - zoom;
        CyMax = y + zoom;
    }

    else if (choice2 == 3)
    {
        x = 0.279;
        y = 0;
        zoom = 0.03;
        CxMin = x - zoom;
        CxMax = x + zoom;
        CyMin = y - zoom;
        CyMax = y + zoom;
    }

    else if (choice2 == 4)
    {
        x = -0.088;
        y = 0.654;
        zoom = 0.03;
        CxMin = x - zoom;
        CxMax = x + zoom;
        CyMin = y - zoom;
        CyMax = y + zoom;
    }

    else if (choice2 == 5)
    {
        x = -1.7705;
        y = 0;
        zoom = 0.03;
        CxMin = x - zoom;
        CxMax = x + zoom;
        CyMin = y - zoom;
        CyMax = y + zoom;
    }

    else if (choice2 == 6)
    {
        x = -0.1592;
        y = -1.0317;
        zoom = 0.02;
        CxMin = x - zoom;
        CxMax = x + zoom;
        CyMin = y - zoom;
        CyMax = y + zoom;
    }

    else if (choice2 == 7)
    {
        x = -1.369;
        y = 0.006;
        zoom = 0.005;
        CxMin = x - zoom;
        CxMax = x + zoom;
        CyMin = y - zoom;
        CyMax = y + zoom;
    }

    else if (choice2 == 8) // Entrer -1.5 et -0.1
    {
        printf("\n                         Guide zoomique de la fractale \n");
        printf("                  Pour d%ccouvrir soi-m%cme la fractale de Mandelbrot:\n\n",130,136);
        printf("            La vall%ce de l'Hippocampe : x = -0.75 et y = -0.055\n",130);
        printf("            La vall%ce de l'%cl%cphant : x = 0.279 et y = 0\n",130,130,130);
        printf("            La vall%ce de la triple spirale : x = -0.088 et y = 0.654\n",130);
        printf("            La mini Mandelbrot : x = -1.7705 et y = 0\n");
        printf("            La seconde mini Mandelbrot : x = -0.1592 et y = -1.0317\n");
        printf("            La vall%ce des sceptres : x = -1.369 et y = 0.006\n",130);
        printf("\n                              _________________\n");


        printf("\n   Entrez l'axe x (compris entre -2.1 et 0.6) :\n");
        do
        {
            printf("     Votre choix : ");
            fflush(stdin);
        }
        while(((scanf ("%lf", &x))==0) || (x < -2.1) || (x > 0.6));
        printf("\n   Entrez l'axe y (compris entre -1.2 et 1.2) :\n");
        do
        {
            printf("     Votre choix : ");
            fflush(stdin);
        }
        while(((scanf ("%lf", &y))==0) || (y < -1.2) || (y > 1.2));
        printf("\n   Entrez la profondeur du zoom :\n");
        do
        {
            printf("     Votre choix : ");
            fflush(stdin);
        }
        while(((scanf ("%lf", &zoom))==0) || (zoom < 0.00000000000001) || (zoom > 100));
        CxMin = x - zoom;
        CxMax = x + zoom;
        CyMin = y - zoom;
        CyMax = y + zoom;
        system ("cls");
        AffichageMenu();
    }

    //////////////////// ITERATION ////////////////////
    printf("\n   Entrez le nombre d'it%crations voulu \n   (maximum 1 000 000 pour des raisons de performance):\n\n",130);
    do
    {
        printf("     Votre choix : ");
        fflush(stdin);
    }
    while(((scanf ("%d", &IterationMax))==0) || (IterationMax < 1) || (IterationMax > 1000000));
    system ("cls");
    AffichageMenu();

    // Calcule de la taille de l'image :
    double PixelWidth = (CxMax - CxMin) / iXmax;
    double PixelHeight = (CyMax - CyMin) / iYmax;

    // Mise en place des couleurs codées de 0 à 255
    // => Un octet represente 2^8 soit 256 valeurs.
    const int MaxColorComponentValue = 255;

    // Génération du fichier image au format .PPM
    // Qui contiendra la fractale dessinée
    FILE * fp;
    char *filename = "fractale 1.0.ppm";
    char *comment = "# ";

    // Tableau "color" pour l'instauration de plusieurs couleurs dans la fractale
    static unsigned char color[3];

    // Initialisation des nombres complexes à l'aide de la structure t_complexe
    /* Z1 = Z1reel + Z1imaginaire*i  */
    t_complexe Z1;
    /* Z2 = Z2reel + Z2imaginaire*i  */
    t_complexe Z2;

    // IterationMax = 1000; // Suffisant pour obtenir une image de bonne qualité.

    // Initialisation du "Escape Radius"
    // Plus il sera élevé, plus il y aura d'itérations
    double EscapeRadius = 2; // compris dans cercle de rayon 2.
    double EscapeRadius2 = EscapeRadius*EscapeRadius;

    // Création d'un nouveau fichier, lui donne un nom et y écrit dedans en mode binaire
    fp = fopen(filename,"wb"); // wb pour écriture binaire : "Binary writing"

    // Ecriture ASCII dans l'en-tête du fichier
    fprintf(fp,"P6\n %s\n %d\n %d\n %d\n",comment,iXmax,iYmax,MaxColorComponentValue);

    // Calcul et écriture de l'image dans le fichier
    for(iY = 0; iY < iYmax; iY++)
    {
        Cy = (CyMin + (iY*PixelHeight));

        if (fabs(Cy) < PixelHeight/2) Cy = 0.0; // Pour l'antenne principale

        for(iX = 0; iX < iXmax; iX++)
        {
            Cx = CxMin + (iX*PixelWidth);

            // Fonction calculant le nombre d'Itérations:
            /* EnsembleDeMandelbrot(Cx,Cy,IterationMax,EscapeRadius2); */
            // Mais la fonction ne fonctionne pas dans le programme

            // Valeur initiale de l'orbite => Point critique à Z = 0
            Z1.r = 0.0;
            Z1.i = 0.0;
            Z2.r = Z1.r*Z1.r;
            Z2.i = Z1.i*Z1.i;
            // Boucle vérifiant si le complexe fait partit de l'ensemble de Mandelbrot ou non
            for (Iteration = 0; Iteration < IterationMax && ((Z2.r + Z2.i) < EscapeRadius2); Iteration++)
            {
                Z1.i = 2*Z1.r*Z1.i + Cy;
                Z1.r = Z2.r - Z2.i + Cx;
                Z2.r = Z1.r*Z1.r;
                Z2.i = Z1.i*Z1.i;
            };

            if (Iteration == IterationMax)
            {
                // Coloriage personnalisée choix 2)
                if (choice3 == 2)
                {
                    color[0]=c1;
                    color[1]=c2;
                    color[2]=c3;
                }
                else
                {
                    // S'il appartient à l'ensemble de Mandelbrot, coloriage en noir
                    color[0]=0;
                    color[1]=0;
                    color[2]=0;
                }
            }

            else if (Iteration < IterationMax)
            {
                // 1) Profil de base en noir et blanc
                if (choice3 == 1)
                {
                    // Coloriage en blanc si le point n'appartient pas à l'ensemble de Mandelbrot
                    color[0]=255;
                    color[1]=255;
                    color[2]=255;
                }
                // 2) Profil de base personalisé
                if (choice3 == 2)
                {
                    // Coloriage personalisé
                    color[0]=c4;
                    color[1]=c5;
                    color[2]=c6;
                }
                // 3) Profil Gris dégradé classe basique
                else if (choice3 == 3)
                {
                    color[0] = Iteration;
                    color[1] = Iteration;
                    color[2] = Iteration;
                }
                // Dégradé discret orangé
                else if (choice3 == 4)
                {
                    Iteration ++;
                    color[0]= Iteration+9;
                    color[1]= Iteration/4;
                    color[2]=0;
                }
                // Dégradé rouge utilisant les racines
                else if (choice3 == 5)
                {
                    color[0]= Iteration*7;
                    color[1]= sqrt(Iteration);
                    color[2]= sqrt(Iteration);
                }
                // Dégradé à variation de rouge
                if (choice3 == 6)
                {
                    color[0]=255;
                    color[1]=((IterationMax/Iteration)*64);
                    color[2]=((IterationMax/Iteration)*128);
                }
                // Beau dégradé à optimisation Bitswap:
                else if (choice3 == 7)
                {
                    /* Iteration ++;*/
                    color[0]= (255*(Iteration>>5)/7);
                    color[1]= (255*((Iteration>>2))/7);
                    color[2]= (255*(Iteration)/3);
                }
                // 3) Fractale à polynôme de Bernstein
                else if (choice3 == 8)
                {
                    double t = (double)Iteration/(double)IterationMax;
                    color[0] = (int)(9*(1-t)*t*t*t*255);
                    color[1] = (int)(15*(1-t)*(1-t)*t*t*255);
                    color[2] = (int)(8.5*(1-t)*(1-t)*(1-t)*t*255);
                }
                // Profil de décomposition binaire LSM/M
                else if (choice3 == 9)
                {
                    if (Z1.i>0)
                    {
                        color[0]=0;
                        color[1]=0;
                        color[2]=0;
                    }
                    else
                    {
                        color[0]=255;
                        color[1]=255;
                        color[2]=255;
                    }
                }
                // Fractale à coloriage continue
                else if (choice3 == 10)
                {
                    potentiel = Iteration + 1 - log(log(sqrt(Z2.r + Z2.i)))/log(2); // Autrement : potentiel = Iteration + (log(log(4)) - log(log(sqrt(Z2.r+Z2.i)))/log(2);
                    color[0] = (((potentiel*2))%512); // ou 255
                    color[1] = (((potentiel*3))%512);
                    color[2] = (((potentiel*5))%512);
                }
                // Fractale à coloriage continue
                if (choice3 == 11)
                {
                    int brightness = 256 * log2(1.75 + Iteration - log2(log2(sqrt(Z2.r + Z2.i))))/log2(IterationMax);
                    color[0]=brightness;
                    color[1]=brightness;
                    color[2]=255;
                }
            }
            /*Met les couleurs dans le fichier*/
            fwrite(color,1,3,fp);
        }
        // Fonction de chargement
        Chargement(iY,iYmax);
    }

    printf("\n      Fractale g%cn%cr%c.\n",130,130,130);
    printf("\n      [Appuyer sur une touche pour fermer le programme]\n");

    fclose(fp);
    return 0;
}
