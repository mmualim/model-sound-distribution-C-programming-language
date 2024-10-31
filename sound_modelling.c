/* Solution to comp20005 Assignment 2, 2020 semester 2.

   Authorship Declaration:
   Name : Merlyvia Mualim
   Student Id : 1086238
   Due date : 4pm Wednesday, 28th October 2020 
   
   C programming is fun!*/

#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAXLINE 99
#define THRESHOLD_55 55
#define THRESHOLD_60 60
#define THRESHOLD_70 70
#define THRESHOLD_80 80
#define THRESHOLD_90 90
#define THRESHOLD_100 100
#define TOTALPOINTS 5929

/*Struct to store the file data*/
typedef struct {
    double x_coordinates, y_coordinates, sound_level;
    char variable;
} data_t;

/*Function to read the file and putting it into an array*/
int load(data_t records[]) {
    int count = 0;
    while(scanf("%c %lf %lf %lf\n", &records[count].variable, 
                &records[count].x_coordinates, &records[count].y_coordinates, 
                &records[count].sound_level) != EOF) {
        count++;
    }
    return count;
}

/*calculate the distance from (0,0) to location*/
double dist(double x, double y) {
    double distance = 1/(sqrt(pow(x, 2)+pow(y, 2)));
    return distance;
}

/*Calculating the loudspeakers*/
int counting_speakers(data_t records[]) {
    int i = 0;
    while (records[i].variable == 'S') {
        i++;
    }
    return i;
}

/*calculate L_sum*/
double L_sum(data_t records[], int loudspeakers, double x, double y) {
    double total = 0, L;
    for (int i=0; i<loudspeakers; i++) {
        double distance = dist(records[i].x_coordinates - x, 
                               records[i].y_coordinates - y);
        L = records[i].sound_level + 20*log10(distance);
        total = total + pow(10, (L/10));
    }
    double L_sum = 10*log10(total);
    return L_sum;
}

/*Stage 1*/
void Stage1(double Lsum, int loudspeakers) {
    printf("Stage 1\n==========\n");
    printf("Number of loudspeakers: %02d\n", loudspeakers);
    printf("Sound level at (000.0, 000.0): %.2f dB\n", Lsum);
}

/*Stage 2*/
void Stage2(data_t records[], int loudspeakers, int count) {
    printf("\nStage 2\n==========\n");
    for (int i = loudspeakers; i<count; i++) {
        double Lsum = L_sum(records, loudspeakers, records[i].x_coordinates, 
                            records[i].y_coordinates);
        printf("Sound level at (%05.1f, %05.1f): %.2f dB\n", 
               records[i].x_coordinates, records[i].y_coordinates, Lsum);
    }
}

/*Stage 3*/
void Stage3(data_t records[], int loudspeakers) {
    double count = 0;
    for (int x=4; x<=308; x=x+4) {
        for (int y=4; y<=308; y=y+4) {
            double Lsum = L_sum(records, loudspeakers, x, y);
            if (Lsum<=THRESHOLD_55) {
                count++;
            }
        }
    }
    double percentage = (count/TOTALPOINTS)*100;
    printf("\nStage 3\n==========\n");
    /*will always be 5929 points since the grid is 312x312*/
    printf("5929 points sampled\n"); 
    printf("%04.0f points (%05.2f%%) have sound level <= 55 dB\n", count, 
           percentage);
}

/*Stage 4*/
void Stage4(data_t records[], int loudspeakers) {
    printf("\nStage 4\n==========\n");
    for (int y=300; y>=12; y=y-24) {
        for (int x=6; x<=306; x=x+12) {
            double Lsum = L_sum(records, loudspeakers, x, y);
            if (Lsum<=THRESHOLD_55) {
                printf("-");
            }
            else if (Lsum<THRESHOLD_60) {
                printf(" ");
            }
            else if (Lsum<THRESHOLD_70) {
                printf("6");
            }
            else if (Lsum<THRESHOLD_80) {
                printf(" ");
            }
            else if (Lsum<THRESHOLD_90) {
                printf("8");
            }
            else if (Lsum<THRESHOLD_100) {
                printf(" ");
            }
            else if (Lsum>=THRESHOLD_100) {
                printf("+");
            }
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {

    data_t records[MAXLINE];
    int count = load(records);
    int loudspeakers = counting_speakers(records);

    /*Stage 1 run*/
    double x_initial = 0.0, y_initial = 0.0;
    double Lsum_1 = L_sum(records, loudspeakers, x_initial, y_initial);
    Stage1(Lsum_1, loudspeakers);

    /*Stage 2 run*/
    Stage2(records, loudspeakers, count);

    /*Stage 3 run*/
    Stage3(records, loudspeakers);

    /*Stage 4 run*/
    Stage4(records, loudspeakers);

    return 0;
}