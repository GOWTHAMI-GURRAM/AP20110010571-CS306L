#include<stdio.h>
char st[50];
char *ip;
int S();
int L();
int Ldash();
int main()
{  

printf("enter the string:");
scanf("%s",st);
ip=st;
printf("\n\nInput\tAction\n--------------------------------\n");
if(S() && ip!='\0')
{  printf("\n--------------------------------\n");
   printf("\n String is successfully parsed\n");
}
else
{  
printf("\n--------------------------------\n");
printf("Error in parsing String\n");
}	
}
        

int S()
{ 
	if(*ip=='(')
	{  printf("%s\tS->(L) \n",ip);
	   ip++;
	   
		if(L())
		{
			
			if(*ip==')')
			{   
				ip++;
			   
				return 1;
			}
			else
			{ 
			printf("Missimg closing parenthesis \n");
				return 0;
			}
			
		}
		else
		{   
			printf("it is an error");
			return 0;
		}
     	}
		else if(*ip=='a')
		{    printf("%s\tS->a \n",ip);
		
		  ip++;
		  
		  return 1;
		}
		else
	{
		
		
		return 0;
	}
	
}

int Ldash()
{ 
  if(*ip==',')
  {printf("%s\tL'->,SL' \n",ip);
  	ip++;
  	if(S())
  	{
  		
  		if(Ldash())
  		{
  			return 1;
		  }
		  else
		  {
		  	return 0;
		  }
	  }
	  else
	  { 
	  	return 0;
	  }
  }
  else 
  { printf("%s\tL'->^ \n",ip);
    
  	return 1;
  }
  
	
	
}

int L()
{ printf("%s\tL->SL' \n",ip);
	if(S())
	{
		if(Ldash())
		{
			return 1;
		}
		else { 
			return 0;
		}
	}
	else
	{
		return 0;
	}
	
	
}

