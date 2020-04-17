//Shortest Job First Scheduling Algorithm in C

#include <stdio.h>
#include <stdlib.h>



struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int total_around_time;
    int completion_time;
};

typedef struct process Process;


double average_waiting_time;
int total_waiting_time;

double average_total_around_time;
int total__around_time;



void sort_process_by_burst_time(Process p[], int n);
void calculate_completion_time(Process p[], int n);
void calculate_waiting_time(Process p[], int n);
void calculate_total_around_time(Process p[], int n);


int main()
{
    Process p[4];
    int n, i, j;
    

    printf("Enter total process: ");
    scanf("%d", &n);
    printf("Enter burst time for each process:\n");
    for(i=0; i<n; i++) {
        printf("P[%d]: ", i+1);
        scanf("%d", &p[i].burst_time);
        p[i].pid = i+1;
    }
    printf("Enter arrival time for each process:\n");
    for(i=0; i<n; i++) {
        printf("P[%d]: ", i+1);
        scanf("%d", &p[i].arrival_time);
        p[i].pid = i+1;
    }
    given_table( p, n);
    
    sort_process_by_burst_time(p, n);
    calculate_completion_time(p, n);
   
   
    
    calculate_total_around_time(p, n);
    calculate_waiting_time(p, n);
    table( p, n);                   // final table formed
    average_total_around_time = (double) ( (double)total__around_time / (double) n );
    
  
    average_waiting_time = (double) ( (double)total_waiting_time / (double) n );

    puts("");
    printf("=> Average Total Around Time: %.2lf\n",average_total_around_time);
    printf("=> Average Waiting Time: %.2lf\n",average_waiting_time);



    return 0;
}



void sort_process_by_burst_time(Process p[], int n)
{
    int i, j ;
    Process temp;
    for(i=0; i<n-1; i++) {
        for(j=0; j<n-1-i; j++) {
            
            if(p[j].burst_time > p[j+1].burst_time) {
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
               
            }
        }
    }
}

void calculate_completion_time(Process p[], int n)
{
    int i;
   int total_completion_time = 0;
    
    for(i=0; i<n; i++) {
        total_completion_time+=p[i].burst_time;
        p[i].completion_time = total_completion_time;
       
    }
}

    void calculate_total_around_time(Process p[], int n)
{
    int i;
    total__around_time = 0;
    
    for(i=0; i<n; i++) {
         p[i].total_around_time= abs(p[i].completion_time - p[i].arrival_time);
    
         total__around_time+=p[i].total_around_time;
    }

}
void calculate_waiting_time(Process p[], int n)
{
    int i;
    total_waiting_time = 0;
   
    for(i=0; i<n; i++) {
         p[i].waiting_time = 0;
        p[i].waiting_time =abs( p[i].total_around_time - p[i].burst_time);
        total_waiting_time += p[i].waiting_time;
    }
}


