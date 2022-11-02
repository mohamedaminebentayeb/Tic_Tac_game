

#include <stdio.h>
char  T [3][3] = {
   {' ' , ' ' , ' ' },
   {' ' , ' ' , ' ' },
   {' ' , ' ' , ' ' }

} ;
void showTable(char T[3][3])
{
int count = 3 ;
    for (int i = 0; i < count; i++)
    {
for (int j = 0; j < count; j++)
{
printf("%c|",T[i][j]);
}
printf("\n");
    }
    
}


int checkwinner(char T[3][3])
{
    // verefier rles lignes .
    for (int row = 0; row<3; row++)
    {
        if (T[row][0]==T[row][1] &&
            T[row][1]==T[row][2])
        {
            if (T[row][0]=='X')
                return +2;
            else if (T[row][0]=='O')
                return -2;
        }
    }
 
    // verefications des diagonales
    if (T[0][0]==T[1][1] && T[1][1]==T[2][2])
    {
        if (T[0][0]=='X')
            return +2;
        else if (T[0][0]=='O')
            return -2;
    }
 
    if (T[0][2]==T[1][1] && T[1][1]==T[2][0])
    {
        if (T[0][2]=='X')
            return +2;
        else if (T[0][2]=='O')
            return -2;
    }
    // verefier les colonnes 
    for (int col = 0; col<3; col++)
    {
        if (T[0][col]==T[1][col] &&
            T[1][col]==T[2][col])
        {
            if (T[0][col]=='X')
                return +2;
 
            else if (T[0][col]=='O')
                return -2;
        }
    }
    // verefier si le jeux est termine rou pas encore
 for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(T[i][j] != 'X' && T[i][j] != 'O') {
                return 1 ;

            }
        }   
    }    
    return 0;
}

int minimax(char T[3][3], int depth, int isMaximizing, int firstTime ) {
   int score;
   int scorefinal ;
   int x, y;
   int result = checkwinner(T);
    if(depth == 0 || result != 1) {
        return result;
    }

    if(isMaximizing) {
        scorefinal = -100;
  
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(T[i][j] == ' ') {
                    T[i][j] = 'X';
                     score = minimax(T, depth - 1, 0, 0);
                    T[i][j] = ' ';
                    if(score > scorefinal) {
                        scorefinal = score;
                        x = i;
                        y = j;
                    }
                    
                }
                
            }   
        }
        if(firstTime ) {
            T[x][y] = 'O';
        }
        return scorefinal;
    } else {
                 scorefinal = 100;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(T[i][j] == ' ') {
                    T[i][j] = 'O';
                     score = minimax(T, depth - 1, 1, 0);
                    T[i][j] = ' ';
                    if(score < scorefinal) {
                        scorefinal = score;
                        x = i;
                        y = j;
                    }
                 }
                }
            }   
        }
        if(firstTime == 1) {
            T[x][y] = 'O';
        }
        return scorefinal;
    }
void guide(){
        printf("\n ********************************************************* GUIDE*******************************************\n");
        printf ("  \n Entrer 0 pour la premiére ligne / colonne \n ");
        printf ("  \n Entrer 1 pour la deuxiéme ligne / colonne \n ");
        printf ("  \n Entrer 2 pour la troisiéme ligne / colonne \n ");
        printf("\n ********************************************************* GUIDE*******************************************\n");

 }
void TIC_TAC_TAO()
{           int end = 1 ;
            guide();
            while ( end  == 1)
            {int indiceLigne ;
            int indiceColonne ;
            printf("entrer les indices de la case ou vous voullez jouer <taper > ");
            printf("\n ligne :");
            scanf("%d",&indiceLigne);
            printf("\n colonne :");
            scanf("%d",&indiceColonne);
            if(indiceColonne < 3  && indiceLigne < 3 && indiceLigne >=0 && indiceColonne >=0)
            { if (T[indiceLigne][indiceColonne] == ' '){
                    T[indiceLigne][indiceColonne] = 'X';
                    int result = minimax(T, 100, 0 , 1);
                    showTable(T);
                    end = checkwinner(T) ;
                }
                else printf("\ncase déja coché , utiliser une autre case ! \n");

            }
            else printf(" les indices a utiliser sonts 0,1,2 et pas d'autres indices ");


                        if(end  == 2 && end == -2 ) {
                                        printf(" end = %d", end);

                                break;
                            }

            }
            if (end == 2 ){printf(" \n ********************COngratulation , you win !******************\n");};
            if (end == -2 ){printf(" \n ******************** I'm the winner!******************\n");};
            if (end == 0 ){printf(" \n ********************Good job  !******************\n");};


}
void menu ()
{

    printf("\n ************** menu **************\n");
    printf("1- NOUVELLE PARTIE \n");
    printf("2- Quitter \n");

}
void init()
{int count = 3;
    for (int i = 0; i < count; i++)
    {for (int j = 0;j < count; j++)
        {
            T[i][j] = ' ';
        }
    
    }
    
}

void  main() {
    int choix = 0 ;
   
    while (choix != 2)
    {     menu();
printf(" Entrer votre choix : ");
        scanf("%d", & choix);
     switch (choix)
    {
     case 1:
         init();
         TIC_TAC_TAO();
     break;
    
    case 2:
    printf("\n GOOD BYE !\n");
        break;
    }    }
    
    
}