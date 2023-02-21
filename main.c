#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dico.h"
#include "arbre.h"
#include <time.h>

int main(int argc, char* argv[]){
    
    while (1)
    {
        printf("\n");
        char motPioche[100] = {0};
        int coupsRestants,rep;
        long tailleMot = 0;
        char *buffer = NULL;
        TArbre* dico=NULL;
        TArbre* dicoCopy=NULL;
        FILE * fptr;
        //printf("\t -------------------------------------------\n");
        printf("\t ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\n");
        printf("\t ¤                                        ¤\n");
        system("setterm -bold on");
        printf("\t ¤    Bienvenue dans Notre Dictionnaire ¤\n");
        system("setterm -bold off");
        printf("\t ¤                                        ¤\n");
        printf("\t ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\n");
        //printf("\t -------------------------------------------\n");
        //printf("\t | |                                     | |\n");
        //printf("\t | --------------------------------------- |\n");
        //printf("\t -------------------------------------------\n");
            printf("\n \n");
            system("setterm -bold on");
            printf("\t ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤ Menu ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\n \n");
            printf("\t      1- Consulter la simulation            \n");
            printf("\t      2- Consulter le dictionnaire          \n");
            printf("\t      3- Ajouter un mot                     \n");
            printf("\t      4- Vider le dictionnaire              \n \n");
            printf("\t ¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\n \n");
            system("setterm -bold off");
        do
        {
            system("setterm -bold on");
            printf("\t  Option : ");
            system("setterm -bold off");
            scanf("%d",&rep);
        
        } while (rep!=1 && rep !=2 && rep!=3 && rep!=4);

        if (rep==3) {
            fptr = fopen("dico.txt", "a");   
            fputs("riadh\n", fptr);
            fclose(fptr);
            continue;
        }

        if (rep==4) {
            fclose(fopen("dico.txt", "w"));   
            continue;
        }

        system("setterm -bold on");
        printf("\t  Combien de mot à piocher ? : ");
        //printf("\t   ==> ");
        system("setterm -bold off");
        //printf("Réponse: ");
        scanf("%d",&coupsRestants);
        printf("\n \n");
        if(rep==1){
        system("setterm -bold on");
        printf("\t ¤~~~~~~~~~~~¤   Simulation   ¤~~~~~~~~~~~~¤\n \n");
        system("setterm -bold off");
        }
        // Construire un dictionnaire vide
        dico = arbreConsVide();
        /* On continue à jouer tant qu'il reste au moins un coup à jouer */
        while (coupsRestants > 0){
            char motPioche[100] = {0};
            long tailleMot = 0;
            char *buffer = NULL;
            // Piocher un mot
            if (!piocherMot(motPioche))
                exit(0);

            tailleMot = strlen(motPioche);
            buffer = malloc((tailleMot+1) * sizeof(char));
            strcpy(buffer, motPioche);
            if(rep==1){
                printf("\t ¤ MotPioche est ");
                system("setterm -bold on");
                printf("\033[1;31m");
                printf("%s \n",motPioche);
                printf("\033[0;37m");
                system("setterm -bold off");
            }
            dicoInsererMot(buffer, &dico);
            if(rep==1){
                print_ascii_treeInsert(dico,buffer);
            }
            char bufferAff[100]={0}; // Buffer servant à stocker les mots à écrire
            int cur = 0; // Case courante à remplir
        // dicoAfficher(dico,bufferAff,&cur);
            // printf("Le nbr d'occ du mot %s est %d \n",buffer,dicoNbOcc(buffer,dico));
            
            //printf("\n");
            coupsRestants--;
        // printf("Nb coups restants = %d \n",coupsRestants);
        }
        
        system("setterm -bold on");
        printf("\t ¤~~~~~~~~~~~¤  Dictionnaire  ¤~~~~~~~~~~~~¤\n \n");
        //printf("\t  Le dictionnaire : \n");
        printf("\n");
        printf("\t ¤ ");
        system("setterm -bold off");
        printf("Sous la forme d'un tableau : \n");
        char bufferAff[100]={0}; // Buffer servant à stocker les mots à écrire
        int cur = 0;
        
        printf("\t ¤-------------------¤---------------------¤\n");
        printf("\t |        Mot        |  Nombre d'occurance |\n");
        printf("\t ¤-------------------¤---------------------¤\n");
        dicoAfficher(dico,bufferAff,&cur);
        printf("\t ¤-------------------¤---------------------¤\n");
        printf("\t | ");
        system("setterm -bold on");
        printf("Le nb de mot diff ");
        system("setterm -bold off");
        printf("|            %d       |\n",dicoNbMotsDifferents(dico));
        printf("\t | ");
        system("setterm -bold on");
        printf("Le nb de mot tot  ");
        system("setterm -bold off");
        printf("|            %d       |\n",dicoNbMotsTotal(dico));
        printf("\t ¤-------------------¤---------------------¤\n");
        printf("\n");
        system("setterm -bold on");
        printf("\t ¤ ");
        system("setterm -bold off");
        printf("Sous la forme d'une arbre : \n");
        print_ascii_tree(dico);
        arbreSuppr(&dico);
        //return 0;
    }
}