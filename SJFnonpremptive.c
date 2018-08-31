
#include<stdio.h>

int main(){

    int i;

    int arr[3]={3,6,0};

    int burst[3]={10,5,8};

    int process[3]={1,2,3};

    sort(arr,burst,process,3);                                                             //call for sorting

    printf("\nPROCESS TIME:\t\t%d\t\t%d\t\t%d\t\t\n\n", burst[0],burst[1],burst[2]);

    printf("PROCESS :\t\tP%d\t\tP%d\t\tP%d\t\t\n\n\n", process[0],process[1],process[2]);

    gnattchart(burst,process,arr);                                                         //call for gnat chart



return 0;



}



int sort(int arr[],int burst[],int process[],int n)

{

   int i, key, key1, key2,j;

   for (i = 1; i < n; i++)

   {

       key = burst[i];                                      //sorting according to shortest burst time

       key1=arr[i];                                         //process       burst time          arrival

       key2=process[i];                                     //  p2              5                   6

       j = i-1;                                             //  p3              8                   0

        while (j >= 0 && burst[j] > key)                    //  p1              10                  3

       {

          burst[j+1]=burst[j];

          arr[j+1]=arr[j];

          process[j+1]=process[j];

           j = j-1;

       }

       burst[j+1] = key;

       arr[j+1]=key1;

       process[j+1]=key2;

   }



    for(i=0;i<3;i++){

        printf("P%d\t%d\t%d\n", process[i],burst[i],arr[i]);

    }

   return 0;

}









int gnattchart(int burst[],int process[],int arr[]){

    int gnat[4],counter,i,k,a,t,l;

    for(a=1;a<3;a++){                                               //checking whether any other process has arrived at 0

        if(arr[a]==0){

            t=arr[a];

            arr[a]=arr[0];                                          //if arrived then change the process execution

            arr[0]=t;                                               //process execution changed from

            k=process[a];                                           //P2 -> P3 -> P1   to

            process[a]=process[0];                                  //P3 -> P2 -> P1

            process[0]=k;

            l=burst[a];

            burst[a]=burst[0];

            burst[0]=l;

            break;

        }

        else

            break;



    }



    gnat[0]=0;

    gnat[1]=burst[0];

    gnat[2]=burst[1]+burst[0];

    gnat[3]=burst[1]+burst[0]+burst[2];                                 //calculating gnat values

    printf("\n\nGNATT CHART:");

    printf("\t|\tP%d\t|\tP%d\t|\tP%d\t|\tend\t|\n\n\t\t|\t", process[0],process[1],process[2]);

    for( i=0;i<4;i++){

        printf("%d\t|\t", gnat[i]);

    }

    printf("\n\n\n");

    turnaround(arr,gnat,process);

}





int turnaround(int arr[], int gnatt[], int process[]){

    int tarr[3][2],a,j,i,k, taranswer[3],waittime[3];float ans1=0,ans2=0;

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



    printf("TURN AROUND TIME:\t");

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



}




