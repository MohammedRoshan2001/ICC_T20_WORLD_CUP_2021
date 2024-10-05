#include <stdio.h>
#include <stdlib.h>
typedef struct team
{
	char team_name[20];
	int matches_played;
	float overs_play_bat;
	float overs_play_bowl;
	int runs_scored_bat;
	int runs_scored_bowl;
	int points;
	int win;
	int loss;
	int draw;
	float NetRunrate;
}TEAM;
void fnMaxHeapify(TEAM a[],int i,int n)
{
int l,r,largest;
TEAM temp;
l=2*i;
r=(2*i)+1;
if((l<=n)&& (a[l].points>a[i].points))
{
largest=l;
}
else
	largest=i;
if((r<=n)&&(a[r].points>a[largest].points))
	largest=r;
if(largest!=i)
{
temp=a[i];
a[i]=a[largest];
a[largest]=temp;
fnMaxHeapify(a,largest,n);
}
}
void fnBuildMaxHeap(TEAM a[],int n)
{
int i;
for(i=n/2;i>=1;i--)
fnMaxHeapify(a,i,n);
}
void fnHeapSort(TEAM a[],int n)
{
TEAM temp;
int i;
fnBuildMaxHeap(a,n);
for(i=n;i>=2;i--)
{
temp=a[1];
a[1]=a[i];
a[i]=temp;
fnMaxHeapify(a,1,i-1);
}
}
int main()
{
	printf("\n\t\t---------------------------------");
	printf("\n\t\tWELCOME TO ICC T20 WORLD CUP 2021");
	printf("\n\t\t---------------------------------\n\n");
    TEAM t[5],z[5],temp;
    int i,w1,w2;
    int a[]={12,34,13,24,14,23};
    int k,l,p,q,r,j;
    int x;
    float y;
    int runs_bat1,runs_bat2;
    float bat1_overs,bat2_overs;
    printf("Enter Names of 4 Teams participating ICC T20 WORLD CUP 2021\n");
    for(i=1;i<=4;i++)
    {
		scanf("%s",t[i].team_name);
		for(r=0;t[i].team_name[r]!='\0';r++)
		{
			if(t[i].team_name[r]>=97&&t[i].team_name[r]<=122)
			{
				t[i].team_name[r]=t[i].team_name[r]-32;
			}
		}
		t[i].matches_played=0;
		t[i].overs_play_bat=0;
		t[i].overs_play_bowl=0;
		t[i].runs_scored_bat=0;
		t[i].runs_scored_bowl=0;
		t[i].points=0;
		t[i].NetRunrate=0;
		t[i].win=0;
		t[i].draw=0;
		t[i].loss=0;

    }
    printf("\n\t--------------------------------------\n");
    printf("\t********* Tournament Schedule ********");
    printf("\n\t--------------------------------------\n");
    for(i=0;i<6;i++)
    {
		k=(a[i]/10)%10;
		l=a[i]%10;
		printf("\n\tMatch %d :\t%s\tvs\t%s\n",i+1,t[k].team_name,t[l].team_name);
    }
    printf("\n\t--------------------------------------\n");
    for(i=0;i<6;i++)
    {
		printf("\n\n\n\t**** Match %d ****\n\n",i+1);
		k=(a[i]/10)%10;
		l=a[i]%10;
		printf("\t    %s vs %s\n",t[k].team_name,t[l].team_name);
		printf("\n\t*** Toss time ***\n\n");
		printf("\nEnter 1 if %s wins the toss\n\tOR\nEnter 2 if %s wins the toss\n",t[k].team_name,t[l].team_name);
		scanf("%d",&p) ;
		if(p==1)
		{
			printf("\nEnter 1 if %s choose to bat\n\tOR\nEnter 2 if %s choose the bowl\n",t[k].team_name,t[k].team_name);
			scanf("%d",&q);
			if(q==1)
				printf("\n\n\t%s won the toss and Elected to bat first\n",t[k].team_name);
			else
				printf("\n\n\t%s won the toss and Elected to field first\n",t[k].team_name);
		}
		else
		{
			printf("Enter 1 if %s choose to bat\n\tOR\nEnter 2 if %s choose the bowl\n",t[l].team_name,t[l].team_name);
			scanf("%d",&q);
			if(q==1)
				printf("\n\n\t%s won the toss and Elected to bat first\n",t[l].team_name);
			else
				printf("\n\n\t%s won the toss and Elected to field first\n",t[l].team_name);
		}
		if((p==1&&q==1)||(p==2&&q==2))
		{
			printf("\n\nEnter runs scored by %s : ",t[k].team_name);
			scanf("%d",&runs_bat1);
			printf("\nEnter overs taken by %s : ",t[k].team_name);
			scanf("%f",&bat1_overs);
			printf("\nEnter wickets conceded by %s : ",t[k].team_name);
			scanf("%d",&w1);
			printf("\nEnter runs scored by %s : ",t[l].team_name);
			scanf("%d",&runs_bat2);
			printf("\nEnter overs taken by %s : ",t[l].team_name);
			scanf("%f",&bat2_overs);
			printf("\nEnter wickets conceded by %s : ",t[l].team_name);
			scanf("%d",&w2);
			printf("\n\n\t\t   MATCH SUMMARY");
			printf("\n\t-----------------------------------");
			printf("\n\n\t%s : %d/%d\t\t%s : %d/%d\n",t[k].team_name,runs_bat1,w1,t[l].team_name,runs_bat2,w2);
			if(w2==10)
				bat2_overs=20;
			x=bat2_overs;
			y=bat2_overs-x;
			y=y/0.6;
			bat2_overs=x+y;
			t[k].overs_play_bat+=20;
			t[k].overs_play_bowl+=bat2_overs;
			t[l].overs_play_bowl+=20;
			t[l].overs_play_bat+=bat2_overs;
			t[k].runs_scored_bat+=runs_bat1;
			t[k].runs_scored_bowl+=runs_bat2;
			t[l].runs_scored_bat+=runs_bat2;
			t[l].runs_scored_bowl+=runs_bat1;
		if(runs_bat1<runs_bat2)
		{
			t[l].win+=1;
			t[k].loss+=1;
			t[l].points+=2;
			printf("\n\t%s beat %s by %d wickets\n",t[l].team_name,t[k].team_name,10-w2);
		}
		else if(runs_bat1>runs_bat2)
		{
			t[k].win+=1;
			t[l].loss+=1;
			t[k].points+=2;
			printf("\n\t%s beat %s by %d runs\n",t[k].team_name,t[l].team_name,runs_bat1-runs_bat2);
		}
		else
		{
			t[l].draw+=1;
			t[k].draw+=1;
			t[k].points+=1;
			t[l].points+=1;
			printf("\n\tMATCH TIED\n");
		}

		}
		else
		{
			printf("\n\nEnter runs scored by %s : ",t[l].team_name);
			scanf("%d",&runs_bat1);
			printf("\nEnter overs taken by %s : ",t[l].team_name);
			scanf("%f",&bat1_overs);
			printf("\nEnter wickets conceded by %s : ",t[l].team_name);
			scanf("%d",&w1);
			printf("\nEnter runs scored by %s : ",t[k].team_name);
			scanf("%d",&runs_bat2);
			printf("\nEnter overs taken by %s : ",t[k].team_name);
			scanf("%f",&bat2_overs);
			printf("\nEnter wickets conceded by %s : ",t[k].team_name);
			scanf("%d",&w2);
			printf("\n\n\t\t   MATCH SUMMARY");
			printf("\n\t-----------------------------------");
			printf("\n\n\t%s : %d/%d\t\t%s : %d/%d\n",t[l].team_name,runs_bat1,w1,t[k].team_name,runs_bat2,w2);
			if(w2==10)
				bat2_overs=20;
			x=bat2_overs;
			y=bat2_overs-x;
			y=y/0.6;
			bat2_overs=x+y;
			t[l].overs_play_bat+=20;
			t[l].overs_play_bowl+=bat2_overs;
			t[k].overs_play_bowl+=20;
			t[k].overs_play_bat+=bat2_overs;
			t[k].runs_scored_bat+=runs_bat2;
			t[k].runs_scored_bowl+=runs_bat1;
			t[l].runs_scored_bat+=runs_bat1;
			t[l].runs_scored_bowl+=runs_bat2;
		if(runs_bat1<runs_bat2)
		{
			t[k].win+=1;
			t[l].loss+=1;
			t[k].points+=2;
			printf("\n\t%s beat %s by %d wickets\n",t[k].team_name,t[l].team_name,10-w2);
		}
		else if(runs_bat1>runs_bat2)
		{
			t[l].win+=1;
			t[k].loss+=1;
			t[l].points+=2;
			printf("\n\t%s beat %s by %d runs\n",t[l].team_name,t[k].team_name,runs_bat1-runs_bat2);
		}
		else
		{
			t[l].draw+=1;
			t[k].draw+=1;
			t[k].points+=1;
			t[l].points+=1;
			printf("\n\t\tMATCH TIED!!!!!\n");
		}

		}

		t[k].matches_played+=1;
		t[l].matches_played+=1;
		t[k].NetRunrate=((float)t[k].runs_scored_bat)/t[k].overs_play_bat-((float)t[k].runs_scored_bowl)/t[k].overs_play_bowl;
		t[l].NetRunrate=((float)t[l].runs_scored_bat)/t[l].overs_play_bat-((float)t[l].runs_scored_bowl)/t[l].overs_play_bowl;
		for(j=1;j<=4;j++)
			z[j]=t[j];
		fnHeapSort(z,4);
		for(j=1;j<=3;j++)
		{
			if(z[j].points==z[j+1].points)
			{
				if(z[j+1].NetRunrate<z[j].NetRunrate)
				{
					temp=z[j+1];
					z[j+1]=z[j];
					z[j]=temp;
				}
			}
		}
		printf("\n\t--------------------------------------------------------") ;
		if(i!=5)
		{
		printf("\n\t\t\tCurrent Points Table");
		printf("\n\t--------------------------------------------------------") ;
		printf("\n\tTeam\tPld\tWon\tLost\tTied\tPts\tNetRR");
		printf("\n\t--------------------------------------------------------\n") ;
		for(j=4;j>=1;j--)
			printf("\t%s\t%d\t%d\t%d\t%d\t%d\t%.3f\n",z[j].team_name,z[j].matches_played,z[j].win,z[j].loss,z[j].draw,z[j].points,z[j].NetRunrate);
		printf("\t--------------------------------------------------------") ;
		}
    }
    printf("\n\t\t\tFinal Points Table");
    printf("\n\t--------------------------------------------------------") ;
	printf("\n\tTeam\tPld\tWon\tLost\tTied\tPts\tNetRR");
	printf("\n\t--------------------------------------------------------\n") ;
	for(j=4;j>=1;j--)
		printf("\t%s\t%d\t%d\t%d\t%d\t%d\t%.3f\n",z[j].team_name,z[j].matches_played,z[j].win,z[j].loss,z[j].draw,z[j].points,z[j].NetRunrate);
	printf("\t--------------------------------------------------------\n\n") ;
    return 0;
}

