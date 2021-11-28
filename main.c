#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *infile = fopen("be.txt", "r");
    FILE *outfile = fopen("ki.txt", "w");
    
    int hegyKornyezet = 0;
    int vizKornyezet = 0;
    int viharKornyezet = 0;
    fscanf(infile, "%d %d %d\n", &hegyKornyezet, &vizKornyezet, &viharKornyezet);
    
    int maxSor;
    int maxOszlop;
    fscanf(infile, "%d %d\n", &maxSor, &maxOszlop);
    
    int** vizek = (int**) malloc(maxSor*sizeof(int*));
    for (int i = 0; i < maxSor; ++i) {
        vizek[i] = (int*) malloc(maxOszlop*sizeof(int));
    }
    int** hegyek = (int**) malloc(maxSor*sizeof(int*));
    for (int i = 0; i < maxSor; ++i) {
        hegyek[i] = (int*) malloc(maxOszlop*sizeof(int));
    }
    int** viharok = (int**) malloc(maxSor*sizeof(int*));
    for (int i = 0; i < maxSor; ++i) {
        viharok[i] = (int*) malloc(maxOszlop*sizeof(int));
    }

    int alkalmashelyek = 0;

    for (int i = 0; i < maxSor; ++i) {
        //char* sortemp = (char*) malloc(maxOszlop*sizeof(char)+2);
        char sortemp[10000];
        fscanf(infile, " %99[^\n]", &sortemp);
        for (int j = 0; j < maxOszlop; ++j) {
            if(sortemp[j] == 'A'){
                hegyek[i][j] = 1;
            } else {
                hegyek[i][j] = 0;
            }
            if(sortemp[j] == 'X'){
                viharok[i][j] = 1;
            } else {
                viharok[i][j] = 0;
            }
            if(sortemp[j] == '~'){
                vizek[i][j] = 1;
            } else {
                vizek[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= hegyKornyezet; ++i) {

        for (int y = 0; y < maxSor; ++y) {
            for (int x = 0; x < maxOszlop; ++x) {

                if(hegyek[y][x] == i){

                    for (int j = 0; j < 3; ++j) {
                        for (int k = 0; k < 3; ++k) {

                            if((y+j-1 >= 0) && (x+k-1 >= 0) && (y+j-1 < maxSor) && (x+k-1 < maxOszlop)){
                                if(hegyek[y+j-1][x+k-1] == 0) {
                                    hegyek[y+j-1][x+k-1] = i+1;
                                }
                            }
                        }
                    }

                }

            }
        }

    }
    printf("Hegyek:\n");
    for (int p = 0; p < maxSor; ++p) {
        for (int q = 0; q < maxOszlop; ++q) {
            printf("%d", hegyek[p][q]);
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 1; i <= vizKornyezet; ++i) {

        for (int y = 0; y < maxSor; ++y) {
            for (int x = 0; x < maxOszlop; ++x) {

                if(vizek[y][x] == i){

                    for (int j = 0; j < 3; ++j) {
                        for (int k = 0; k < 3; ++k) {

                            if((y+j-1 >= 0) && (x+k-1 >= 0) && (y+j-1 < maxSor) && (x+k-1 < maxOszlop)){
                                if(vizek[y+j-1][x+k-1] == 0) {
                                    vizek[y+j-1][x+k-1] = i+1;
                                }
                            }
                        }
                    }

                }

            }
        }

    }
    printf("Vizek:\n");
    for (int p = 0; p < maxSor; ++p) {
        for (int q = 0; q < maxOszlop; ++q) {
            printf("%d", vizek[p][q]);
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 1; i <= viharKornyezet; ++i) {

        for (int y = 0; y < maxSor; ++y) {
            for (int x = 0; x < maxOszlop; ++x) {

                if(viharok[y][x] == i){

                    for (int j = 0; j < 3; ++j) {
                        for (int k = 0; k < 3; ++k) {

                            if((y+j-1 >= 0) && (x+k-1 >= 0) && (y+j-1 < maxSor) && (x+k-1 < maxOszlop)){
                                if(viharok[y+j-1][x+k-1] == 0) {
                                    viharok[y+j-1][x+k-1] = i+1;
                                }
                            }
                        }
                    }

                }

            }
        }

    }
    printf("Viharok:\n");
    for (int p = 0; p < maxSor; ++p) {
        for (int q = 0; q < maxOszlop; ++q) {
            printf("%d", viharok[p][q]);
        }
        printf("\n");
    }
    printf("\n");

    for (int y = 0; y < maxSor; ++y) {
        for (int x = 0; x < maxOszlop; ++x) {
            if((vizek[y][x] != 0) && (hegyek[y][x] != 0) && (viharok[y][x] == 0) && (hegyek[y][x] != 1)){
                printf("1");
                alkalmashelyek++;
            } else {
                printf("0");
            }
        }
        printf("\n");
    }

    
    
    
    
    for (int i = 0; i < maxSor; ++i) {
        free(vizek[i]);
    }
    free(vizek);
    
    for (int i = 0; i < maxSor; ++i) {
        free(hegyek[i]);
    }
    free(hegyek);
    
    for (int i = 0; i < maxSor; ++i) {
        free(viharok[i]);
    }
    free(viharok);

    fprintf(outfile,"%d\n", alkalmashelyek);
    fclose(infile);
    fclose(outfile);
    return 0;
}
