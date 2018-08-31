//Priority Scheduling algorithm (non premptive)



#include<stdio.h>

int main(){

    int n,i;

    printf("Enter the number of processes:\t");

    scanf("%d", &n);

    int burst[n], arr[n], pri[n], process[n];

    printf("Enter the Burst time, Arrival time, Priority : \n");

    for(i=0;i<n;i++){

        printf("For process %d:\n", i);

        scanf("%d%d%d", &burst[i],&arr[i],&pri[i]);

        process[i]=i+1;

    }

    sort(arr,burst,process,pri,3);                                                             //call for sorting

    //gnattchart(burst,process,arr);                                                         //call for gnat chart

return 0;



}



int sort(int arr[],int burst[],int process[],int pri[], int n)

{

    int i,j,a,gnatt[n+1];

    for (i = 0; i < n; ++i) {

        for (j = i + 1; j < n; ++j){

            if (arr[i] > arr[j]) {

                a = arr[i];arr[i] = arr[j];arr[j] = a;

                a = burst[i];burst[i] = burst[j];burst[j] = a;

                a= process[i];process[i] = process[j];process[j] = a;

                a= pri[i];pri[i] = pri[j];pri[j] = a;

            }

        }

    }





gnatt[0]=0;

gnatt[1]=burst[0];

for (i = 1; i < n; ++i) {

        for (j = i + 1; j < n; ++j){

            if (pri[i] > pri[j]) {

                    a= pri[i];pri[i] = pri[j];pri[j] = a;

                a = arr[i];arr[i] = arr[j];arr[j] = a;

                a = burst[i];burst[i] = burst[j];burst[j] = a;

                a= process[i];process[i] = process[j];process[j] = a;

            }

        }

    }

printf("\nGNATT CHART:\n");

printf("\n\t\t\t0\t\t");

for(i=1;i<=n;i++){

gnatt[i]=burst[i-1]+gnatt[i-1];

printf("%d\t\t", gnatt[i]);

}



printf("\n\n\t\t\t");

for(i=0;i<n;i++){

    printf("-->P%d\t\t", process[i]);

}

int tarr[3][2],k, taranswer[3],waittime[3];float ans1=0,ans2=0;

        for( a=0;a<3; a++){

            tarr[a][0]=gnatt[a+1];                      //making tarr multidimensional which is holding two columns for

        }                                               //end time(gnat) and arrival time(arr)

        for(j=0;j<3;j++){

            tarr[j][1]=arr[j];

        }

        for(i=0;i<3;i++){

                taranswer[i]=tarr[i][0]-tarr[i][1];        //turnaround time = end time - arrival time

                 ans1=ans1+taranswer[i];                   //calculating total turn around time

        }











    printf("\n\nTURN AROUND TIME:\t");

        for(i=0;i<3;i++){

            printf("%d\t\t", taranswer[i]);



        }



        for(i=0;i<3;i++){

            waittime[i]=gnatt[i]-arr[i];                    //wait time= when process gets CPU - arrival time

            ans2=ans2+waittime[i];                          //calculating wait time

        }



    printf("\n\n\nWAITTIME:\t\t");

        for(i=0;i<3;i++){

            printf("%d\t\t",  waittime[i]);

        }



    printf("\n\n\nAverage turnaround time:\t %f",ans1/3 );

    printf("\n\n\nAverage waiting time   :\t %f\n\n\n\n",ans2/3 );



    return 0;

}




