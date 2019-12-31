#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

int calcule_base(int etage)
{
    int base = 1;
    int buff = 0;
    
    for (int i = 3; i < etage + 3; i++) //etage + 3 = nombre de lignes ( i = 3 car 1 er etage 4 lignes ) 
    {
        base = base + 2 * i; //début : base = 1 ( nombre d'étoile du top )( rajout d'etoiles / calcul d'etoiles de la base du sapin )
    }
    for (int j = 2; j < etage + 1; j++) //Etages de retrait d'étoiles
    {
        buff = floor(j / 2); //Mise de coté de la valeur ( 1 1 2 2 3 3 4 4 etc.. )
        base = base - 2 * buff; //floor = partie entière ( 3.9 = 3 )
    }
    return (base);
}
void add_etoile (int nbr_etoile)
{    
        for (int i = 0; i < nbr_etoile; i++)
        {
            putchar('*');
        }
}

void add_space (int base, int nbr_etoiles)
{
    int nbr_espace = (base - nbr_etoiles) / 2; // ( base = + grosse ligne ) ( nbr_et = nbr et ligne actuelle )
    for(int i = 0; i < nbr_espace; i++)
    {
        putchar(' ');
    }
}

void add_pipe(int base, int etage)
{
    int largeur = 1 + 2 * floor(etage / 2); // 1(etat initial) + 2 tout les 2 
    add_space(base, largeur); // appel de add_space pour les ||
    for (int i = 0; i < largeur; i++)
    {
        putchar('|');
    }
    putchar('\n');
}

int check_error(int etape)
{
    int ok = 1;
    if ( etape <= 0 )
    {
        ok = 0;
        write(1, "Entrez une valeur > 0\n", 23);
    }
    return (ok);
}
    
void tree (int etape)
{
    if (check_error(etape) == 0)
    {
        exit;
    }
    
    int nombre_etoile = 1;
    int nombre_ligne = 4;
    int substrat = 0;
    int sub_etape = 1;
    int base = calcule_base(etape);
    
    for(int i = 0; i < etape; i++)
    {
        if( sub_etape %2 == 0 )
        {
            substrat = substrat + 2;
        }

        nombre_etoile = nombre_etoile - substrat - 2;

        for(int j = 0; j < nombre_ligne; j++)
        {
            nombre_etoile = nombre_etoile + 2;
            add_space(base, nombre_etoile);
            add_etoile(nombre_etoile);
            putchar('\n');
        }
       
        nombre_ligne ++;
        sub_etape ++;
    }
    for( int k = 0; k < etape; k++)
    {
        add_pipe(base, etape);
    }
}

int main(int argc, char **argv)
{
    tree(atoi(argv[1]));
}
