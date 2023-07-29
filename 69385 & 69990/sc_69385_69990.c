#include<stdio.h>
#include<math.h>
int main(){

    int numcalls, calltype, i, minute, second, localtotalduration, intertotalduration, minutelocal, secondlocal, minuteinter, secondinter;
    float totalcharge1, totalcharge2, totalcharge3, totalcharge4, totalcharge, totallocalcharge, totalintercharge,
    flatratesameopt, flatratedifferopt, flatrateinter, flatrateintermobile, 
    duration1, duration2, duration3, duration4, block, block1, block2, block3, block4,
    fixedcharge, firstthreeminutes, fixedcharge3, firstthreeminutes3;

    printf("Enter the number of calls(s) : ");
    scanf("%d", &numcalls);


    for(i=1; i<=numcalls; i++){

    printf("Enter the type of call %d (1-Local(Same); 2-Local(Other); 3-Inter(Land); 4-Inter(Mobile)): " , i);
    scanf("%d", &calltype);


    printf("Enter the duration of call-%d (in minute and second, separated by a space): ", i);
    scanf("%d %d", &minute, &second);

    switch(calltype)
    {

    case 1:
        {
                duration1=minute*60+second;
				block1=ceil(duration1/25);
				totalcharge1=block1*0.20;
				printf("Call-%d charge is RM%.2f\n\n",i,totalcharge1);
				break;
        }

    case 2:
        {
                duration2=minute*60+second;
				block2=ceil(duration2/30);
				totalcharge2=block2*0.35;
				printf("Call-%d charge is RM%.2f\n\n",i,totalcharge2);
				break;
        }

    case 3:
        {
        	flatrateinter = 0.75;
            fixedcharge3= 0.50;
            firstthreeminutes3= 2.50;
			duration3=minute*60+second;
            block3=ceil((duration3-180)/60);

                if(duration3<=180&&duration3>0 )
		    	{
		    		totalcharge3=fixedcharge3+firstthreeminutes3;
		        	printf("Call-%d charge is RM%.2lf\n\n",i,totalcharge3);
		        }
		    	else
		    	{
					totalcharge3 = (block3 * flatrateinter)+ fixedcharge3+ firstthreeminutes3;
                    printf("Call %d charge is RM%.2f\n\n", i, totalcharge3);
				}
				break;
       }

    case 4:
        {
        	flatrateintermobile = 0.85;
            fixedcharge= 1.00;
            firstthreeminutes= 3.00;
			duration4=minute*60+second;
            block4=ceil((duration4-180)/60);
                if(duration4<=180&&duration4>0)
		    	{
		    		totalcharge4=fixedcharge+firstthreeminutes;
		        	printf("Call-%d charge is RM%.2f\n\n",i,totalcharge4);
		        }
		    	else
		    	{
                    totalcharge4 = (block4 * flatrateintermobile) + fixedcharge+ firstthreeminutes;
                    printf("Call %d charge is RM%.2f\n\n", i, totalcharge4);
				}
				break;

            default:
			{
				printf("Invalid choice.\n");
			}
            break;

        }
    }
}   
	
	localtotalduration= duration1+duration2;
	intertotalduration= duration3+duration4;
	minutelocal = localtotalduration / 60;
    secondlocal = localtotalduration % 60;
    
	minuteinter = intertotalduration / 60;
	secondinter = intertotalduration % 60;

	totallocalcharge = totalcharge1 + totalcharge2;
	totalintercharge = totalcharge3 + totalcharge4;
	totalcharge = totalcharge1 + totalcharge2 + totalcharge3 + totalcharge4;

    printf("Total local call duration is %dmin %dsec \n", minutelocal, secondlocal);
    printf("Total local charge is RM%.2f \n", totallocalcharge);
    printf("Total international call duration is  %dmin %dsec \n", minuteinter, secondinter);
    printf("Total international charge is RM%.2f \n", totalintercharge);
    printf("Total charge is RM%.2f \n", totalcharge);


return 0;

}
